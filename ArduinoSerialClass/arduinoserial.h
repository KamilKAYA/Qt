#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QString>

struct availablePorts{
    QString name[50];
    unsigned int size;
};

class ArduinoSerial : public QObject
{
    Q_OBJECT
private:
    uint8_t packetSize;
    uint8_t startSignature[3];
    uint16_t incomingDataUint16_t;
public:
    availablePorts  availablePortNames; // bu tamamlandı.
    ArduinoSerial();
    unsigned int getPortNames();
    bool begin(QString portname);
    bool dead();
    QSerialPort Port;
    uint16_t  read();
    bool    write(uint16_t data);
private slots:
    void readData();
};

#endif // ARDUINOSERIAL_H
