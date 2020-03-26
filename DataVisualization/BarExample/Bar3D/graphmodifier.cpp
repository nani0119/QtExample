#include "graphmodifier.h"
#include <QComboBox>
#include <QtMath>
GraphModifier::GraphModifier(Q3DBars *bargraph):
    m_graph(bargraph),m_ZAxis(nullptr), m_RowAxis(nullptr), m_ColAxis(nullptr),
    seriesList(QList<QBar3DSeries *>()),
    m_fontSize(30), m_xRotation(0.0f),m_yRotation(0.0f),m_smooth(false),
    m_barMesh(QAbstract3DSeries::MeshBevelBar)
{
    seriesList.clear();

    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftMedium);
    m_graph->activeTheme()->setBackgroundEnabled(false);
    m_graph->activeTheme()->setFont(QFont("Times New Roman", m_fontSize));
    m_graph->activeTheme()->setLabelBackgroundEnabled(true);
    m_graph->setMultiSeriesUniform(true);

    changePresetCamera();
    // Set up property animations for zooming to the selected bar
    Q3DCamera *camera = m_graph->scene()->activeCamera();
    m_defaultAngleX = camera->xRotation();
    m_defaultAngleY = camera->yRotation();
    m_defaultZoom = camera->zoomLevel();
    m_defaultTarget = camera->target();

    m_animationCameraX.setTargetObject(camera);
    m_animationCameraY.setTargetObject(camera);
    m_animationCameraZoom.setTargetObject(camera);
    m_animationCameraTarget.setTargetObject(camera);

    m_animationCameraX.setPropertyName("xRotation");
    m_animationCameraY.setPropertyName("yRotation");
    m_animationCameraZoom.setPropertyName("zoomLevel");
    m_animationCameraTarget.setPropertyName("target");

    int duration = 1700;
    m_animationCameraX.setDuration(duration);
    m_animationCameraY.setDuration(duration);
    m_animationCameraZoom.setDuration(duration);
    m_animationCameraTarget.setDuration(duration);

    // The zoom always first zooms out above the graph and then zooms in
    qreal zoomOutFraction = 0.3;
    m_animationCameraX.setKeyValueAt(zoomOutFraction, QVariant::fromValue(0.0f));
    m_animationCameraY.setKeyValueAt(zoomOutFraction, QVariant::fromValue(90.0f));
    m_animationCameraZoom.setKeyValueAt(zoomOutFraction, QVariant::fromValue(50.0f));
    m_animationCameraTarget.setKeyValueAt(zoomOutFraction,
                                          QVariant::fromValue(QVector3D(0.0f, 0.0f, 0.0f)));

}

GraphModifier::~GraphModifier()
{
    delete  m_graph;
}

void GraphModifier::setDataSource(IBarDataInterface *dataSoureInterface)
{

    dataSource = dataSoureInterface;

    if(m_ZAxis != nullptr)
    {
        m_graph->releaseAxis(m_ZAxis);
    }
    m_ZAxis = dataSource->getZAxis();
    m_graph->setValueAxis(m_ZAxis);


    if( m_RowAxis != nullptr)
    {
        m_graph->releaseAxis(m_RowAxis);
    }
    m_RowAxis = dataSource->getRowAxis();
    m_graph->setRowAxis(m_RowAxis);


    if(m_ColAxis != nullptr)
    {
        m_graph->releaseAxis(m_ColAxis);
    }
    m_ColAxis = dataSource->getColAxis();
    m_graph->setColumnAxis(m_ColAxis);

    QList<QBar3DSeries *> list = m_graph->seriesList();
    for(int i = 0; i < list.count(); i++)
    {
        m_graph->removeSeries(list[i]);
    }

    seriesList = getBar3DSeriesList(dataSource->getBar3DSeriesData());
    for(int i = 0; i < seriesList.count(); i++)
    {
        m_graph->addSeries(seriesList[i]);
    }

}

void GraphModifier::changePresetCamera()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();
    m_animationCameraZoom.stop();
    m_animationCameraTarget.stop();

    // Restore camera target in case animation has changed it
    m_graph->scene()->activeCamera()->setTarget(QVector3D(0.0f, 0.0f, 0.0f));

    static int preset = Q3DCamera::CameraPresetFront;

    m_graph->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)preset);

    if (++preset > Q3DCamera::CameraPresetDirectlyBelow)
        preset = Q3DCamera::CameraPresetFrontLow;
}

void GraphModifier::changeLabelBackground()
{
    m_graph->activeTheme()->setLabelBackgroundEnabled(!m_graph->activeTheme()->isLabelBackgroundEnabled());
}

void GraphModifier::changeFont(const QFont &font)
{
    QFont newFont = font;
    m_graph->activeTheme()->setFont(newFont);
}

void GraphModifier::changeFontSize(int fontsize)
{
    m_fontSize = fontsize;
    QFont font = m_graph->activeTheme()->font();
    font.setPointSize(m_fontSize);
    m_graph->activeTheme()->setFont(font);
}

void GraphModifier::rotateX(int rotation)
{
    m_xRotation = rotation;
    m_graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);
}

void GraphModifier::rotateY(int rotation)
{
    m_yRotation = rotation;
    m_graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);
}

void GraphModifier::setBackgroundEnabled(int enabled)
{
    m_graph->activeTheme()->setBackgroundEnabled(bool(enabled));
}

void GraphModifier::setGridEnabled(int enabled)
{
    m_graph->activeTheme()->setGridEnabled(bool(enabled));
}

void GraphModifier::setSmoothBars(int smooth)
{
    m_smooth = bool(smooth);
    for(int i = 0; i < seriesList.count(); i++)
    {
        seriesList[i]->setMeshSmooth(m_smooth);
    }
}

void GraphModifier::setReverseValueAxis(int enabled)
{
    m_graph->valueAxis()->setReversed(enabled);
}

void GraphModifier::setReflection(bool enabled)
{
    m_graph->setReflection(enabled);
}

QCategory3DAxis *GraphModifier::getGraphModifierRowAxis()
{
    return m_RowAxis;
}

QList<QBar3DSeries *> GraphModifier::getseriesList()
{
    return seriesList;
}

void GraphModifier::changeRange(int range)
{
    int rowSize = seriesList[0]->dataProxy()->rowCount();
    qDebug()<<__func__<<"  "<< rowSize<< "  " <<range;
    if (range >=rowSize)
        m_RowAxis->setRange(0, rowSize - 1);
    else
        m_RowAxis->setRange(range, range);
}

void GraphModifier::changeStyle(int style)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox) {
        m_barMesh = QAbstract3DSeries::Mesh(comboBox->itemData(style).toInt());
        for(int i = 0; i < seriesList.count(); i++)
        {
            seriesList[i]->setMesh(m_barMesh);
        }
    }
}

void GraphModifier::changeSelectionMode(int selectionMode)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox) {
        int flags = comboBox->itemData(selectionMode).toInt();
        m_graph->setSelectionMode(QAbstract3DGraph::SelectionFlags(flags));
    }
}

void GraphModifier::changeTheme(int theme)
{
    Q3DTheme *currentTheme = m_graph->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(theme));
    emit backgroundEnabledChanged(currentTheme->isBackgroundEnabled());
    emit gridEnabledChanged(currentTheme->isGridEnabled());
    emit fontChanged(currentTheme->font());
    emit fontSizeChanged(currentTheme->font().pointSize());
}

void GraphModifier::changeShadowQuality(int quality)
{
    QAbstract3DGraph::ShadowQuality sq = QAbstract3DGraph::ShadowQuality(quality);
    m_graph->setShadowQuality(sq);
    emit shadowQualityChanged(quality);
}

void GraphModifier::shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality shadowQuality)
{
    int quality = int(shadowQuality);
    // Updates the UI component to show correct shadow quality
    emit shadowQualityChanged(quality);
}

void GraphModifier::changeLabelRotation(int rotation)
{
    m_ZAxis->setLabelAutoRotation(float(rotation));
    m_RowAxis->setLabelAutoRotation(float(rotation));
    m_ColAxis->setLabelAutoRotation(float(rotation));
}

void GraphModifier::setAxisTitleVisibility(bool enabled)
{
    m_ZAxis->setTitleVisible(enabled);
    m_RowAxis->setTitleVisible(enabled);
    m_ColAxis->setTitleVisible(enabled);
}

void GraphModifier::setAxisTitleFixed(bool enabled)
{
    m_ZAxis->setTitleFixed(enabled);
    m_RowAxis->setTitleFixed(enabled);
    m_ColAxis->setTitleFixed(enabled);
}

void GraphModifier::zoomToSelectedBar()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();
    m_animationCameraZoom.stop();
    m_animationCameraTarget.stop();

    Q3DCamera *camera = m_graph->scene()->activeCamera();
    float currentX = camera->xRotation();
    float currentY = camera->yRotation();
    float currentZoom = camera->zoomLevel();
    QVector3D currentTarget = camera->target();

    m_animationCameraX.setStartValue(QVariant::fromValue(currentX));
    m_animationCameraY.setStartValue(QVariant::fromValue(currentY));
    m_animationCameraZoom.setStartValue(QVariant::fromValue(currentZoom));
    m_animationCameraTarget.setStartValue(QVariant::fromValue(currentTarget));

    QPoint selectedBar = m_graph->selectedSeries()
            ? m_graph->selectedSeries()->selectedBar()
            : QBar3DSeries::invalidSelectionPosition();

    if (selectedBar != QBar3DSeries::invalidSelectionPosition()) {
        // Normalize selected bar position within axis range to determine target coordinates
        QVector3D endTarget;
        float xMin = m_graph->columnAxis()->min();
        float xRange = m_graph->columnAxis()->max() - xMin;
        float zMin = m_graph->rowAxis()->min();
        float zRange = m_graph->rowAxis()->max() - zMin;
        endTarget.setX((selectedBar.y() - xMin) / xRange * 2.0f - 1.0f);
        endTarget.setZ((selectedBar.x() - zMin) / zRange * 2.0f - 1.0f);

        // Rotate the camera so that it always points approximately to the graph center
        qreal endAngleX = 90.0 - qRadiansToDegrees(qAtan(qreal(endTarget.z() / endTarget.x())));
        if (endTarget.x() > 0.0f)
            endAngleX -= 180.0f;
        float barValue = m_graph->selectedSeries()->dataProxy()->itemAt(selectedBar.x(),
                                                                        selectedBar.y())->value();
        float endAngleY = barValue >= 0.0f ? 30.0f : -30.0f;
        if (m_graph->valueAxis()->reversed())
            endAngleY *= -1.0f;

        m_animationCameraX.setEndValue(QVariant::fromValue(float(endAngleX)));
        m_animationCameraY.setEndValue(QVariant::fromValue(endAngleY));
        m_animationCameraZoom.setEndValue(QVariant::fromValue(250));
        m_animationCameraTarget.setEndValue(QVariant::fromValue(endTarget));
    } else {
        // No selected bar, so return to the default view
        m_animationCameraX.setEndValue(QVariant::fromValue(m_defaultAngleX));
        m_animationCameraY.setEndValue(QVariant::fromValue(m_defaultAngleY));
        m_animationCameraZoom.setEndValue(QVariant::fromValue(m_defaultZoom));
        m_animationCameraTarget.setEndValue(QVariant::fromValue(m_defaultTarget));
    }

    m_animationCameraX.start();
    m_animationCameraY.start();
    m_animationCameraZoom.start();
    m_animationCameraTarget.start();
}

QList<QBar3DSeries *> GraphModifier::getBar3DSeriesList(QMap<QString,QList<QList<qreal> > > list)
{
    QList<QBar3DSeries *> seriesList;
    int seriesCount = list.count();

    qDebug()<<"seriesCount "<<seriesCount;

    foreach (QString key, list.keys())
    {
        QBar3DSeries * series = new QBar3DSeries;
        QBarDataArray *dataSet = new QBarDataArray;
        QBarDataRow *dataRow;
        int rowCount = list[key].count();

        qDebug()<<"rowCount "<<rowCount;

        QList<QList<qreal>> row = list[key];
        for(int r = 0; r < rowCount; r++)
        {
            QList<qreal> col = row[r];
            int colCount = col.count();

            qDebug()<<"colCount "<<colCount;

            dataRow = new QBarDataRow(colCount);
            for(int c = 0; c < colCount; c++)
            {
                qDebug()<<"col[c] "<<col[c];
                (*dataRow)[c].setValue(col[c]);
            }
            dataSet->append(dataRow);
        }

        series->dataProxy()->resetArray(dataSet);
        seriesList.append(series);
        series->setName(key);
        series->setItemLabelFormat(key + "-@colLabel @rowLabel: @valueLabel");
        series->setMesh(QtDataVisualization::QAbstract3DSeries::MeshBevelBar);
        series->setMeshSmooth(false);
    }
    return seriesList;
}


