#include "dialog.h"
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent),pFontDialog(new QFontDialog)
{
    pFontDialog->setOption(QFontDialog::DontUseNativeDialog);
    pFontDialog->show();
}

Widget::~Widget()
{
}

