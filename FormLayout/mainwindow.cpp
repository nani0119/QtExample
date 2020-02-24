#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pFormLayout(new QFormLayout)
{
    QHBoxLayout *layout = new QHBoxLayout;

    QLabel *usr = new QLabel();
    QPixmap pixmap = QPixmap();
    pixmap.load(":/img/usr");
    pixmap = pixmap.scaled(80,80);
    usr->setPixmap(pixmap);

    layout->addWidget(usr);

    QLabel *name = new QLabel("用户名");
    QLineEdit *nameLineEdit = new QLineEdit;
    pFormLayout->addRow(name, nameLineEdit);

    QLabel *passwd = new QLabel("密码");
    QLineEdit *passwdLineEdit = new QLineEdit;
    passwdLineEdit->setEchoMode(QLineEdit::Password);
    pFormLayout->addRow(passwd, passwdLineEdit);

    layout->addLayout(pFormLayout);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);


}

MainWindow::~MainWindow()
{
}

