#include "basealarm.h"

basealarm::basealarm()
{

}

void basealarm::alarmInit(int rank)
{
    this->rank = rank;
    date = QDate::currentDate();
    time = QTime::currentTime();

    ui_alarm = new QTableWidget();
    ui_alarm->setRowCount(1);   //
    ui_alarm->setColumnCount(4);
    ui_alarm->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置为不可编辑
    ui_alarm->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui_alarm->verticalHeader()->setVisible(false);                 //设置行列头隐藏
    ui_alarm->horizontalHeader()->setVisible(false);
    ui_alarm->setFrameStyle(QFrame::NoFrame);

    table00 = new QTableWidgetItem;
    table00->setText(QStringLiteral("序号"));
    table01 = new QTableWidgetItem;
    table01->setText(QStringLiteral("时间"));
    table02 = new QTableWidgetItem;
    table02->setText(QStringLiteral("异常类型"));
    table03 = new QTableWidgetItem;
    table03->setText(QStringLiteral("异常修正"));

    ui_alarm->setItem(0,0,table00);
    ui_alarm->setItem(0,1,table01);
    ui_alarm->setItem(0,2,table02);
    ui_alarm->setItem(0,3,table03);



    ui_alarm->setVisible(false);

}

void basealarm::alarm_set_limits(int temperatureLower,
                                 int temperatureUpper,
                                 int humidityLower,
                                 int humidityUpper,
                                 int lightluxLower,
                                 int lightluxUpper)
{
    this->temperatureLower = temperatureLower;
    this->temperatureUpper = temperatureUpper;
    this->humidityLower = humidityLower;
    this->humidityUpper = humidityUpper;
    this->lightluxLower = lightluxLower;
    this->lightluxUpper = lightluxUpper;
}

void basealarm::alarm_update(int temperature,int humidity,int lightlux)
{
//    qDebug() << temperatureLower << temperatureUpper;

    QDate datetemp = QDate::currentDate();
    time = QTime::currentTime();

    int curRow = ui_alarm->rowCount();

    QTableWidgetItem *item0 = new QTableWidgetItem;
    QTableWidgetItem *item1 = new QTableWidgetItem;
    QTableWidgetItem *item2 = new QTableWidgetItem;
    QTableWidgetItem *item3 = new QTableWidgetItem;

    QTableWidgetItem *item4 = new QTableWidgetItem;
    QTableWidgetItem *item5 = new QTableWidgetItem;
    QTableWidgetItem *item6 = new QTableWidgetItem;
    QTableWidgetItem *item7 = new QTableWidgetItem;

    QTableWidgetItem *item8 = new QTableWidgetItem;
    QTableWidgetItem *item9 = new QTableWidgetItem;
    QTableWidgetItem *item10 = new QTableWidgetItem;
    QTableWidgetItem *item11 = new QTableWidgetItem;


    item0->setText(QString::number(curRow));
    item4->setText(QString::number(curRow));
    item8->setText(QString::number(curRow));
    item1->setText(time.toString());
    item5->setText(time.toString());
    item9->setText(time.toString());

    alarm_compare(temperature,humidity,lightlux);

    if(curRow <= 28800 && datetemp == date)
    {
        curRow = ui_alarm->rowCount();
        if(tFlag)
        {
            ui_alarm->insertRow(curRow);
            item0->setText(QString::number(curRow));
            item2->setText(tType);
            item3->setText(QString::number(tCorrect));
            ui_alarm->setItem(curRow, 0, item0);
            ui_alarm->setItem(curRow, 1, item1);
//            qDebug() << curRow;
            ui_alarm->setItem(curRow, 2, item2);
            ui_alarm->setItem(curRow, 3, item3);
            tFlag = false;
            curRow = curRow + 1;
        }
        if(hFlag)
        {
            ui_alarm->insertRow(curRow);
            item4->setText(QString::number(curRow));
            item6->setText(hType);
            item7->setText(QString::number(hCorrect));
            ui_alarm->setItem(curRow, 0, item4);
            ui_alarm->setItem(curRow, 1, item5);
//            qDebug() << curRow;
            ui_alarm->setItem(curRow, 2, item6);
            ui_alarm->setItem(curRow, 3, item7);
            hFlag = false;
            curRow = curRow + 1;
        }
        if(lFlag)
        {
            ui_alarm->insertRow(curRow);
            item8->setText(QString::number(curRow));
            item10->setText(lType);
            item11->setText(QString::number(lCorrect));
            ui_alarm->setItem(curRow, 0, item8);
            ui_alarm->setItem(curRow, 1, item9);
//            qDebug() << curRow;
            ui_alarm->setItem(curRow, 2, item10);
            ui_alarm->setItem(curRow, 3, item11);
            lFlag = false;
            curRow = curRow + 1;
        }
    }else{
        delete ui_alarm;
        alarmInit(this->rank);
    }

}

void basealarm::alarm_compare(int temperature,int humidity,int lightlux)
{
    if(temperature >= 0 && temperature <= 60)
    {
        if(temperature >= this->temperatureLower && temperature <= this->temperatureUpper)
        {
            this->tFlag = false;
        }else{
            this->tFlag = true;
            if(temperature < this->temperatureLower)
            {
                tType = "节点温度过低";
                tCorrect = temperature - temperatureLower;
            }else{
                tType = "节点温度过高";
                tCorrect = temperature - temperatureUpper;
            }
        }
    }

    if(humidity >= 0 && humidity <= 100)
    {
        if(humidity >= this->humidityLower && humidity <= this->humidityUpper)
        {
            this->hFlag = false;
        }else{
            this->hFlag = true;
            if(humidity < this->humidityLower)
            {
                hType = "节点湿度过低";
                hCorrect = humidity - humidityLower;
            }else{
                hType = "节点湿度过高";
                hCorrect = humidity - humidityUpper;
            }
        }
    }

    if(lightlux >= 0 && lightlux <= 6000)
    {
        if(lightlux >= this->lightluxLower && lightlux <= this->lightluxUpper)
        {
            this->lFlag = false;
        }else{
            this->lFlag = true;
            if(lightlux < this->lightluxLower)
            {
                lType = "节点光照过低";
                tCorrect = lightlux - lightluxLower;
            }else{
                lType = "节点光照过高";
                lCorrect = lightlux - lightluxUpper;
            }
        }
    }
}
