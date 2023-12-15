#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->lblRamT->setText(QString().asprintf("Total Ram: %5.1f GB", mySys.memTGB()));
    ui->lblOs->setText(QString().asprintf("OS Name: %s", mySys.osPull().c_str()));
    ui->lblKern->setText(QString().asprintf("Linux Kernel: %s", mySys.kernPull().c_str()));
    ui->lblHostn->setText(QString().asprintf("Hostname: %s", mySys.hostPull().c_str()));
    ui->lblMail->setText("<a href='mailto:dj@huntleyweb.com'>Email Me</a>");
    ui->lblMail->setOpenExternalLinks(true);
    ui->lblMail->show();
    ui->pgbRam->setMinimum(0);
    ui->pgbRam->setMaximum(mySys.memTGB());
    timerRam = new QTimer(this);
    timerProc = new QTimer(this);
    connect(timerRam,SIGNAL(timeout()),this,SLOT(myRam()));
    connect(timerProc,SIGNAL(timeout()),this,SLOT(myProc()));
    timerRam->start(100);
    timerProc->start(10);

}

MainWindow::~MainWindow()
{


    delete ui;
}

void MainWindow::myRam()
{
    ui->pgbRam->setValue(mySys.memUGB());
    ui->lblRamU->setText(QString().asprintf("Ram Used: %5.1f GB", mySys.memUGB()));
    ui->lblRamF->setText(QString().asprintf("Ram Free: %5.1f GB", mySys.memFGB()));
}

void MainWindow::myProc()
{
    ui->lblProcu->setText(QString().asprintf("CPU Usage: %3.2f%", mySys.cpuUse()));
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

