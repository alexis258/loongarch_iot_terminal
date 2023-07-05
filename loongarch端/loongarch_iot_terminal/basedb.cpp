#include "basedb.h"

basedb::basedb()   //创建数据库
{
//    //1.添加数据库驱动
//    //2.设置数据库名称
//    if(QSqlDatabase::contains("qt_sql_default_connection"))
//    {
//        sqldb = QSqlDatabase::database("qt_sql_default_connection");
//    }
//    else
//    {
//        sqldb = QSqlDatabase::addDatabase("QSQLITE");
//        sqldb.setDatabaseName("loongarch_iot.db");
//        sqldb.setUserName("reah");
//        sqldb.setPassword("123456");
//    }


//    //3.打开此数据库是否成功
//    if(sqldb.open()==true)
//    {
//        QMessageBox::information(0,"true","database connection succeeded!",QMessageBox::Ok);
//        qDebug() << "database connection succeeded" << endl;
//    }
//    else
//    {
//        QMessageBox::critical(0,"false","database connection failed!",QMessageBox::Ok);
//        qDebug() << "database connection failed" << sqldb.lastError() << endl;
//    }

}

basedb::~basedb()
{

}
