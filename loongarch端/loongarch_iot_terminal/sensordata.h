#ifndef SENSORDATA_H
#define SENSORDATA_H

#define BAT_MAX_V 4.20
#define BAT_MIN_V 3.50

#define ADC_REG_MAX 30240
#define ADC_REG_MIN 25935

#define Number 5            // 采样点数

#include <QDebug>
#include <QTextStream>
#include <QDate>            //日期
#include <QTime>            //时间
#include <QMessageBox>      //消息窗口

class sensordata
{
public:
    //标识是哪个节点
    int rank = 0;

    //节点的数据表对象
    int id = 0;
    QString dateTime;
    QString date = "2023-4-4";
    QString time = "12:30:00";
    int temperature = 25;   //节点温度
    int humidity = 60;      //节点湿度
    int lightlux = 200;     //节点光照
    int state = 0;     //节点在线状态
    int stateStack = 0;     //节点状态修正
    int bat = 100;          //节点电量
    int bat_uint16 = 0;     //节点ADC寄存器值
    int batState = 0;       //节点充放电指示器
    float ultrasonic = 0.5;

    int Filter_Arr[Number];    //保存过去N个采样值
    int sma_data = 0;          //滤波后的数据
    int bat_min = 100;         //设置电量波动最小值

    sensordata();
    sensordata(int rank);
    ~sensordata();

    int SMA_Filter(int bat_uint16);

    void get_bat(int bat_uint16);
    void get_bat_2();

    void get_state();

    void insert_sensordb();
    void delete_sensordb();
    void update_sensordb();
    void select_sensordb();

private:
    int get_state_on = 0;
    int get_state_off = 0;


};

#endif // SENSORDATA_H
