#include "window6.h"
#include "ui_window6.h"

window6::window6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window6)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(199,237,204)");

    m_message = new QByteArray();
    messageTimer = new QTimer(this);
    connect(messageTimer,&QTimer::timeout,this,&window6::messageUpdate);
    messageTimer->start(1000);   //半天切换

    //节点参数设计
    sensor1.rank = 1;
    sensor2.rank = 2;
    sensor3.rank = 3;

    //mqtt服务器
    m_client = new QMqttClient(this);
    m_client->setHostname(host_aliyun);
    m_client->setUsername(username_aliyun);
    m_client->setPassword(password_aliyun);
    m_client->setClientId(clientid_aliyun);
    m_client->setPort(1883);
    m_client->setKeepAlive(30);

    connect(m_client, &QMqttClient::stateChanged, this, &window6::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &window6::brokerDisconnected);


    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QLatin1String(" Received Topic: ")
                    + topic.name()
                    + QLatin1Char('\n')
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n')
                    + QLatin1Char('\n');
        ui->receiveTB->insertPlainText(content);

        *m_message = message;


    });


    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
//        ui->heartbeatTB->insertPlainText(content);
    });

    updateLogStateChange();
}

window6::~window6()
{
    delete ui;
}

void window6::on_pushButton_clicked()
{
    this->hide();
}

//更新mqtt服务器连接状态
void window6::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    ui->stateTB->insertPlainText(content);
    if (m_client->state() == QMqttClient::Disconnected) {
        ui->stateTB->insertPlainText("断开连接！\n");
    }else{
        ui->stateTB->insertPlainText("连接成功！\n");
    }

}

//断开mqtt连接
void window6::brokerDisconnected()
{
    ui->connectBT->setText(tr("连接"));
}


//连接mqtt服务器
void window6::on_connectBT_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected) {
        ui->connectBT->setText(tr("未连接"));
        m_client->connectToHost();
        qDebug() << "111" ;
    } else {
        ui->connectBT->setText(tr("连接"));
        m_client->disconnectFromHost();
        qDebug() << "222" ;
    }

}

//订阅主题
void window6::on_subBT_clicked()
{
    auto subscription = m_client->subscribe(topic_receive);
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
}

//线程处理
void window6::messageUpdate()
{

    QByteArray data = *m_message;

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);   //字符串转Json
    if(err.error != QJsonParseError::NoError)
    {
        qDebug() << "Json格式错误";
//        return false;
    }

    m_data = doc.object();
    QJsonValue value = m_data.value("items");
    m_items =  value.toObject();

    get_json_data(&m_items,"temperature_node1",&sensor1.temperature);
    get_json_data(&m_items,"humidity_node1",&sensor1.humidity);
    get_json_data(&m_items,"lightLux_node1",&sensor1.lightlux);
    get_json_data(&m_items,"state_node1",&sensor1.state);
    get_json_data(&m_items,"battery_node1",&sensor1.bat);

    get_json_data(&m_items,"temperature_node2",&sensor2.temperature);
    get_json_data(&m_items,"humidity_node2",&sensor2.humidity);
    get_json_data(&m_items,"lightLux_node2",&sensor2.lightlux);
    get_json_data(&m_items,"state_node2",&sensor2.state);
    get_json_data(&m_items,"battery_node2",&sensor2.bat);

    get_json_data(&m_items,"temperature_node3",&sensor3.temperature);
    get_json_data(&m_items,"humidity_node3",&sensor3.humidity);
    get_json_data(&m_items,"lightLux_node3",&sensor3.lightlux);
    get_json_data(&m_items,"state_node3",&sensor3.state);
    get_json_data(&m_items,"battery_node3",&sensor3.bat);

    if (m_client->state() == QMqttClient::Disconnected) {
        aliyun_state = 0;
    }else{
        aliyun_state = 1;
    }

}

//读取Json中数据
void window6::get_json_data(QJsonObject *json,QString value,int *sensor)
{
    QJsonValue value1 = json->value(value);
    QJsonObject json2 = value1.toObject();
    QJsonValue value2 = json2.value("value");
    *sensor = value2.toInt();

}


//清空消息栏
void window6::on_clearPB1_clicked()
{
    ui->stateTB->clear();
}

void window6::on_clearPB2_clicked()
{
    ui->heartbeatTB->clear();
}

void window6::on_clearPB3_clicked()
{
    ui->receiveTB->clear();
}

void window6::on_clearPB4_clicked()
{
    ui->sendTB->clear();
}
