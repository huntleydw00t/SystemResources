#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "htsystem.h"
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    //create slots for my memory and processor timers.
    void myRam();
    void myProc();


private slots:
    //create an event for when the quit button is pushed
    void on_pushButton_clicked();



private:
    //base items needed like UI windows, htSystem object, and QTimers.
    Ui::MainWindow *ui;
    htSystem mySys;
    QTimer *timerRam;
    QTimer *timerProc;



};
#endif // MAINWINDOW_H
