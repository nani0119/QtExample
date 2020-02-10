#include "MainWindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pLabel(new QLabel), pLCDNumber(new QLCDNumber), pLayout(new QHBoxLayout()), pTimer(new QTimer(this))
{
    pLabel->setText("DateTime:");
    pLabel->setBuddy(pLCDNumber);
    pLayout->addWidget(pLabel);

    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    int dateTimeSize = dateTime.size();
    qDebug() << "dateTime"<<dateTime<<"\ndateTimeSize:" << dateTimeSize;
    //设置所显示的位数
    pLCDNumber->setDigitCount(dateTimeSize);
    //以十进制形式显示
    pLCDNumber->setMode(QLCDNumber::Dec);
    //改变现实数字的外观
    pLCDNumber->setSegmentStyle(QLCDNumber::Flat);
    pLCDNumber->setStyleSheet("border: 1px solid green; color: green; background: silver;");

    pLCDNumber->display(dateTime);
    pLayout->addWidget(pLCDNumber);



    pTimer->setInterval(1000);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    pTimer->start();

    connect(pLCDNumber, SIGNAL(overflow()), this, SLOT(onOverflow()));

    QWidget* pWidget = new QWidget(this);
    pWidget->setLayout(pLayout);
    setCentralWidget(pWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onOverflow()
{
    qDebug()<<"onOverflow";
}

void MainWindow::onTimeOut()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    pLCDNumber->display(dateTime.toString("yyyy-MM-dd HH:mm:ss"));
}

