#ifndef GRAPHMODIFIER_H
#define GRAPHMODIFIER_H

#include "BarDataInterface.h"
#include <QObject>
#include <QPropertyAnimation>
#include <QtDataVisualization/Q3DBars>
using namespace QtDataVisualization;

class GraphModifier : public QObject
{
    Q_OBJECT
public:
    explicit GraphModifier(Q3DBars *bargraph);
    ~GraphModifier();
    void setDataSource(IBarDataInterface* dataSoureInterface);
    void changePresetCamera();
    void changeLabelBackground();
    void changeFont(const QFont &font);
    void changeFontSize(int fontsize);
    void rotateX(int rotation);
    void rotateY(int rotation);
    void setBackgroundEnabled(int enabled);
    void setGridEnabled(int enabled);
    void setSmoothBars(int smooth);
    void setReverseValueAxis(int enabled);
    void setReflection(bool enabled);
    QCategory3DAxis* getGraphModifierRowAxis();

public Q_SLOTS:
    void changeRange(int range);
    void changeStyle(int style);
    void changeSelectionMode(int selectionMode);
    void changeTheme(int theme);
    void changeShadowQuality(int quality);
    void shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality shadowQuality);
    void changeLabelRotation(int rotation);
    void setAxisTitleVisibility(bool enabled);
    void setAxisTitleFixed(bool enabled);
    void zoomToSelectedBar();


Q_SIGNALS:
    void shadowQualityChanged(int quality);
    void backgroundEnabledChanged(bool enabled);
    void gridEnabledChanged(bool enabled);
    void fontChanged(QFont font);
    void fontSizeChanged(int size);

private:
     Q3DBars *m_graph;
     IBarDataInterface* dataSource;
     QValue3DAxis *m_ZAxis;
     QCategory3DAxis *m_RowAxis;
     QCategory3DAxis *m_ColAxis;
     QList<QBar3DSeries *> seriesList;
     int m_fontSize;
     float m_defaultAngleX;
     float m_defaultAngleY;
     float m_defaultZoom;
     QVector3D m_defaultTarget;
     QPropertyAnimation m_animationCameraX;
     QPropertyAnimation m_animationCameraY;
     QPropertyAnimation m_animationCameraZoom;
     QPropertyAnimation m_animationCameraTarget;
     float m_xRotation;
     float m_yRotation;
     bool m_smooth;
     QAbstract3DSeries::Mesh m_barMesh;

};

#endif // GRAPHMODIFIER_H
