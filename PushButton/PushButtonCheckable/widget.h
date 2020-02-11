#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onClicked();
private:
    QPushButton *pPushButton;
    QLabel *pLabel;
};
#endif // WIDGET_H
