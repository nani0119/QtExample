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
    void onChartThemeChanged(int index);
private:
     IChartInterface* chartInterface;
     QWidget* myWidget;
     QVBoxLayout* layout;
     enum QChart::ChartTheme  theme;
};

#endif // WIDGET_H
