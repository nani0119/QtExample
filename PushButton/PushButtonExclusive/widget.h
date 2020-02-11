#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QButtonGroup;
class QLabel;
class QAbstractButton;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
   void onButtonClicked(QAbstractButton*);
private:
    QLabel *pLabel;
    QButtonGroup *pButtonGroup;
};
#endif // WIDGET_H
