#include "sensordb.h"

//创建表
sensordb::sensordb()
{
//    //创建sql语句
//    QSqlQuery sqlquery(sqldb);
//    sqlquery.prepare("create table sensor:rankdb"
//                     "("
//                     "id int primary key not null,"
//                     "date date not null,"
//                     "time time not null,"
//                     "temperature float not null,"
//                     "humidity float not null,"
//                     "lightlux int not null"
//                     ")");
//    sqlquery.addBindValue(rank);

//    //执行sql语句
//    if(sqlquery.exec()==true)
//    {
//        QMessageBox::information(0,"true","sensor table creation succeeded!!!",QMessageBox::Ok);
//        qDebug() << "Table created!!!" << endl;
//    }
//    else
//    {
//        QMessageBox::critical(0,"false","sensor table creation failed!!!",QMessageBox::Ok);
//        qDebug() << "Error:Fail to create table!!!" << sqlquery.lastError() << endl;
//    }
}

sensordb::~sensordb()
{

}

//增添数据记录
void insert_sensordb(int id,
                     QString date,
                     QString time,
                     float temperature,
                     float humidity,
                     int lightlux)
{
    //创建sql语句
    QSqlQuery sqlquery;
    sqlquery.prepare("insert into sensor1db(id,date,time,temperature,humidity,lightlux)"
                     "values(:id,:date,:time,:temperature,:humidity,:lightlux)");
    sqlquery.addBindValue(id);
    sqlquery.addBindValue(date);
    sqlquery.addBindValue(time);
    sqlquery.addBindValue(temperature);
    sqlquery.addBindValue(humidity);
    sqlquery.addBindValue(lightlux);

    //执行sql语句
    if(sqlquery.exec()==true)
    {
        qDebug() << "Insert success!" << endl;
    }
    else
    {
        qDebug() << "Error:Fail to create table" << sqlquery.lastError() << endl;
    }
}

//删除数据记录
void delete_sensordb(int id)
{
    //创建sql语句
    QSqlQuery sqlquery;
    QString deletesql = QString("DELETE FROM sensor1db WHERE id = ?");
    sqlquery.prepare(deletesql);
    sqlquery.addBindValue(id);

    //执行sql语句
    if(sqlquery.exec()==true)
    {
        qDebug() << "Delete record success!" << endl;
    }
    else
    {
        qDebug() << "Error:Fail to delete record!" << sqlquery.lastError() << endl;
    }
}

//更新数据
void update_sensordb(int id)
{

}

//查询数据
void select_sensordb()
{

}







