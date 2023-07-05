/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB1;
    QPushButton *PB2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *PB3;
    QPushButton *PB4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB5;
    QPushButton *PB6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 1200);
        QFont font;
        font.setPointSize(17);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow{border-image:url(:/background.jpg)}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setStyleSheet(QString::fromUtf8("border-image:url(:/background.jpg);"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(124, 188, 231);"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PB1 = new QPushButton(centralwidget);
        PB1->setObjectName(QString::fromUtf8("PB1"));
        PB1->setMinimumSize(QSize(0, 248));
        PB1->setMaximumSize(QSize(16777215, 372));
        PB1->setStyleSheet(QString::fromUtf8("image:url(:/but1.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;\n"
"background-color:rgb(199,237,204);"));

        horizontalLayout->addWidget(PB1);

        PB2 = new QPushButton(centralwidget);
        PB2->setObjectName(QString::fromUtf8("PB2"));
        PB2->setMinimumSize(QSize(0, 248));
        PB2->setStyleSheet(QString::fromUtf8("image:url(:/but2.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;\n"
"background-color:rgb(199,237,204);\n"
""));

        horizontalLayout->addWidget(PB2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PB3 = new QPushButton(centralwidget);
        PB3->setObjectName(QString::fromUtf8("PB3"));
        PB3->setMinimumSize(QSize(0, 248));
        PB3->setStyleSheet(QString::fromUtf8("image:url(:/but3.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;\n"
"background-color:rgb(199,237,204);"));

        horizontalLayout_2->addWidget(PB3);

        PB4 = new QPushButton(centralwidget);
        PB4->setObjectName(QString::fromUtf8("PB4"));
        PB4->setMinimumSize(QSize(0, 248));
        PB4->setStyleSheet(QString::fromUtf8("image:url(:/but4.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;\n"
"background-color:rgb(199,237,204);"));

        horizontalLayout_2->addWidget(PB4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PB5 = new QPushButton(centralwidget);
        PB5->setObjectName(QString::fromUtf8("PB5"));
        PB5->setMinimumSize(QSize(0, 248));
        PB5->setStyleSheet(QString::fromUtf8("image:url(:/but5.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;\n"
"background-color:rgb(199,237,204);"));

        horizontalLayout_3->addWidget(PB5);

        PB6 = new QPushButton(centralwidget);
        PB6->setObjectName(QString::fromUtf8("PB6"));
        PB6->setMinimumSize(QSize(0, 248));
        PB6->setStyleSheet(QString::fromUtf8("image:url(:/but6.png);\n"
"image-position: left;\n"
"text-align:right;\n"
"padding-left:30px;\n"
"padding-right:30px;\n"
"background-color:rgb(199,237,204);"));

        horizontalLayout_3->addWidget(PB6);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\237\272\344\272\216\351\276\231\350\212\257\346\264\276\347\232\204\347\211\251\350\201\224\347\275\221\344\273\223\345\202\250\347\263\273\347\273\237", nullptr));
        PB1->setText(QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271\346\246\202\350\247\210", nullptr));
        PB2->setText(QCoreApplication::translate("MainWindow", "\344\274\240\346\204\237\346\225\260\346\215\256", nullptr));
        PB3->setText(QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271\347\275\221\347\273\234", nullptr));
        PB4->setText(QCoreApplication::translate("MainWindow", "\347\224\265\351\207\217\344\277\241\346\201\257", nullptr));
        PB5->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\344\277\241\346\201\257", nullptr));
        PB6->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
