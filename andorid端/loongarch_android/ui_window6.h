/********************************************************************************
** Form generated from reading UI file 'window6.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW6_H
#define UI_WINDOW6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window6
{
public:
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *connectBT;
    QPushButton *subBT;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_1;
    QGridLayout *gridLayout_4;
    QTextBrowser *stateTB;
    QPushButton *clearPB1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *heartbeatTB;
    QPushButton *clearPB2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *clearPB3;
    QTextBrowser *receiveTB;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QTextBrowser *sendTB;
    QPushButton *clearPB4;
    QPushButton *pushButton;

    void setupUi(QWidget *window6)
    {
        if (window6->objectName().isEmpty())
            window6->setObjectName(QString::fromUtf8("window6"));
        window6->resize(800, 1200);
        window6->setMinimumSize(QSize(600, 800));
        gridLayout_5 = new QGridLayout(window6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        connectBT = new QPushButton(window6);
        connectBT->setObjectName(QString::fromUtf8("connectBT"));
        connectBT->setMinimumSize(QSize(200, 124));
        connectBT->setMaximumSize(QSize(600, 372));

        horizontalLayout_3->addWidget(connectBT);

        subBT = new QPushButton(window6);
        subBT->setObjectName(QString::fromUtf8("subBT"));
        subBT->setMinimumSize(QSize(200, 124));
        subBT->setMaximumSize(QSize(600, 372));
        subBT->setStyleSheet(QString::fromUtf8("image:url(:/subscribe.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;"));

        horizontalLayout_3->addWidget(subBT);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_1 = new QGroupBox(window6);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        gridLayout_4 = new QGridLayout(groupBox_1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        stateTB = new QTextBrowser(groupBox_1);
        stateTB->setObjectName(QString::fromUtf8("stateTB"));

        gridLayout_4->addWidget(stateTB, 0, 0, 1, 1);

        clearPB1 = new QPushButton(groupBox_1);
        clearPB1->setObjectName(QString::fromUtf8("clearPB1"));

        gridLayout_4->addWidget(clearPB1, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_1);

        groupBox_2 = new QGroupBox(window6);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        heartbeatTB = new QTextBrowser(groupBox_2);
        heartbeatTB->setObjectName(QString::fromUtf8("heartbeatTB"));

        gridLayout_2->addWidget(heartbeatTB, 0, 0, 1, 1);

        clearPB2 = new QPushButton(groupBox_2);
        clearPB2->setObjectName(QString::fromUtf8("clearPB2"));

        gridLayout_2->addWidget(clearPB2, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(window6);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        clearPB3 = new QPushButton(groupBox);
        clearPB3->setObjectName(QString::fromUtf8("clearPB3"));

        gridLayout->addWidget(clearPB3, 2, 0, 1, 1);

        receiveTB = new QTextBrowser(groupBox);
        receiveTB->setObjectName(QString::fromUtf8("receiveTB"));

        gridLayout->addWidget(receiveTB, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_4 = new QGroupBox(window6);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        sendTB = new QTextBrowser(groupBox_4);
        sendTB->setObjectName(QString::fromUtf8("sendTB"));

        gridLayout_3->addWidget(sendTB, 0, 0, 1, 1);

        clearPB4 = new QPushButton(groupBox_4);
        clearPB4->setObjectName(QString::fromUtf8("clearPB4"));

        gridLayout_3->addWidget(clearPB4, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(window6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 124));
        pushButton->setMaximumSize(QSize(1800, 124));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        pushButton->setStyleSheet(QString::fromUtf8("image:url(:/back.png);"));

        verticalLayout_2->addWidget(pushButton);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(window6);

        QMetaObject::connectSlotsByName(window6);
    } // setupUi

    void retranslateUi(QWidget *window6)
    {
        window6->setWindowTitle(QCoreApplication::translate("window6", "Form", nullptr));
        connectBT->setText(QCoreApplication::translate("window6", "\346\234\252\350\277\236\346\216\245", nullptr));
        subBT->setText(QCoreApplication::translate("window6", "\350\256\242\351\230\205", nullptr));
        groupBox_1->setTitle(QCoreApplication::translate("window6", "\347\212\266\346\200\201\346\230\276\347\244\272\346\241\206", nullptr));
        clearPB1->setText(QCoreApplication::translate("window6", "\346\270\205\347\251\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("window6", "\345\277\203\350\267\263\346\216\245\346\224\266\346\241\206", nullptr));
        clearPB2->setText(QCoreApplication::translate("window6", "\346\270\205\347\251\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("window6", "\346\266\210\346\201\257\346\216\245\346\224\266\346\241\206", nullptr));
        clearPB3->setText(QCoreApplication::translate("window6", "\346\270\205\347\251\272", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("window6", "\346\266\210\346\201\257\345\217\221\351\200\201\346\241\206", nullptr));
        clearPB4->setText(QCoreApplication::translate("window6", "\346\270\205\347\251\272", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class window6: public Ui_window6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW6_H
