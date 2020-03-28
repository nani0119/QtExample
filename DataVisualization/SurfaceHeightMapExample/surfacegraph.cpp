#include "surfacegraph.h"
#include <QtCore/qmath.h>

#define  USE_NUMBER 1

SurfaceGraph::SurfaceGraph(Q3DSurface *surface): m_graph(surface),imgFile(":/img/mountain")
{
    changeTheme(Q3DTheme::ThemeQt);
    setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
    setHeightMapSurfaceAxis();

    m_heightMapProxy = new QHeightMapSurfaceDataProxy();
    m_surfaceSeries = new QSurface3DSeries(m_heightMapProxy);
#ifdef USE_NUMBER
    m_surfaceSeries->setItemLabelFormat("W:@xLabel, H:@zLabel, D:@yLabel");
#endif
    setSurfaceSeries();

    m_graph->addSeries(m_surfaceSeries);

    fillHeightMapProxy();

}

SurfaceGraph::~SurfaceGraph()
{
    delete m_graph;
}

void SurfaceGraph::setAxisMinSliderX(QSlider *slider)
{
    m_axisMinSliderX = slider;
}

void SurfaceGraph::setAxisMaxSliderX(QSlider *slider)
{
    m_axisMaxSliderX = slider;
}

void SurfaceGraph::setAxisMinSliderZ(QSlider *slider)
{
    m_axisMinSliderZ = slider;
}

void SurfaceGraph::setAxisMaxSliderZ(QSlider *slider)
{
    m_axisMaxSliderZ = slider;
}

void SurfaceGraph::setSurfaceSeries()
{
    setDrawMode(1);
    m_surfaceSeries->setFlatShadingEnabled(false);
}

void SurfaceGraph::changeTheme(int theme)
{
    qDebug()<<__func__;
    m_graph->activeTheme()->setType(Q3DTheme::Theme(theme));
}

void SurfaceGraph::setShadowQuality(int quality)
{
    QAbstract3DGraph::ShadowQuality sq = QAbstract3DGraph::ShadowQuality(quality);
    m_graph->setShadowQuality(sq);
}

void SurfaceGraph::setDrawMode(int mode)
{
    QSurface3DSeries::DrawFlag flag = QSurface3DSeries::DrawFlag(mode+1);
    m_surfaceSeries->setDrawMode(flag);
}


void SurfaceGraph::toggleModeNone()
{
    m_graph->setSelectionMode(QAbstract3DGraph::SelectionNone);
}

void SurfaceGraph::toggleModeItem()
{
    m_graph->setSelectionMode(QAbstract3DGraph::SelectionItem);
}

void SurfaceGraph::toggleModeSliceRow()
{
    m_graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow
                                                      | QAbstract3DGraph::SelectionSlice);
}

void SurfaceGraph::toggleModeSliceColumn()
{
    m_graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndColumn
                                                         | QAbstract3DGraph::SelectionSlice);
}

void SurfaceGraph::setAxisXRange(float min, float max)
{
    m_graph->axisX()->setRange(min, max);
}

void SurfaceGraph::setAxisZRange(float min, float max)
{
    m_graph->axisZ()->setRange(min, max);
}


void SurfaceGraph::adjustXMin(int min)
{
    float minX = m_stepX * float(min) + m_rangeMinX;

    int max = m_axisMaxSliderX->value();
    if (min >= max) {
        max = min + 1;
        m_axisMaxSliderX->setValue(max);
    }
    float maxX = m_stepX * max + m_rangeMinX;

    setAxisXRange(minX, maxX);
}

void SurfaceGraph::adjustXMax(int max)
{
    float maxX = m_stepX * float(max) + m_rangeMinX;

    int min = m_axisMinSliderX->value();
    if (max <= min) {
        min = max - 1;
        m_axisMinSliderX->setValue(min);
    }
    float minX = m_stepX * min + m_rangeMinX;

    setAxisXRange(minX, maxX);
}

void SurfaceGraph::adjustZMin(int min)
{
    float minZ = m_stepZ * float(min) + m_rangeMinZ;

    int max = m_axisMaxSliderZ->value();
    if (min >= max) {
        max = min + 1;
        m_axisMaxSliderZ->setValue(max);
    }
    float maxZ = m_stepZ * max + m_rangeMinZ;

    setAxisZRange(minZ, maxZ);
}

void SurfaceGraph::adjustZMax(int max)
{
    float maxX = m_stepZ * float(max) + m_rangeMinZ;

    int min = m_axisMinSliderZ->value();
    if (max <= min) {
        min = max - 1;
        m_axisMinSliderZ->setValue(min);
    }
    float minX = m_stepZ * min + m_rangeMinZ;

    setAxisZRange(minX, maxX);
}

void SurfaceGraph::setBlackToYellowGradient()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    m_surfaceSeries->setBaseGradient(gr);
    m_surfaceSeries->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

void SurfaceGraph::setGreenToRedGradient()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::darkGreen);
    gr.setColorAt(0.5, Qt::yellow);
    gr.setColorAt(0.8, Qt::red);
    gr.setColorAt(1.0, Qt::darkRed);

    m_surfaceSeries->setBaseGradient(gr);
    m_surfaceSeries->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

void SurfaceGraph::toggleSurfaceTexture(bool enable)
{
    if (enable)
        m_surfaceSeries->setTextureFile(imgFile);
    else
        m_surfaceSeries->setTextureFile("");
}

void SurfaceGraph::setHeightMapSurfaceAxis()
{
    m_graph->setAxisX(new QValue3DAxis);
    m_graph->setAxisY(new QValue3DAxis);
    m_graph->setAxisZ(new QValue3DAxis);
}

void SurfaceGraph::updateHeightMapData(QString file)
{
    qDebug()<<__func__<<"  "<< file;
#ifdef USE_NUMBER
    imgFile = file;
    QImage heightMapImage(file);
    m_heightMapProxy->setHeightMap(heightMapImage);

    m_heightMapWidth = heightMapImage.width();
    m_heightMapHeight = heightMapImage.height();
    m_heightMapProxy->setValueRanges(0.0f, m_heightMapWidth, 0.0f, m_heightMapHeight);
    resetAxisRange();

    //qDebug()<<"formate:"<<m_surfaceSeries->itemLabelFormat();
    //m_surfaceSeries->setTexture(heightMapImage);
#else
    imgFile = file;
    QImage heightMapImage(file);
    m_heightMapProxy->setHeightMap(heightMapImage);

    m_heightMapProxy->setValueRanges(34.0f, 40.0f, 18.0f, 24.0f);
    m_heightMapWidth = heightMapImage.width();
    m_heightMapHeight = heightMapImage.height();
#endif
}

//===============================================
#ifdef USE_NUMBER
const int heightMapGridStepX = 1;
const int heightMapGridStepZ = 1;
#else
const int heightMapGridStepZ = 6;
const int heightMapGridStepX = 6;
#endif
void SurfaceGraph::resetAxisRange()
{
#ifdef USE_NUMBER

    m_graph->axisX()->setRange(0.0f, m_heightMapWidth);
    m_graph->axisY()->setAutoAdjustRange(true);
    m_graph->axisZ()->setRange(0.0f, m_heightMapHeight);
    m_graph->axisX()->setLabelFormat("%.1f ");
    m_graph->axisY()->setLabelFormat("%.1f ");
    m_graph->axisZ()->setLabelFormat("%.1f ");

    m_graph->axisX()->setTitle(QStringLiteral("Width"));
    m_graph->axisY()->setTitle(QStringLiteral("Depth"));
    m_graph->axisZ()->setTitle(QStringLiteral("Height"));

    // Reset range sliders for height map
    int mapGridCountX = m_heightMapWidth / heightMapGridStepX;
    int mapGridCountZ = m_heightMapHeight / heightMapGridStepZ;
    m_rangeMinX = 0.0f;
    m_rangeMinZ = 0.0f;
    m_stepX = 1;
    m_stepZ = 1;
    m_axisMinSliderX->setMaximum(mapGridCountX);
    m_axisMinSliderX->setValue(0);

    m_axisMaxSliderX->setMaximum(mapGridCountX);
    m_axisMaxSliderX->setValue(mapGridCountX);

    m_axisMinSliderZ->setMaximum(mapGridCountZ);
    m_axisMinSliderZ->setValue(0);

    m_axisMaxSliderZ->setMaximum(mapGridCountZ);
    m_axisMaxSliderZ->setValue(mapGridCountZ);

 #else

    m_graph->axisX()->setLabelFormat("%.1f N");
    m_graph->axisZ()->setLabelFormat("%.1f E");
    m_graph->axisX()->setRange(34.0f, 40.0f);
    m_graph->axisY()->setAutoAdjustRange(true);
    m_graph->axisZ()->setRange(18.0f, 24.0f);

    m_graph->axisX()->setTitle(QStringLiteral("Latitude"));
    m_graph->axisY()->setTitle(QStringLiteral("Height"));
    m_graph->axisZ()->setTitle(QStringLiteral("Longitude"));

    // Reset range sliders for height map
    int mapGridCountX = m_heightMapWidth / heightMapGridStepX;
    int mapGridCountZ = m_heightMapHeight / heightMapGridStepZ;
    m_rangeMinX = 34.0f;
    m_rangeMinZ = 18.0f;
    m_stepX = 6.0f / float(mapGridCountX - 1);
    m_stepZ = 6.0f / float(mapGridCountZ - 1);
    m_axisMinSliderX->setMaximum(mapGridCountX - 2);
    m_axisMinSliderX->setValue(0);
    m_axisMaxSliderX->setMaximum(mapGridCountX - 1);
    m_axisMaxSliderX->setValue(mapGridCountX - 1);
    m_axisMinSliderZ->setMaximum(mapGridCountZ - 2);
    m_axisMinSliderZ->setValue(0);
    m_axisMaxSliderZ->setMaximum(mapGridCountZ - 1);
    m_axisMaxSliderZ->setValue(mapGridCountZ - 1);

#endif
}

void SurfaceGraph::fillHeightMapProxy()
{
#ifdef USE_NUMBER

    imgFile = ":/img/mountain";
    QImage heightMapImage(":/img/mountain");
    m_heightMapWidth = heightMapImage.width();
    m_heightMapHeight = heightMapImage.height();

    m_heightMapProxy->setHeightMap(heightMapImage);
    m_heightMapProxy->setValueRanges(0.0f, m_heightMapWidth, 0.0f, m_heightMapHeight);

#else
    QImage heightMapImage(":/img/mountain");
    m_heightMapProxy->setHeightMap(heightMapImage);
    m_heightMapProxy->setValueRanges(34.0f, 40.0f, 18.0f, 24.0f);
    m_heightMapWidth = heightMapImage.width();
    m_heightMapHeight = heightMapImage.height();
#endif
}

