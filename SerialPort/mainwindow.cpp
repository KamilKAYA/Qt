#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtserialclass.h"

QtSerialClass mySerialPort;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mySerialPort.PortName="COM4";
    mySerialPort.BaudRate=9600;
}

MainWindow::~MainWindow()
{
    delete ui;
}
