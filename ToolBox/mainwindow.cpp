#include "mainwindow.h"
#include <QToolBox>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pToolBox(new QToolBox), pLabel(new QLabel)
{
    QLabel *pLabel1 = new QLabel;
    pLabel1->setText("测试1");
    QLabel *pLabel2 = new QLabel;
    pLabel2->setText("测试2");

    QLabel *pLabel3 = new QLabel;
    pLabel3->setText("测试3");
    QLabel *pLabel4 = new QLabel;
    pLabel4->setText("测试4");

    QLabel *pLabel5 = new QLabel;
    pLabel5->setText("测试5");
    QLabel *pLabel6 = new QLabel;
    pLabel6->setText("测试6");

    QLabel *pLabel7 = new QLabel;
    pLabel7->setText("测试7");
    QLabel *pLabel8 = new QLabel;
    pLabel7->setText("测试8");

    QVBoxLayout *vBoxLayout1 = new QVBoxLayout;
    vBoxLayout1->addWidget(pLabel1);
    vBoxLayout1->addWidget(pLabel2);

    QGroupBox *pGroupBox1 = new QGroupBox;
    pGroupBox1->setLayout(vBoxLayout1);
    pGroupBox1->setObjectName("GroupBox1");


    QVBoxLayout *vBoxLayout2 = new QVBoxLayout;
    vBoxLayout2->addWidget(pLabel3);
    vBoxLayout2->addWidget(pLabel4);

    QGroupBox *pGroupBox2 = new QGroupBox;
    pGroupBox2->setLayout(vBoxLayout2);
    pGroupBox2->setObjectName("GroupBox2");


    QVBoxLayout *vBoxLayout3 = new QVBoxLayout;
    vBoxLayout3->addWidget(pLabel5);
    vBoxLayout3->addWidget(pLabel6);

    QGroupBox *pGroupBox3 = new QGroupBox;
    pGroupBox3->setLayout(vBoxLayout3);
    pGroupBox3->setObjectName("GroupBox3");

    QVBoxLayout *vBoxLayout4 = new QVBoxLayout;
    vBoxLayout4->addWidget(pLabel7);
    vBoxLayout4->addWidget(pLabel8);

    QGroupBox *pGroupBox4 = new QGroupBox;
    pGroupBox4->setLayout(vBoxLayout4);
    pGroupBox4->setObjectName("GroupBox4");


    pToolBox->addItem(pGroupBox1,"GroupBox1");
    pToolBox->addItem(pGroupBox2,"GroupBox2");
    pToolBox->addItem(pGroupBox3,"GroupBox3");
    pToolBox->addItem(pGroupBox4,"GroupBox4");
    pToolBox->setMinimumWidth(150);
    connect(pToolBox, SIGNAL(currentChanged(int)), this, SLOT(onCurrentChanged(int)));

    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    hBoxLayout->addWidget(pToolBox);
    QString labelText = "";
    labelText += QString("count: %1\n").arg(pToolBox->count());
    labelText += QString("current Index: %1\n").arg(pToolBox->currentIndex());
    labelText += QString("current widget: %1\n").arg(pToolBox->currentWidget()->objectName());
    pLabel->setText(labelText);
    hBoxLayout->addWidget(pLabel);


    QWidget *widget = new QWidget(this);
    widget->setLayout(hBoxLayout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onCurrentChanged(int index)
{
    QString strText = "";
    strText += QString("ToolBox Current Index: %1\n").arg(index);
    QWidget* widget = pToolBox->widget(index);
    strText += QString("current widget: %1\n").arg(widget->objectName());
    strText += QString("current Index: %1\n").arg(pToolBox->indexOf(widget));
    pLabel->setText(strText);
}

