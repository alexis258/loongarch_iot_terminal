/*********************************************************************
 * INCLUDES
 */

#include <stdio.h>
#include <string.h>
#include "AF.h"
#include "OnBoard.h"
#include "OSAL_Tasks.h"
#include "SampleApp.h"
#include "ZDApp.h"
#include "ZDObject.h"
#include "ZDProfile.h"

#include "hal_drivers.h"
#include "hal_key.h"

#if defined ( LCD_SUPPORTED )
  #include "hal_lcd.h"
#endif

#include "hal_led.h"
#include "hal_uart.h"
#include "dht11.h"
#include "B_LUX_V30.h"
#include "ADC.h"
#include "cJSON.h"


/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

#if !defined( SAMPLE_APP_PORT )
#define SAMPLE_APP_PORT  0
#endif

#if !defined( SAMPLE_APP_BAUD )
  #define SAMPLE_APP_BAUD  HAL_UART_BR_115200
#endif

// When the Rx buf space is less than this threshold, invoke the Rx callback.
#if !defined( SAMPLE_APP_THRESH )
#define SAMPLE_APP_THRESH  64
#endif

#if !defined( SAMPLE_APP_RX_SZ )
#define SAMPLE_APP_RX_SZ  128
#endif

#if !defined( SAMPLE_APP_TX_SZ )
#define SAMPLE_APP_TX_SZ  128
#endif

// Millisecs of idle time after a byte is received before invoking Rx callback.
#if !defined( SAMPLE_APP_IDLE )
#define SAMPLE_APP_IDLE  6
#endif

// Loopback Rx bytes to Tx for throughput testing.
#if !defined( SAMPLE_APP_LOOPBACK )
#define SAMPLE_APP_LOOPBACK  FALSE
#endif

// This is the max byte count per OTA message.
#if !defined( SAMPLE_APP_TX_MAX )
#define SAMPLE_APP_TX_MAX  80
#endif

#define SAMPLE_APP_RSP_CNT  4

// This list should be filled with Application specific Cluster IDs.
const cId_t SampleApp_ClusterList[SAMPLE_MAX_CLUSTERS] =
{
  SAMPLEAPP_P2P_CLUSTERID,
  SAMPLEAPP_PERIODIC_CLUSTERID,
};

const SimpleDescriptionFormat_t SampleApp_SimpleDesc =
{
  SAMPLEAPP_ENDPOINT,              //  int   Endpoint;
  SAMPLEAPP_PROFID,                //  uint16 AppProfId[2];
  SAMPLEAPP_DEVICEID,              //  uint16 AppDeviceId[2];
  SAMPLEAPP_DEVICE_VERSION,        //  int   AppDevVer:4;
  SAMPLEAPP_FLAGS,                 //  int   AppFlags:4;
  SAMPLE_MAX_CLUSTERS,          //  byte  AppNumInClusters;
  (cId_t *)SampleApp_ClusterList,  //  byte *pAppInClusterList;
  SAMPLE_MAX_CLUSTERS,          //  byte  AppNumOutClusters;
  (cId_t *)SampleApp_ClusterList   //  byte *pAppOutClusterList;
};

endPointDesc_t SampleApp_epDesc =
{
  SAMPLEAPP_ENDPOINT,
 &SampleApp_TaskID,
  (SimpleDescriptionFormat_t *)&SampleApp_SimpleDesc,
  noLatencyReqs
};

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */
devStates_t SampleApp_NwkState;   
uint8 SampleApp_TaskID;           // Task ID for internal task/event processing.

/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */

static uint8 SampleApp_MsgID;

afAddrType_t SampleApp_Periodic_DstAddr; //广播
afAddrType_t SampleApp_Flash_DstAddr;    //组播
afAddrType_t SampleApp_P2P_DstAddr;      //点播


static afAddrType_t SampleApp_TxAddr;
static uint8 SampleApp_TxSeq;
static uint8 SampleApp_TxBuf[SAMPLE_APP_TX_MAX+1];
static uint8 SampleApp_TxLen;

static afAddrType_t SampleApp_RxAddr;
static uint8 SampleApp_RxSeq;
static uint8 SampleApp_RspBuf[SAMPLE_APP_RSP_CNT];

/*********************************************************************
 * LOCAL FUNCTIONS
 */

static void SampleApp_ProcessMSGCmd( afIncomingMSGPacket_t *pkt );
void SampleApp_CallBack(uint8 port, uint8 event); 
static void SampleApp_Send_P2P_Message( void );


uint8 temp1Int;     //协调器保存终端1温度
uint8 temp2Int;     //协调器保存终端2温度
uint8 temp3Int;     //协调器保存终端3温度
uint8 hum1Int;      //协调器保存终端1湿度
uint8 hum2Int;      //协调器保存终端2湿度
uint8 hum3Int;      //协调器保存终端3湿度
uint16 light1Int;   //协调器保存终端1光照
uint16 light2Int;   //协调器保存终端2光照
uint16 light3Int;   //协调器保存终端3光照
uint32 light32;     //临时光照数据32
uint16 light;
uint8 state1Int;    //协调器保存终端1上线状态,0为离线，1为在线
uint8 state2Int;    //协调器保存终端2上线状态
uint8 state3Int;    //协调器保存终端3上线状态
uint16 bat1;         //协调器保存终端1电压
uint16 bat2;         //协调器保存终端2电压
uint16 bat3;         //协调器保存终端3电压
uint16 bat;         //临时电量数据
uint8 bat1State = 0;    //节点1电池充电状态
uint8 bat2State = 0;    //节点2电池充电状态
uint8 bat3State = 0;    //节点3电池充电状态

//cJSON *cjson_head=NULL; //json数据包
char *str=NULL;         //转化的发送内容

/*********************************************************************
 * @fn      示例应用程序信息//SampleApp_Init
 *
 * @brief   这是在OSAL任务初始化期间调用的//This is called during OSAL tasks' initialization.
 *
 * @param   task_id-OSAL分配的任务id//task_id - the Task ID assigned by OSAL.
 *
 * @return  none
 */
void SampleApp_Init( uint8 task_id )
{
  halUARTCfg_t uartConfig;

  SampleApp_TaskID = task_id;
  SampleApp_RxSeq = 0xC3;
  SampleApp_NwkState = DEV_INIT;       

  MT_UartInit();                  //串口初始化
  MT_UartRegisterTaskID(task_id); //注册串口任务
  afRegister( (endPointDesc_t *)&SampleApp_epDesc );
  RegisterForKeys( task_id );

#ifdef ZDO_COORDINATOR
  //协调器初始化
  Init_ADC0();
  Init_P06();
  
#else
  //终端初始化
  B_LUX30_Init();                 //光照传感器初始化
  Init_ADC0();
  Init_P06();
  
#endif

  SampleApp_Periodic_DstAddr.addrMode = (afAddrMode_t)AddrBroadcast;//广播
  SampleApp_Periodic_DstAddr.endPoint = SAMPLEAPP_ENDPOINT;
  SampleApp_Periodic_DstAddr.addr.shortAddr = 0xFFFF;

  // Setup for the flash command's destination address - Group 1
  SampleApp_Flash_DstAddr.addrMode = (afAddrMode_t)afAddrGroup;//组播
  SampleApp_Flash_DstAddr.endPoint = SAMPLEAPP_ENDPOINT;
  SampleApp_Flash_DstAddr.addr.shortAddr = SAMPLEAPP_FLASH_GROUP;
  
  SampleApp_P2P_DstAddr.addrMode = (afAddrMode_t)Addr16Bit; //点播 
  SampleApp_P2P_DstAddr.endPoint = SAMPLEAPP_ENDPOINT; 
  SampleApp_P2P_DstAddr.addr.shortAddr = 0x0000;            //发给协调器

  
}

/*********************************************************************
 * @fn      SampleApp_ProcessEvent
 *
 * @brief   Generic Application Task event processor.
 *
 * @param   task_id  - The OSAL assigned task ID.
 * @param   events   - Bit map of events to process.
 *
 * @return  Event flags of all unprocessed events.
 */
UINT16 SampleApp_ProcessEvent( uint8 task_id, UINT16 events )
{
  (void)task_id;  // Intentionally unreferenced parameter
  
  if ( events & SYS_EVENT_MSG )
  {
    afIncomingMSGPacket_t *MSGpkt;

    while ( (MSGpkt = (afIncomingMSGPacket_t *)osal_msg_receive( SampleApp_TaskID )) )
    {
      switch ( MSGpkt->hdr.event )
      {
      case AF_INCOMING_MSG_CMD:
        SampleApp_ProcessMSGCmd( MSGpkt );
        break;
        
      case ZDO_STATE_CHANGE:
        SampleApp_NwkState = (devStates_t)(MSGpkt->hdr.status);
        if ( (SampleApp_NwkState == DEV_ZB_COORD)||
            (SampleApp_NwkState == DEV_ROUTER)
            || (SampleApp_NwkState == DEV_END_DEVICE) )
        {
            //连网成功后，启动一个定时器
            osal_start_timerEx( SampleApp_TaskID,
                              SAMPLEAPP_SEND_PERIODIC_MSG_EVT,
                              SAMPLEAPP_SEND_PERIODIC_MSG_TIMEOUT );  //3秒定时器
        }
        else
        {
          // Device is no longer in the network
        }
        break;

      default:
        break;
      }

      osal_msg_deallocate( (uint8 *)MSGpkt );
    }

    return ( events ^ SYS_EVENT_MSG );
  }

  //定时器时间到
  if ( events & SAMPLEAPP_SEND_PERIODIC_MSG_EVT )
  {
    
#ifdef ZDO_COORDINATOR   //协调器节点完成的工作
    
    //协调器串口输出数据
    {
      uint8 buff[384]={0};
      
      cJSON *cjson_head=NULL; //json数据包
      char *str=NULL;         //转化的发送内容
      
      cjson_head=cJSON_CreateObject();

      cJSON_AddNumberToObject(cjson_head,"tem1",temp1Int);
      cJSON_AddNumberToObject(cjson_head,"hum1",hum1Int);
      cJSON_AddNumberToObject(cjson_head,"lux1",light1Int);
      cJSON_AddNumberToObject(cjson_head,"bat1",bat1);
      cJSON_AddNumberToObject(cjson_head,"state1",state1Int);
      
      cJSON_AddNumberToObject(cjson_head,"tem2",temp2Int);
      cJSON_AddNumberToObject(cjson_head,"hum2",hum2Int);
      cJSON_AddNumberToObject(cjson_head,"lux2",light2Int);
      cJSON_AddNumberToObject(cjson_head,"bat2",bat2);
      cJSON_AddNumberToObject(cjson_head,"state2",state2Int);
      cJSON_AddNumberToObject(cjson_head,"bat2State",bat2State);      
      
      cJSON_AddNumberToObject(cjson_head,"tem3",temp3Int);
      cJSON_AddNumberToObject(cjson_head,"hum3",hum3Int);
      cJSON_AddNumberToObject(cjson_head,"lux3",light3Int);
      cJSON_AddNumberToObject(cjson_head,"bat3",bat3);
      cJSON_AddNumberToObject(cjson_head,"state3",state3Int);
      
      str = cJSON_Print(cjson_head);

//      //格式化温度数据，收集数据，用于串口输出
//      sprintf(buff, "I1T%dH%dL%uS%dE\n", temp1Int, hum1Int, light1Int, state1Int);
      
//      sprintf(buff, "I1T%dH%dL%uB%uS%dE\n", temp1Int, hum1Int, light1Int, bat1, state1Int);
//      
//      //串口输出
//      HalUARTWrite(0, buff, osal_strlen(buff));
      
      //转buff
      sprintf(buff, str);
      
      //串口输出
      HalUARTWrite(0, buff, osal_strlen(buff));
      
//      int bbb = Get_P06();     //获取充电池电状态
//      
//      sprintf(buff, "%d",bbb);
//      
//      HalUARTWrite(0, buff, osal_strlen(buff));
      
      //释放内存
      cJSON_Delete(cjson_head);
      osal_mem_free(str);
      
      //状态定时器设为0
      state1Int=0;
      state2Int=0;
      state3Int=0;
    }
    
#else                    //终端类节点完成的工作
    
    //终端周期采集温湿度数据（发送数据),无线传输数据
    SampleApp_Send_P2P_Message();
    
#endif

    // 重新启动定时器
    osal_start_timerEx( SampleApp_TaskID, SAMPLEAPP_SEND_PERIODIC_MSG_EVT,
        (SAMPLEAPP_SEND_PERIODIC_MSG_TIMEOUT + (osal_rand() & 0x00FF)) );

    // return unprocessed events
    return (events ^ SAMPLEAPP_SEND_PERIODIC_MSG_EVT);
  }


  return ( 0 );  // Discard unknown events.
}

/*********************************************************************
 * @fn      SerialApp_ProcessMSGCmd
 *
 * @brief   Data message processor callback. This function processes
 *          any incoming data - probably from other devices. Based
 *          on the cluster ID, perform the intended action.
 *
 * @param   pkt - pointer to the incoming message packet
 *
 * @return  TRUE if the 'pkt' parameter is being used and will be freed later,
 *          FALSE otherwise.
 */

//处理发送过来的数据
void SampleApp_ProcessMSGCmd( afIncomingMSGPacket_t *pkt )
{
  uint8 buff[128]={0};

  switch ( pkt->clusterId )
  {
    
#ifdef ZDO_COORDINATOR      
  // 接收终端上传的温度数据
  case SAMPLEAPP_P2P_CLUSTERID: 
    {
        uint8 id=pkt->cmd.Data[0];//终端id
        uint8 t=pkt->cmd.Data[1]; //终端温度
        uint8 h=pkt->cmd.Data[2]; //终端湿度
        
        uint8 ll=pkt->cmd.Data[3]; //终端光照数据前半段
        uint8 lh=pkt->cmd.Data[4]; //终端光照数据后半段
        
        uint8 bl=pkt->cmd.Data[5]; //终端电池数据前半段
        uint8 bh=pkt->cmd.Data[6]; //终端电池数据后半段
        
        uint8 bs=pkt->cmd.Data[7]; //终端电池充电状态
        
        uint16 l=ll;    //处理光照数据
        l <<= 8;
        l = l + lh;
        
        uint16 b=bl;    //处理电量数据
        b <<= 8;
        b = b + bh;     
        
        if(id==1)
        {
          //保存终端1的温度,湿度,光照,状态,电量
          temp1Int=t;
          hum1Int=h;
          light1Int=l;
          state1Int=1;
          bat1 = b;
          bat1State = bs;
          
        }
        else if(id==2)
        {
          //保存终端2的温度,湿度,光照,状态,电量
          temp2Int=t;
          hum2Int=h;
          light2Int=l;
          state2Int=1;
          bat2 = b;
          bat2State = bs;          
          
        }
        else if(id==3)
        {
          //保存终端3的温度,湿度,光照,状态,电量
          temp3Int=t;
          hum3Int=h;
          light3Int=l;
          state3Int=1;
          bat3 = b;
          bat3State = bs;          
          
        }

    }
    break;
#endif
    
  case SAMPLEAPP_PERIODIC_CLUSTERID:

    break;

    default:
      break;
  }
}


/*********************************************************************
 * @fn      SampleApp_CallBack
 *
 * @brief   Send data OTA.
 *
 * @param   port - UART port.
 * @param   event - the UART port event flag.
 *
 * @return  none
 */
void SampleApp_CallBack(uint8 port, uint8 event)
{
  (void)port;

  if ((event & (HAL_UART_RX_FULL | HAL_UART_RX_ABOUT_FULL | HAL_UART_RX_TIMEOUT)) &&
#if SAMPLE_APP_LOOPBACK
      (SampleApp_TxLen < SAMPLE_APP_TX_MAX))
#else
      !SampleApp_TxLen)
#endif
  {
    SampleApp_TxLen += HalUARTRead(SAMPLE_APP_PORT, SampleApp_TxBuf+SampleApp_TxLen+1,
                                                      SAMPLE_APP_TX_MAX-SampleApp_TxLen);
  }
}

/*********************************************************************
 * @fn      SampleApp_Send_P2P_Message
 *
 * @brief   point to point.
 *
 * @param   none
 *
 * @return  none
 */
//搜集传感器数据及发送函数
void SampleApp_Send_P2P_Message( void )
{
  uint8 str[9]={0};
  uint8 strTemp[20]={0};
  int len=0;

  DHT11();             //获取温湿度
  light32 = B_LUX30_GetLux();
  light = light32 / 1000;
  
  bat = Get_ADC();     //获取电量数据
  
  int batState = Get_P06();     //获取充电池电状态

  str[0] = 2;             //增加一个ID，如果是多个终端就增加这个值
  str[1] = wendu;//温度
  str[2] = shidu;//湿度
  
  str[4] = light&0xFF;    //光照数据后8位
  light >>= 8;
  str[3] = light&0xFF;    //光照数据前8位
  
  str[6] = bat&0xFF;    //电量数据后8位
  bat >>= 8;
  str[5] = bat&0xFF;    //电量数据前8位 
  
  str[7] = batState;    //电池充电状态 

  len=9;

  sprintf(strTemp, "T:%d H:%d L:%u BS:%d", wendu,shidu,light,batState);

  HalUARTWrite(0, strTemp, osal_strlen(strTemp));           //串口输出提示信息
  HalUARTWrite(0, "\r\n",2);

  //无线发送到协调器
  if ( AF_DataRequest( &SampleApp_P2P_DstAddr, &SampleApp_epDesc,
                       SAMPLEAPP_P2P_CLUSTERID,
                       len,
                       str,
                       &SampleApp_MsgID,
                       AF_DISCV_ROUTE,
                       AF_DEFAULT_RADIUS ) == afStatus_SUCCESS )
  {
  }
  else
  {
    // Error occurred in request to send.
  }
}
