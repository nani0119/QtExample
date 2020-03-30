#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
public slots:
    int  value();
    void setValue(int);
    void updateValue();

private:
    int val;

};

#endif // MYWIDGET_H
