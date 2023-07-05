#include "window2.h"
#include "ui_window2.h"

window2::window2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(199,237,204)");

    //节点参数设计
    sensor1.rank = 1;
    sensor2.rank = 2;
    sensor3.rank = 3;

    //更新图表
    sensor1chart.chartInit(1,currentDate);
    sensor2chart.chartInit(2,currentDate);
    sensor3chart.chartInit(3,currentDate);
    ChartInit();
    Window2UpdateTimer = new QTimer(this);
    connect(Window2UpdateTimer,&QTimer::timeout,this,&window2::chartUpdate);
    Window2UpdateTimer->start(3000);
}

window2::~window2()
{
    delete ui;
}

void window2::on_pushButton_clicked()
{
    this->hide();
}

//数据图表函数
void window2::ChartInit()
{
    T1_chartView = new QChartView(sensor1chart.temperature_chart,this);     //画布
    sensor1chart.temperature_chart = T1_chartView->chart();                 //画笔
    T1_chartView->setRubberBand(QChartView::NoRubberBand);                  //矩形缩放
    T1_chartView->setRenderHint(QPainter::Antialiasing);                    //设置抗锯齿
    T1_chartView->setVisible(false);

    H1_chartView = new QChartView(sensor1chart.humidity_chart,this);
    sensor1chart.temperature_chart = H1_chartView->chart();
    H1_chartView->setRubberBand(QChartView::NoRubberBand);
    H1_chartView->setRenderHint(QPainter::Antialiasing);
    H1_chartView->setVisible(false);

    L1_chartView = new QChartView(sensor1chart.lightlux_chart,this);
    sensor1chart.temperature_chart = L1_chartView->chart();
    L1_chartView->setRubberBand(QChartView::NoRubberBand);
    L1_chartView->setRenderHint(QPainter::Antialiasing);
    L1_chartView->setVisible(false);


    T2_chartView = new QChartView(sensor2chart.temperature_chart,this);     //画布
    sensor2chart.temperature_chart = T2_chartView->chart();                 //画笔
    T2_chartView->setRubberBand(QChartView::NoRubberBand);                  //矩形缩放
    T2_chartView->setRenderHint(QPainter::Antialiasing);                    //设置抗锯齿
    T2_chartView->setVisible(false);

    H2_chartView = new QChartView(sensor2chart.humidity_chart,this);
    sensor2chart.temperature_chart = H2_chartView->chart();
    H2_chartView->setRubberBand(QChartView::NoRubberBand);
    H2_chartView->setRenderHint(QPainter::Antialiasing);
    H2_chartView->setVisible(false);

    L2_chartView = new QChartView(sensor2chart.lightlux_chart,this);
    sensor2chart.temperature_chart = L2_chartView->chart();
    L2_chartView->setRubberBand(QChartView::NoRubberBand);
    L2_chartView->setRenderHint(QPainter::Antialiasing);
    L2_chartView->setVisible(false);


    T3_chartView = new QChartView(sensor3chart.temperature_chart,this);     //画布
    sensor3chart.temperature_chart = T3_chartView->chart();                 //画笔
    T3_chartView->setRubberBand(QChartView::NoRubberBand);                  //矩形缩放
    T3_chartView->setRenderHint(QPainter::Antialiasing);                    //设置抗锯齿
    T3_chartView->setVisible(false);

    H3_chartView = new QChartView(sensor3chart.humidity_chart,this);
    sensor1chart.temperature_chart = H3_chartView->chart();
    H3_chartView->setRubberBand(QChartView::NoRubberBand);
    H3_chartView->setRenderHint(QPainter::Antialiasing);
    H3_chartView->setVisible(false);

    L3_chartView = new QChartView(sensor3chart.lightlux_chart,this);
    sensor3chart.temperature_chart = L3_chartView->chart();
    L3_chartView->setRubberBand(QChartView::NoRubberBand);
    L3_chartView->setRenderHint(QPainter::Antialiasing);
    L3_chartView->setVisible(false);

}

//数据图定时器更新函数
void window2::chartUpdate()
{
    chartUpdate_Update(&sensor1chart,&sensor1);

    chartUpdate_Update(&sensor2chart,&sensor2);

    chartUpdate_Update(&sensor3chart,&sensor3);

}

//数据图定时器更新函数(子函数)
void window2::chartUpdate_Update(basechart *sensorchart_temp,sensordata *sensordata_temp)
{
    sensorchart_temp->temperature_chart_update(sensordata_temp->temperature);
    sensorchart_temp->humidity_chart_update(sensordata_temp->humidity);
    sensorchart_temp->lightlux_chart_update(sensordata_temp->lightlux);
}


void window2::on_chooseBT_clicked()
{
    if(ui->chartGL->count())    //每次重置显示框里的图表
    {
        pWidget = ui->chartGL->itemAt(0)->widget();     //循环每次取第一个控件，依次删除下去
        pWidget->setParent(NULL);
        ui->chartGL->removeWidget(pWidget);
        m_chartView->setVisible(false);
    }
    int temp1 = 0;
    int temp2 = 0;
    temp1 = ui->sensorCB->currentIndex();
    temp2 = ui->indexCB->currentIndex();
    switch (temp1) {
        case 0:
            switch (temp2) {
                case 0:
                    m_chartView = T1_chartView;
                    break;
                case 1:
                    m_chartView = H1_chartView;
                    break;
                case 2:
                    m_chartView = L1_chartView;
                    break;
            }
            break;
        case 1:
            switch (temp2) {
                case 0:
                    m_chartView = T2_chartView;
                    break;
                case 1:
                    m_chartView = H2_chartView;
                    break;
                case 2:
                    m_chartView = L2_chartView;
                    break;
            }
            break;
        case 2:
            switch (temp2) {
                case 0:
                    m_chartView = T3_chartView;
                    break;
                case 1:
                    m_chartView = H3_chartView;
                    break;
                case 2:
                    m_chartView = L3_chartView;
                    break;
            }
            break;
    }
    ui->chartGL->addWidget(m_chartView);
    m_chartView->setVisible(true);
}
