#include "mainwindow.h"
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QAction>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pSearchLineEdit(new QLineEdit),pLabel(new QLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QAction *pLeadingAction = new QAction;
    pLeadingAction->setIcon(QIcon(":/img/lead"));
    pSearchLineEdit->addAction(pLeadingAction,QLineEdit::LeadingPosition);

    pSearchLineEdit->setPlaceholderText("输入搜索内容");

    QAction *pTrailingAction = pSearchLineEdit->addAction(QIcon(":/img/search_idle"),QLineEdit::TrailingPosition);
    pTrailingAction->setObjectName("TrailingAction");
    connect(pTrailingAction, SIGNAL(triggered(bool)), this, SLOT(onTrggered(bool)));

    connect(pSearchLineEdit,SIGNAL(textChanged(const QString& )), this, SLOT(onTextChange(const QString&)));
    connect(pSearchLineEdit,SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));



    layout->addWidget(pSearchLineEdit);
    layout->addWidget(pLabel);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onTrggered(bool checked)
{
    Q_UNUSED(checked)
    pLabel->setText(pSearchLineEdit->text());
}

void MainWindow::onTextChange(const QString &text)
{
    QList<QAction*> actionList = pSearchLineEdit->actions();
    foreach(QAction *action, actionList)
    {
        if(action->objectName() == "TrailingAction")
        {
            if(text.size() > 0)
            {
                action->setIcon(QIcon(":/img/search_input"));
            }
            else
            {
                action->setIcon(QIcon(":/img/search_idle"));
            }
        }
    }
}

void MainWindow::onReturnPressed()
{
    pLabel->setText(pSearchLineEdit->text());
}

