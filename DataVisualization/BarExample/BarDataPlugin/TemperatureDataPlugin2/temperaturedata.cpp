#include "temperaturedata.h"

TemperatureData2::TemperatureData2(QObject *parent) : QObject(parent)
{

}

QString TemperatureData2::echo(const QString &message)
{
    qDebug()<<"temp2";
    return message;
}

QString TemperatureData2::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QtDataVisualization::QValue3DAxis *TemperatureData2::getZAxis()
{
    int m_segments = 4;
    int m_subSegments = 3;
    int m_minval = -20;
    int m_maxval = 20;

    const QString celsiusString = QString(QChar(0xB0)) + "C";
    QtDataVisualization::QValue3DAxis *m_temperatureAxis = new QtDataVisualization::QValue3DAxis();
    m_temperatureAxis->setTitle("Average temperature");
    m_temperatureAxis->setSegmentCount(m_segments);
    m_temperatureAxis->setSubSegmentCount(m_subSegments);
    m_temperatureAxis->setRange(m_minval, m_maxval);
    m_temperatureAxis->setLabelFormat(QString(QStringLiteral("%.1f ") + celsiusString));
    m_temperatureAxis->setLabelAutoRotation(30.0f);
    m_temperatureAxis->setTitleVisible(true);

    return m_temperatureAxis;
}

QtDataVisualization::QCategory3DAxis *TemperatureData2::getRowAxis()
{
    QtDataVisualization::QCategory3DAxis *m_yearAxis = new QtDataVisualization::QCategory3DAxis();
    m_yearAxis->setTitle("Year");
    m_yearAxis->setLabelAutoRotation(30.0f);
    m_yearAxis->setTitleVisible(true);

    return m_yearAxis;
}

QtDataVisualization::QCategory3DAxis *TemperatureData2::getColAxis()
{
    QtDataVisualization::QCategory3DAxis *m_monthAxis = new QtDataVisualization::QCategory3DAxis();
    m_monthAxis->setTitle("Month");
    m_monthAxis->setLabelAutoRotation(30.0f);
    m_monthAxis->setTitleVisible(true);
    return m_monthAxis;
}

QList<QtDataVisualization::QBar3DSeries *> TemperatureData2::getBar3DSeriesList()
{
    QList<QtDataVisualization::QBar3DSeries *> list;

    QStringList m_months;
    m_months << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec";

    QStringList m_years;
    m_years << "2006" << "2007";



    // Set up data
    static const float tempOulu2[8][12] = {
        {-12.0f, -12.7f, -19.7f, 13.3f, 9.2f, 12.0f, 15.3f, 10.8f, 12.2f, 12.1f, -12.6f, -10.3f},    // 2006
        {-16.8f, -13.3f, 10.2f, 11.5f, 17.9f, 1.4f, 16.1f, 10.5f, 18.2f, 15.4f, -12.6f, -10.8f},      // 2007
    };

    QtDataVisualization::QBarDataArray *dataSet = new QtDataVisualization::QBarDataArray;

    QtDataVisualization::QBar3DSeries *m_primarySeries = new QtDataVisualization::QBar3DSeries();
    int monthSize = m_months.size();
    int yearSize = m_years.size();
    dataSet->reserve(yearSize);
    QtDataVisualization::QBarDataRow *dataRow;
    for (int year = 0; year < yearSize; year++) {
        // Create a data row
        dataRow = new QtDataVisualization::QBarDataRow(monthSize);
        for (int month = 0; month < monthSize; month++) {
            // Add data to the row
            (*dataRow)[month].setValue(tempOulu2[year][month]);
        }
        // Add the row to the set
        dataSet->append(dataRow);
    }

    // Add data to the data proxy (the data proxy assumes ownership of it)
    m_primarySeries->dataProxy()->resetArray(dataSet, m_years, m_months);
    m_primarySeries->setItemLabelFormat(QStringLiteral("Oulu - @colLabel @rowLabel: @valueLabel"));
    m_primarySeries->setMesh(QtDataVisualization::QAbstract3DSeries::MeshBevelBar);
    m_primarySeries->setMeshSmooth(false);


    list.append(m_primarySeries);

    return list;
}


