#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace std;

double kalibrasyonKatsayisi=1.0;

QPen   gridPen(QColor(200, 200, 200));
QPen   myPens[10]={ QColor(255, 126, 121),
                    QColor(255, 147, 0),
                    QColor(148, 17, 0),
                    QColor(255, 251, 0),
                    QColor(0, 249, 0),
                    QColor(0, 143, 0),
                    QColor(115, 253, 255),
                    QColor(4, 51, 255),
                    QColor(255, 133, 255),
                    QColor(148, 23, 81)};

ArduinoSerial FPGA_Serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->heightOfGraph=600;
    this->widthOfGraph=1020;
    this->gridPenWidth=1;
    this->linePenWidth=2;
    this->refreshTime=100;  //milisecond
    this->timeStep=100;     // tarama hızı milisecond
    this->tempStep=20;
    this->gridSize=60;


    scane = new QGraphicsScene(this);
    ui->graphicsView->setScene(scane);


    scane->clear();

    drawGrid();

    connect(refresh, SIGNAL(timeout()), this, SLOT(refreshFunction()));


    connect(getPortTimer, SIGNAL(timeout()), this, SLOT(automaticPortConnection()));
    getPortTimer->start(1000);

}

double old_temperatures[10]={300};

void MainWindow::drawLine(uint32_t timex, double  temperatures[10]){
    static int time=-(this->widthOfGraph/2);
    static int old_time=-(this->widthOfGraph/2);

    for(int i=0; i<10; i++)myPens[i].setWidth(this->linePenWidth);


    time+=(this->gridSize)*100/this->timeStep;

    for(int i=0; i<10; i++)graphLine[i] = scane->addLine(old_time,-3*old_temperatures[i],time,-3*temperatures[i],myPens[i]);

    old_time=time;

    //qDebug()<<time;

    if(time>(this->widthOfGraph/2)){
        time=-(this->widthOfGraph/2);
        old_time=-(this->widthOfGraph/2);
        scane->clear();
        drawGrid();
    }

    for(int i=0; i<10; i++){
        old_temperatures[i]=temperatures[i];
    }
}

void MainWindow::drawGrid(){
    gridPen.setWidth(this->gridPenWidth);
    int x_min=-(this->widthOfGraph/2);
    int x_max=(this->widthOfGraph/2);
    int y_min=-(this->heightOfGraph/2);
    int y_max=(this->heightOfGraph/2);

    int temperatureLabel=(this->heightOfGraph/this->gridSize)*(this->tempStep/2);

    for(int i=y_min; i<y_max; i=i+this->gridSize){
        gridLine = scane->addLine(x_min,i,x_max,i);
        tempText = scane->addText(QString::number(temperatureLabel)+" °C");
        temperatureLabel-=this->tempStep;
        tempText->setPos(x_min,i);
        //qDebug()<<temperatureLabel;

    }

    static uint32_t progressTime=0;
    QString value="";
    for(int i=x_min; i<x_max; i=i+this->gridSize){

        if(progressTime>999 && progressTime<60000){
            value=QString::number((progressTime/1000.0),'f',1)+" s";
        }else if(progressTime>59999){
            value=QString::number(progressTime/60000)+" d";
        }else{
            value=QString::number(progressTime)+" ms";
        }

        gridLine = scane->addLine(i,y_min,i,y_max);
        tempText = scane->addText(value);
        progressTime+=this->timeStep;

        tempText->setPos(i,(y_max-20));
        //qDebug()<<temperatureLabel;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::refreshFunction(){
    HexLoggerData myData=FPGA_Serial.read();
    double temps[10]={0.0};
    for(int i=0; i<myData.activeChannel; i++)temps[i]=myData.tempSensor[i]*kalibrasyonKatsayisi;
    ui->item_display_1->display(temps[0]);
    ui->item_display_2->display(temps[1]);
    ui->item_display_3->display(temps[2]);
    ui->item_display_4->display(temps[3]);
    ui->item_display_5->display(temps[4]);
    ui->item_display_6->display(temps[5]);
    ui->item_display_7->display(temps[6]);
    ui->item_display_8->display(temps[7]);
    ui->item_display_9->display(temps[8]);
    ui->item_display_11->display(temps[9]);

    drawLine(myData.time, temps);
    ui->reelTimeTrig->setText("Zaman:"+(QString::number(myData.time*100))+" ms");
    //qDebug()<<myData.time;

}

void MainWindow::automaticPortConnection(){
    static uint8_t portItem, old_portItem=0;
    static QString oldPortName="";


    if(FPGA_Serial.read().available){
        getPortTimer->stop();
        refresh->start(this->refreshTime);
        ui->connectionStatusLabel->setText("Bağlantı Durumu: Bağlandı.");
        ui->progressBar->setValue(FPGA_Serial.availablePortNames.size);
    }else{

        if(oldPortName.size()>0)FPGA_Serial.dead();

        ui->progressBar->setMaximum(FPGA_Serial.availablePortNames.size);
        ui->progressBar->setValue(portItem);
        portItem++;

        if (portItem==FPGA_Serial.availablePortNames.size   ||  FPGA_Serial.availablePortNames.size==0){
            portItem=0;
            old_portItem=255;
        }
        if(portItem==0)FPGA_Serial.getPortNames();


        //for(unsigned int i=0; i<FPGA_Serial.availablePortNames.size; i++)qDebug()<<(FPGA_Serial.availablePortNames.name[i]);
        //qDebug()<<portItem;

        if(old_portItem!=portItem   && FPGA_Serial.availablePortNames.size!=0){
            FPGA_Serial.begin(FPGA_Serial.availablePortNames.name[portItem]);
            oldPortName=FPGA_Serial.availablePortNames.name[portItem];
        }

        ui->connectionStatusLabel->setText("Bağlantı Durumu: Aranıyor.");
        ui->connectionPortName->setText("Port: "+FPGA_Serial.availablePortNames.name[portItem]);

        old_portItem=portItem;
    }
}

void MainWindow::on_scaleBar_valueChanged(int value)
{
    this->timeStep=ui->scaleBar->value();
    ui->timeScaleLabel->setText("Örnekleme aralığı: "+QString::number(this->timeStep)+" ms");
    scane->clear();
    drawGrid();
}
