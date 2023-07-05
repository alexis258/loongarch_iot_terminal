#include "window4.h"
#include "ui_window4.h"

#include "qpainter.h"
#include "qtimer.h"

window4::window4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window4)
{
    ui->setupUi(this);

//    this->setStyleSheet("background-color:rgb(199,237,204)");
    Window4UpdateTimer = new QTimer(this);
    connect(Window4UpdateTimer,&QTimer::timeout,this,&window4::Window4Update);
    Window4UpdateTimer->start(1000);



}

window4::~window4()
{
    delete ui;
}

void window4::Window4Update()
{
    ui->battery1->setValue(batt1);
    ui->battery2->setValue(batt2);
    ui->battery3->setValue(batt3);

    ui->bat1->setText(QString::number(batt1, 10));
    ui->bat2->setText(QString::number(batt2, 10));
    ui->bat3->setText(QString::number(batt3, 10));
}


void window4::on_pushButton_clicked()
{
    this->hide();
}
