#-------------------------------------------------
#
# Project created by QtCreator 2023-04-04T21:48:35
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += serialport
QT       += network
QT       += mqtt
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loongarch_iot_terminal
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11\
          -qt-sql-sqlite\
          -plugin-sql-sqlite\
          -sql-sqlite

SOURCES += \
    basealarm.cpp \
    basechart.cpp \
    basetable.cpp \
    exportapi.cpp \
    main.cpp \
    mainwindow.cpp \
    basedb.cpp \
    sensordata.cpp \
    sensordb.cpp



HEADERS += \
    basealarm.h \
    basechart.h \
    basetable.h \
    exportapi.h \
    mainwindow.h \
    basedb.h \
    sensordata.h \
    sensordb.h



FORMS += \
        mainwindow.ui

# 添加QXlsx库文件
#include($$PWD/QXlsx/QXlsx.pri)
#INCLUDEPATH += $$PWD/QXlsx

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES += \
    picture/Light sensor.jpg \
    picture/humidity sensor.jpg \

