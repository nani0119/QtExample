#ifndef TEMPERATUREDATA_H
#define TEMPERATUREDATA_H

#include <QObject>
#include "BarDataInterface.h"
class TemperatureData2 : public QObject, IBarDataInterface
{
    Q_OBJECT
    Q_INTERFACES(IBarDataInterface)
    Q_PLUGIN_METADATA(IID "Qt.Examples.Charts.TemperatureData2")
public:
    explicit TemperatureData2(QObject *parent = nullptr);

    // IBarDataInterface interface
public:
    QString echo(const QString &message);
    QString getPluginId();
    QtDataVisualization::QValue3DAxis *getZAxis();
    QtDataVisualization::QCategory3DAxis *getRowAxis();
    QtDataVisualization::QCategory3DAxis *getColAxis();
//    QList<QtDataVisualization::QBar3DSeries *> getBar3DSeriesList();
    QMap<QString,QList<QList<qreal>>> getBar3DSeriesData();
    void set3DBars(QtDataVisualization::Q3DBars* bar);
    void leave();
private:
    QtDataVisualization::Q3DBars* bars3D;
};

#endif // TEMPERATUREDATA_H
