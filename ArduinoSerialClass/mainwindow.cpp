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

    mySerialPort.getPortNames();
    ui->ports->clear();
    for(unsigned int i=0; i<mySerialPort.availablePortNames.size; i++)ui->ports->addItem(mySerialPort.availablePortNames.name[i]);

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

    if(mySerialPort.begin(selectedPortName)){
        ui->disconnectFromArduino->setEnabled(true);
        ui->connectToArduino->setEnabled(false);
        ui->ports->setEnabled(false);
        //connect(&mySerialPort.Port, SIGNAL(readyRead()), this, SLOT(mySerialPort.readData()));
    }
}

void MainWindow::on_ports_activated(const QString &arg1)
{

}

void MainWindow::on_send_clicked()
{
    mySerialPort.write(1453);
}

void MainWindow::on_disconnectFromArduino_clicked()
{
    if(mySerialPort.dead()){
        ui->disconnectFromArduino->setEnabled(false);
        ui->connectToArduino->setEnabled(true);
        ui->ports->setEnabled(true);
    }
}

void MainWindow::on_read_clicked()
{
    ui->incomingData->setText(QString::number(mySerialPort.read()));
}
