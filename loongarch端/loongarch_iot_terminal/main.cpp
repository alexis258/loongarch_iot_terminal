#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <QString>

int main(int argc, char *argv[])
{
    QString path = QDir::currentPath();
        QApplication::addLibraryPath(path+QString("/plugins"));
        QPluginLoader loader(path+QString("/plugins/sqldrivers/libqsqlite.so"));

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
