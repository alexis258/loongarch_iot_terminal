#ifndef SENSORDB_H
#define SENSORDB_H

#include "basedb.h"

class sensordb:public basedb
{
public:
    //标识是哪个节点
    int rank = 0;

    //节点的数据表对象
    int id = 0;
    QString date = "2023-4-4";
    QString time = "12:30:00";
    float temperature = 25.0;
    float humidity = 60.0;
    int lightlux = 200;
    QString dateTime;

    sensordb();
    ~sensordb();

    //数据库增删该查
    static void insert_sensordb(int id,
                                 QString date,
                                 QString time,
                                 float temperature,
                                 float humidity,
                                 int lightlux);
    void delete_sensordb(int id);
    void update_sensordb(int id);
    void select_sensordb();




};

#endif // SENSORDB_H
