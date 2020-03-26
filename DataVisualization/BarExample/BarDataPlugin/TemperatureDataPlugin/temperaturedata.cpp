#include "temperaturedata.h"

TemperatureData::TemperatureData(QObject *parent) : QObject(parent)
{

}

QString TemperatureData::echo(const QString &message)
{
    qDebug()<<"temp1";
    return message;
}

QString TemperatureData::getPluginId()
{
    const QMetaObject *obj = metaObject();
    return obj->className();
}

QtDataVisualization::QValue3DAxis *TemperatureData::getZAxis()
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

QtDataVisualization::QCategory3DAxis *TemperatureData::getRowAxis()
{
    QStringList m_years;
    m_years << "2006" << "2007" << "2008" << "2009" << "2010" << "2011" << "2012" << "2013";
    QtDataVisualization::QCategory3DAxis *m_yearAxis = new QtDataVisualization::QCategory3DAxis();
    m_yearAxis->setLabels(m_years);
    m_yearAxis->setTitle("Year");
    m_yearAxis->setLabelAutoRotation(30.0f);
    m_yearAxis->setTitleVisible(true);

    return m_yearAxis;
}

QtDataVisualization::QCategory3DAxis *TemperatureData::getColAxis()
{
    QStringList m_months;
    m_months << "January" << "February" << "March" << "April" << "May" << "June" << "July" << "August" << "September" << "October" << "November" << "December";
    QtDataVisualization::QCategory3DAxis *m_monthAxis = new QtDataVisualization::QCategory3DAxis();
    m_monthAxis->setTitle("Month");
    m_monthAxis->setLabels(m_months);
    m_monthAxis->setLabelAutoRotation(30.0f);
    m_monthAxis->setTitleVisible(true);
    return m_monthAxis;
}

//QList<QtDataVisualization::QBar3DSeries *> TemperatureData::getBar3DSeriesList()
//{
//    QList<QtDataVisualization::QBar3DSeries *> list;

//    // Set up data
//    static const float tempOulu[8][12] = {
//        {-6.7f, -11.7f, -9.7f, 3.3f, 9.2f, 14.0f, 16.3f, 17.8f, 10.2f, 2.1f, -2.6f, -0.3f},    // 2006
//        {-6.8f, -13.3f, 0.2f, 1.5f, 7.9f, 13.4f, 16.1f, 15.5f, 8.2f, 5.4f, -2.6f, -0.8f},      // 2007
//        {-4.2f, -4.0f, -4.6f, 1.9f, 7.3f, 12.5f, 15.0f, 12.8f, 7.6f, 5.1f, -0.9f, -1.3f},      // 2008
//        {-7.8f, -8.8f, -4.2f, 0.7f, 9.3f, 13.2f, 15.8f, 15.5f, 11.2f, 0.6f, 0.7f, -8.4f},      // 2009
//        {-14.4f, -12.1f, -7.0f, 2.3f, 11.0f, 12.6f, 18.8f, 13.8f, 9.4f, 3.9f, -5.6f, -13.0f},  // 2010
//        {-9.0f, -15.2f, -3.8f, 2.6f, 8.3f, 15.9f, 18.6f, 14.9f, 11.1f, 5.3f, 1.8f, -0.2f},     // 2011
//        {-8.7f, -11.3f, -2.3f, 0.4f, 7.5f, 12.2f, 16.4f, 14.1f, 9.2f, 3.1f, 0.3f, -12.1f},     // 2012
//        {-7.9f, -5.3f, -9.1f, 0.8f, 11.6f, 16.6f, 15.9f, 15.5f, 11.2f, 4.0f, 0.1f, -1.9f}      // 2013
//    };




//    QtDataVisualization::QBarDataArray *dataSet = new QtDataVisualization::QBarDataArray;

//    QtDataVisualization::QBar3DSeries *m_primarySeries = new QtDataVisualization::QBar3DSeries();

//    int monthSize =sizeof (tempOulu[0])/sizeof (tempOulu[0][0]);

//    int yearSize = sizeof (tempOulu)/sizeof (tempOulu[0]);

//    qDebug()<<__func__<<" "<<yearSize<<"x"<<monthSize;
//    dataSet->reserve(yearSize);
//    QtDataVisualization::QBarDataRow *dataRow;
//    for (int year = 0; year < yearSize; year++) {
//        // Create a data row
//        dataRow = new QtDataVisualization::QBarDataRow(monthSize);
//        for (int month = 0; month < monthSize; month++) {
//            // Add data to the row
//            (*dataRow)[month].setValue(tempOulu[year][month]);
//        }
//        // Add the row to the set
//        dataSet->append(dataRow);
//    }

//    // Add data to the data proxy (the data proxy assumes ownership of it)
//    m_primarySeries->dataProxy()->resetArray(dataSet);
//    m_primarySeries->setItemLabelFormat(QStringLiteral("Oulu - @colLabel @rowLabel: @valueLabel"));
//    m_primarySeries->setMesh(QtDataVisualization::QAbstract3DSeries::MeshBevelBar);
//    m_primarySeries->setMeshSmooth(false);





//    static const float tempHelsinki[8][12] = {
//        {-3.7f, -7.8f, -5.4f, 3.4f, 10.7f, 15.4f, 18.6f, 18.7f, 14.3f, 8.5f, 2.9f, 4.1f},      // 2006
//        {-1.2f, -7.5f, 3.1f, 5.5f, 10.3f, 15.9f, 17.4f, 17.9f, 11.2f, 7.3f, 1.1f, 0.5f},       // 2007
//        {-0.6f, 1.2f, 0.2f, 6.3f, 10.2f, 13.8f, 18.1f, 15.1f, 10.1f, 9.4f, 2.5f, 0.4f},        // 2008
//        {-2.9f, -3.5f, -0.9f, 4.7f, 10.9f, 14.0f, 17.4f, 16.8f, 13.2f, 4.1f, 2.6f, -2.3f},     // 2009
//        {-10.2f, -8.0f, -1.9f, 6.6f, 11.3f, 14.5f, 21.0f, 18.8f, 12.6f, 6.1f, -0.5f, -7.3f},   // 2010
//        {-4.4f, -9.1f, -2.0f, 5.5f, 9.9f, 15.6f, 20.8f, 17.8f, 13.4f, 8.9f, 3.6f, 1.5f},       // 2011
//        {-3.5f, -3.2f, -0.7f, 4.0f, 11.1f, 13.4f, 17.3f, 15.8f, 13.1f, 6.4f, 4.1f, -5.1f},     // 2012
//        {-4.8f, -1.8f, -5.0f, 2.9f, 12.8f, 17.2f, 18.0f, 17.1f, 12.5f, 7.5f, 4.5f, 2.3f}       // 2013
//    };



//    QtDataVisualization::QBarDataArray *dataSet2 = new QtDataVisualization::QBarDataArray;
//    QtDataVisualization::QBarDataRow *dataRow2;
//    dataSet2->reserve(yearSize);
//    for (int year = 0; year < yearSize; year++) {
//        // Create a data row
//        dataRow2 = new QtDataVisualization::QBarDataRow(monthSize);
//        for (int month = 0; month < monthSize; month++) {
//            // Add data to the row
//            (*dataRow2)[month].setValue(tempHelsinki[year][month]);
//        }
//        // Add the row to the set
//        dataSet2->append(dataRow2);
//    }

//    QtDataVisualization::QBar3DSeries *m_secondarySeries = new QtDataVisualization::QBar3DSeries();
//    m_secondarySeries->setItemLabelFormat(QStringLiteral("Helsinki - @colLabel @rowLabel: @valueLabel"));
//    m_secondarySeries->setMesh(QtDataVisualization::QAbstract3DSeries::MeshBevelBar);
//    m_secondarySeries->setMeshSmooth(false);
//    m_secondarySeries->setVisible(false);
//    m_secondarySeries->dataProxy()->resetArray(dataSet2);


//    list.append(m_primarySeries);
//    list.append(m_secondarySeries);

//    return list;
//}

 QMap<QString,QList<QList<qreal>>> TemperatureData::getBar3DSeriesData()
{
    // Set up data
    static const float tempOulu[8][12] = {
        {-6.7f, -11.7f, -9.7f, 3.3f, 9.2f, 14.0f, 16.3f, 17.8f, 10.2f, 2.1f, -2.6f, -0.3f},    // 2006
        {-6.8f, -13.3f, 0.2f, 1.5f, 7.9f, 13.4f, 16.1f, 15.5f, 8.2f, 5.4f, -2.6f, -0.8f},      // 2007
        {-4.2f, -4.0f, -4.6f, 1.9f, 7.3f, 12.5f, 15.0f, 12.8f, 7.6f, 5.1f, -0.9f, -1.3f},      // 2008
        {-7.8f, -8.8f, -4.2f, 0.7f, 9.3f, 13.2f, 15.8f, 15.5f, 11.2f, 0.6f, 0.7f, -8.4f},      // 2009
        {-14.4f, -12.1f, -7.0f, 2.3f, 11.0f, 12.6f, 18.8f, 13.8f, 9.4f, 3.9f, -5.6f, -13.0f},  // 2010
        {-9.0f, -15.2f, -3.8f, 2.6f, 8.3f, 15.9f, 18.6f, 14.9f, 11.1f, 5.3f, 1.8f, -0.2f},     // 2011
        {-8.7f, -11.3f, -2.3f, 0.4f, 7.5f, 12.2f, 16.4f, 14.1f, 9.2f, 3.1f, 0.3f, -12.1f},     // 2012
        {-7.9f, -5.3f, -9.1f, 0.8f, 11.6f, 16.6f, 15.9f, 15.5f, 11.2f, 4.0f, 0.1f, -1.9f}      // 2013
    };

    int monthSize =sizeof (tempOulu[0])/sizeof (tempOulu[0][0]);
    int yearSize = sizeof (tempOulu)/sizeof (tempOulu[0]);

    QList<QList<qreal>> series1;
    for(int y = 0; y < yearSize; y++)
    {
        QList<qreal> month;
        for(int m = 0; m < monthSize; m++)
        {
            month.append(tempOulu[y][m]);
        }
        series1.append(month);
    }



    static const float tempHelsinki[8][12] = {
        {-3.7f, -7.8f, -5.4f, 3.4f, 10.7f, 15.4f, 18.6f, 18.7f, 14.3f, 8.5f, 2.9f, 4.1f},      // 2006
        {-1.2f, -7.5f, 3.1f, 5.5f, 10.3f, 15.9f, 17.4f, 17.9f, 11.2f, 7.3f, 1.1f, 0.5f},       // 2007
        {-0.6f, 1.2f, 0.2f, 6.3f, 10.2f, 13.8f, 18.1f, 15.1f, 10.1f, 9.4f, 2.5f, 0.4f},        // 2008
        {-2.9f, -3.5f, -0.9f, 4.7f, 10.9f, 14.0f, 17.4f, 16.8f, 13.2f, 4.1f, 2.6f, -2.3f},     // 2009
        {-10.2f, -8.0f, -1.9f, 6.6f, 11.3f, 14.5f, 21.0f, 18.8f, 12.6f, 6.1f, -0.5f, -7.3f},   // 2010
        {-4.4f, -9.1f, -2.0f, 5.5f, 9.9f, 15.6f, 20.8f, 17.8f, 13.4f, 8.9f, 3.6f, 1.5f},       // 2011
        {-3.5f, -3.2f, -0.7f, 4.0f, 11.1f, 13.4f, 17.3f, 15.8f, 13.1f, 6.4f, 4.1f, -5.1f},     // 2012
        {-4.8f, -1.8f, -5.0f, 2.9f, 12.8f, 17.2f, 18.0f, 17.1f, 12.5f, 7.5f, 4.5f, 2.3f}       // 2013
    };

    QList<QList<qreal>> series2;
    for(int y = 0; y < yearSize; y++)
    {
        QList<qreal> month;
        for(int m = 0; m < monthSize; m++)
        {
            month.append(tempHelsinki[y][m]);
        }
        series2.append(month);
    }
    QMap<QString,QList<QList<qreal>>> allData;
    allData["Oulu"] = series1;
    allData["Helsinki"]=series2;
    return allData;
}


