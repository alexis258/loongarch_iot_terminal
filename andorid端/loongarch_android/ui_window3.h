/********************************************************************************
** Form generated from reading UI file 'window3.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW3_H
#define UI_WINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window3
{
public:
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QLabel *LB1;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *LB2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *LB3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *LB4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *LB5;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *window3)
    {
        if (window3->objectName().isEmpty())
            window3->setObjectName(QString::fromUtf8("window3"));
        window3->resize(800, 1200);
        window3->setMinimumSize(QSize(800, 1200));
        gridLayout_7 = new QGridLayout(window3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_5 = new QGroupBox(window3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        LB1 = new QLabel(groupBox_5);
        LB1->setObjectName(QString::fromUtf8("LB1"));
        LB1->setMinimumSize(QSize(0, 124));
        LB1->setStyleSheet(QString::fromUtf8("image:url(:/wifi-off.png);\n"
"image-position: left;\n"
"padding-left:30px;\n"
"color:rgb(255, 0, 0);"));
        LB1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(LB1, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(window3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("image:url(:/coor.png);\n"
"image-position: left;\n"
"text-align:right;\n"
""));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        LB2 = new QLabel(groupBox);
        LB2->setObjectName(QString::fromUtf8("LB2"));

        verticalLayout_3->addWidget(LB2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(window3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("image:url(:/end.png);\n"
"image-position: left;\n"
"text-align:right;\n"
""));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        LB3 = new QLabel(groupBox_2);
        LB3->setObjectName(QString::fromUtf8("LB3"));

        verticalLayout_4->addWidget(LB3);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(window3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("image:url(:/end.png);\n"
"image-position: left;\n"
"text-align:right;\n"
""));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_5->addWidget(label_8);

        LB4 = new QLabel(groupBox_3);
        LB4->setObjectName(QString::fromUtf8("LB4"));

        verticalLayout_5->addWidget(LB4);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(window3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("image:url(:/end.png);\n"
"image-position: left;\n"
"text-align:right;\n"
""));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_6->addWidget(label_10);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_6->addWidget(label_11);

        LB5 = new QLabel(groupBox_4);
        LB5->setObjectName(QString::fromUtf8("LB5"));

        verticalLayout_6->addWidget(LB5);


        gridLayout_4->addLayout(verticalLayout_6, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);


        horizontalLayout_5->addLayout(verticalLayout);

        groupBox_6 = new QGroupBox(window3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidget = new QTableWidget(groupBox_6);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_5->addWidget(tableWidget, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(groupBox_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        pushButton = new QPushButton(window3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 124));
        pushButton->setMaximumSize(QSize(16777215, 124));
        pushButton->setStyleSheet(QString::fromUtf8("image:url(:/back.png);"));

        verticalLayout_2->addWidget(pushButton);


        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(window3);

        QMetaObject::connectSlotsByName(window3);
    } // setupUi

    void retranslateUi(QWidget *window3)
    {
        window3->setWindowTitle(QCoreApplication::translate("window3", "Form", nullptr));
        groupBox_5->setTitle(QString());
        LB1->setText(QCoreApplication::translate("window3", "\346\234\252\350\277\236\346\216\245\350\207\263\351\230\277\351\207\214\344\272\221\345\271\263\345\217\260", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("window3", "\345\215\217\350\260\203\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("window3", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        LB2->setText(QCoreApplication::translate("window3", "\346\234\252\350\277\236\346\216\245", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QCoreApplication::translate("window3", "\350\212\202\347\202\2711", nullptr));
        label_5->setText(QCoreApplication::translate("window3", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        LB3->setText(QCoreApplication::translate("window3", "\346\234\252\350\277\236\346\216\245", nullptr));
        groupBox_3->setTitle(QString());
        label_7->setText(QCoreApplication::translate("window3", "\350\212\202\347\202\2712", nullptr));
        label_8->setText(QCoreApplication::translate("window3", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        LB4->setText(QCoreApplication::translate("window3", "\346\234\252\350\277\236\346\216\245", nullptr));
        groupBox_4->setTitle(QString());
        label_10->setText(QCoreApplication::translate("window3", "\350\212\202\347\202\2713", nullptr));
        label_11->setText(QCoreApplication::translate("window3", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        LB5->setText(QCoreApplication::translate("window3", "\346\234\252\350\277\236\346\216\245", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("window3", "\350\212\202\347\202\271\344\270\212\344\270\213\347\272\277\346\227\245\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("window3", "\350\212\202\347\202\271\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("window3", "\344\272\213\344\273\266\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("window3", "\344\272\213\344\273\266\347\261\273\345\236\213", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class window3: public Ui_window3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW3_H
