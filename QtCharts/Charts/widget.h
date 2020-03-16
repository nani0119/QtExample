#ifndef WIDGET_H
#define WIDGET_H
#include "chartinterface.h"
#include <QWidget>

class QVBoxLayout;
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
public slots:
    void loadPlugin(const QString& text);
private:
     IChartInterface* chart;
     QWidget* myWidget;
     QVBoxLayout* layout;
};

#endif // WIDGET_H
