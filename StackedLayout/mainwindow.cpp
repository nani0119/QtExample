#include "mainwindow.h"
#include <QStackedLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pStackedLayout(new QStackedLayout)
{
    QLabel *lable1 = new QLabel("label1");
    lable1->setPixmap(QPixmap(":/img/1"));
    firstLabel = lable1;
    QLabel *lable2 = new QLabel("label2");
    lable2->setPixmap(QPixmap(":/img/2"));
    QLabel *lable3 = new QLabel("label3");
    lable3->setPixmap(QPixmap(":/img/3"));
    QLabel *lable4 = new QLabel("label4");
    lable4->setPixmap(QPixmap(":/img/4"));
    QLabel *lable5 = new QLabel("label5");
    lable5->setPixmap(QPixmap(":/img/5"));
    lastLabel = lable5;

    pStackedLayout->addWidget(lable1);
    pStackedLayout->addWidget(lable2);
    pStackedLayout->addWidget(lable3);
    pStackedLayout->addWidget(lable4);
    pStackedLayout->addWidget(lable5);
    connect(pStackedLayout, SIGNAL(currentChanged(int)), this, SLOT(onStackedLayoutCurrentChanged(int)));

    QGridLayout *layout = new QGridLayout;

    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    hBoxLayout->addStretch();
    hBoxLayout->addLayout(pStackedLayout);
    hBoxLayout->addStretch();

    layout->addLayout(hBoxLayout, 0, 0, 1, 4);


    QPushButton *firstButton = new QPushButton("first label");
    layout->addWidget(firstButton,1,0);
    QPushButton *previousButton = new QPushButton("previous label");
    layout->addWidget(previousButton,1,1);
    QPushButton *nextButton = new QPushButton("next label");
    layout->addWidget(nextButton,1,2);
    QPushButton *lastButton = new QPushButton("last label");
    layout->addWidget(lastButton,1,3);

    connect(firstButton, SIGNAL(clicked()), this, SLOT(onFirstButtonClick()));
    connect(lastButton, SIGNAL(clicked()), this, SLOT(onLastButtonClick()));
    connect(previousButton, SIGNAL(clicked()), this, SLOT(onPreviousClick()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(onNextButtonClick()));



    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onStackedLayoutCurrentChanged(int index)
{
    QLabel *label = qobject_cast<QLabel*>(pStackedLayout->currentWidget());
    qDebug()<<__func__<<":"<<"current index " << index <<" label text " << label->text();
}

void MainWindow::onFirstButtonClick()
{
    pStackedLayout->setCurrentWidget(firstLabel);
}

void MainWindow::onLastButtonClick()
{
    pStackedLayout->setCurrentWidget(lastLabel);
}

void MainWindow::onPreviousClick()
{
    int currentIndex = pStackedLayout->currentIndex();
    int count = pStackedLayout->count();
    currentIndex--;
     if(currentIndex < 0)
    {
        currentIndex = count - 1;
    }
    pStackedLayout->setCurrentIndex(currentIndex);
}

void MainWindow::onNextButtonClick()
{
    int currentIndex = pStackedLayout->currentIndex();
    int count = pStackedLayout->count();
    currentIndex++;
    if(currentIndex == count)
    {
        currentIndex = 0;
    }
    pStackedLayout->setCurrentIndex(currentIndex);
}

