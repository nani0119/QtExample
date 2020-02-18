#include "mainwindow.h"
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QCommandLinkButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel), pInstall(new QCommandLinkButton),
      pFormat(new QCommandLinkButton), pSkip(new QCommandLinkButton)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);

    pLabel->setText("请选择当前操作");
    pLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(pLabel);


    pInstall->setDescription("在当前介质中安装");
    pInstall->setText("安装");
    pInstall->setFlat(false);
    layout->addWidget(pInstall);
    connect(pInstall, SIGNAL(clicked()), this, SLOT(onInstallClicked()));

    pFormat->setDescription("格式化当前介质");
    pFormat->setText("格式化");
    pFormat->setFlat(false);
    layout->addWidget(pFormat);
    connect(pFormat, SIGNAL(clicked()), this, SLOT(onFormatClicked()));

    pSkip->setDescription("跳过当前操作");
    pSkip->setText("跳过");
    pSkip->setFlat(false);
    layout->addWidget(pSkip);
    connect(pSkip, SIGNAL(clicked()), this, SLOT(onSkipClicked()));


    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onInstallClicked()
{
    pLabel->setText("Install Button is clicked");
}

void MainWindow::onFormatClicked()
{
    pLabel->setText("Format Button is clicked");
}

void MainWindow::onSkipClicked()
{
    pLabel->setText("Skip Button is clicked");
}

