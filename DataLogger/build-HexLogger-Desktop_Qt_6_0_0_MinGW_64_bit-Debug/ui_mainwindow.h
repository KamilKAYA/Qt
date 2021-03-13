/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *temperatures;
    QFrame *item_frame;
    QLCDNumber *item_display_1;
    QLabel *item_label_1;
    QFrame *item_frame_2;
    QLCDNumber *item_display_2;
    QLabel *item_label_2;
    QFrame *item_frame_3;
    QLCDNumber *item_display_3;
    QLabel *item_label_3;
    QFrame *item_frame_4;
    QLCDNumber *item_display_4;
    QLabel *item_label_4;
    QFrame *item_frame_5;
    QLCDNumber *item_display_5;
    QLabel *item_label_5;
    QFrame *item_frame_6;
    QLCDNumber *item_display_6;
    QLabel *item_label_6;
    QFrame *item_frame_7;
    QLCDNumber *item_display_7;
    QLabel *item_label_7;
    QFrame *item_frame_8;
    QLCDNumber *item_display_8;
    QLabel *item_label_8;
    QFrame *item_frame_9;
    QLCDNumber *item_display_9;
    QLabel *item_label_9;
    QFrame *item_frame_10;
    QLCDNumber *item_display_11;
    QLabel *item_label_11;
    QFrame *item_title_frame;
    QLabel *item_title_label;
    QLabel *item_title_label_2;
    QFrame *graphics;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1278, 732);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        temperatures = new QFrame(centralwidget);
        temperatures->setObjectName(QString::fromUtf8("temperatures"));
        temperatures->setGeometry(QRect(10, 10, 211, 681));
        temperatures->setFrameShape(QFrame::StyledPanel);
        temperatures->setFrameShadow(QFrame::Raised);
        item_frame = new QFrame(temperatures);
        item_frame->setObjectName(QString::fromUtf8("item_frame"));
        item_frame->setGeometry(QRect(10, 50, 181, 61));
        item_frame->setFrameShape(QFrame::StyledPanel);
        item_frame->setFrameShadow(QFrame::Raised);
        item_display_1 = new QLCDNumber(item_frame);
        item_display_1->setObjectName(QString::fromUtf8("item_display_1"));
        item_display_1->setGeometry(QRect(40, 10, 141, 41));
        item_display_1->setAutoFillBackground(false);
        item_display_1->setFrameShape(QFrame::Box);
        item_display_1->setFrameShadow(QFrame::Plain);
        item_display_1->setSmallDecimalPoint(false);
        item_display_1->setDigitCount(5);
        item_display_1->setProperty("value", QVariant(1.000000000000000));
        item_display_1->setProperty("intValue", QVariant(1));
        item_label_1 = new QLabel(item_frame);
        item_label_1->setObjectName(QString::fromUtf8("item_label_1"));
        item_label_1->setGeometry(QRect(0, 10, 31, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        item_label_1->setFont(font);
        item_label_1->setAlignment(Qt::AlignCenter);
        item_frame_2 = new QFrame(temperatures);
        item_frame_2->setObjectName(QString::fromUtf8("item_frame_2"));
        item_frame_2->setGeometry(QRect(10, 110, 181, 61));
        item_frame_2->setFrameShape(QFrame::StyledPanel);
        item_frame_2->setFrameShadow(QFrame::Raised);
        item_display_2 = new QLCDNumber(item_frame_2);
        item_display_2->setObjectName(QString::fromUtf8("item_display_2"));
        item_display_2->setGeometry(QRect(40, 10, 141, 41));
        item_display_2->setAutoFillBackground(false);
        item_display_2->setFrameShape(QFrame::Box);
        item_display_2->setFrameShadow(QFrame::Plain);
        item_display_2->setSmallDecimalPoint(false);
        item_display_2->setDigitCount(5);
        item_display_2->setProperty("value", QVariant(38.500000000000000));
        item_label_2 = new QLabel(item_frame_2);
        item_label_2->setObjectName(QString::fromUtf8("item_label_2"));
        item_label_2->setGeometry(QRect(0, 10, 31, 41));
        item_label_2->setFont(font);
        item_label_2->setAlignment(Qt::AlignCenter);
        item_frame_3 = new QFrame(temperatures);
        item_frame_3->setObjectName(QString::fromUtf8("item_frame_3"));
        item_frame_3->setGeometry(QRect(10, 170, 181, 61));
        item_frame_3->setFrameShape(QFrame::StyledPanel);
        item_frame_3->setFrameShadow(QFrame::Raised);
        item_display_3 = new QLCDNumber(item_frame_3);
        item_display_3->setObjectName(QString::fromUtf8("item_display_3"));
        item_display_3->setGeometry(QRect(40, 10, 141, 41));
        item_display_3->setAutoFillBackground(false);
        item_display_3->setFrameShape(QFrame::Box);
        item_display_3->setFrameShadow(QFrame::Plain);
        item_display_3->setSmallDecimalPoint(false);
        item_display_3->setDigitCount(5);
        item_display_3->setProperty("value", QVariant(38.500000000000000));
        item_label_3 = new QLabel(item_frame_3);
        item_label_3->setObjectName(QString::fromUtf8("item_label_3"));
        item_label_3->setGeometry(QRect(0, 10, 31, 41));
        item_label_3->setFont(font);
        item_label_3->setAlignment(Qt::AlignCenter);
        item_frame_4 = new QFrame(temperatures);
        item_frame_4->setObjectName(QString::fromUtf8("item_frame_4"));
        item_frame_4->setGeometry(QRect(10, 230, 181, 61));
        item_frame_4->setFrameShape(QFrame::StyledPanel);
        item_frame_4->setFrameShadow(QFrame::Raised);
        item_display_4 = new QLCDNumber(item_frame_4);
        item_display_4->setObjectName(QString::fromUtf8("item_display_4"));
        item_display_4->setGeometry(QRect(40, 10, 141, 41));
        item_display_4->setAutoFillBackground(false);
        item_display_4->setFrameShape(QFrame::Box);
        item_display_4->setFrameShadow(QFrame::Plain);
        item_display_4->setSmallDecimalPoint(false);
        item_display_4->setDigitCount(5);
        item_display_4->setProperty("value", QVariant(38.500000000000000));
        item_label_4 = new QLabel(item_frame_4);
        item_label_4->setObjectName(QString::fromUtf8("item_label_4"));
        item_label_4->setGeometry(QRect(0, 10, 31, 41));
        item_label_4->setFont(font);
        item_label_4->setAlignment(Qt::AlignCenter);
        item_frame_5 = new QFrame(temperatures);
        item_frame_5->setObjectName(QString::fromUtf8("item_frame_5"));
        item_frame_5->setGeometry(QRect(10, 290, 181, 61));
        item_frame_5->setFrameShape(QFrame::StyledPanel);
        item_frame_5->setFrameShadow(QFrame::Raised);
        item_display_5 = new QLCDNumber(item_frame_5);
        item_display_5->setObjectName(QString::fromUtf8("item_display_5"));
        item_display_5->setGeometry(QRect(40, 10, 141, 41));
        item_display_5->setAutoFillBackground(false);
        item_display_5->setFrameShape(QFrame::Box);
        item_display_5->setFrameShadow(QFrame::Plain);
        item_display_5->setSmallDecimalPoint(false);
        item_display_5->setDigitCount(5);
        item_display_5->setProperty("value", QVariant(38.500000000000000));
        item_label_5 = new QLabel(item_frame_5);
        item_label_5->setObjectName(QString::fromUtf8("item_label_5"));
        item_label_5->setGeometry(QRect(0, 10, 31, 41));
        item_label_5->setFont(font);
        item_label_5->setAlignment(Qt::AlignCenter);
        item_frame_6 = new QFrame(temperatures);
        item_frame_6->setObjectName(QString::fromUtf8("item_frame_6"));
        item_frame_6->setGeometry(QRect(10, 350, 181, 61));
        item_frame_6->setFrameShape(QFrame::StyledPanel);
        item_frame_6->setFrameShadow(QFrame::Raised);
        item_display_6 = new QLCDNumber(item_frame_6);
        item_display_6->setObjectName(QString::fromUtf8("item_display_6"));
        item_display_6->setGeometry(QRect(40, 10, 141, 41));
        item_display_6->setAutoFillBackground(false);
        item_display_6->setFrameShape(QFrame::Box);
        item_display_6->setFrameShadow(QFrame::Plain);
        item_display_6->setSmallDecimalPoint(false);
        item_display_6->setDigitCount(5);
        item_display_6->setProperty("value", QVariant(38.500000000000000));
        item_label_6 = new QLabel(item_frame_6);
        item_label_6->setObjectName(QString::fromUtf8("item_label_6"));
        item_label_6->setGeometry(QRect(0, 10, 31, 41));
        item_label_6->setFont(font);
        item_label_6->setAlignment(Qt::AlignCenter);
        item_frame_7 = new QFrame(temperatures);
        item_frame_7->setObjectName(QString::fromUtf8("item_frame_7"));
        item_frame_7->setGeometry(QRect(10, 410, 181, 61));
        item_frame_7->setFrameShape(QFrame::StyledPanel);
        item_frame_7->setFrameShadow(QFrame::Raised);
        item_display_7 = new QLCDNumber(item_frame_7);
        item_display_7->setObjectName(QString::fromUtf8("item_display_7"));
        item_display_7->setGeometry(QRect(40, 10, 141, 41));
        item_display_7->setAutoFillBackground(false);
        item_display_7->setFrameShape(QFrame::Box);
        item_display_7->setFrameShadow(QFrame::Plain);
        item_display_7->setSmallDecimalPoint(false);
        item_display_7->setDigitCount(5);
        item_display_7->setProperty("value", QVariant(38.500000000000000));
        item_label_7 = new QLabel(item_frame_7);
        item_label_7->setObjectName(QString::fromUtf8("item_label_7"));
        item_label_7->setGeometry(QRect(0, 10, 31, 41));
        item_label_7->setFont(font);
        item_label_7->setAlignment(Qt::AlignCenter);
        item_frame_8 = new QFrame(temperatures);
        item_frame_8->setObjectName(QString::fromUtf8("item_frame_8"));
        item_frame_8->setGeometry(QRect(10, 470, 181, 61));
        item_frame_8->setFrameShape(QFrame::StyledPanel);
        item_frame_8->setFrameShadow(QFrame::Raised);
        item_display_8 = new QLCDNumber(item_frame_8);
        item_display_8->setObjectName(QString::fromUtf8("item_display_8"));
        item_display_8->setGeometry(QRect(40, 10, 141, 41));
        item_display_8->setAutoFillBackground(false);
        item_display_8->setFrameShape(QFrame::Box);
        item_display_8->setFrameShadow(QFrame::Plain);
        item_display_8->setSmallDecimalPoint(false);
        item_display_8->setDigitCount(5);
        item_display_8->setProperty("value", QVariant(38.500000000000000));
        item_label_8 = new QLabel(item_frame_8);
        item_label_8->setObjectName(QString::fromUtf8("item_label_8"));
        item_label_8->setGeometry(QRect(0, 10, 31, 41));
        item_label_8->setFont(font);
        item_label_8->setAlignment(Qt::AlignCenter);
        item_frame_9 = new QFrame(temperatures);
        item_frame_9->setObjectName(QString::fromUtf8("item_frame_9"));
        item_frame_9->setGeometry(QRect(10, 530, 181, 61));
        item_frame_9->setFrameShape(QFrame::StyledPanel);
        item_frame_9->setFrameShadow(QFrame::Raised);
        item_display_9 = new QLCDNumber(item_frame_9);
        item_display_9->setObjectName(QString::fromUtf8("item_display_9"));
        item_display_9->setGeometry(QRect(40, 10, 141, 41));
        item_display_9->setAutoFillBackground(false);
        item_display_9->setFrameShape(QFrame::Box);
        item_display_9->setFrameShadow(QFrame::Plain);
        item_display_9->setSmallDecimalPoint(false);
        item_display_9->setDigitCount(5);
        item_display_9->setProperty("value", QVariant(38.500000000000000));
        item_label_9 = new QLabel(item_frame_9);
        item_label_9->setObjectName(QString::fromUtf8("item_label_9"));
        item_label_9->setGeometry(QRect(0, 10, 31, 41));
        item_label_9->setFont(font);
        item_label_9->setAlignment(Qt::AlignCenter);
        item_frame_10 = new QFrame(temperatures);
        item_frame_10->setObjectName(QString::fromUtf8("item_frame_10"));
        item_frame_10->setGeometry(QRect(10, 590, 181, 61));
        item_frame_10->setFrameShape(QFrame::StyledPanel);
        item_frame_10->setFrameShadow(QFrame::Raised);
        item_display_11 = new QLCDNumber(item_frame_10);
        item_display_11->setObjectName(QString::fromUtf8("item_display_11"));
        item_display_11->setGeometry(QRect(40, 10, 141, 41));
        item_display_11->setAutoFillBackground(false);
        item_display_11->setFrameShape(QFrame::Box);
        item_display_11->setFrameShadow(QFrame::Plain);
        item_display_11->setSmallDecimalPoint(false);
        item_display_11->setDigitCount(5);
        item_display_11->setProperty("value", QVariant(38.500000000000000));
        item_label_11 = new QLabel(item_frame_10);
        item_label_11->setObjectName(QString::fromUtf8("item_label_11"));
        item_label_11->setGeometry(QRect(0, 10, 31, 41));
        item_label_11->setFont(font);
        item_label_11->setAlignment(Qt::AlignCenter);
        item_title_frame = new QFrame(temperatures);
        item_title_frame->setObjectName(QString::fromUtf8("item_title_frame"));
        item_title_frame->setGeometry(QRect(10, 10, 181, 41));
        item_title_frame->setFrameShape(QFrame::StyledPanel);
        item_title_frame->setFrameShadow(QFrame::Raised);
        item_title_label = new QLabel(item_title_frame);
        item_title_label->setObjectName(QString::fromUtf8("item_title_label"));
        item_title_label->setGeometry(QRect(0, 0, 51, 41));
        item_title_label->setFont(font);
        item_title_label->setAlignment(Qt::AlignCenter);
        item_title_label_2 = new QLabel(item_title_frame);
        item_title_label_2->setObjectName(QString::fromUtf8("item_title_label_2"));
        item_title_label_2->setGeometry(QRect(60, 0, 121, 41));
        item_title_label_2->setFont(font);
        item_title_label_2->setAlignment(Qt::AlignCenter);
        graphics = new QFrame(centralwidget);
        graphics->setObjectName(QString::fromUtf8("graphics"));
        graphics->setGeometry(QRect(230, 10, 1041, 681));
        graphics->setFrameShape(QFrame::StyledPanel);
        graphics->setFrameShadow(QFrame::Raised);
        graphicsView = new QGraphicsView(graphics);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 30, 1000, 600));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(1000, 600));
        graphicsView->setMaximumSize(QSize(1000, 600));
        graphicsView->setAcceptDrops(true);
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1278, 21));
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
        item_label_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        item_label_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        item_label_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        item_label_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        item_label_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        item_label_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        item_label_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        item_label_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        item_label_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        item_label_11->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        item_title_label->setText(QCoreApplication::translate("MainWindow", "Ch", nullptr));
        item_title_label_2->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
