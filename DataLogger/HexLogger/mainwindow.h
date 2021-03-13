#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *refresh = new QTimer(this);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scane;
    QGraphicsLineItem   *blackLine;
    QGraphicsLineItem   *redLine;
    QGraphicsLineItem   *blueLine;
    QGraphicsLineItem   *yellowLine;
    QGraphicsLineItem   *greenLine;


public slots:
    void refreshFunction();
};
#endif // MAINWINDOW_H
