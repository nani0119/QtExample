#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
class QGradient;
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

public slots:
    void  gradientUpdate();


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

private:
    virtual QGradient* createGradient();
    enum QGradient::Spread spreadType;
    enum QGradient::Type gradientType;

};

#endif // MYWIDGET_H
