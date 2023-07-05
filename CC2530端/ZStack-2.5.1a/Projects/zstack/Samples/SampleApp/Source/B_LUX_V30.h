#ifndef __B_LUX_V30_H
#define __B_LUX_V30_H

/*--------------------------头文件引用--------------------------------*/
#include <iocc2530.h>

/*-----------------------------结构体定义---------------------------------*/

/*-----------------------------宏定义---------------------------------*/
//数据类型定义
#define   uint16    unsigned int
#define   uint8     unsigned char
#define   fint32    float
#define   uint32    unsigned long


#define         B_LUX30_SCL0      (0x01<<2)
#define         B_LUX30_SDA0      (0x01<<3)

//引脚定义，SCL定义为P1_2，SDA定义为P1_3
#define B_LUX30_SCL0_O    P1DIR |= 0x04
#define B_LUX30_SCL0_H    P1_2 = 1
#define B_LUX30_SCL0_L    P1_2 = 0

#define B_LUX30_SDA0_O    P1DIR |= 0x08    
#define B_LUX30_SDA0_H    P1_3 = 1
#define B_LUX30_SDA0_L    P1_3 = 0

#define B_LUX30_SDA0_I    P1DIR &= ~0x08
#define B_LUX30_SDA0_DAT  P1_3

#define	B_LUX30_SlaveAddress	  0x94        //定义器件在IIC总线中的从地址,根据ALT  ADDRESS地址引脚不同修改

/*-----------------------------函数声明-------------------------------*/
void B_LUX30_delay_nms(uint16 k);
void B_LUX30_Init(void);

void B_LUX30_Multiple_Write(uint8 REG_Address, uint8* vBuf, uint8 vLen);        //多字节写
void B_LUX30_Multiple_read(uint8 REG_Address, uint8* vBuf, uint8 vLen);         //多字节读
//------------------------------------
void B_LUX30_Delay5us(void);
void B_LUX30_Delay5ms(void);
void B_LUX30_Start(void);                          //起始信号
void B_LUX30_Stop(void);                           //停止信号
void B_LUX30_SendACK(uint8 ack);                  //应答ACK
uint8  B_LUX30_RecvACK(void);                     //读ack
void B_LUX30_SendByte(uint8 dat);                 //IIC单个字节写
uint8 B_LUX30_RecvByte(void);                     //IIC单个字节读
uint32 B_LUX30_GetLux();
#endif
