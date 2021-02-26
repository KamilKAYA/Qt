#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>

struct packet{
    uint8_t header;
    uint16_t    message;
};

struct availablePorts{
    QString name[50];
    unsigned int size;
};

class ArduinoSerial : public QObject
{
    Q_OBJECT
private:

public:
    availablePorts  availablePortNames;
    QString portname;
    ArduinoSerial();
    unsigned int getPortNames();
    bool connect();
    bool disconnect();
    QSerialPort Port;
    packet  read();
    bool    write();
public slots:
    void readData();
};

#endif // ARDUINOSERIAL_H
