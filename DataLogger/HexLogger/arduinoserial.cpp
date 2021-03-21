#include "arduinoserial.h"
#include <QDebug>

ArduinoSerial::ArduinoSerial()
{

    this->getPortNames();
    this->startSignature[0]=255;    // Başlangıç işaretlerini verir
    this->startSignature[1]=0;     //
    this->startSignature[2]=127;    //

    this->packetSize=29;     //  Toplam gidecek paketin boyutunu belirler (byte).

    this->HextioData.available=false;

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
    //qDebug()<<"readData";
    QByteArray myIncomingData=this->Port.readAll();

    if(19<myIncomingData.size()){
        try {
            if((uint8_t)myIncomingData.at(0)==this->startSignature[0] &&  (uint8_t)myIncomingData.at(1)==this->startSignature[1]    &&  (uint8_t)myIncomingData.at(2)==this->startSignature[2]){
                this->HextioData.activeChannel=myIncomingData.at(3);
                this->HextioData.time=0x00;
                this->HextioData.time=(myIncomingData.at(4)<<24)&0xff000000;
                this->HextioData.time|=(myIncomingData.at(5)<<16)&0x00ff0000;
                this->HextioData.time|=(myIncomingData.at(6)<<8)&0x0000ff00;
                this->HextioData.time|=myIncomingData.at(7)&0x000000ff;

                qDebug()<<this->HextioData.time;

                this->HextioData.dataSize=myIncomingData.at(8);

                for(int i=0; i<this->HextioData.activeChannel; i++){
                    if(this->HextioData.dataSize==1){
                        HextioData.tempSensor[i]=myIncomingData.at(9+i);
                    }else if(this->HextioData.dataSize==2){
                        uint8_t index=9+(i*2);
                        HextioData.tempSensor[i]=(myIncomingData.at(index)<<8)&0xff00;
                        HextioData.tempSensor[i]|=myIncomingData.at(index+1);
                    }
                }

            //this->incomingDataUint16_t=0;
            //this->incomingDataUint16_t=myIncomingData.at(3);
            //this->incomingDataUint16_t=(this->incomingDataUint16_t<<8)&0xff00;
            //this->incomingDataUint16_t=this->incomingDataUint16_t|(myIncomingData.at(4)&0x00ff);
            this->HextioData.available=true;
            //qDebug()<<"Giris Basarili";
            }else this->HextioData.available=false;

        }  catch (int x) {
            //qDebug()<<"okuyamadı.";
            this->HextioData.available=false;
        }

    }

}
bool ArduinoSerial::begin(QString portname){
    this->Port.setPortName(portname);
    this->Port.setBaudRate(QSerialPort::Baud9600);
    this->Port.setDataBits(QSerialPort::Data8);
    this->Port.setFlowControl(QSerialPort::NoFlowControl);
    try {
        qDebug()<<"Serial baglanti "+portname+" ile denendi";
        this->Port.open(QSerialPort::ReadWrite);
        connect(&this->Port, SIGNAL(readyRead()), this, SLOT(readData()));
        return true;
    }  catch (int test) {
        qDebug()<<" hata ile döndü";
        return false;
    }



}
bool ArduinoSerial::dead(){
    qDebug()<<"port kapatıldı.";
    this->Port.close();
    return true;
}

HexLoggerData  ArduinoSerial::read(){

    return HextioData;
}

bool    ArduinoSerial::write(uint16_t data){
    uint8_t sendData[2];
    sendData[0]=data&0x00FF;
    sendData[1]=(data>>8)&0x00FF;
    for(int i=0; i<3; i++)this->Port.write((char *)this->startSignature[i]);
    for(int i=3; i<this->packetSize; i++)this->Port.write((char *)sendData[i]);
    return true;
}


