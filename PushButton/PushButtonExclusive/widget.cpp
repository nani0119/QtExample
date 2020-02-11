#include "widget.h"
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent), pLabel(new QLabel), pButtonGroup(new QButtonGroup)
{
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;

    vLayout->addWidget(pLabel);

    // 设置互斥
    pButtonGroup->setExclusive(true);
    for(int i = 0; i < 3; i++)
    {
        QPushButton* button = new QPushButton();
        button->setText(QString("ClickMe %1").arg(i));
        hLayout->addWidget(button);
        pButtonGroup->addButton(button);
    }
    vLayout->addLayout(hLayout);

    setLayout(vLayout);

    connect(pButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonClicked(QAbstractButton*)));
}

Widget::~Widget()
{
}

void Widget::onButtonClicked(QAbstractButton *button)
{
    pLabel->setText(button->text());
}

