#ifndef BASETABLE_H
#define BASETABLE_H

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDebug>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHeaderView>

class basetable
{
public:
    int rank;
    int rowCount;   //表格行数

    int id = 1;     //<28800
    QDate date;
    QTime time;
    int temperature;
    int humidity;
    int lightlux;

    QTableWidget *ui_table;
    QTableWidgetItem *table00;  //序号
    QTableWidgetItem *table01;  //时间
    QTableWidgetItem *table02;  //温度
    QTableWidgetItem *table03;  //湿度
    QTableWidgetItem *table04;  //光照

    basetable();

    void tableInit(int rank);
    void table_update(int temperatureint,int humidity,int lightlux);


};

#endif // BASETABLE_H
