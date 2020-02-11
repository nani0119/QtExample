#include "MainWindow.h"
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QToolButton>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QStatusBar>
#include <QHBoxLayout>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pToolBar(new QToolBar()), pLabel(new QLabel), statusBarLabel(new QLabel), permanentLabel(new QLabel), pTimer(new QTimer)
{
    addAction = new QAction;
    addAction->setText("添加项目");
    addAction->setIcon(QIcon(":/img/add"));
    addAction->setToolTip("添加项目");

    delAction = new QAction;
    delAction->setText("删除项目");
    delAction->setIcon(QIcon(":/img/del"));
    delAction->setToolTip("删除项目");

    cancelAction = new QAction;
    cancelAction->setText("取消");
    cancelAction->setIcon(QIcon(":/img/cancle"));
    cancelAction->setToolTip("取消");

    settingAction = new QAction;
    settingAction->setText("设置");
    settingAction->setIcon(QIcon(":/img/setting"));
    settingAction->setToolTip("设置");

    backAction = new QAction;
    backAction->setText("后退");
    backAction->setIcon(QIcon(":/img/back"));
    backAction->setToolTip("后退");

    QMenu *subMenu = new QMenu(this);
    subMenu->setTitle("子菜单");
    subMenu->addAction(addAction);
    subMenu->addAction(delAction);
    subMenu->addAction(cancelAction);
    subMenu->addAction(settingAction);

    //菜单栏
    QMenu *mainMenu = menuBar()->addMenu("主菜单");
    mainMenu->setTitle("主菜单");
    mainMenu->addAction(addAction);
    mainMenu->addAction(delAction);
    mainMenu->addAction(cancelAction);
    mainMenu->addAction(settingAction);
    mainMenu->addMenu(subMenu);
    connect(mainMenu, SIGNAL(triggered(QAction*)), this, SLOT(onTrigerMenu(QAction*)));
    connect(mainMenu,SIGNAL(hovered(QAction*)), this, SLOT(onHovered(QAction*)));

    //工具栏
    QMenu *toolMenu = new QMenu(this);
    toolMenu->setTitle("工具栏菜单");
    toolMenu->addAction(addAction);
    toolMenu->addAction(delAction);
    toolMenu->addAction(cancelAction);
    toolMenu->addAction(settingAction);
    toolMenu->addMenu(subMenu);

    pToolBar->addAction(addAction);
    pToolBar->addAction(delAction);
    pToolBar->addAction(cancelAction);
    pToolBar->addAction(settingAction);
    pToolBar->addSeparator();



    QToolButton *pToolButton = new QToolButton();
    pToolButton->setText("后退");
    pToolButton->setToolTip("后退");
    pToolButton->setIcon(QIcon(":/img/back"));
    pToolButton->setMenu(toolMenu);
    pToolButton->setPopupMode(QToolButton::InstantPopup);
    pToolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    pToolBar->addWidget(pToolButton);
    addToolBar(pToolBar);


    // 状态栏
    statusBarLabel = new QLabel("StatusBar Label");
    statusBarLabel->setAlignment(Qt::AlignCenter);
    statusBarLabel->setMinimumSize(statusBarLabel->sizeHint());
    statusBar()->addWidget(statusBarLabel);

    QDateTime dateTime = QDateTime::currentDateTime();
    permanentLabel->setText(dateTime.toString("HH:mm:ss"));
    statusBar()->addPermanentWidget(permanentLabel); //实现永久信息

    statusBar()->setVisible(true);
    statusBar()->setSizeGripEnabled(true);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 10px}"));

    pTimer->setInterval(1000);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    pTimer->start();



    QWidget *widget = new QWidget(this);
    pLabel->setText("NaN");
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(pLabel);
    widget->setLayout(hLayout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onTrigerMenu(QAction *action)
{
    pLabel->setText(action->text());
}

void MainWindow::onTimeout()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    permanentLabel->setText(dateTime.toString("HH:mm:ss"));
}

void MainWindow::onHovered(QAction* action)
{
    statusBarLabel->setText(action->text());
}

