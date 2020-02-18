#include "mainwindow.h"
#include <QLabel>
#include <QKeySequenceEdit>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pKeySequenceEdit(new QKeySequenceEdit)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);

    layout->addWidget(pKeySequenceEdit);
    connect(pKeySequenceEdit, SIGNAL(editingFinished()), this, SLOT(onEditingFinished()));
    connect(pKeySequenceEdit, SIGNAL(keySequenceChanged(const QKeySequence&)), this, SLOT(onKeySequenceChanged(const QKeySequence&)));

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onEditingFinished()
{
    qDebug()<<__func__<<":"<<pKeySequenceEdit->keySequence().toString();
}

void MainWindow::onKeySequenceChanged(const QKeySequence &keySeq)
{
    QString str = QString("count:%1\n").arg(keySeq.count());
    str += "key seq: " + keySeq.toString();
    pLabel->setText(str);
}

