#ifndef SURFACEGRAPH_H
#define SURFACEGRAPH_H

#include <QObject>
#include <QSlider>
#include <QtDataVisualization>
using namespace QtDataVisualization;


class SurfaceGraph : public QObject
{
    Q_OBJECT
public:
    explicit SurfaceGraph(Q3DSurface *surface);
    ~SurfaceGraph();

    void setAxisMinSliderX(QSlider *slider);
    void setAxisMaxSliderX(QSlider *slider);
    void setAxisMinSliderZ(QSlider *slider);
    void setAxisMaxSliderZ(QSlider *slider);
    void resetAxisRange();


public slots:
    void setShadowQuality(int quality);
    void setDrawMode(int mode);

    void toggleModeNone();
    void toggleModeItem() ;
    void toggleModeSliceRow();
    void toggleModeSliceColumn();

    void adjustXMin(int min);
    void adjustXMax(int max);
    void adjustZMin(int min);
    void adjustZMax(int max);

    void changeTheme(int theme);

    void setBlackToYellowGradient();
    void setGreenToRedGradient();

    void updateHeightMapData(QString file);

    void toggleSurfaceTexture(bool enable);

private:
   void setHeightMapSurfaceAxis();
   void setSurfaceSeries();
   void setAxisXRange(float min, float max);
   void setAxisZRange(float min, float max);
   //data provider
   void fillHeightMapProxy();

   Q3DSurface *m_graph;
   QSlider *m_axisMinSliderX;
   QSlider *m_axisMaxSliderX;
   QSlider *m_axisMinSliderZ;
   QSlider *m_axisMaxSliderZ;
   float m_rangeMinX;
   float m_rangeMinZ;
   float m_stepX;
   float m_stepZ;

   QHeightMapSurfaceDataProxy *m_heightMapProxy;
   QSurface3DSeries* m_surfaceSeries;
   int m_heightMapWidth;
   int m_heightMapHeight;
   QString imgFile;
};

#endif // SURFACEGRAPH_H
