#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "chartinterface.h"

class BarChart : public QWidget,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.BarChart")

public:
    BarChart(QWidget *parent = nullptr);
    ~BarChart();

    // IChartInterface interface
public:
    virtual QString echo(const QString &message) override;
    virtual QString getPluginId() override;
    virtual QObject *getInstance() override;
};
#endif // WIDGET_H
