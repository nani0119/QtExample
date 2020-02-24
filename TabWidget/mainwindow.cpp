#include "mainwindow.h"
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollArea>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pTabWidget(new QTabWidget), pScrollArea(new QScrollArea),pMainPanelScrollAreaWidget(new QWidget),
      pLoginScrollAreaWidget(new QWidget)
{

    QListWidget *basicSetting = new QListWidget;

    mainPanel = new QListWidgetItem("主面板");

    QCheckBox *noAds = new QCheckBox("不显示广告");
    QVBoxLayout *vMainPanelLayout = new QVBoxLayout;
    vMainPanelLayout->addWidget(noAds);
    pMainPanelScrollAreaWidget->setLayout(vMainPanelLayout);
    pScrollArea->setWidget(pMainPanelScrollAreaWidget);

    basicSetting->addItem(mainPanel);



    login = new QListWidgetItem("登录");
    QCheckBox *bootWhenStart = new QCheckBox("开机启动");
    QVBoxLayout *vLoginLayout = new QVBoxLayout;
    vLoginLayout->addWidget(bootWhenStart);
    pLoginScrollAreaWidget->setLayout(vLoginLayout);


    basicSetting->addItem(login);

    QHBoxLayout *hMainPanelLayout = new QHBoxLayout;
    hMainPanelLayout->addWidget(basicSetting);
    hMainPanelLayout->addWidget(pScrollArea,1);
    connect(basicSetting, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListWidgetItemClicked(QListWidgetItem*)));

    //pTabWidget->setLayout(hMainPanelLayout);
    QWidget *basicSettingWidget = new QWidget();
    basicSettingWidget->setLayout(hMainPanelLayout);
    pTabWidget->addTab(basicSettingWidget, "基本设置");





    QListWidget *secSetting = new QListWidget;
    QListWidgetItem *passwd = new QListWidgetItem("密码");
    QListWidgetItem *lock = new QListWidgetItem("密码锁");
    secSetting->addItem(passwd);
    secSetting->addItem(lock);

    pTabWidget->addTab(secSetting, "安全设置");



    pTabWidget->setTabPosition(QTabWidget::North);
    pTabWidget->setMovable(true);
    //pTabWidget->setTabsClosable(true);

    connect(pTabWidget,SIGNAL(currentChanged(int)), this, SLOT(onTabWidgetCurrentChanged(int)));
    connect(pTabWidget,SIGNAL(tabBarClicked(int)), this, SLOT(onTabWidgetTabBarClicked(int)));
    connect(pTabWidget,SIGNAL(tabBarDoubleClicked(int)), this, SLOT(onTabWidgetTabBarDoubleClicked(int)));
    connect(pTabWidget,SIGNAL(tabCloseRequested(int)), this, SLOT(onTabWidgettabCloseRequested(int)));

    setCentralWidget(pTabWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onTabWidgetCurrentChanged(int index)
{
    qDebug() << __func__<<":"<<index;
}

void MainWindow::onTabWidgetTabBarClicked(int index)
{
    qDebug() << __func__<<":"<<index;
}

void MainWindow::onTabWidgetTabBarDoubleClicked(int index)
{
    qDebug() << __func__<<":"<<index;
}

void MainWindow::onTabWidgettabCloseRequested(int index)
{
    qDebug() << __func__<<":"<<index;
    pTabWidget->removeTab(index);
}

void MainWindow::onListWidgetItemClicked(QListWidgetItem *item)
{
    //qDebug()<<__func__<<":"<<item;
    if(item == login)
    {
        pScrollArea->takeWidget();
        pScrollArea->setWidget(pLoginScrollAreaWidget);
    }
    else if(item == mainPanel)
    {
        pScrollArea->takeWidget();
        pScrollArea->setWidget(pMainPanelScrollAreaWidget);
    }
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 400);
}



