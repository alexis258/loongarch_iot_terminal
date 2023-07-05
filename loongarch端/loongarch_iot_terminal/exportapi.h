#ifndef EXPORTAPI_H
#define EXPORTAPI_H

#include <QDebug>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDir>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class exportapi
{
public:
    exportapi();

    static void exportTxt(QString title,QTableWidget *table);
};

#endif // EXPORTAPI_H
