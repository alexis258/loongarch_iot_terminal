#ifndef BASEALARM_H
#define BASEALARM_H

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDebug>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHeaderView>

class basealarm
{
public:
    int rank;
    int rowCount;   //表格行数

    int id = 1;     //<28800
    QDate date;
    QTime time;
    int temperatureLower = 0;
    int temperatureUpper = 40;
    int humidityLower = 0;
    int humidityUpper = 95;
    int lightluxLower = 0;
    int lightluxUpper = 2000;
    QString tType;
    int tCorrect;
    QString hType;
    int hCorrect;
    QString lType;
    int lCorrect;
    bool tFlag = false;
    bool hFlag = false;
    bool lFlag = false;

    QTableWidget *ui_alarm;
    QTableWidgetItem *table00;  //序号
    QTableWidgetItem *table01;  //时间
    QTableWidgetItem *table02;  //报警种类
    QTableWidgetItem *table03;  //报警修正


    basealarm();

    void alarmInit(int rank);
    void alarm_set_limits(int temperatureLower,
                          int temperatureUpper,
                          int humidityLower,
                          int humidityUpper,
                          int lightluxLower,
                          int lightluxUpper);
    void alarm_update(int temperature,int humidity,int lightlux);
    void alarm_compare(int temperature,int humidity,int lightlux);


};


#endif // BASEALARM_H
