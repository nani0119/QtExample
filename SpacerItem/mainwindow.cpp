#include "mainwindow.h"
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;
    QSpacerItem *hSpacerItem = new QSpacerItem(100,20);
    QSpacerItem *vSpacerItem = new QSpacerItem(20,100);
    QLabel *pHLabel = new QLabel("HSpacerItem");
    QLabel *pVLabel = new QLabel("VSpacerItem");
    QLabel *pLabel = new QLabel("Label");

    hLayout->addItem(hSpacerItem);
    hLayout->addWidget(pHLabel);

    vLayout->addLayout(hLayout);


    QHBoxLayout *hLayout1 = new QHBoxLayout;

    hLayout1->addWidget(pLabel);

    QVBoxLayout *vLayout1 = new QVBoxLayout;
    vLayout1->addItem(vSpacerItem);
    vLayout1->addWidget(pVLabel);

    hLayout1->addLayout(vLayout1);
    vLayout->addLayout(hLayout1);


    QWidget *widget = new QWidget(this);
    widget->setLayout(vLayout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

