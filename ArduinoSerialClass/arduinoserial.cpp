#include "arduinoserial.h"
#include <QDebug>

ArduinoSerial::ArduinoSerial()
{

    this->getPortNames();
    this->startSignature[0]=255;    // Başlangıç işaretlerini verir
    this->startSignature[1]=53;     //
    this->startSignature[2]=128;    //

    this->packetSize=5;     //  Toplam gidecek paketin boyutunu belirler (byte).

    qDebug()<<"Class cagrildi.";
}

unsigned int ArduinoSerial::getPortNames(){
    uint8_t portcounter=1;
    foreach(QSerialPortInfo ports, QSerialPortInfo::availablePorts()){
        this->availablePortNames.name[portcounter-1]=ports.portName();
        this->availablePortNames.size=portcounter;
        portcounter++;
    }
    return portcounter-1;
}

void ArduinoSerial::readData(){
    qDebug()<<"readData";
    QByteArray myIncomingData;
    myIncomingData=this->Port.readAll();
    qDebug()<<myIncomingData.size();
    for(int i=0; i<myIncomingData.size(); i++)qDebug()<<QString::number((uint8_t)myIncomingData.at(i));
    if((uint8_t)myIncomingData.at(0)==this->startSignature[0] &&  (uint8_t)myIncomingData.at(1)==this->startSignature[1]    &&  (uint8_t)myIncomingData.at(2)==this->startSignature[2]){
        this->incomingDataUint16_t=0;
        this->incomingDataUint16_t=myIncomingData.at(3);
        this->incomingDataUint16_t=(this->incomingDataUint16_t<<8)&0xff00;
        this->incomingDataUint16_t=this->incomingDataUint16_t|(myIncomingData.at(4)&0x00ff);

        qDebug()<<"Giris Basarili";
    }
}

bool ArduinoSerial::begin(QString portname){
    this->Port.setPortName(portname);
    this->Port.setBaudRate(QSerialPort::Baud9600);
    this->Port.setDataBits(QSerialPort::Data8);
    this->Port.setFlowControl(QSerialPort::NoFlowControl);
    this->Port.open(QSerialPort::ReadWrite);
    connect(&this->Port, SIGNAL(readyRead()), this, SLOT(readData()));
    return true;
}
bool ArduinoSerial::dead(){
    this->Port.close();
    return true;
}

uint16_t  ArduinoSerial::read(){
    qDebug()<<this->incomingDataUint16_t;
    return this->incomingDataUint16_t;
}

bool    ArduinoSerial::write(uint16_t data){
    uint8_t sendData[2];
    sendData[0]=data&0x00FF;
    sendData[1]=(data>>8)&0x00FF;
    for(int i=0; i<3; i++)this->Port.write((char *)this->startSignature[i]);
    for(int i=3; i<this->packetSize; i++)this->Port.write((char *)sendData[i]);
    return true;
}


