#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduinoserial.h"
#include <QDebug>

ArduinoSerial mySerialPort;

void getPortNames();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mySerialPort.getPortNames();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listPorts_clicked()
{
    mySerialPort.getPortNames();
    ui->ports->clear();
    for(unsigned int i=0; i<mySerialPort.availablePortNames.size; i++)ui->ports->addItem(mySerialPort.availablePortNames.name[i]);
}

void MainWindow::on_connectToArduino_clicked()
{
    QString selectedPortName=ui->ports->itemText(ui->ports->currentIndex());

    mySerialPort.Port.setPortName(selectedPortName);
    mySerialPort.connect();
}

void MainWindow::on_ports_activated(const QString &arg1)
{

}

void MainWindow::on_send_clicked()
{
    mySerialPort.write();
}
