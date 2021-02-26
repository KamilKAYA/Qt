#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduinoserial.h"
#include <QDebug>

ArduinoSerial mySerialPort;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ArduinoSerial Teleskop;

    QString test[Teleskop.availablePortNames.size];
    for(unsigned int i=0; i<Teleskop.availablePortNames.size; i++){
        test[i]=Teleskop.availablePortNames.name[i];
        qDebug()<<test[i];
    }

    connect(&mySerialPort.Port, SIGNAL(readyRead()), this, SLOT(mySerialPort.readData()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

