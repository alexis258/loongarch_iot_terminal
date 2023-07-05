#ifndef WINDOW1_H
#define WINDOW1_H

#include <QWidget>
#include <QTimer>

#include "sensordata.h"

namespace Ui {
class window1;
}

class window1 : public QWidget
{
    Q_OBJECT

public:
    explicit window1(QWidget *parent = nullptr);
    ~window1();

    //添加设备参数
    sensordata sensor1;
    sensordata sensor2;
    sensordata sensor3;

private slots:

    void on_pushButton_clicked();

private:
    Ui::window1 *ui;

    void Window1Update();
    QTimer *Window1UpdateTimer;

};

#endif // WINDOW1_H
