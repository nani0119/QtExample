#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      pOpenUrlButton(new QPushButton("打开网址")), pOpenUrlLineEdit(new QLineEdit),
      pOpenMailButton(new QPushButton("发送邮件")), pOpenMailLineEdit(new QLineEdit),
      pOpenTxtButton(new QPushButton("打开Txt文件")), pOpenTxtLineEdit(new QLineEdit),
      myHelpHandler(new MyHelpHandler)
{
    QFormLayout *layout = new QFormLayout;

    pOpenUrlLineEdit->setPlaceholderText("http://");
    pOpenTxtLineEdit->setPlaceholderText("/home/xxxx/xxx");
    connect(pOpenUrlButton, SIGNAL(clicked()),this, SLOT(onOpenUrl()));
    connect(pOpenMailButton, SIGNAL(clicked()),this, SLOT(onOpenMail()));
    connect(pOpenTxtButton, SIGNAL(clicked()),this, SLOT(onOpenTxt()));

    layout->addRow(pOpenUrlButton,pOpenUrlLineEdit);
    layout->addRow(pOpenMailButton,pOpenMailLineEdit);
    layout->addRow(pOpenTxtButton,pOpenTxtLineEdit);

    //指定自定义的处理方式，不适用系统默认
    QDesktopServices::setUrlHandler("mailto",myHelpHandler,"onHelpHandlerOpenMail");
    QDesktopServices::setUrlHandler("file",myHelpHandler,"onHelpHandlerOpenTxt");

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onOpenUrl()
{
    QDesktopServices::openUrl(QUrl(pOpenUrlLineEdit->text()));
}

void MainWindow::onOpenMail()
{
    QDesktopServices::openUrl(QUrl(QString("mailto:")+pOpenMailLineEdit->text()));
}

void MainWindow::onOpenTxt()
{
    QDesktopServices::openUrl(QUrl(QString("file:///")+pOpenTxtLineEdit->text()));
}


MyHelpHandler::MyHelpHandler(QObject *parent):QObject(parent)
{

}

MyHelpHandler::~MyHelpHandler()
{

}

void MyHelpHandler::onHelpHandlerOpenMail(QUrl url)
{
    qDebug() << __func__<<":"<<"custom operation";
    QDesktopServices::openUrl(url);
    // or other things
}

void MyHelpHandler::onHelpHandlerOpenTxt(QUrl url)
{
    qDebug() << __func__<<":"<<"custom operation";
    QDesktopServices::openUrl(url);
    // or other things
}
