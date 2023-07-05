#ifndef WINDOW4_H
#define WINDOW4_H

#include <QWidget>
#include <QTimer>

#include "battery.h"

namespace Ui {
class window4;
}

class window4 : public QWidget
{
    Q_OBJECT

public:
    explicit window4(QWidget *parent = nullptr);
    ~window4();

    int batt1 = 100;    //电量
    int batt2 = 100;
    int batt3 = 100;

    QTimer *Window4UpdateTimer;


private slots:
    void on_pushButton_clicked();

private:
    Ui::window4 *ui;

    void Window4Update();




};

#endif // WINDOW4_H
