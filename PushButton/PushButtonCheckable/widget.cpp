#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent), pPushButton(new QPushButton()),pLabel(new QLabel())
{
    QHBoxLayout *layout = new QHBoxLayout;
    onClicked();

    layout->addWidget(pLabel);

    pPushButton->setText("click me");
    pPushButton->setCheckable(true);

    layout->addWidget(pPushButton);
    setLayout(layout);

    connect(pPushButton, SIGNAL(clicked()), this, SLOT(onClicked()));
}

Widget::~Widget()
{
}

void Widget::onClicked()
{
    if(pPushButton->isChecked())
    {
        pLabel->setText("Checked");
    }
    else
    {
        pLabel->setText("unChecked");
    }
}

