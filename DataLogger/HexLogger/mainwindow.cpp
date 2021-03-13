#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    scane = new QGraphicsScene(this);
    ui->graphicsView->setScene(scane);



    redPen.setWidth(2);
    bluePen.setWidth(2);
    blackPen.setWidth(2);
    greenPen.setWidth(2);
    yellowPen.setWidth(2);


    scane->clear();


    connect(refresh, SIGNAL(timeout()), this, SLOT(refreshFunction()));
    refresh->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int x_line=-500;
double old_temperatures[10]={300};

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

    redLine = scane->addLine(x_line,old_temperatures[0]*10,x_line+1,temperatures[0]*10,redPen);
    blueLine = scane->addLine(x_line,old_temperatures[1]*10,x_line+1,temperatures[1]*10,bluePen);
    blackLine = scane->addLine(x_line,old_temperatures[2]*10,x_line+1,temperatures[2]*10,blackPen);
    greenLine = scane->addLine(x_line,old_temperatures[3]*10,x_line+1,temperatures[3]*10,greenPen);
    yellowLine = scane->addLine(x_line,old_temperatures[4]*10,x_line+1,temperatures[4]*10,yellowPen);
    x_line+=10;
    if(x_line>500){
        x_line=-500;
        scane->clear();
    }

    for(int i=0; i<10; i++){
        old_temperatures[i]=temperatures[i];
    }

}
