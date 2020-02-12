#include "MainWindow.h"
#include <QLabel>
#include <QCheckBox>
#include <QButtonGroup>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pButtonGroupLabel(new QLabel),
      pCheckBox1(new QCheckBox), pCheckBox2(new QCheckBox),
      pCheckBox3(new QCheckBox),pButtonGroup (new QButtonGroup())
{
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;

    pCheckBox1->setText("CheckBox1");
    pCheckBox1->setObjectName("CheckBox1");
    pCheckBox2->setText("CheckBox2");
    pCheckBox2->setObjectName("CheckBox2");
    pCheckBox3->setText("CheckBox3");
    pCheckBox3->setObjectName("CheckBox3");
    pCheckBox3->setTristate(true);
    connect(pCheckBox3,SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));


    pButtonGroup->addButton(pCheckBox1);
    pButtonGroup->addButton(pCheckBox2);
    pButtonGroup->addButton(pCheckBox3);
    pButtonGroup->setExclusive(false);
    connect(pButtonGroup,SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonClicked(QAbstractButton*)));

    vLayout->addWidget(pLabel);
    vLayout->addWidget(pButtonGroupLabel);
    hLayout->addWidget(pCheckBox1);
    hLayout->addWidget(pCheckBox2);
    hLayout->addWidget(pCheckBox3);
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

void MainWindow::onStateChanged(int state)
{
    if(state == Qt::CheckState::Checked)
    {
        pLabel->setText("CheckBox3 Checked");
    }
    else if(state == Qt::CheckState::Unchecked)
    {
        pLabel->setText("CheckBox3 UnChecked");
    }
    else if(pCheckBox3->isTristate()&&state == Qt::CheckState::PartiallyChecked)
    {
        pLabel->setText("CheckBox3 PartiallyChecked");
    }

}

void MainWindow::onButtonClicked(QAbstractButton *button)
{
    QString strText = button->text();
    Qt::CheckState status = Qt::CheckState::Unchecked;
    QList<QAbstractButton*> list = pButtonGroup->buttons();
    foreach(QAbstractButton *checkBox, list)
    {
        if(button == checkBox)
        {

            status =qobject_cast<QCheckBox*>(checkBox)->checkState();
        }
    }
    pButtonGroupLabel->setText(strText+":"+QString("%1").arg(status));
}

