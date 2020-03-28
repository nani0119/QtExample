#include "surfacegraph.h"
#include <QtCore/qmath.h>

SurfaceGraph::SurfaceGraph(Q3DSurface *surface): m_graph(surface)
{
    changeTheme(Q3DTheme::ThemeQt);
    setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
    setDataSurfaceAxis();

    m_dataProxy = new QSurfaceDataProxy();
    m_surfaceSeries = new QSurface3DSeries(m_dataProxy);
    setSurfaceSeries();

    m_graph->addSeries(m_surfaceSeries);

    fillSqrtSinProxy();

}


SurfaceGraph::~SurfaceGraph()
{
    delete m_graph;
}

const float sampleMin = -8.0f;
const float sampleMax = 8.0f;
const int sampleCountX = 50;
const int sampleCountZ = 50;

void SurfaceGraph::setDataSurfaceAxis()
{
    m_graph->setAxisX(new QValue3DAxis);
    m_graph->setAxisY(new QValue3DAxis);
    m_graph->setAxisZ(new QValue3DAxis);

    m_graph->axisX()->setLabelFormat("%.2f");
    m_graph->axisZ()->setLabelFormat("%.2f");
    m_graph->axisX()->setRange(sampleMin, sampleMax);
    m_graph->axisY()->setRange(0.0f, 2.0f);
    m_graph->axisZ()->setRange(sampleMin, sampleMax);
    m_graph->axisX()->setLabelAutoRotation(30);
    m_graph->axisY()->setLabelAutoRotation(90);
    m_graph->axisZ()->setLabelAutoRotation(30);
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
void SurfaceGraph::resetAxisRange()
{
    // Reset range sliders for Sqrt&Sin
    m_rangeMinX = sampleMin;
    m_rangeMinZ = sampleMin;
    m_stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
    m_stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);
    m_axisMinSliderX->setMaximum(sampleCountX - 2);
    m_axisMinSliderX->setValue(0);
    m_axisMaxSliderX->setMaximum(sampleCountX - 1);
    m_axisMaxSliderX->setValue(sampleCountX - 1);
    m_axisMinSliderZ->setMaximum(sampleCountZ - 2);
    m_axisMinSliderZ->setValue(0);
    m_axisMaxSliderZ->setMaximum(sampleCountZ - 1);
    m_axisMaxSliderZ->setValue(sampleCountZ - 1);
}

void SurfaceGraph::setSurfaceSeries()
{
    setDrawMode(3);
    m_surfaceSeries->setFlatShadingEnabled(true);
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

void SurfaceGraph::fillSqrtSinProxy()
{
    float stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
    float stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);

    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(sampleCountZ);
    for (int i = 0 ; i < sampleCountZ ; i++) {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);
        // Keep values within range bounds, since just adding step can cause minor drift due
        // to the rounding errors.
        float z = qMin(sampleMax, (i * stepZ + sampleMin));
        int index = 0;
        for (int j = 0; j < sampleCountX; j++) {
            float x = qMin(sampleMax, (j * stepX + sampleMin));
            float R = qSqrt(z * z + x * x) + 0.01f;
            float y = (qSin(R) / R + 0.24f) * 1.61f;
            (*newRow)[index++].setPosition(QVector3D(x, y, z));
        }
        *dataArray << newRow;
    }

    m_dataProxy->resetArray(dataArray);
}
