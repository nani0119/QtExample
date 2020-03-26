#ifndef BARDATAINTERFACE_H
#define BARDATAINTERFACE_H
#include <QObject>
#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/QCategory3DAxis>
#include <QtDataVisualization/QBar3DSeries>


class IBarDataInterface
{
public:
    virtual ~IBarDataInterface(){}
    virtual QString echo(const QString &message) = 0;
    virtual QString getPluginId() = 0;
    virtual QtDataVisualization::QValue3DAxis* getZAxis() = 0;
    virtual  QtDataVisualization::QCategory3DAxis* getRowAxis() = 0;
    virtual  QtDataVisualization::QCategory3DAxis* getColAxis() = 0;
//    virtual  QList<QtDataVisualization::QBar3DSeries*> getBar3DSeriesList() = 0;
    virtual  QMap<QString,QList<QList<qreal>>> getBar3DSeriesData() = 0;
};

#define IBarDataInterface_iid "Examples.Plugin.IBarDataInterface"

Q_DECLARE_INTERFACE(IBarDataInterface, IBarDataInterface_iid)
#endif // BARDATAINTERFACE_H
