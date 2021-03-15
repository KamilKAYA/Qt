#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace std;

double  temperatures[10]={-10,-20,-18,-30,-40,-10,-20,-18,-30,-40};

QPen    redPen(Qt::red);
QPen    bluePen(Qt::blue);
QPen    blackPen(Qt::black);
QPen    greenPen(Qt::green);
QPen    yellowPen(Qt::yellow);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->heightOfGraph=600;
    this->widthOfGraph=1000;
    this->gridPenWidth=1;
    this->linePenWidth=2;
    this->refreshTime=100;  //milisecond
    this->timeStep=1000;     // tarama hızı milisecond
    this->tempStep=20;
    this->gridSize=60;

    scane = new QGraphicsScene(this);
    ui->graphicsView->setScene(scane);


    scane->clear();

    drawGrid();

    connect(refresh, SIGNAL(timeout()), this, SLOT(refreshFunction()));
    refresh->start(this->refreshTime);

}

double old_temperatures[10]={300};

void MainWindow::drawLine(){
    static int time=-(this->widthOfGraph/2);
    static int old_time=-(this->widthOfGraph/2);

    redPen.setWidth(this->linePenWidth);
    bluePen.setWidth(this->linePenWidth);
    blackPen.setWidth(this->linePenWidth);
    greenPen.setWidth(this->linePenWidth);
    yellowPen.setWidth(this->linePenWidth);

    time+=(this->gridSize)*100/this->timeStep;

    redLine = scane->addLine(old_time,-3*old_temperatures[0],time,-3*temperatures[0],redPen);
    blueLine = scane->addLine(old_time,-3*old_temperatures[1],time,-3*temperatures[1],bluePen);
    blackLine = scane->addLine(old_time,-3*old_temperatures[2],time,-3*temperatures[2],blackPen);
    greenLine = scane->addLine(old_time,-3*old_temperatures[3],time,-3*temperatures[3],greenPen);
    yellowLine = scane->addLine(old_time,-3*old_temperatures[4],time,-3*temperatures[4],yellowPen);

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
    blackPen.setWidth(this->gridPenWidth);
    int x_min=-(this->widthOfGraph/2);
    int x_max=(this->widthOfGraph/2);
    int y_min=-(this->heightOfGraph/2);
    int y_max=(this->heightOfGraph/2);

    int temperatureLabel=(this->heightOfGraph/this->gridSize)*(this->tempStep/2);

    for(int i=y_min; i<y_max; i=i+this->gridSize){
        blackLine = scane->addLine(x_min,i,x_max,i);
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

        blackLine = scane->addLine(i,y_min,i,y_max);
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

    for(int i=0; i<10; i++){
        temperatures[i]=temperatures[i]+0.1;
    }

    ui->item_display_1->display(temperatures[0]);
    ui->item_display_2->display(temperatures[1]);
    ui->item_display_3->display(temperatures[2]);
    ui->item_display_4->display(temperatures[3]);
    ui->item_display_5->display(temperatures[4]);
    ui->item_display_6->display(temperatures[5]);
    ui->item_display_7->display(temperatures[6]);
    ui->item_display_8->display(temperatures[7]);
    ui->item_display_9->display(temperatures[8]);
    ui->item_display_11->display(temperatures[9]);

    drawLine();

}

void MainWindow::on_scaleBar_valueChanged(int value)
{
    this->timeStep=ui->scaleBar->value();
    ui->timeScaleLabel->setText("Örnekleme aralığı: "+QString::number(this->timeStep)+" ms");
    scane->clear();
    drawGrid();
}
