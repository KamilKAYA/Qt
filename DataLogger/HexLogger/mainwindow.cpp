#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

double  temperatures[10]={-10,-20,-18,-30,-40,-10,-20,-18,-30,-40};




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(refresh, SIGNAL(timeout()), this, SLOT(refreshFunction()));
    refresh->start(500);
    ui->setupUi(this);
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
}
