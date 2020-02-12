#include "MainWindow.h"
#include <QLabel>
#include <QAbstractButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QFile>
#include <QTextStream>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel),pRadioLabel(new QLabel),
      pRadioButton1(new QRadioButton),pRadioButton2(new QRadioButton),
      pRadioButton3(new QRadioButton), pButtonGroup(new QButtonGroup)
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;

    pRadioButton1->setText("RadioButton1");
    pRadioButton2->setText("RadioButton2");
    pRadioButton2->setObjectName("RadioButton2");
    pRadioButton3->setText("RadioButton3");
    connect(pRadioButton3, SIGNAL(toggled(bool)), this, SLOT(onToggled(bool)));

    pButtonGroup->addButton(pRadioButton1);
    pButtonGroup->addButton(pRadioButton2);
    pButtonGroup->addButton(pRadioButton3);
    pButtonGroup->setExclusive(true);
    connect(pButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonClicked(QAbstractButton*)));

    hLayout->addWidget(pRadioButton1);
    hLayout->addWidget(pRadioButton2);
    hLayout->addWidget(pRadioButton3);

    vLayout->addWidget(pLabel);
    vLayout->addWidget(pRadioLabel);
    vLayout->addLayout(hLayout);

    QFile qssFile(":/qss/main.qss");
    qssFile.open(QFile::ReadOnly);
    QTextStream qssText(&qssFile);
    QString qss = qssText.readAll();
    setStyleSheet(qss);
    qssFile.close();

    QWidget *widget = new QWidget(this);
    widget->setLayout(vLayout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onToggled(bool checked)
{
    if(checked)
    {
        pRadioLabel->setText("RadioButton3 checked");
    }
    else
    {
        pRadioLabel->setText("RadioButton3 unChecked");
    }
}

void MainWindow::onButtonClicked(QAbstractButton *button)
{
    QList<QAbstractButton*> list = pButtonGroup->buttons();
    foreach(QAbstractButton* radioButton, list)
    {
        if(radioButton == button)
        {
            pLabel->setText(button->text() + " " + "checked");
        }
    }
}

