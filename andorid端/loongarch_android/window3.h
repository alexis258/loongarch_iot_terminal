#ifndef WINDOW3_H
#define WINDOW3_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

#include <QLabel.h>

namespace Ui {
class window3;
}

class window3 : public QWidget
{
    Q_OBJECT

public:
    explicit window3(QWidget *parent = nullptr);
    ~window3();

    QDateTime dateTime;

    int aliyun_state = 0;
    int node1_state = 0;    //节点1在线状态
    int node2_state = 0;    //节点2在线状态
    int node3_state = 0;    //节点3在线状态

    int rank1 = 1;
    int rank2 = 2;
    int rank3 = 3;

    int node1_state_temp = 0;
    int node2_state_temp = 0;
    int node3_state_temp = 0;

    int node1_state_stack = 0;
    int node2_state_stack = 0;
    int node3_state_stack = 0;

    int topoCurRow;

private slots:
    void on_pushButton_clicked();

private:
    Ui::window3 *ui;

    QTimer *Window3UpdateTimer;       //用于周期上报云平台
    void Window3Update();
    void Label3Update(int node_state,int *node_state_temp,int *node_state_stack,int rank,QLabel *LB);
};

#endif // WINDOW3_H
