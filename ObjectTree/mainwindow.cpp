#include "mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QAction>
#include <QVBoxLayout>
#include <QListWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pPushButton(new QPushButton), pLineEdit(new QLineEdit)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setObjectName("layout");

    pPushButton->setObjectName("PushButton");
    layout->addWidget(pPushButton);

    QAction *pLeadingAction = new QAction(pLineEdit);
    pLeadingAction->setObjectName("LeadingAction");
    pLeadingAction->setIcon(QIcon(":/img/lead"));
    pLineEdit->addAction(pLeadingAction,QLineEdit::LeadingPosition);

    pLineEdit->setPlaceholderText("输入搜索内容");
    pLineEdit->setObjectName("LineEdit");

    QAction *pTrailingAction = pLineEdit->addAction(QIcon(":/img/search_idle"),QLineEdit::TrailingPosition);
    pTrailingAction->setObjectName("TrailingAction");

    connect(pTrailingAction, SIGNAL(triggered(bool)), this, SLOT(onTrggered(bool)));

    connect(pLineEdit,SIGNAL(textChanged(const QString& )), this, SLOT(onTextChange(const QString&)));
    connect(pLineEdit,SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));
    connect(this, SIGNAL(customClicked()), this, SLOT(onReturnPressed()));

    layout->addWidget(pLineEdit);

    QWidget *widget = new QWidget(this);
    widget->setObjectName("Widget");
    widget->setLayout(layout);
    //widget->dumpObjectTree();
    //qDebug()<<"===========================";
    //this->setObjectName("MainWindow");
    //this->dumpObjectInfo();


    QAction *action = this->findChild<QAction *>("TrailingAction");
    qDebug()<<"findChild:"<<action->objectName();

    QAction *whichAction = this->findChild<QAction *>();
    qDebug()<<"findChild:"<<whichAction->objectName();

    QList<QAction*> childrenActions = this->findChildren<QAction*>();
    foreach (QAction* a , childrenActions) {
        qDebug()<<"Child:"<<a->objectName();
    }

    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onTrggered(bool)
{
}

void MainWindow::onTextChange(const QString&)
{
}

void MainWindow::onReturnPressed()
{
}
