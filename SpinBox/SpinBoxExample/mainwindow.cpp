#include "mainwindow.h"
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pSpinBox(new QSpinBox), pDoubleSpinBox(new QDoubleSpinBox)
{
    QVBoxLayout *laybox = new QVBoxLayout;

    laybox->addWidget(pLabel);

    pSpinBox->setRange(0,200);
    pSpinBox->setSingleStep(10);
    pSpinBox->setPrefix("$");
    pSpinBox->setSuffix("%");
    pSpinBox->setSpecialValueText("Automatic");
    laybox->addWidget(pSpinBox);
    connect(pSpinBox, SIGNAL(valueChanged(const QString&)), this, SLOT(onValueChanged(const QString&)));
    connect(pSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onValueChanged(int)));


    pDoubleSpinBox->setRange(0,3);
    pDoubleSpinBox->setDecimals(3);
    pDoubleSpinBox->setSingleStep(0.005);
    laybox->addWidget(pDoubleSpinBox);

    QWidget* widget = new QWidget(this);
    widget->setLayout(laybox);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onValueChanged(const QString &text)
{
    qDebug()<<__func__<<":QString";
    pLabel->clear();
    QString str = "Text　Value:" + text + "\n";
    str += "Clean Value" + pSpinBox->cleanText()+ "\n";
    pLabel->setText(str);

}

void MainWindow::onValueChanged(int value)
{
    qDebug()<<__func__<<"int";
    QString str = pLabel->text();
    qDebug()<<__func__<<"int:"<<str;
    str += QString("Value:%1\n").arg(value) + "Text:" + pSpinBox->text() + "\n";
    pLabel->setText(str);

}

