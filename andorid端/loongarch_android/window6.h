#ifndef WINDOW6_H
#define WINDOW6_H

#include <QWidget>

#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QtMqtt/QMqttClient>

#include <QJsonDocument>        //获取json串
#include <QJsonObject>
#include <QJsonArray>

#include <QThread>
#include <QObject>
#include <QtConcurrent>

#include <QTimer>

#include "sensordata.h"

/*
 *阿里云mqtt连接参数，修改以切换平台和设备
 */
#define HOST_ALIYUN "iot-06z00fag7q36ymv.mqtt.iothub.aliyuncs.com"
#define USERNAME_ALIYUN "Java&ifosctA7yNu"
#define PASSWORD_ALIYUN "f4419b60f47affb9ebd87e6962289776dfc53ce60dd6c248bc1f22c2b4c64514"
#define CLIENDID_ALIYUN "ifosctA7yNu.Java|securemode=2,signmethod=hmacsha256,timestamp=1686636538095|"


//主题，用来接收龙芯派上传给云平台的的转发数据（包括所有3个节点的全部数据）
#define TOPIC_RECEIVE "/sys/ifosctA7yNu/Java/thing/service/property/set"
#define RECEIVE_TOPIC_ALIYUN "/sys/ifosctA7yNu/Java/thing/service/property/set"

namespace Ui {
class window6;
}

class window6 : public QWidget
{
    Q_OBJECT

public:
    explicit window6(QWidget *parent = nullptr);
    ~window6();

    void updateLogStateChange();
    void brokerDisconnected();
    void messageUpdate();     //处理数据
    void get_json_data(QJsonObject *json,QString value,int *sensor);  //从Json提取数据

    //添加设备参数
    sensordata sensor1;
    sensordata sensor2;
    sensordata sensor3;
    
    int aliyun_state = 0;       //阿里云平台连接情况


private slots:
    void on_pushButton_clicked();

    void on_connectBT_clicked();

    void on_clearPB1_clicked();

    void on_clearPB2_clicked();

    void on_clearPB3_clicked();

    void on_clearPB4_clicked();

    void on_subBT_clicked();

private:
    Ui::window6 *ui;



    //Json数据解析
    QByteArray data;           //原始的字符流
    QJsonObject m_data;        //转化接收到的完整Json
    QJsonObject m_items;       //转化Json中items
    
    QByteArray *m_message;      //全部的字符流
    QTimer *messageTimer;       //用于周期上报云平台


    //mqtt连接参数
    QMqttClient *m_client;
    QString host_aliyun = HOST_ALIYUN;
    QString username_aliyun = USERNAME_ALIYUN;
    QString password_aliyun = PASSWORD_ALIYUN;
    QString clientid_aliyun = CLIENDID_ALIYUN;
    QString topic_receive = RECEIVE_TOPIC_ALIYUN;
    QMqttTopicName topic_1 = topic_receive;
    QTimer  *mqttTimer;       //用于周期上报云平台
    

};

#endif // WINDOW6_H
