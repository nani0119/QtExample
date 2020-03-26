#ifndef TEMPERATUREDATA_H
#define TEMPERATUREDATA_H

#include <QObject>
#include "BarDataInterface.h"
class TemperatureData : public QObject, IBarDataInterface
{
    Q_OBJECT
    Q_INTERFACES(IBarDataInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.TemperatureData")
public:
    explicit TemperatureData(QObject *parent = nullptr);

    // IBarDataInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QtDataVisualization::QValue3DAxis *getZAxis();
    QtDataVisualization::QCategory3DAxis *getRowAxis();
    QtDataVisualization::QCategory3DAxis *getColAxis();
//    QList<QtDataVisualization::QBar3DSeries *> getBar3DSeriesList();
     QMap<QString,QList<QList<qreal>>> getBar3DSeriesData();
};

#endif // TEMPERATUREDATA_H
