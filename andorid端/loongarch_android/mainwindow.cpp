#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setStyleSheet("background-color:rgb(199,237,204)");

    //所有窗口初始化
    Window_Init();

    //窗口1数据传递
    window1Timer = new QTimer(this);
    connect(window1Timer,&QTimer::timeout,this,&MainWindow::Window1TimerUpdate);
    window1Timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Window_Init()
{
    Window_1 = new window1;
    Window_1->setWindowModality(Qt::ApplicationModal);
    Window_2 = new window2;
    Window_2->setWindowModality(Qt::ApplicationModal);
    Window_3 = new window3;
    Window_3->setWindowModality(Qt::ApplicationModal);
    Window_4 = new window4;
    Window_4->setWindowModality(Qt::ApplicationModal);
    Window_5 = new window5;
    Window_5->setWindowModality(Qt::ApplicationModal);
    Window_6 = new window6;
    Window_6->setWindowModality(Qt::ApplicationModal);

}

void MainWindow::on_PB1_clicked()
{
    Window_1->show();
}

void MainWindow::on_PB2_clicked()
{
    Window_2->show();
}

void MainWindow::on_PB3_clicked()
{
    Window_3->show();
}

void MainWindow::on_PB4_clicked()
{
    Window_4->show();
}

void MainWindow::on_PB5_clicked()
{
    Window_5->show();
}

void MainWindow::on_PB6_clicked()
{
    Window_6->show();
}

//窗口1定时器函数，更新窗口1内数据
void MainWindow::Window1TimerUpdate()
{
    //更新窗口1数据
    Window_1->sensor1 = Window_6->sensor1;
    Window_1->sensor2 = Window_6->sensor2;
    Window_1->sensor3 = Window_6->sensor3;

    //更新窗口2数据
    Window_2->sensor1 = Window_6->sensor1;
    Window_2->sensor2 = Window_6->sensor2;
    Window_2->sensor3 = Window_6->sensor3;

    //更新窗口3数据
    Window_3->aliyun_state = Window_6->aliyun_state;
    Window_3->node1_state = Window_6->sensor1.state;
    Window_3->node2_state = Window_6->sensor2.state;
    Window_3->node3_state = Window_6->sensor3.state;

    //更新窗口4数据
    Window_4->batt1 = Window_6->sensor1.bat;
    Window_4->batt2 = Window_6->sensor2.bat;
    Window_4->batt3 = Window_6->sensor3.bat;

}
