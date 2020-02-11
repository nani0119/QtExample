#include "MainWindow.h"
#include <QPushButton>
#include <QMenu>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QLabel>
#include <QActionGroup>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pPushButton(new QPushButton),pLable(new QLabel), pActionGroup(new QActionGroup(this))
{

    QMenu *pMenu = new QMenu(this);


    QAction *pSubAction1 = new QAction;
    QAction *pSubAction2 = new QAction;
    QAction *pSubAction3 = new QAction;

    pSubAction1->setText("SubAction1");
    pSubAction2->setText("SubAction2");
    pSubAction3->setText("SubAction3");
    pSubAction1->setCheckable(true);
    pSubAction2->setCheckable(true);
    pSubAction3->setCheckable(true);

    pActionGroup->addAction(pSubAction1);
    pActionGroup->addAction(pSubAction2);
    pActionGroup->addAction(pSubAction3);


    QMenu *pSubMenu = new QMenu();
    pSubMenu->addAction(pSubAction1);
    pSubMenu->addAction(pSubAction2);
    pSubMenu->addAction(pSubAction3);
    pSubMenu->setTitle("子菜单");

    connect(pActionGroup, SIGNAL(triggered(QAction *)), this, SLOT(onSubAction(QAction *)));
    pMenu->addMenu(pSubMenu);



    QAction *quit = new QAction;
    quit->setText("退出");
    quit->setShortcut(QKeySequence::Quit);
    pMenu->addAction(quit);
    connect(quit, SIGNAL(triggered()), this, SLOT(close()));

    pPushButton->setText("主菜单");
    QFile file(":/qss/main.qss");
    file.open(QFile::ReadOnly);
    QTextStream fileText(&file);
    QString qss = fileText.readAll();
    qDebug()<<"qss:"<<qss;
    pPushButton->setStyleSheet(qss);
    file.close();
    pPushButton->setMenu(pMenu);


    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(pPushButton);

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    vBoxLayout->addWidget(pLable);
    vBoxLayout->addLayout(hLayout);


    QWidget *widget = new QWidget(this);
    widget->setLayout(vBoxLayout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onSubAction(QAction *action)
{
    pLable->setText(action->text());
}

