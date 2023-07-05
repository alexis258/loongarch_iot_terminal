#ifndef WINDOW2_H
#define WINDOW2_H

#include <QWidget>

#include <QtCharts>

#include "basechart.h"
#include "sensordata.h"

namespace Ui {
class window2;
}

class window2 : public QWidget
{
    Q_OBJECT

public:
    explicit window2(QWidget *parent = nullptr);
    ~window2();

    sensordata sensor1;
    sensordata sensor2;
    sensordata sensor3;


private slots:
    void on_pushButton_clicked();

    void on_chooseBT_clicked();

private:
    Ui::window2 *ui;

    QDate currentDate = QDate::currentDate();
    QTimer *Window2UpdateTimer;

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
};

#endif // WINDOW2_H
