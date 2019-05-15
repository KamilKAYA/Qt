#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void timerUpdate();

private:
    Ui::MainWindow *ui;
    void setSpeedValue(int);
};

#endif // MAINWINDOW_H
