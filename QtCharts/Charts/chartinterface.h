#ifndef CHARTINTERFACE_H
#define CHARTINTERFACE_H

#include <QObject>
#include <QtCharts>
//using namespace QtCharts;

class IChartInterface
{
public:
    virtual ~IChartInterface(){}
    virtual QString echo(const QString &message) = 0;
    virtual QString getPluginId() = 0;
    virtual QObject* getInstance() = 0;
    virtual QChart* getChart() = 0;
};

#define IChartInterface_iid "Examples.Plugin.ChartInterface"

Q_DECLARE_INTERFACE(IChartInterface, IChartInterface_iid)

#endif // CHARTINTERFACE_H
