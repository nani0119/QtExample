#ifndef WIDGET_H
#define WIDGET_H
#include "chartinterface.h"
#include "chartstooltip.h"
#include <QWidget>

class BarChart : public QWidget,IChartInterface
{
    Q_OBJECT
    Q_INTERFACES(IChartInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.BarChart")

public:
    BarChart(QWidget *parent = nullptr);
    ~BarChart();
    virtual QString echo(const QString &message) override;
    virtual QString getPluginId() override;
    virtual QObject *getInstance() override;
    virtual QChart *getChart() override;
private slots:
    void onBarSeriesClicked(int index,QBarSet* set);
private:
    QChart* chart;
    ChartToolTip *tooltip;

};
#endif // WIDGET_H
