/*说明：基础数据库类
*/

#ifndef BASEDB_H
#define BASEDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

#include <QDebug>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QMessageBox>

class basedb
{
public:
    //建立数据库对象
    QSqlDatabase sqldb;             //创建数据库
    QSqlQueryModel sqlmodel;        //存储结果集

    basedb();
    ~basedb();

};


#endif // BASEDB_H
