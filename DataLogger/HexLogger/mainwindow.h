#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "arduinoserial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawGrid();
    void drawLine(uint32_t time, double  temperatures[10]);

    QTimer *refresh = new QTimer(this);
    QTimer *getPortTimer = new QTimer(this);

private:
    uint8_t linePenWidth;
    uint8_t gridPenWidth;
    uint8_t gridSize;
    uint16_t timeStep;
    uint8_t tempStep;
    uint16_t refreshTime;
    uint16_t heightOfGraph;
    uint16_t widthOfGraph;
    Ui::MainWindow *ui;
    QGraphicsScene *scane;
    QGraphicsTextItem   *timeText;
    QGraphicsTextItem   *tempText;
    QGraphicsLineItem   *graphLine[10];
    QGraphicsLineItem   *gridLine;


public slots:
    void refreshFunction();
    void automaticPortConnection();
private slots:
    void on_scaleBar_valueChanged(int value);
};
#endif // MAINWINDOW_H
