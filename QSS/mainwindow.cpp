#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    onStyleChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStyleChanged(int index)
{
    qDebug()<<__func__<<" : "<<index;
    QString path = QString("style%1.qss").arg(index);
    qDebug()<<__func__<<" path: "<<path;
    QFile qssFile(path);
    bool ok = qssFile.open(QIODevice::ReadOnly);
    if(ok != true)
    {
        qDebug()<<__func__<<" "<<"open "<< path<< " fail";
    }
    QTextStream textString(&qssFile);
    QString qss = textString.readAll();
    qDebug()<<__func__<<" qss:" <<qss;
    setStyleSheet(qss);

}

