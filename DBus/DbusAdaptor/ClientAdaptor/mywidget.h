#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>
#include "mywidget_interface.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
public slots:
    void onSetValue();
    void onShowValue();
private:
    com::example::MyWidget* serviceWidget;
};

#endif // MYWIDGET_H
