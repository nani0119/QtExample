#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QColorDialog;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onAccepted();

private:
   QColorDialog *pColorDialog;
};
#endif // WIDGET_H
