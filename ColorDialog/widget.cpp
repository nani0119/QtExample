#include "widget.h"
#include <QColorDialog>
#include <QColor>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), pColorDialog(new QColorDialog)
{
    pColorDialog->setOption(QColorDialog::DontUseNativeDialog);
    pColorDialog->show();
    QColor currentColor = pColorDialog->currentColor();
    qDebug()<<"currentColor:"<<currentColor.name();
    connect(pColorDialog, SIGNAL(accepted()), this, SLOT(onAccepted()));
}

Widget::~Widget()
{
}

void Widget::onAccepted()
{

    QColor color = pColorDialog->selectedColor();
    qDebug()<<"selectedColor:"<<color.name();

}

