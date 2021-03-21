/*
 * Kamil KAYA 2016
 *
 * Şimdi bu class ne işe yarıyor diye soranlarınız olabilir, bende kendime soruyorum merak etmeyin.
 * Şimdi hacılar biz seri portdan datayı öyle ascii olarak göndermiyoruz. neden mi? eğer ascii gönderirsek takibi kolay, veri boyutu buyük ve
 * karmaşık bir okuma sistemi gerekebilir. lakin eğer veriyi bir paket içerisinde gönderirsek daha güvenli ve daha doğru şekilde iletebiliriz.
 * bu bağlamda bizlerde bir paket oluşturuyourz. örneğin bir başlangıç işareti atıyoruz; 66,46,53 diye üç bytlık bir başlangıç işareti atıyoruz.
 * ondan sonra verilerimizi ve eğer var ise kontrol ve başlık bilgilerini ekliyoruz. sonuna da doğrulama crc ve kapanış bytlerini ekliyoruz ve
 * paketi kapatıyoruz.
 *
 * İşin gerçeği bu kod arduino için değil daha çok diğer gömülü chipler için örneğin stm32fxxx veya diğerleri için daha çok işinize yarayabilir.
 * çünkü arduino da zaten kolay bir haberleşme methodu var.
 *
 */


#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QString>
#include <QByteArray>

struct HexLoggerData{
    //| Başlangıç işareti | kanal sayısı | zaman | data büyüklüğü | data |
    uint8_t  activeChannel;
    uint8_t dataSize;
    uint32_t time;
    short int tempSensor[10];
    bool     available;
};

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
    HexLoggerData HextioData;
public:
    availablePorts  availablePortNames; // Bu yapı içerisinde 2 adet tipi barındırmaktadır, bunlardan biri string array diğeri de unsigned int.
                                        // Bu iki yapının string olanına port isimleri diğer int olanına da kaç adet port bulunduğunu yazmaktadır,
                                        // örnek verecek olursak, myport.availablePortNames.size; veya myport.availablePortNames.name[3]; gibi.
    ArduinoSerial();                    // constructor fonksiyon
    unsigned int getPortNames();        // port isimlerini alan fonksiyon
    bool begin(QString portname);       // bağlantı fonksiyonudur. uygun port isimi girilerek bağlantı sağlanır.
    bool dead();                        // bağlantıyı koparan fonksiyondur. Aslında destructor oluşturulup onun içine de yerleştirilebilinir.
    QSerialPort Port;                   // burdan aslında donanıma erişen değişkendir, gerekli port ayarlamalarını buradan yapacağız. hız vs.
    HexLoggerData  read();                   // en şekilli fonksiyondur, olmasaydı okuyamazdık.
    bool    write(uint16_t data);       // en şekillinin yarı şekilli olan fonksiyonudur, yazmaya yarar.
private slots:
    void readData();                    // gelen sinyalden bağlanılan slot dur.
};

#endif // ARDUINOSERIAL_H
