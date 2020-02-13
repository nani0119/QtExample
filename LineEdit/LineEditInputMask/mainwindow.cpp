#include "mainwindow.h"
#include <QLineEdit>
#include <QLabel>

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pIPLineEdit(new QLineEdit),pMACLineEdit(new QLineEdit),pDateLineEdit(new QLineEdit),pLicenseLineEdit(new QLineEdit)
{
    QGridLayout *layout = new QGridLayout;
    QLabel* pIPLable = new QLabel("IP address:");
    pIPLable->setBuddy(pIPLineEdit);
    pIPLineEdit->setInputMask("000.000.000.000;_");
    pIPLineEdit->setFrame(false);
    layout->addWidget(pIPLable,0,0);
    layout->addWidget(pIPLineEdit,0,1);

    QLabel* pMACLabel = new QLabel("MAC address:");
    pMACLabel->setBuddy(pMACLineEdit);
    pMACLineEdit->setInputMask("HH:HH:HH:HH:HH:HH;_");
    pMACLineEdit->setFrame(false);
    layout->addWidget(pMACLabel,1,0);
    layout->addWidget(pMACLineEdit,1,1);


    QLabel* pDateLabel = new QLabel("Date:");
    pDateLabel->setBuddy(pDateLineEdit);
    pDateLineEdit->setInputMask("0000-00-00");
    pDateLineEdit->setFrame(false);
    layout->addWidget(pDateLabel,2,0);
    layout->addWidget(pDateLineEdit,2,1);

    QLabel* pLicenseLabel = new QLabel("License:");
    pLicenseLabel->setBuddy(pLicenseLineEdit);
    pLicenseLineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
    pLicenseLineEdit->setFrame(false);
    layout->addWidget(pLicenseLabel,3,0);
    layout->addWidget(pLicenseLineEdit,3,1);

    layout->addWidget(pIPLineEdit);
    layout->addWidget(pMACLineEdit);
    layout->addWidget(pDateLineEdit);
    layout->addWidget(pLicenseLineEdit);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{

}

