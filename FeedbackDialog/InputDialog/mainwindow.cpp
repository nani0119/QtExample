#include "mainwindow.h"
#include <QInputDialog>
#include <QEvent>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pInputDialog(new QInputDialog)
{

    MyInputDialog *myInputDialog = new MyInputDialog;
    connect(myInputDialog, SIGNAL(accepted()), this, SLOT(onMyInputDialogAccepted()));
    myInputDialog->exec();


    pInputDialog->setLabelText("输入姓名");
    pInputDialog->setOkButtonText("确定");
    pInputDialog->setCancelButtonText("取消");
    pInputDialog->setTextEchoMode(QLineEdit::EchoMode::Normal);
    pInputDialog->setInputMode(QInputDialog::TextInput);
    pInputDialog->setWindowTitle("输入对话框");
    connect(pInputDialog, SIGNAL(textValueChanged(const QString&)),this, SLOT(onTextValueChanged(const QString&)));

    pInputDialog->show();
    connect(pInputDialog, SIGNAL(accepted()), this, SLOT(onAccepted()));
    connect(pInputDialog, SIGNAL(rejected()), this, SLOT(onRejected()));
    connect(pInputDialog, SIGNAL(finished(int)), this, SLOT(onFinished(int)));



//    bool ok;
//    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
//                                 tr("Percentage:"), 25, 0, 100, 1, &ok);
//    if (ok)
//    {
//        QMessageBox::information(nullptr,"info",
//                                 QString("value:%1").arg(i),
//                                 QMessageBox::Yes|QMessageBox::No,
//                                 QMessageBox::Yes);
//    }

//    QStringList items;
//    items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

//    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
//                                         tr("Season:"), items, 0, false, &ok);
//    if (ok && !item.isEmpty())
//    {
//        QMessageBox::information(nullptr,"info",
//                                 item,
//                                 QMessageBox::Yes|QMessageBox::No,
//                                 QMessageBox::Yes);
//    }

}

MainWindow::~MainWindow()
{

}

void MainWindow::onTextValueChanged(const QString &text)
{
    qDebug()<<__func__<<": text:"<<text;
}

void MainWindow::onAccepted()
{
    qDebug()<<__func__;
    QMessageBox::information(nullptr,"info",
                             pInputDialog->textValue(),
                             QMessageBox::Yes|QMessageBox::No,
                             QMessageBox::Yes);
}

void MainWindow::onRejected()
{
    qDebug()<<__func__;
    QMessageBox::information(nullptr,"info",
                             "cannel",
                             QMessageBox::Yes|QMessageBox::No,
                             QMessageBox::Yes);
}

void MainWindow::onFinished(int r)
{
    qDebug()<<__func__<<" : result " << r;
}

void MainWindow::onMyInputDialogAccepted()
{
    qDebug()<<__func__;
}


MyInputDialog::MyInputDialog(QWidget *parent): QInputDialog(parent)
{

}

MyInputDialog::~MyInputDialog()
{

}

void MyInputDialog::done(int r)
{
    qDebug()<<"MyInputDialog  "<< __func__<<"  "<<r;
    emit finished(r);
    QInputDialog::done(r);
}

void MyInputDialog::accept()
{
    qDebug()<<"MyInputDialog  " <<__func__;
    emit accepted();
    QInputDialog::accept();
}

void MyInputDialog::reject()
{
    qDebug()<<"MyInputDialog  " <<__func__;
    emit rejected();
    QInputDialog::reject();
}
