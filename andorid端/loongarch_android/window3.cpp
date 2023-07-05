#include "window3.h"
#include "ui_window3.h"

window3::window3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window3)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(199,237,204)");

    Window3UpdateTimer = new QTimer(this);
    connect(Window3UpdateTimer,&QTimer::timeout,this,&window3::Window3Update);
    Window3UpdateTimer->start(1000);   //半天切换
}

window3::~window3()
{
    delete ui;
}

void window3::on_pushButton_clicked()
{
    this->hide();
}


void window3::Window3Update()
{
    dateTime = QDateTime::currentDateTime();

    if(aliyun_state == 1)
    {
        ui->LB1->setText("已连接至物联网平台");
        ui->LB1->setStyleSheet("QLabel{color:rgb(0, 170, 0);}"
                               "QLabel{image:url(:/wifi.png);}"
                               "QLabel{image-position: left;}"
                               "QLabel{padding-left:30px;}");
    }else{
        ui->LB1->setText("未连接至物联网平台");
        ui->LB1->setStyleSheet("QLabel{color:rgb(255, 0, 0);}"
                               "QLabel{image:url(:/wifi-off.png);}"
                               "QLabel{image-position: left;}"
                               "QLabel{padding-left:30px;}");
    }

    Label3Update(node1_state, &node1_state_temp,&node1_state_stack,rank1,ui->LB3);
    Label3Update(node2_state, &node2_state_temp,&node2_state_stack,rank2,ui->LB4);
    Label3Update(node3_state, &node3_state_temp,&node3_state_stack,rank3,ui->LB5);


}

void window3::Label3Update(int node_state,int *node_state_temp,int *node_state_stack,int rank,QLabel *LB)
{
    topoCurRow = ui->tableWidget->rowCount();

    if(node_state == 1)
    {
        LB->setText("已连接");
        LB->setStyleSheet("QLabel{color:rgb(0, 170, 0);}");
        if(node_state != *node_state_temp)
        {
            ui->tableWidget->insertRow(topoCurRow);
            QTableWidgetItem *topo0 = new QTableWidgetItem;
            QTableWidgetItem *topo1 = new QTableWidgetItem;
            QTableWidgetItem *topo2 = new QTableWidgetItem;
            topo0->setText("节点"+QString::number(rank,10));
            topo1->setText(dateTime.toString("hh:mm:ss"));
            topo2->setText("上线");
            ui->tableWidget->setItem(topoCurRow, 0, topo0);
            ui->tableWidget->setItem(topoCurRow, 1, topo1);
            ui->tableWidget->setItem(topoCurRow, 2, topo2);
            *node_state_temp = node_state;
        }
        *node_state_stack = 0;
    }else{
        (*node_state_stack)++;
        if(*node_state_stack == 3)
        {
            LB->setText("未连接");
            LB->setStyleSheet("QLabel{color:rgb(255, 0, 0);}");
            if(node_state != *node_state_temp)
            {
                ui->tableWidget->insertRow(topoCurRow);
                QTableWidgetItem *topo0 = new QTableWidgetItem;
                QTableWidgetItem *topo1 = new QTableWidgetItem;
                QTableWidgetItem *topo2 = new QTableWidgetItem;
                topo0->setText("节点"+QString::number(rank,10));
                topo1->setText(dateTime.toString("hh:mm:ss"));
                topo2->setText("掉线");
                ui->tableWidget->setItem(topoCurRow, 0, topo0);
                ui->tableWidget->setItem(topoCurRow, 1, topo1);
                ui->tableWidget->setItem(topoCurRow, 2, topo2);
                *node_state_temp = node_state;
            }
            *node_state_stack = 0;
        }
    }
}




