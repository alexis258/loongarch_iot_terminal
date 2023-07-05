#include "window5.h"
#include "ui_window5.h"

window5::window5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window5)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(199,237,204)");
}

window5::~window5()
{
    delete ui;
}

void window5::on_pushButton_clicked()
{
    this->hide();
}

void window5::on_pushButton_2_clicked()
{
    QMessageBox::information(0,"设置成功提醒","报警条件阈值设置成功!",QMessageBox::Ok);
}
