#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QWizard;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void onCurrentIdChanged(int index);
private:
    QWizard* pWizard;
};
#endif // WIDGET_H
