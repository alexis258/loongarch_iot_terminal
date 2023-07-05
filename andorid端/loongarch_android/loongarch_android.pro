#-------------------------------------------------
#
# Project created by QtCreator 2023-04-04T21:48:35
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += mqtt
QT       += charts
QT       += concurrent


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loongarch_android
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basechart.cpp \
    batt.cpp \
    battery.cpp \
    main.cpp \
    mainwindow.cpp \
    sensordata.cpp \
    window1.cpp \
    window2.cpp \
    window3.cpp \
    window4.cpp \
    window5.cpp \
    window6.cpp

HEADERS += \
    basechart.h \
    batt.h \
    battery.h \
    mainwindow.h \
    sensordata.h \
    window1.h \
    window2.h \
    window3.h \
    window4.h \
    window5.h \
    window6.h

FORMS += \
    mainwindow.ui \
    window1.ui \
    window2.ui \
    window3.ui \
    window4.ui \
    window5.ui \
    window6.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture/picture.qrc

DISTFILES +=
