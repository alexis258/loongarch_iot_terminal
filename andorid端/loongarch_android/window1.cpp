#include "window1.h"
#include "ui_window1.h"

window1::window1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window1)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(199,237,204)");

    //节点参数设计
    sensor1.rank = 1;
    sensor2.rank = 2;
    sensor3.rank = 3;

    Window1UpdateTimer = new QTimer(this);
    Window1UpdateTimer->start(1000);
    connect(Window1UpdateTimer,&QTimer::timeout,[=](){
        QString strT1 = QString::number(sensor1.temperature, 10);
        QString strH1 = QString::number(sensor1.humidity, 10);
        QString strL1 = QString::number(sensor1.lightlux, 10);
        QString strB1 = QString::number(sensor1.bat, 10);
        ui->node1_LB1->setText(strT1);
        ui->node1_LB2->setText(strH1);
        ui->node1_LB3->setText(strL1);
        ui->node1_LB4->setText(strB1);
        if(sensor1.state == 1)
        {
            ui->node1_LB5->setText("在线");
            ui->node1_LB5->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
        }else{
            ui->node1_LB5->setText("离线");
            ui->node1_LB5->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
        }


        QString strT2 = QString::number(sensor2.temperature, 10);
        QString strH2 = QString::number(sensor2.humidity, 10);
        QString strL2 = QString::number(sensor2.lightlux, 10);
        QString strB2 = QString::number(sensor2.bat, 10);
        ui->node2_LB1->setText(strT2);
        ui->node2_LB2->setText(strH2);
        ui->node2_LB3->setText(strL2);
        ui->node2_LB4->setText(strB2);
        if(sensor2.state == 1)
        {
            ui->node2_LB5->setText("在线");
            ui->node2_LB5->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
        }else{
            ui->node2_LB5->setText("离线");
            ui->node2_LB5->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
        }

        QString strT3 = QString::number(sensor3.temperature, 10);
        QString strH3 = QString::number(sensor3.humidity, 10);
        QString strL3 = QString::number(sensor3.lightlux, 10);
        QString strB3 = QString::number(sensor3.bat, 10);
        ui->node3_LB1->setText(strT3);
        ui->node3_LB2->setText(strH3);
        ui->node3_LB3->setText(strL3);
        ui->node3_LB4->setText(strB3);
        if(sensor3.state == 1)
        {
            ui->node3_LB5->setText("在线");
            ui->node3_LB5->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
        }else{
            ui->node3_LB5->setText("离线");
            ui->node3_LB5->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
        }
    });

}

window1::~window1()
{
    delete ui;
}


void window1::on_pushButton_clicked()
{
    this->hide();
}



