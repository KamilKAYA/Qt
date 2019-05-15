#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QFrame>


QGraphicsScene *scene;
QFrame *dial;
QGraphicsProxyWidget *w;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *rotationTimer = new QTimer(this);
    connect(rotationTimer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    rotationTimer->start(50);



}

void MainWindow::timerUpdate(){
    static int rotation=0;
    static bool direction=false;
    if(rotation>70)direction=true;
    if(rotation==0)direction=false;

    if(direction==false)    rotation =rotation+1;
    else     rotation =rotation-1;
    QString s = QString::number(rotation);

    setSpeedValue(rotation);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSpeedValue(int speed){
    /*
    QGraphicsScene *scene = new QGraphicsScene(this);
    QFrame *dial = new QFrame();
    dial->setGeometry(0,0,400,28);
    dial->setStyleSheet("background-image: url(:/images/images/dial.png);"
                        "background-repeat: none;"
                        "background-color:transparent;");


    QGraphicsProxyWidget *w = scene->addWidget(dial);
    */
    //ui->speedValue->setText(speed);
    speed=(speed*2.5)-41;
    scene = new QGraphicsScene(this);
    QFrame *dial = new QFrame();
    dial->setGeometry(0,0,400,28);
    dial->setStyleSheet("background-image: url(:/images/images/dial.png);"
                        "background-repeat: none;"
                        "background-color:transparent;");
    w = scene->addWidget(dial);
    w->setPos(0, 0);
    w->setRotation(speed);
    ui->speed->setScene(scene);
}
