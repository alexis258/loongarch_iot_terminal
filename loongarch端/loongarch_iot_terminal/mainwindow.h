#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>

#include <QTimer>
#include <QPainter>
#include <QDateTime>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

#include <QtCharts>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QModelIndexList>

#include <QJsonDocument>        //获取json串
#include <QJsonObject>
#include <QJsonArray>

#include <QtMqtt/QMqttClient>

#include "sensordata.h"
#include "basechart.h"
#include "basetable.h"
#include "basealarm.h"
#include "exportapi.h"

#define DEVICE_NAME "LoongArch64"
#define POST_TOPIC_ALIYUN "/sys/ifosctA7yNu/LoongArch64/thing/event/property/post"
#define JSON_METHOD "/thing/event/property/post"

using namespace QtCharts;

#pragma pack(push,1)
typedef struct {
    uint8_t type;
    uint16_t pNWK;
    uint16_t myNWK;

}RXBF;
#pragma pack(pop)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void setClientPort(int p);

private slots:
    //日期标签定时器更新
    void timerUpdate();

    //滚动标签定时器更新
    void indexUpdate();

    //界面1数据显示变化
    void CB1TimerUpdate();

    //时间组合框定时器更新
    void dateCBTimerUpdate();

    //拓扑网络图时间定时器更新
    void topoUpdate();

    //串口
    void serialPortReadyRead();  //当串口有数据传输过来时触发定时器
    void serialTimerUpdate();       //定时器内处理数据

    //mqtt上报
    void mqttTimerUpdate();

    //数据库
    void on_insertPB_clicked();
    void on_deletePB_clicked();
    void on_checkPB_clicked();
    void on_getTimePB_clicked();

    //mqtt
    void on_buttonSetting_clicked();
    void on_buttonConnect_clicked();
    void updateLogStateChange();
    void brokerDisconnected();
    void on_buttonSubscribe_clicked();
    void on_buttonPublish_clicked();
    void on_buttonUnsubscribe_clicked();
    void on_buttonClear_clicked();
    void on_settopicPB_clicked();
    void on_publishPB_clicked();

    void on_connectdbPB_clicked();

    void on_clear1PB_clicked();

    void on_clear2PB_clicked();

    void on_findserialPB_clicked();

    void on_openserialPB_clicked();

    void on_closeserialPB_clicked();

    void on_sendPB_clicked();

    void on_debugPB_clicked();

    void on_showChartPB_clicked();

    void on_showTablePB_clicked();

    void on_showAlarmPB_clicked();

    void on_setValuePB_clicked();

    void on_exportPB_clicked();


    void on_pushButton_clicked();

    void on_exportPB2_clicked();

private:
    Ui::MainWindow *ui;

    //滚动标签参数
    QString rollShowText = "XXXX大学基于龙芯派的物联网食品仓库监测系统            "; //21+12
    QTimer  *rollTimer;

    //日期标签参数，界面1数据更新
    QDateTime dateTime;
    QString dateStr;
    QTimer *dateTimer;


    //1.更新所有组合框时间
    QDate currentDate = QDate::currentDate();
    QString dateToday;
    QString dateYesterday;
    QString dateBeforeday;
    QTimer *updateDateTimer;
    QString strT1;
    QString strH1;
    QString strL1;
    QString strB1;
    void CB1TimerUpdate_Update(sensordata sensordata_temp);

    //2.图表显示
    void ChartInit();
    void chartUpdate();
    void chartUpdate_Update(basechart *sensorchart_temp,sensordata *sensordata_temp);
    QChartView  *m_chartView;       //画布
    QChartView  *T1_chartView;
    QChartView  *H1_chartView;
    QChartView  *L1_chartView;
    QChartView  *T2_chartView;
    QChartView  *H2_chartView;
    QChartView  *L2_chartView;
    QChartView  *T3_chartView;
    QChartView  *H3_chartView;
    QChartView  *L3_chartView;
    basechart sensor1chart;
    basechart sensor2chart;
    basechart sensor3chart;
    QWidget *pWidget;
    QTimer *chartTimer;

    //3.表格显示
    void TableInit();
    void tableUpdate();
    QTableView *m_tableView;
    basetable sensor1table;
    basetable sensor2table;
    basetable sensor3table;
    QWidget *tWidget;
    QTimer *tableTimer;

    //4.报警显示
    void AlarmInit();
    void alarmUpdate();
    QTableView *a_tableView;
    basealarm sensor1alarm;
    basealarm sensor2alarm;
    basealarm sensor3alarm;
    QWidget *aWidget;
    QTimer *alarmTimer;

    //5.节点网络拓扑图
    int coorstate = 0;
    int coorStack = 0;
    int topoCurRow;
    QTimer *topoTimer;
    int coor_temp = 0;  //协调器临时状态
    int enda_temp = 0;
    int endb_temp = 0;
    int endc_temp = 0;
    void topoUpdate_Update(sensordata *sensor_temp,int *temp,QLabel *endL,int topoCurRow);

    //7.串口对象
    QSerialPort *serialPort;
    QByteArray serialBuf;       //串口接收的数据
    QTimer  *serialTimer;       //用于串口接收数据延迟，一次性读取所有数据
//    QString strout;             //最终拼接的字符串
//    QString strI;               //接收发来信息的源头
//    QString strT;               //接收发来数据帧的温度
//    QString strH;               //接收发来数据帧的湿度
//    QString strL;               //接收发来数据帧的光照
//    QString strS;               //接收发来数据帧的在线状态
//    QString strB;               //接收发来数据帧的电压
//    int battery;                //电压16位
//    int state;                  //掉线状态
//    int stateFlag;
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity checkBits;
    void serialTimerUpdate_Update(sensordata *sensordata_temp);

    QByteArray m_message;      //全部的字符流
    void message1Update();       //处理节点一数据
    void message2Update();       //处理节点二数据
    void message3Update();       //处理节点三数据
    void get_json_data(QJsonObject *json,QString value,int *sensor);
    QTimer  *messageTimer;       //处理全部json数据

    int SMA_DATA = 0;           //ADC电压滤波之后的结果

    //数据库创建
//    void CreateDatabaseFunc();
//    void CreateTableFunc();
//    QSqlDatabase sqldb;
//    QSqlQueryModel sqlmodel;
    sensordata sensor1;
    sensordata sensor2;
    sensordata sensor3;
    sensordata sensor4;

    //mqtt连接参数
    QMqttClient *m_client;
    QString host_aliyun = "iot-06z00fag7q36ymv.mqtt.iothub.aliyuncs.com";
    QString username_aliyun = "LoongArch64&ifosctA7yNu";
    QString password_aliyun = "0b77d1909de557804c9f384410bde5a66990c978f6ce17ae4d36a1892bb59403";
    QString clientid_aliyun = "ifosctA7yNu.LoongArch64|securemode=2,signmethod=hmacsha256,timestamp=1681799741455|";
    QString topic_node1_aliyun = "/ifosctA7yNu/LoongArch64/user/node1";
    QString topic1 = POST_TOPIC_ALIYUN;
    QMqttTopicName post_sensor1_topic_aliyun = topic1;
    QTimer  *mqttTimer;       //用于周期上报云平台


protected:



};

#endif // MAINWINDOW_H
