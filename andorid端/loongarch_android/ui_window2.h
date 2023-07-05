/********************************************************************************
** Form generated from reading UI file 'window2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW2_H
#define UI_WINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window2
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *sensorCB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *indexCB;
    QPushButton *chooseBT;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGridLayout *chartGL;
    QPushButton *pushButton;

    void setupUi(QWidget *window2)
    {
        if (window2->objectName().isEmpty())
            window2->setObjectName(QString::fromUtf8("window2"));
        window2->resize(800, 1200);
        window2->setMinimumSize(QSize(800, 1200));
        gridLayout_3 = new QGridLayout(window2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(window2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 124));

        horizontalLayout->addWidget(label);

        sensorCB = new QComboBox(groupBox);
        sensorCB->addItem(QString());
        sensorCB->addItem(QString());
        sensorCB->addItem(QString());
        sensorCB->setObjectName(QString::fromUtf8("sensorCB"));
        sensorCB->setMaximumSize(QSize(16777215, 124));

        horizontalLayout->addWidget(sensorCB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 124));

        horizontalLayout_2->addWidget(label_2);

        indexCB = new QComboBox(groupBox);
        indexCB->addItem(QString());
        indexCB->addItem(QString());
        indexCB->addItem(QString());
        indexCB->setObjectName(QString::fromUtf8("indexCB"));
        indexCB->setMaximumSize(QSize(16777215, 124));

        horizontalLayout_2->addWidget(indexCB);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        chooseBT = new QPushButton(groupBox);
        chooseBT->setObjectName(QString::fromUtf8("chooseBT"));
        chooseBT->setMaximumSize(QSize(16777215, 124));

        horizontalLayout_3->addWidget(chooseBT);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(400, 400));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chartGL = new QGridLayout();
        chartGL->setObjectName(QString::fromUtf8("chartGL"));

        gridLayout_2->addLayout(chartGL, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        pushButton = new QPushButton(window2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 124));
        pushButton->setMaximumSize(QSize(16777215, 124));
        pushButton->setStyleSheet(QString::fromUtf8("image:url(:/back.png);"));

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(window2);

        QMetaObject::connectSlotsByName(window2);
    } // setupUi

    void retranslateUi(QWidget *window2)
    {
        window2->setWindowTitle(QCoreApplication::translate("window2", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("window2", "\351\200\211\346\213\251\350\212\202\347\202\271\357\274\232", nullptr));
        sensorCB->setItemText(0, QCoreApplication::translate("window2", "\344\270\200\345\217\267\350\212\202\347\202\271", nullptr));
        sensorCB->setItemText(1, QCoreApplication::translate("window2", "\344\272\214\345\217\267\350\212\202\347\202\271", nullptr));
        sensorCB->setItemText(2, QCoreApplication::translate("window2", "\344\270\211\345\217\267\350\212\202\347\202\271", nullptr));

        label_2->setText(QCoreApplication::translate("window2", "\351\200\211\346\213\251\346\225\260\346\215\256\357\274\232", nullptr));
        indexCB->setItemText(0, QCoreApplication::translate("window2", "\346\270\251\345\272\246", nullptr));
        indexCB->setItemText(1, QCoreApplication::translate("window2", "\346\271\277\345\272\246", nullptr));
        indexCB->setItemText(2, QCoreApplication::translate("window2", "\345\205\211\347\205\247", nullptr));

        chooseBT->setText(QCoreApplication::translate("window2", "\347\241\256\345\256\232\351\200\211\346\213\251", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("window2", "\345\233\276\350\241\250\346\230\276\347\244\272", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class window2: public Ui_window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H
