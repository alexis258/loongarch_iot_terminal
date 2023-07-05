#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "window1.h"
#include "window2.h"
#include "window3.h"
#include "window4.h"
#include "window5.h"
#include "window6.h"

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>

#include <QTimer>
#include <QDateTime>

#include <QJsonDocument>        //获取json串
#include <QJsonObject>
#include <QJsonArray>



#include <QtMqtt/QMqttClient>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_PB1_clicked();

    void on_PB2_clicked();

    void on_PB3_clicked();

    void on_PB4_clicked();

    void on_PB5_clicked();

    void on_PB6_clicked();

private:
    Ui::MainWindow *ui;

    //从窗口6获取物联网数据，并赋值给窗口1
    void Window1TimerUpdate();
    QTimer *window1Timer;


    //各个模块窗口对象构造,对应1~6个按钮
    window1 *Window_1;
    window2 *Window_2;
    window3 *Window_3;
    window4 *Window_4;
    window5 *Window_5;
    window6 *Window_6;
    void Window_Init();

    //窗口6

};
#endif // MAINWINDOW_H
