#include "mainwindow.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pSystemTrayIcon(new QSystemTrayIcon),
      pLabel(new QLabel), pPushButton(new QPushButton),pHideToSystemTray(new QPushButton),
      pShowMessage(new QLineEdit)
{

    QAction *pShowAction = new QAction;
    pShowAction->setText("显示");
    pShowAction->setIcon(QIcon(":/img/show"));
    connect(pShowAction, SIGNAL(triggered(bool)), this, SLOT(onShowWindow()));

    QAction *pSettingAction = new QAction;
    pSettingAction->setText("设置");
    pSettingAction->setIcon(QIcon(":/img/setting"));

    QAction *pExitAction = new QAction;
    pExitAction->setText("退出");
    pExitAction->setIcon(QIcon(":/img/exit"));
    connect(pExitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    QMenu *pMenu = new QMenu;
    pMenu->addAction(pShowAction);
    pMenu->addAction(pSettingAction);
    pMenu->addSeparator();
    pMenu->addAction(pExitAction);

    pSystemTrayIcon->setContextMenu(pMenu);
    pSystemTrayIcon->setIcon(QIcon(":/img/logo"));
    pSystemTrayIcon->setToolTip("这是系统托盘");
    pSystemTrayIcon->show();
    connect(pSystemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnSystemTrayActivated(QSystemTrayIcon::ActivationReason)));
    connect(pSystemTrayIcon, SIGNAL(messageClicked()), this, SLOT(OnSystemTrayMessageClicked()));


    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(pLabel);
    pLabel->setText("Message...");

    pPushButton->setText("隐藏系统托盘");
    connect(pPushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()) );
    layout->addWidget(pPushButton);

    pShowMessage->setPlaceholderText("托盘消息");
    pShowMessage->setEchoMode(QLineEdit::Normal);
    pShowMessage->setEnabled(true);
    connect(pShowMessage, SIGNAL(returnPressed()), this, SLOT(onShowMessageReturnPressed()));
    layout->addWidget(pShowMessage);


    pHideToSystemTray->setText("最小化到系统托盘");
    connect(pHideToSystemTray, SIGNAL(clicked()), this, SLOT(onHideWindow()));
    layout->addWidget(pHideToSystemTray);


    if(QSystemTrayIcon::supportsMessages())
    {
        qDebug()<<"Supports Messages";
    }
    else
    {
        qDebug()<<"Not Supports Messages";
    }

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onPushButtonClicked()
{
    if(QSystemTrayIcon::isSystemTrayAvailable())
    {
        qDebug()<<"SystemTray is Available";
    }
    else
    {
        qDebug()<<"SystemTray is not Available";
    }
    if(pPushButton->text() == "隐藏系统托盘")
    {
        pSystemTrayIcon->hide();
        pPushButton->setText("显示系统托盘");
    }
    else
    {
        pSystemTrayIcon->show();
        pPushButton->setText("隐藏系统托盘");
    }

    if(pSystemTrayIcon->isVisible())
    {
        pShowMessage->setEnabled(true);
    }
    else
    {
        pShowMessage->setEnabled(false);
    }
}

void MainWindow::onShowMessageReturnPressed()
{
    pSystemTrayIcon->showMessage("托盘标题", pShowMessage->text());
}

void MainWindow::onShowWindow()
{
    showNormal();
    raise();
    activateWindow();
    if(pSystemTrayIcon->isVisible())
    {
        pShowMessage->setEnabled(true);
        pPushButton->setText("隐藏系统托盘");
    }
    else
    {
        pShowMessage->setEnabled(false);
        pPushButton->setText("显示系统托盘");
    }
}

void MainWindow::onHideWindow()
{
    pLabel->setText("onHideWindow");
    this->hide();
    if(!pSystemTrayIcon->isVisible())
    {
        pSystemTrayIcon->show();
    }
}

void MainWindow::OnSystemTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    pLabel->clear();
    QString str = "SystemTray　Activated　Reason:";
    switch(reason)
    {
        case QSystemTrayIcon::Unknown:
                str += "Unknown";
                break;
        case QSystemTrayIcon::Context:
                str += "Context";
                break;
        case QSystemTrayIcon::DoubleClick:
                str += "DoubleClick";
                break;
        case QSystemTrayIcon::Trigger:
                str += "Trigger";
                break;
        case QSystemTrayIcon::MiddleClick:
                str += "MiddleClick";
                break;
    }
    pLabel->setText(str);
}

void MainWindow::OnSystemTrayMessageClicked()
{
    pLabel->setText("OnSystemTray Message Clicked");
}

