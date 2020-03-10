#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

public slots:
    void onModeChanged(int);
private:
    void setCompositionMode(QPainter::CompositionMode mode);
    QPainter::CompositionMode getCompositionMode();
    QPainter::CompositionMode compositionMode;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MYWIDGET_H
