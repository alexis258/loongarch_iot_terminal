#include "basetable.h"

basetable::basetable()
{

}

void basetable::tableInit(int rank)
{
    this->rank = rank;
    date = QDate::currentDate();
    time = QTime::currentTime();

    ui_table = new QTableWidget();
    ui_table->setRowCount(1);   //
    ui_table->setColumnCount(5);
    ui_table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置为不可编辑
    ui_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui_table->verticalHeader()->setVisible(false);                 //设置行列头隐藏
    ui_table->horizontalHeader()->setVisible(false);
    ui_table->setFrameStyle(QFrame::NoFrame);

    table00 = new QTableWidgetItem;
    table00->setText(QStringLiteral("序号"));
    table01 = new QTableWidgetItem;
    table01->setText(QStringLiteral("时间"));
    table02 = new QTableWidgetItem;
    table02->setText(QStringLiteral("温度/℃"));
    table03 = new QTableWidgetItem;
    table03->setText(QStringLiteral("湿度/RH"));
    table04 = new QTableWidgetItem;
    table04->setText(QStringLiteral("光照/LUX"));

    ui_table->setItem(0,0,table00);
    ui_table->setItem(0,1,table01);
    ui_table->setItem(0,2,table02);
    ui_table->setItem(0,3,table03);
    ui_table->setItem(0,4,table04);



    ui_table->setVisible(false);

}

void basetable::table_update(int temperature,int humidity,int lightlux)
{

    QDate datetemp = QDate::currentDate();
    time = QTime::currentTime();

    int curRow = ui_table->rowCount();
    ui_table->insertRow(curRow);

    QTableWidgetItem *item0 = new QTableWidgetItem;
    QTableWidgetItem *item1 = new QTableWidgetItem;
    QTableWidgetItem *item2 = new QTableWidgetItem;
    QTableWidgetItem *item3 = new QTableWidgetItem;
    QTableWidgetItem *item4 = new QTableWidgetItem;

    item0->setText(QString::number(curRow));
    item1->setText(time.toString());
    item2->setText(QString::number(temperature));
    item3->setText(QString::number(humidity));
    item4->setText(QString::number(lightlux));

    if(curRow <= 28800 && datetemp == date && temperature != 0)
    {
        ui_table->setItem(curRow, 0, item0);
        ui_table->setItem(curRow, 1, item1);
        ui_table->setItem(curRow, 2, item2);
        ui_table->setItem(curRow, 3, item3);
        ui_table->setItem(curRow, 4, item4);
    }else{
        delete ui_table;
        tableInit(this->rank);
    }

}
