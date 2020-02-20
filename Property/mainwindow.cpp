#include "mainwindow.h"
#include <QDateEdit>
#include <QDate>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pDateEdit(new QDateEdit)
{

    pDateEdit->setDisplayFormat("yyyy-MM-dd");
    pDateEdit->setDate(QDate::currentDate());


    connect(this, SIGNAL(myDateChanged(QString)), this, SLOT(onDateMainWindowChanged(QString)));
    connect(this, SIGNAL(dateTextChanged(QString)), this, SLOT(onDateTextChanged(QString)));
    connect(pDateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(onDateChanged(QDate)));


    setCentralWidget(pDateEdit);
}

MainWindow::~MainWindow()
{
}

QString MainWindow::myDate()
{
    return dateStr;
}

void MainWindow::setMyDate(QString date)
{
    dateStr = date;
    setProperty("dateText", date);
    emit myDateChanged(dateStr);
}

void MainWindow::unsetMyDate()
{
    dateStr = "0000/00/00";
}

void MainWindow::onDateChanged(QDate date)
{
    QString str = date.toString("yyyy/MM/dd");
    setMyDate(str);
}

void MainWindow::onDateMainWindowChanged(QString date)
{
    qDebug()<<__func__<<":"<<date;
}

void MainWindow::onDateTextChanged(QString date)
{
    qDebug()<<__func__<<":"<<date;
    qDebug()<<__func__<<" m_date:"<<m_date;
    qDebug()<<__func__<<"property():"<<property("dateText").toString();
}

