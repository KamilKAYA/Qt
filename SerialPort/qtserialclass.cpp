#include "qtserialclass.h"


QtSerialClass::QtSerialClass()
{

}

QtSerialClass::~QtSerialClass(){
    this->SerialPort->disconnect();
}

bool QtSerialClass::Connect(){
    this->SerialPort->setPortName(this->PortName);
    this->SerialPort->open(QSerialPort::ReadOnly);
    this->SerialPort->setBaudRate(QSerialPort::Baud9600);
    this->SerialPort->setDataBits(QSerialPort::Data8);
    this->SerialPort->setFlowControl(QSerialPort::NoFlowControl);
    this->SerialPort->setParity(QSerialPort::NoParity);
    this->SerialPort->setStopBits(QSerialPort::OneStop);
    if(this->SerialPort->isOpen())return true;
    else return false;
}

bool QtSerialClass::Disconnect(){
    this->SerialPort->disconnect();
    if(this->SerialPort->isOpen())return false;
    else return true;
}

void QtSerialClass::ReadSerial(){
    ...
}
