#ifndef SENSORDATA_H
#define SENSORDATA_H

#define BAT_MAX_V 4.0
#define BAT_MIN_V 3.7


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
    int temperature = 25;   //节点温度          1
    int humidity = 60;      //节点湿度          2
    int lightlux = 200;     //节点光照          3
    int bat = 100;          //节点电量          4
    int bat_uint16 = 0;     //节点ADC寄存器值
    float ultrasonic = 0.5;
    int state = 0;          //节点在线状态       5
    int stateStack = 0;     //节点状态修正

    sensordata();
    sensordata(int rank);
    ~sensordata();

    void get_bat(int bat_uint16);
    void insert_sensordb();
    void delete_sensordb();
    void update_sensordb();
    void select_sensordb();



};

#endif // SENSORDATA_H
