#ifndef WIDGET_H
#define WIDGET_H

#include "chartinterface.h"
#include <QWidget>

class HBarChart : public QWidget,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.HBarChart")

public:
    HBarChart(QWidget *parent = nullptr);
    ~HBarChart();

    // IChartInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QObject *getInstance();
    QChart *getChart();
private:
    QChart *chart;
};
#endif // WIDGET_H
