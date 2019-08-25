#ifndef QTSERIALCLASS_H
#define QTSERIALCLASS_H
#include <qstring.h>
#include <QSerialPort>
#include <QSerialPortInfo>

class QtSerialClass
{
private:
    QSerialPort *SerialPort;
    QByteArray   SerialIncomingData;
public:
    unsigned int BaudRate;
    QString PortName;
    QtSerialClass();
    ~QtSerialClass();
    bool Connect();
    bool Disconnect();
    void ReadSerial();

};

#endif // QTSERIALCLASS_H
