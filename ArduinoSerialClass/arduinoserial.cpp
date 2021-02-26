#include "arduinoserial.h"
#include <QDebug>


ArduinoSerial::ArduinoSerial()
{
    this->getPortNames();
}

unsigned int ArduinoSerial::getPortNames(){
    uint8_t portcounter=1;
    foreach(QSerialPortInfo ports, QSerialPortInfo::availablePorts()){
        this->availablePortNames.name[portcounter-1]=ports.portName();
        this->availablePortNames.size=portcounter;
        //qDebug()<<this->availablePortNames.name[portcounter-1];
        portcounter++;
    }
    qDebug()<<this->availablePortNames.size;
    return 1;
}

bool ArduinoSerial::connect(){
    this->Port.setPortName(this->portname);
    this->Port.setBaudRate(QSerialPort::Baud9600);
    this->Port.setDataBits(QSerialPort::Data8);
    this->Port.setFlowControl(QSerialPort::NoFlowControl);
    this->Port.open(QSerialPort::ReadWrite);

    return true;
}
bool ArduinoSerial::disconnect(){

    return true;
}

packet  ArduinoSerial::read(){
    packet test;
    test.header=0;
    test.message=123;
    return test;
}
bool    ArduinoSerial::write(){
    return true;
}

void ArduinoSerial::readData(){

}
