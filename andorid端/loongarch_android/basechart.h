#ifndef BASECHART_H
#define BASECHART_H

#include <QtCharts>
#include <QDate>
#include <QTime>
#include <QDateTime>

using namespace QtCharts;

//折线图的类
class basechart
{
public:

    int rank;
    QString datestr = "2023-4-4";
    QString timestr = "12:30:00";
    QDate date;
    QTime time;
    bool flagt = true;
    bool flagh = true;
    bool flagl = true;

    QDateTime xMin,xMax;                // 设置时间初始坐标轴范围

    QChart *temperature_chart;
    QDateTimeAxis *temperature_axisX;          //坐标轴
    QValueAxis *temperature_axisY;
    QSplineSeries *temperature_series ;     //平滑曲线的集合

    QChart *humidity_chart;
    QDateTimeAxis *humidity_axisX;
    QValueAxis *humidity_axisY;
    QSplineSeries *humidity_series ;

    QChart *lightlux_chart;
    QDateTimeAxis *lightlux_axisX;
    QValueAxis *lightlux_axisY;
    QSplineSeries *lightlux_series ;

    basechart();
    basechart(int rank,QDate date);

    void chartInit(int rank,QDate date);
    void temperature_chartInit();
    void temperature_chart_update(int temperature);
    void humidity_chartInit();
    void humidity_chart_update(int humidity);
    void lightlux_chartInit();
    void lightlux_chart_update(int lightlux);
//    void time_range_update();

signals:

};

#endif // BASECHART_H
