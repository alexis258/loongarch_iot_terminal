#include "basechart.h"

basechart::basechart()
{

}

basechart::basechart(int rank,QDate date)
{
    this->rank = rank;
    this->date = date;
}


//初始化类的三张图
void basechart::chartInit(int rank,QDate date)
{
    this->rank = rank;
    this->date = date;
    xMin = QDateTime::currentDateTime();
    xMax = xMin.addSecs(90);
    temperature_chartInit();
    humidity_chartInit();
    lightlux_chartInit();
}

//初始化温度图
void basechart::temperature_chartInit()
{
    temperature_chart = new QChart();

    //设置x轴
    temperature_axisX = new QDateTimeAxis;          //坐标类型
    temperature_axisY = new QValueAxis;

    temperature_axisX->setFormat("hh:mm:ss");        //坐标轴下标的数字类型
    temperature_axisY->setLabelFormat("%d");


    temperature_axisX->setRange(xMin,xMax);            //坐标系区间
    temperature_axisY->setRange(0, 60);

    temperature_axisX->setGridLineVisible(true);    //是否显示网格
    temperature_axisY->setGridLineVisible(true);

    temperature_axisX->setTickCount(6+1);            //设置坐标轴区间格数
    temperature_axisY->setTickCount(6+1);

    temperature_axisX->setTitleText("时间");           //坐标轴名称
    temperature_axisY->setTitleText("温度");

    //设置图表
    temperature_chart->addAxis(temperature_axisX, Qt::AlignBottom);  //将x坐标轴加到chart上，居下
    temperature_chart->addAxis(temperature_axisY, Qt::AlignLeft);    //将y坐标轴加到chart上，居左
    QString settitle = date.toString("yyyy-MM-dd") + " 传感器 " + QString::number(this->rank) + " 温度曲线图";
    temperature_chart->setTitle(settitle);              //设置图表标题
    temperature_chart->legend()->hide();                 //设置图例不可见
    temperature_chart->legend()->setLayoutDirection(Qt::LeftToRight);
    temperature_chart->legend()->setAlignment(Qt::AlignLeft);

    //设置曲线
    temperature_series = new QSplineSeries();       //平滑曲线的集合
    temperature_series->setName(QString("temperature")); //设置曲线对应的名字，用于图例显示
    temperature_chart->addSeries(temperature_series);         //将曲线增入chart中
    temperature_series->attachAxis(temperature_axisX);          //将曲线与轴对应起来
    temperature_series->attachAxis(temperature_axisY);

}

//温度图更新函数
void basechart::temperature_chart_update(int temperature)
{
    QDateTime Min,Max;                  // 设置时间更新坐标轴范围
    if(flagt)                                    // 确保第一次从原点开始
    {
        flagt=false;
        Min = QDateTime::currentDateTime();
        Max = Min.addSecs(60);
        temperature_axisX->setRange(Min,Max);    // X轴位当前 时间
        temperature_series->append(Min.toMSecsSinceEpoch(),temperature);
    }

    QDateTime tmax = QDateTime::currentDateTime();
    QDateTime tmin = tmax.addSecs(qint64(-60));
    temperature_series->append(tmax.toMSecsSinceEpoch(),temperature);

    if(tmax > temperature_axisX->max())
    {
        temperature_axisX->setRange(tmin,tmax);
    }
}

//初始化湿度图
void basechart::humidity_chartInit()
{
    humidity_chart = new QChart();

    //设置x轴
    humidity_axisX = new QDateTimeAxis;          //坐标类型
    humidity_axisY = new QValueAxis;

    humidity_axisX->setFormat("hh:mm:ss");        //坐标轴下标的数字类型
    humidity_axisY->setLabelFormat("%d");

    humidity_axisX->setRange(xMin,xMax);            //坐标系区间
    humidity_axisY->setRange(0, 100);

    humidity_axisX->setGridLineVisible(true);    //是否显示网格
    humidity_axisY->setGridLineVisible(true);

    humidity_axisX->setTickCount(5+1);            //设置坐标轴区间格数
    humidity_axisY->setTickCount(6+1);

    humidity_axisX->setTitleText("时间");           //坐标轴名称
    humidity_axisY->setTitleText("湿度");

    //设置图表
    humidity_chart->addAxis(humidity_axisX, Qt::AlignBottom);  //将x坐标轴加到chart上，居下
    humidity_chart->addAxis(humidity_axisY, Qt::AlignLeft);    //将y坐标轴加到chart上，居左
    QString settitle = date.toString("yyyy-MM-dd") + " 传感器 " + QString::number(this->rank) + " 湿度曲线图";
    humidity_chart->setTitle(settitle);              //设置图表标题
    humidity_chart->legend()->hide();                 //设置图例不可见
    humidity_chart->legend()->setLayoutDirection(Qt::LeftToRight);
    humidity_chart->legend()->setAlignment(Qt::AlignLeft);

    //设置曲线
    humidity_series = new QSplineSeries();       //平滑曲线的集合
    humidity_series->setName(QString("humidity")); //设置曲线对应的名字，用于图例显示
    humidity_chart->addSeries(humidity_series);         //将曲线增入chart中
    humidity_series->attachAxis(humidity_axisX);          //将曲线与轴对应起来
    humidity_series->attachAxis(humidity_axisY);
}

//湿度图更新函数
void basechart::humidity_chart_update(int humidity)
{
    QDateTime Min,Max;                  // 设置时间更新坐标轴范围
    if(flagh)                                    // 确保第一次从原点开始
    {
        flagh=false;
        Min = QDateTime::currentDateTime();
        Max = Min.addSecs(60);
        humidity_axisX->setRange(Min,Max);    // X轴位当前 时间
        humidity_series->append(Min.toMSecsSinceEpoch(),humidity);
    }

    QDateTime tmax = QDateTime::currentDateTime();
    QDateTime tmin = tmax.addSecs(qint64(-60));
    humidity_series->append(tmax.toMSecsSinceEpoch(),humidity);

    if(tmax > humidity_axisX->max())
    {
        humidity_axisX->setRange(tmin,tmax);
    }
}

//初始化光照图
void basechart::lightlux_chartInit()
{
    lightlux_chart = new QChart();

    //设置x轴
    lightlux_axisX = new QDateTimeAxis;          //坐标类型
    lightlux_axisY = new QValueAxis;

    lightlux_axisX->setFormat("hh:mm:ss");        //坐标轴下标的数字类型
    lightlux_axisY->setLabelFormat("%d");

    lightlux_axisX->setRange(xMin,xMax);            //坐标系区间
    lightlux_axisY->setRange(0, 4000);

    lightlux_axisX->setGridLineVisible(true);    //是否显示网格
    lightlux_axisY->setGridLineVisible(true);

    lightlux_axisX->setTickCount(6+1);            //设置坐标轴区间格数
    lightlux_axisY->setTickCount(4+1);

    lightlux_axisX->setTitleText("时间");           //坐标轴名称
    lightlux_axisY->setTitleText("光照");

    //设置图表
    lightlux_chart->addAxis(lightlux_axisX, Qt::AlignBottom);  //将x坐标轴加到chart上，居下
    lightlux_chart->addAxis(lightlux_axisY, Qt::AlignLeft);    //将y坐标轴加到chart上，居左
    QString settitle = date.toString("yyyy-MM-dd") + " 传感器 " + QString::number(this->rank) + " 光照曲线图";
    lightlux_chart->setTitle(settitle);              //设置图表标题
    lightlux_chart->legend()->hide();                 //设置图例不可见
    lightlux_chart->legend()->setLayoutDirection(Qt::LeftToRight);
    lightlux_chart->legend()->setAlignment(Qt::AlignLeft);

    //设置曲线
    lightlux_series = new QSplineSeries();       //平滑曲线的集合
    lightlux_series->setName(QString("lightlux")); //设置曲线对应的名字，用于图例显示
    lightlux_chart->addSeries(lightlux_series);         //将曲线增入chart中
    lightlux_series->attachAxis(lightlux_axisX);          //将曲线与轴对应起来
    lightlux_series->attachAxis(lightlux_axisY);
}

//光照图更新函数
void basechart::lightlux_chart_update(int lightlux)
{
    QDateTime Min,Max;                  // 设置时间更新坐标轴范围
    if(flagl)                                    // 确保第一次从原点开始
    {
        flagl=false;
        Min = QDateTime::currentDateTime();
        Max = Min.addSecs(60);
        lightlux_axisX->setRange(Min,Max);    // X轴位当前 时间
        lightlux_series->append(Min.toMSecsSinceEpoch(),lightlux);
    }

    QDateTime tmax = QDateTime::currentDateTime();
    QDateTime tmin = tmax.addSecs(qint64(-60));
    lightlux_series->append(tmax.toMSecsSinceEpoch(),lightlux);

    if(tmax > lightlux_axisX->max())
    {
        lightlux_axisX->setRange(tmin,tmax);
    }
}


