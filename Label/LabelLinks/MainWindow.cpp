#include "MainWindow.h"
#include <QDesktopServices>
#include <QLabel>
#include <QHBoxLayout>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pLabelUrl1(new QLabel()),pLabelUrl2(new QLabel())
{

    pLabelUrl1->setText(QString("<a href = \"%1\">%2</a>").arg("https://www.baidu.com").arg("百度"));
    pLabelUrl1->setStyleSheet("color:red");
    pLabelUrl1->setOpenExternalLinks(true);

    pLabelUrl2->setText(QString("<a href = \"%1\">%2</a>").arg("https://www.bing.com").arg("bing"));
    connect(pLabelUrl2, SIGNAL(linkActivated(QString)), this, SLOT(openUrl(QString)));

    layout = new QHBoxLayout();
    layout->addWidget(pLabelUrl1);
    layout->addWidget(pLabelUrl2);

    QWidget* pWidget = new QWidget(this);
    pWidget->setLayout(layout);
    setCentralWidget(pWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openUrl(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}

