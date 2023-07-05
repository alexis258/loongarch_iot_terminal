/********************************************************************************
** Form generated from reading UI file 'window4.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW4_H
#define UI_WINDOW4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "battery.h"

QT_BEGIN_NAMESPACE

class Ui_window4
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    Battery *battery1;
    QLabel *bat1;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    Battery *battery2;
    QLabel *bat2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    Battery *battery3;
    QLabel *bat3;
    QLabel *label_9;
    QPushButton *pushButton;

    void setupUi(QWidget *window4)
    {
        if (window4->objectName().isEmpty())
            window4->setObjectName(QString::fromUtf8("window4"));
        window4->resize(800, 1200);
        window4->setMinimumSize(QSize(800, 1200));
        gridLayout = new QGridLayout(window4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(window4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        battery1 = new Battery(window4);
        battery1->setObjectName(QString::fromUtf8("battery1"));
        battery1->setMinimumSize(QSize(600, 248));
        battery1->setMaximumSize(QSize(16777215, 248));

        horizontalLayout->addWidget(battery1);

        bat1 = new QLabel(window4);
        bat1->setObjectName(QString::fromUtf8("bat1"));
        bat1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(bat1);

        label_3 = new QLabel(window4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(window4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        battery2 = new Battery(window4);
        battery2->setObjectName(QString::fromUtf8("battery2"));
        battery2->setMinimumSize(QSize(600, 248));
        battery2->setMaximumSize(QSize(16777215, 248));

        horizontalLayout_2->addWidget(battery2);

        bat2 = new QLabel(window4);
        bat2->setObjectName(QString::fromUtf8("bat2"));
        bat2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(bat2);

        label_6 = new QLabel(window4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(window4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        battery3 = new Battery(window4);
        battery3->setObjectName(QString::fromUtf8("battery3"));
        battery3->setMinimumSize(QSize(600, 248));
        battery3->setMaximumSize(QSize(16777215, 248));

        horizontalLayout_3->addWidget(battery3);

        bat3 = new QLabel(window4);
        bat3->setObjectName(QString::fromUtf8("bat3"));
        bat3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(bat3);

        label_9 = new QLabel(window4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        pushButton = new QPushButton(window4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 124));
        pushButton->setMaximumSize(QSize(16777215, 124));
        pushButton->setStyleSheet(QString::fromUtf8("image:url(:/back.png);"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);


        retranslateUi(window4);

        QMetaObject::connectSlotsByName(window4);
    } // setupUi

    void retranslateUi(QWidget *window4)
    {
        window4->setWindowTitle(QCoreApplication::translate("window4", "Form", nullptr));
        label->setText(QCoreApplication::translate("window4", "\350\212\202\347\202\2711\357\274\232", nullptr));
        bat1->setText(QCoreApplication::translate("window4", "100", nullptr));
        label_3->setText(QCoreApplication::translate("window4", "%", nullptr));
        label_4->setText(QCoreApplication::translate("window4", "\350\212\202\347\202\2712\357\274\232", nullptr));
        bat2->setText(QCoreApplication::translate("window4", "100", nullptr));
        label_6->setText(QCoreApplication::translate("window4", "%", nullptr));
        label_7->setText(QCoreApplication::translate("window4", "\350\212\202\347\202\2713\357\274\232", nullptr));
        bat3->setText(QCoreApplication::translate("window4", "100", nullptr));
        label_9->setText(QCoreApplication::translate("window4", "%", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class window4: public Ui_window4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW4_H
