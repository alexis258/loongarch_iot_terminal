#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.设置背景颜色，设置滚动标签
    this->setStyleSheet("background-color:rgb(199,237,204)");
    this->ui->rollLabel->setText(rollShowText);
    rollTimer = new QTimer(this);
    connect(rollTimer,&QTimer::timeout,this,&MainWindow::indexUpdate);
    rollTimer->start(300);

    //1.初始化日期标签，界面数据更新
    ui->dateTimeLabel->setText("欢迎使用系统！");
    dateTimer = new QTimer(this);
    connect(dateTimer,&QTimer::timeout,this,&MainWindow::timerUpdate);
    connect(dateTimer,&QTimer::timeout,this,&MainWindow::CB1TimerUpdate);
    dateTimer->start(1000);


    //2.更新所有组合框时间
    dateCBTimerUpdate();
    updateDateTimer = new QTimer(this);
    connect(updateDateTimer,&QTimer::timeout,this,&MainWindow::dateCBTimerUpdate);
    updateDateTimer->start(43200000);   //半天切换

    //2.更新图表    2,3,4,5共用定时器
    sensor1chart.chartInit(1,currentDate);
    sensor2chart.chartInit(2,currentDate);
    sensor3chart.chartInit(3,currentDate);
    ChartInit();
    chartTimer = new QTimer(this);
    connect(chartTimer,&QTimer::timeout,this,&MainWindow::chartUpdate);
    chartTimer->start(3000);

    //3.更新表格
    sensor1table.tableInit(1);
    sensor2table.tableInit(2);
    sensor3table.tableInit(3);
//    tableTimer = new QTimer(this);
    connect(chartTimer,&QTimer::timeout,this,&MainWindow::tableUpdate);
//    tableTimer->start(3000);

    //4.更新报警
    sensor1alarm.alarmInit(1);
    sensor2alarm.alarmInit(2);
    sensor3alarm.alarmInit(3);
//    alarmTimer = new QTimer(this);
    connect(chartTimer,&QTimer::timeout,this,&MainWindow::alarmUpdate);
//    alarmTimer->start(3000);

    //5.节点网络设置
    topoTimer = new QTimer(this);
    connect(topoTimer,&QTimer::timeout,this,&MainWindow::topoUpdate);
    topoTimer->start(1000);

    //7.数据库
//    CreateDatabaseFunc();
//    CreateTableFunc();
    sensor1.rank = 1;
    sensor2.rank = 2;
    sensor3.rank = 3;
    sensor4.rank = 4;

    //7.串口
    serialPort = new QSerialPort(this);
    serialTimer = new QTimer(this);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(serialPortReadyRead()));/*手动连接槽函数*/
    connect(serialTimer,&QTimer::timeout,this,&MainWindow::serialTimerUpdate);

    messageTimer = new QTimer(this);
    connect(messageTimer,&QTimer::timeout,this,&MainWindow::message1Update);    //处理串口数据
    connect(messageTimer,&QTimer::timeout,this,&MainWindow::message2Update);
    connect(messageTimer,&QTimer::timeout,this,&MainWindow::message3Update);
    messageTimer->start(1000);

    //6.mqtt服务器
    ui->LE1->setText(host_aliyun);
    ui->LE2->setText(username_aliyun);
    ui->LE3->setText(password_aliyun);
    ui->LE4->setText(clientid_aliyun);
    ui->LE5->setText(topic_node1_aliyun);
    ui->LE6->setText(topic_node1_aliyun);

    m_client = new QMqttClient(this);
    m_client->setHostname(ui->LE1->text());
    m_client->setUsername(ui->LE2->text());
    m_client->setPassword(ui->LE3->text());
    m_client->setClientId(ui->LE4->text());
    m_client->setPort(ui->spinBox->value());
    m_client->setKeepAlive(30);

    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" Received Topic: ")
                    + topic.name()
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n');
        ui->TB1->insertPlainText(content);
    });

    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        ui->TB1->insertPlainText(content);
    });

    connect(ui->LE1, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);
    connect(ui->LE2, &QLineEdit::textChanged, m_client, &QMqttClient::setUsername);
    connect(ui->LE3, &QLineEdit::textChanged, m_client, &QMqttClient::setPassword);
    connect(ui->LE4, &QLineEdit::textChanged, m_client, &QMqttClient::setClientId);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::setClientPort);
    updateLogStateChange();

    mqttTimer = new QTimer(this);       //上报阿里云定时器
    connect(mqttTimer,&QTimer::timeout,this,&MainWindow::mqttTimerUpdate);

}

MainWindow::~MainWindow()
{
    delete ui;
}


////创建数据库
//void MainWindow::CreateDatabaseFunc()
//{
//    //数据库
//    sqldb = QSqlDatabase::addDatabase("QSQLITE","OLD_DB");
//    sqldb.setDatabaseName("loongarch_iot.db");
//    if(sqldb.open()==true)
//    {
//        QMessageBox::information(0,"true","database connection succeeded",QMessageBox::Ok);
//    }
//    else
//    {
//        QMessageBox::critical(0,"false","database connection failed",QMessageBox::Ok);
//    }

//}

////创建数据表
//void MainWindow::CreateTableFunc()
//{
//    //数据表1
//    QSqlQuery sqlquery(sqldb);
//    QString strsql = QString("create table sensor1db("
//                             "id int primary key not null,"
//                             "datetime text not null,"
//                             "date date not null,"
//                             "time time not null,"
//                             "temperature float not null,"
//                             "humidity float not null,"
//                             "lightlux int not null,"
//                             "ultrasonic float not null)");
//    if(sqlquery.exec(strsql)==true)
//    {
//        QMessageBox::information(0,"true","sensor1 table creation succeeded!",QMessageBox::Ok);
//    }
//    else
//    {
//        qDebug() << "Error:Fail to create table!" << sqlquery.lastError() << endl;
//    }


//1.日期标签定时器函数
void MainWindow::timerUpdate(void)
{
    dateTime = QDateTime::currentDateTime();
    dateStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    this->ui->dateTimeLabel->setText(dateStr);
//    sensor1.temperature = qrand()% 50;
}

//1.滚动标签定时器函数
void MainWindow::indexUpdate(void)
{
    QString str = "";
    static int nPos = 0;

    if (nPos > rollShowText.length())
    {
        nPos = 0;
    }

    str += rollShowText.mid(nPos) + rollShowText.left(nPos);
    this->ui->rollLabel->setText(str);

    if(nPos <= 21)
    {
        nPos++;
    }
    else
    {
        nPos += 2;
    }

}

//1.时间组合框定时器更新
void MainWindow::dateCBTimerUpdate(void)
{
    currentDate = QDate::currentDate();
    dateToday = currentDate.toString("yyyy/MM/dd");
    dateYesterday = currentDate.addDays(-1).toString("yyyy/MM/dd");
    dateBeforeday = currentDate.addDays(-2).toString("yyyy/MM/dd");

    ui->dateCB1->clear();
    ui->dateCB1->addItem(dateToday);
    ui->dateCB1->addItem(dateYesterday);
    ui->dateCB1->addItem(dateBeforeday);

    ui->dateCB2->clear();
    ui->dateCB2->addItem(dateToday);
    ui->dateCB2->addItem(dateYesterday);
    ui->dateCB2->addItem(dateBeforeday);

    ui->dateCB3->clear();
    ui->dateCB3->addItem(dateToday);
    ui->dateCB3->addItem(dateYesterday);
    ui->dateCB3->addItem(dateBeforeday);
}


//1.数据显示更新定时器函数
void MainWindow::CB1TimerUpdate(void)
{
    int rankCB1 = 0;
    rankCB1 = ui->nodeChooseCB1->currentIndex()+1;
    switch (rankCB1) {
        case 1:
            CB1TimerUpdate_Update(sensor1);
           break;
        case 2:
            CB1TimerUpdate_Update(sensor2);
           break;
        case 3:
            CB1TimerUpdate_Update(sensor3);
           break;
    }
    mqttTimer->start(50);
}

//1.数据显示更新定时器函数（子函数）
void MainWindow::CB1TimerUpdate_Update(sensordata sensordata_temp)
{
    strT1 = QString::number(sensordata_temp.temperature, 10);
    strH1 = QString::number(sensordata_temp.humidity, 10);
    strL1 = QString::number(sensordata_temp.lightlux, 10);
    strB1 = QString::number(sensordata_temp.bat, 10);
    if(sensordata_temp.state == 1)
    {
        ui->stateL->setText("已连接");
        ui->stateL->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
    }else{
        ui->stateL->setText("未连接");
        ui->stateL->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
    }
    ui->temL->setText(strT1);
    ui->humL->setText(strH1);
    ui->ligL->setText(strL1);
    ui->batL->setText(strB1);

}

//2.显示图表按钮，根据组合栏内容显示不同图表
void MainWindow::on_showChartPB_clicked()
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
    temp1 = ui->sensorCB1->currentIndex();
    temp2 = ui->indexCB1->currentIndex();
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

//2.数据图表函数
void MainWindow::ChartInit()
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

//2.数据图定时器更新函数
void MainWindow::chartUpdate()
{
    chartUpdate_Update(&sensor1chart,&sensor1);

    chartUpdate_Update(&sensor2chart,&sensor2);

    chartUpdate_Update(&sensor3chart,&sensor3);

}

//2.数据图定时器更新函数(子函数)
void MainWindow::chartUpdate_Update(basechart *sensorchart_temp,sensordata *sensordata_temp)
{
    sensorchart_temp->temperature_chart_update(sensordata_temp->temperature);
    sensorchart_temp->humidity_chart_update(sensordata_temp->humidity);
    sensorchart_temp->lightlux_chart_update(sensordata_temp->lightlux);
}

//3.数据图定时器更新函数
void MainWindow::tableUpdate()
{
    sensor1table.table_update(sensor1.temperature,sensor1.humidity,sensor1.lightlux);
    sensor2table.table_update(sensor2.temperature,sensor2.humidity,sensor2.lightlux);
    sensor3table.table_update(sensor3.temperature,sensor3.humidity,sensor3.lightlux);
}

//3.显示表格按钮，根据组合栏内容显示不同图表
void MainWindow::on_showTablePB_clicked()
{
    if(ui->tableGL->count())    //每次重置显示框里的图表
    {
        tWidget = ui->tableGL->itemAt(0)->widget();     //循环每次取第一个控件，依次删除下去
        tWidget->setParent(NULL);
        ui->tableGL->removeWidget(tWidget);
        sensor1table.ui_table->setVisible(false);
        sensor2table.ui_table->setVisible(false);
        sensor3table.ui_table->setVisible(false);
    }
    int temp1 = 0;
    temp1 = ui->sensorCB2->currentIndex();
    switch (temp1) {
        case 0:
            ui->tableGL->addWidget(sensor1table.ui_table);
            sensor1table.ui_table->setVisible(true);
            break;
        case 1:
            ui->tableGL->addWidget(sensor2table.ui_table);
            sensor2table.ui_table->setVisible(true);
            break;
        case 2:
            ui->tableGL->addWidget(sensor3table.ui_table);
            sensor3table.ui_table->setVisible(true);
            break;
    }

}

//3.导出数表格据成txt
void MainWindow::on_exportPB_clicked()
{
    QTableWidget *table;
    //导出文件名
    int temp = ui->sensorCB2->currentIndex() + 1;
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    QString sensor = QString::number(ui->sensorCB2->currentIndex()+1, 10);
    QString title = date + "-sensor" + sensor + "-data";
    table = sensor1table.ui_table;
    switch (temp) {
        case 1:
            table = sensor1table.ui_table;
            break;
        case 2:
            table = sensor2table.ui_table;
            break;
        case 3:
            table = sensor3table.ui_table;
            break;
    }

    //设置文件保存文件名及需要保存的图表，保存到程序当前目录下
    exportapi::exportTxt(title,table);

}

//3.表格函数
void MainWindow::TableInit()
{
    m_tableView = new QTableView(this);

    m_tableView->horizontalHeader()->setVisible(true); // 显示水平表头
    m_tableView->verticalHeader()->setVisible(true);   // 显示垂直表头
}

//4.报警定时器更新函数
void MainWindow::alarmUpdate()
{
    sensor1alarm.alarm_update(sensor1.temperature,sensor1.humidity,sensor1.lightlux);
    sensor2alarm.alarm_update(sensor2.temperature,sensor2.humidity,sensor2.lightlux);
    sensor3alarm.alarm_update(sensor3.temperature,sensor3.humidity,sensor3.lightlux);
}

//4.导出数表格据成txt
void MainWindow::on_exportPB2_clicked()
{
    QTableWidget *table;
    //导出文件名
    int temp = ui->sensorCB3->currentIndex() + 1;
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    QString sensor = QString::number(ui->sensorCB3->currentIndex()+1, 10);
    QString title = date + "-sensor" + sensor + "-alarm";
    table = sensor1alarm.ui_alarm;
    switch (temp) {
        case 1:
            table = sensor1alarm.ui_alarm;
            break;
        case 2:
            table = sensor2alarm.ui_alarm;
            break;
        case 3:
            table = sensor3alarm.ui_alarm;
            break;
    }

    //设置文件保存文件名及需要保存的图表，保存到程序当前目录下
    exportapi::exportTxt(title,table);

}

//4.显示报警按钮，根据组合栏内容显示不同图表
void MainWindow::on_showAlarmPB_clicked()
{
    if(ui->alarmGL->count())    //每次重置显示框里的图表
    {
        aWidget = ui->alarmGL->itemAt(0)->widget();     //循环每次取第一个控件，依次删除下去
        aWidget->setParent(NULL);
        ui->alarmGL->removeWidget(aWidget);
        sensor1alarm.ui_alarm->setVisible(false);
        sensor2alarm.ui_alarm->setVisible(false);
        sensor3alarm.ui_alarm->setVisible(false);
    }
    int temp1 = 0;
    temp1 = ui->sensorCB3->currentIndex();
    switch (temp1) {
        case 0:
            ui->alarmGL->addWidget(sensor1alarm.ui_alarm);
            sensor1alarm.ui_alarm->setVisible(true);
            break;
        case 1:
            ui->alarmGL->addWidget(sensor2alarm.ui_alarm);
            sensor2alarm.ui_alarm->setVisible(true);
            break;
        case 2:
            ui->alarmGL->addWidget(sensor3alarm.ui_alarm);
            sensor3alarm.ui_alarm->setVisible(true);
            break;
    }
}

//4.报警函数
void MainWindow::AlarmInit()
{
    a_tableView = new QTableView(this);

    a_tableView->horizontalHeader()->setVisible(true); // 显示水平表头
    a_tableView->verticalHeader()->setVisible(true);   // 显示垂直表头
}

//5.节点网络初始化
void MainWindow::topoUpdate()
{
    topoCurRow = ui->topoTable->rowCount();

//    qDebug()<< coorstate <<" "<<coorStack;
    //协调器节点显示
    if(coorstate == 1)
    {
        ui->coorL->setText("已连接");
        ui->coorL->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
        if(coorstate != coor_temp)
        {
            ui->messageTB->insertPlainText("协调器上线！\n");
            ui->topoTable->insertRow(topoCurRow);
            QTableWidgetItem *topo0 = new QTableWidgetItem;
            QTableWidgetItem *topo1 = new QTableWidgetItem;
            QTableWidgetItem *topo2 = new QTableWidgetItem;
            topo0->setText("协调器");
            topo1->setText(dateTime.toString("hh:mm:ss"));
            topo2->setText("上线");
            ui->topoTable->setItem(topoCurRow, 0, topo0);
            ui->topoTable->setItem(topoCurRow, 1, topo1);
            ui->topoTable->setItem(topoCurRow, 2, topo2);
            coor_temp = coorstate;
        }
        coorStack = 0;
    }
    else
    {
        coorStack++;
        if(coorStack == 2)
        {
            ui->coorL->setText("未连接");
            ui->coorL->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
            if(coorstate != coor_temp)
            {
                ui->messageTB->insertPlainText("协调器掉线！\n");
                ui->topoTable->insertRow(topoCurRow);
                QTableWidgetItem *topo0 = new QTableWidgetItem;
                QTableWidgetItem *topo1 = new QTableWidgetItem;
                QTableWidgetItem *topo2 = new QTableWidgetItem;
                topo0->setText("协调器");
                topo1->setText(dateTime.toString("hh:mm:ss"));
                topo2->setText("掉线");
                ui->topoTable->setItem(topoCurRow, 0, topo0);
                ui->topoTable->setItem(topoCurRow, 1, topo1);
                ui->topoTable->setItem(topoCurRow, 2, topo2);
                coor_temp = coorstate;
            }
            coorStack = 0;
        }
    }

    //节点1上下线
    topoUpdate_Update(&sensor1, &enda_temp, ui->endaL, topoCurRow);

    topoUpdate_Update(&sensor2, &endb_temp, ui->endbL, topoCurRow);

    topoUpdate_Update(&sensor3, &endc_temp, ui->endcL, topoCurRow);


    coorstate = 0;

}

//5.节点网络初始化(子函数)
void MainWindow::topoUpdate_Update(sensordata *sensor_temp,int *temp,QLabel *endL,int topoCurRow)
{
    topoCurRow = ui->topoTable->rowCount();

    if(sensor_temp->state == 1)
    {
        endL->setText("已连接");
        endL->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
        if(sensor_temp->state != *temp)
        {
            ui->messageTB->insertPlainText("节点"+QString::number(sensor_temp->rank,10)+"上线！\n");
            ui->topoTable->insertRow(topoCurRow);
            QTableWidgetItem *topo0 = new QTableWidgetItem;
            QTableWidgetItem *topo1 = new QTableWidgetItem;
            QTableWidgetItem *topo2 = new QTableWidgetItem;
            topo0->setText("节点"+QString::number(sensor_temp->rank,10));
            topo1->setText(dateTime.toString("hh:mm:ss"));
            topo2->setText("上线");
            ui->topoTable->setItem(topoCurRow, 0, topo0);
            ui->topoTable->setItem(topoCurRow, 1, topo1);
            ui->topoTable->setItem(topoCurRow, 2, topo2);
            *temp = sensor_temp->state;
        }
        sensor_temp->stateStack = 0;
    }
    else
    {
        sensor_temp->stateStack++;
        if(sensor_temp->stateStack == 3)
        {
            endL->setText("未连接");
            endL->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
            if(sensor_temp->state != *temp)
            {
                ui->messageTB->insertPlainText("节点"+QString::number(sensor_temp->rank,10)+"掉线！\n");
                ui->topoTable->insertRow(topoCurRow);
                QTableWidgetItem *topo0 = new QTableWidgetItem;
                QTableWidgetItem *topo1 = new QTableWidgetItem;
                QTableWidgetItem *topo2 = new QTableWidgetItem;
                topo0->setText("节点"+QString::number(sensor_temp->rank,10));
                topo1->setText(dateTime.toString("hh:mm:ss"));
                topo2->setText("掉线");
                ui->topoTable->setItem(topoCurRow, 0, topo0);
                ui->topoTable->setItem(topoCurRow, 1, topo1);
                ui->topoTable->setItem(topoCurRow, 2, topo2);
                *temp = sensor_temp->state;
            }
            sensor_temp->stateStack = 0;
        }
    }
}

//5.节点上下线通知

//6.阿里云自动上报
void MainWindow::mqttTimerUpdate()
{
//    sensor1.get_state();
//    sensor2.get_state();
//    sensor3.get_state();

    if(m_client->state() == QMqttClient::Connected)
    {
        QString strPublish;             //需要发送的字符串
        QJsonObject jsonPublish;        //需要发送的Json
        QJsonObject jsonPublishParams;

        jsonPublish.insert("method",JSON_METHOD);

        jsonPublishParams.insert("temperature_node1",sensor1.temperature);
        jsonPublishParams.insert("humidity_node1",sensor1.humidity);
        jsonPublishParams.insert("lightLux_node1",sensor1.lightlux);
        jsonPublishParams.insert("state_node1",sensor1.state);
        jsonPublishParams.insert("battery_node1",sensor1.bat);

        jsonPublishParams.insert("temperature_node2",sensor2.temperature);
        jsonPublishParams.insert("humidity_node2",sensor2.humidity);
        jsonPublishParams.insert("lightLux_node2",sensor2.lightlux);
        jsonPublishParams.insert("state_node2",sensor2.state);
        jsonPublishParams.insert("battery_node2",sensor2.bat);

        jsonPublishParams.insert("temperature_node3",sensor3.temperature);
        jsonPublishParams.insert("humidity_node3",sensor3.humidity);
        jsonPublishParams.insert("lightLux_node3",sensor3.lightlux);
        jsonPublishParams.insert("state_node3",sensor3.state);
        jsonPublishParams.insert("battery_node3",sensor3.bat);

        jsonPublish.insert("params",jsonPublishParams);
        jsonPublish.insert("version","1.0.0");

        strPublish = QString(QJsonDocument(jsonPublish).toJson());

        if (m_client->publish(post_sensor1_topic_aliyun, strPublish.toUtf8()) == -1)
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    }

}

//6.设置阿里云登录数据
void MainWindow::on_buttonSetting_clicked()
{
    ui->LE1->setText(host_aliyun);
    ui->LE2->setText(username_aliyun);
    ui->LE3->setText(password_aliyun);
    ui->LE4->setText(clientid_aliyun);
    ui->LE5->setText(topic_node1_aliyun);
    ui->LE6->setText(topic_node1_aliyun);
}

//6.mqtt服务器连接按钮
void MainWindow::on_buttonConnect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected) {
        ui->LE1->setEnabled(false);
        ui->LE2->setEnabled(false);
        ui->LE3->setEnabled(false);
        ui->LE4->setEnabled(false);
        ui->spinBox->setEnabled(false);
        ui->buttonConnect->setText(tr("Disconnect"));
        m_client->connectToHost();
    } else {
        ui->LE1->setEnabled(true);
        ui->LE2->setEnabled(true);
        ui->LE3->setEnabled(true);
        ui->LE4->setEnabled(true);
        ui->spinBox->setEnabled(true);
        ui->buttonConnect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }
}

//6.更新mqtt服务器连接状态，并在端口中输出
void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    ui->TB3->insertPlainText(content);
}

//6.断开mqtt连接
void MainWindow::brokerDisconnected()
{
    ui->LE3->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->buttonConnect->setText(tr("Connect"));
}

//6.设置mqtt服务器端口
void MainWindow::setClientPort(int p)
{
    m_client->setPort(p);
}

//6.订阅
void MainWindow::on_buttonSubscribe_clicked()
{
    auto subscription = m_client->subscribe(ui->LE5->text());
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
}

//6.取消订阅
void MainWindow::on_buttonUnsubscribe_clicked()
{

}

//6.清空订阅消息窗口
void MainWindow::on_buttonClear_clicked()
{
    ui->TB1->clear();
}

//6.发布消息
void MainWindow::on_buttonPublish_clicked()
{
    if (m_client->publish(ui->LE6->text(), ui->TB2->toPlainText().toUtf8()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}

//7.插入按钮
void MainWindow::on_insertPB_clicked()
{
    int id1 = ui->idLE->text().toInt();
    QString date1 = ui->dateLE->text();
    QString time1 = ui->timeLE->text();
    float temperature1 = ui->temperatureLE->text().toFloat();
    float humidity1 = ui->humidityLE->text().toFloat();
    int lightlux1 = ui->lightluxLE->text().toInt();

    //创建sql语句
    QSqlQuery sqlquery;
    QString insertsql = QString("insert into sensor1db(id,date,time,temperature,humidity,lightlux)"
                                     "values(:id,:date,:time,:temperature,:humidity,:lightlux)");
    sqlquery.prepare(insertsql);
    sqlquery.addBindValue(id1);
    sqlquery.addBindValue(date1);
    sqlquery.addBindValue(time1);
    sqlquery.addBindValue(temperature1);
    sqlquery.addBindValue(humidity1);
    sqlquery.addBindValue(lightlux1);

    //执行sql语句
    if(sqlquery.exec()==true)
    {
        qDebug() << "Insert success!" << endl;
    }
    else
    {
        qDebug() << "Error:Fail to create table" << sqlquery.lastError() << endl;
    }
}

//7.删除按钮
void MainWindow::on_deletePB_clicked()
{
    int id1 = ui->idLE->text().toInt();

    //创建sql语句
    QSqlQuery sqlquery;
    QString deletesql = QString("DELETE FROM sensor1db WHERE id = ?");
    sqlquery.prepare(deletesql);
    sqlquery.addBindValue(id1);

    //执行sql语句
    if(sqlquery.exec()==true)
    {
        qDebug() << "Delete record success!" << endl;
    }
    else
    {
        qDebug() << "Error:Fail to delete record!" << sqlquery.lastError() << endl;
    }
}

//7.查询按钮
void MainWindow::on_checkPB_clicked()
{
    ui->textEdit->clear();
    QSqlQuery sqlquery("select * from sensor1db");
    while(sqlquery.next())
    {
        QString id = sqlquery.value("id").toString();
        QString date = sqlquery.value("date").toString();
        QString time = sqlquery.value("time").toString();
        QString temperature = sqlquery.value("temperature").toString();
        QString humidity = sqlquery.value("humidity").toString();
        QString lightlux = sqlquery.value("lightlux").toString();
        ui->textEdit->insertPlainText(id);
        ui->textEdit->insertPlainText(" ");
        ui->textEdit->insertPlainText(date);
        ui->textEdit->insertPlainText(" ");
        ui->textEdit->insertPlainText(time);
        ui->textEdit->insertPlainText(" ");
        ui->textEdit->insertPlainText(temperature);
        ui->textEdit->insertPlainText(" ");
        ui->textEdit->insertPlainText(humidity);
        ui->textEdit->insertPlainText(" ");
        ui->textEdit->insertPlainText(lightlux);
        ui->textEdit->insertPlainText("\n");

    }

}

//7.获取按钮
void MainWindow::on_getTimePB_clicked()
{
    QDate datenow = QDate::currentDate();
    QString datenowstr = datenow.toString("yyyy-MM-dd");
    ui->dateLE->setText(datenowstr);

    QTime timenow = QTime::currentTime();
    QString timenowstr = timenow.toString("hh:mm:ss");
    ui->timeLE->setText(timenowstr);
}

//7.设置主题
void MainWindow::on_settopicPB_clicked()
{
    ui->topicLE->setText(POST_TOPIC_ALIYUN);
}

//7.数据发布
void MainWindow::on_publishPB_clicked()
{
    QString strPublish;
    QJsonObject jsonPublish;
    QJsonObject jsonPublishParams;

    jsonPublish.insert("method",JSON_METHOD);
    jsonPublishParams.insert("temperature_node1",ui->temperatureLE->text().toFloat());
    jsonPublishParams.insert("humidity_node1",ui->humidityLE->text().toFloat());
    jsonPublishParams.insert("lightLux_node1",ui->lightluxLE->text().toInt());
    jsonPublish.insert("params",jsonPublishParams);
    jsonPublish.insert("version","1.0.0");

    strPublish = QString(QJsonDocument(jsonPublish).toJson());

    if (m_client->publish(ui->topicLE->text(), strPublish.toUtf8()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
}

void MainWindow::on_connectdbPB_clicked()
{

}

//7.启动定时器，读取50ms内串口传输的数据
void MainWindow::serialPortReadyRead()
{
    serialTimer->start(100);
    serialBuf.append(serialPort->readAll());
}

//7.串口传输槽函数，当串口有缓存数据时，调用
void MainWindow::serialTimerUpdate()
{
    serialTimer->stop();


    if(serialBuf.length()!=0)
    {
        m_message = serialBuf;

        QString str = m_message;
        coorstate = 1;

        ui->debugTB->clear();

        ui->debugTB->append(str);
    }

    serialBuf.clear();
}

//线程1处理
void MainWindow::message1Update()
{
    ui->debugTB->clear();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(m_message, &err);   //字符串转Json
//    if(err.error != QJsonParseError::NoError)
//    {
//        qDebug() << "Json格式错误";
//    }

    QJsonObject m_data = doc.object();

    //节点1数据更新
    get_json_data(&m_data,"tem1",&sensor1.temperature);
    get_json_data(&m_data,"hum1",&sensor1.humidity);
    get_json_data(&m_data,"lux1",&sensor1.lightlux);
    get_json_data(&m_data,"bat1",&sensor1.bat_uint16);
    get_json_data(&m_data,"state1",&sensor1.state);

    sensor1.get_bat_2();

}

//线程2处理
void MainWindow::message2Update()
{
    ui->debugTB->clear();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(m_message, &err);   //字符串转Json
//    if(err.error != QJsonParseError::NoError)
//    {
//        qDebug() << "Json格式错误";
//    }

    QJsonObject m_data = doc.object();

    //节点2数据更新
    get_json_data(&m_data,"tem2",&sensor2.temperature);
    get_json_data(&m_data,"hum2",&sensor2.humidity);
    get_json_data(&m_data,"lux2",&sensor2.lightlux);
    get_json_data(&m_data,"bat2",&sensor2.bat_uint16);
    get_json_data(&m_data,"state2",&sensor2.state);
    get_json_data(&m_data,"bat2State",&sensor2.batState);

    sensor2.get_bat_2();

}

//线程3处理
void MainWindow::message3Update()
{
    ui->debugTB->clear();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(m_message, &err);   //字符串转Json

    QJsonObject m_data = doc.object();

    //节点3数据更新
    get_json_data(&m_data,"tem3",&sensor3.temperature);
    get_json_data(&m_data,"hum3",&sensor3.humidity);
    get_json_data(&m_data,"lux3",&sensor3.lightlux);
    get_json_data(&m_data,"bat3",&sensor3.bat_uint16);
    get_json_data(&m_data,"state3",&sensor3.state);

    sensor3.get_bat_2();

}

//读取Json中数据
void MainWindow::get_json_data(QJsonObject *json,QString val,int *sensor)
{
    QJsonValue value1 = json->value(val);
    int i = (int)value1.toInt();
    *sensor = i;

}


////7.串口传输槽函数，当串口有缓存数据时，调用
//void MainWindow::serialTimerUpdate_Update(sensordata *sensordata_temp)
//{
//    sensordata_temp->temperature = strT.toInt();
//    sensordata_temp->humidity = strH.toInt();
//    sensordata_temp->lightlux = strL.toInt();
//    sensordata_temp->state = stateFlag;
//    sensordata_temp->get_bat(battery);
//}

//7.清空窗口1
void MainWindow::on_clear1PB_clicked()
{
    ui->sendTB->clear();
}

//7.清空窗口2
void MainWindow::on_clear2PB_clicked()
{
    ui->recvTB->clear();
}

//7.搜索串口
void MainWindow::on_findserialPB_clicked()
{
    ui->serialCB->clear();

    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->serialCB->addItem(info.portName());
    }
}

//7.打开串口
void MainWindow::on_openserialPB_clicked()
{

    if(ui->baudrateCB->currentText()=="4800")
        baudRate=QSerialPort::Baud4800;
    else if(ui->baudrateCB->currentText()=="9600")
        baudRate=QSerialPort::Baud9600;
    else if(ui->baudrateCB->currentText()=="115200")
        baudRate=QSerialPort::Baud115200;

    if(ui->databitsCB->currentText()=="5")
        dataBits=QSerialPort::Data5;
    else if(ui->databitsCB->currentText()=="6")
        dataBits=QSerialPort::Data6;
    else if(ui->databitsCB->currentText()=="7")
        dataBits=QSerialPort::Data7;
    else if(ui->databitsCB->currentText()=="8")
        dataBits=QSerialPort::Data8;

    if(ui->stopbitsCB->currentText()=="1")
        stopBits=QSerialPort::OneStop;
    else if(ui->stopbitsCB->currentText()=="1.5")
        stopBits=QSerialPort::OneAndHalfStop;
    else if(ui->stopbitsCB->currentText()=="2")
        stopBits=QSerialPort::TwoStop;

    if(ui->checkbitsCB->currentText()=="none")
        checkBits=QSerialPort::NoParity;

    serialPort->setPortName(ui->serialCB->currentText());
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(checkBits);

    if(serialPort->open(QIODevice::ReadWrite)==true)
        QMessageBox::information(this,"提示","成功");
    else
        QMessageBox::critical(this,"提示","失败");

}

//7.关闭串口
void MainWindow::on_closeserialPB_clicked()
{
    serialPort->close();
}

//7.发送数据
void MainWindow::on_sendPB_clicked()
{
    serialPort->write(ui->sendTB->toPlainText().toLocal8Bit().data());
}

//8.调试
void MainWindow::on_debugPB_clicked()
{
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach (QString driver, drivers) {
//        qDebug() << "/t" << driver;
//    }
    qDebug() << SMA_DATA;
}

//1.设置报警上下限阈值
void MainWindow::on_setValuePB_clicked()
{
    int temp0 = ui->nodeChooseCB2->currentIndex()+1;
    int temp1 = ui->L1->text().toInt();
    int temp2 = ui->L2->text().toInt();
    int temp3 = ui->L3->text().toInt();
    int temp4 = ui->L4->text().toInt();
    int temp5 = ui->L5->text().toInt();
    int temp6 = ui->L6->text().toInt();

    if(temp1 && temp2 && temp3 && temp4 && temp5 && temp6 && temp1<temp2 && temp3<temp4 && temp5<temp6)
    {
        switch (temp0) {
            case 1:
                sensor1alarm.alarm_set_limits(temp1,temp2,temp3,temp4,temp5,temp6);
                QMessageBox::information(0,"设置成功提醒","节点1的报警阈值设置成功!",QMessageBox::Ok);
                break;
            case 2:
                sensor2alarm.alarm_set_limits(temp1,temp2,temp3,temp4,temp5,temp6);
                QMessageBox::information(0,"设置成功提醒","节点2的报警阈值设置成功!",QMessageBox::Ok);
                break;
            case 3:
                sensor3alarm.alarm_set_limits(temp1,temp2,temp3,temp4,temp5,temp6);
                QMessageBox::information(0,"设置成功提醒","节点3的报警阈值设置成功!",QMessageBox::Ok);
                break;
        }
    }
    else if(temp1 || temp2 || temp3 || temp4 || temp5 || temp6)
    {
        QMessageBox::critical(0,"设置失败提醒","请填写完整阈值项!",QMessageBox::Ok);
    }
    else if(temp1>temp2 || temp3>temp4 || temp1>temp4)
    {
        QMessageBox::critical(0,"设置失败提醒","数值越界!",QMessageBox::Ok);
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->messageTB->clear();
}





