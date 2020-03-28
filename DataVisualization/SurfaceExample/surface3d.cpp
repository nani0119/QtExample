#include "surface3d.h"
#include "surfacegraph.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QtDataVisualization>

using namespace QtDataVisualization;

SurFace3D::SurFace3D(QWidget *parent)
    : QMainWindow(parent)
{
    Q3DSurface *graph = new Q3DSurface;
    QWidget* container = QWidget::createWindowContainer(graph);
    if (!graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
        return;
    }

    QSize screenSize = graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 1.6));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->setAlignment(Qt::AlignTop);

    // Selection Mode
    QGroupBox *selectionGroupBox = new QGroupBox(QStringLiteral("Selection Mode"));
    QRadioButton *modeNoneRB = new QRadioButton();
    modeNoneRB->setText(QStringLiteral("No selection"));
    modeNoneRB->setChecked(false);

    QRadioButton *modeItemRB = new QRadioButton();
    modeItemRB->setText(QStringLiteral("Item"));
    modeItemRB->setChecked(false);
    modeItemRB->setChecked(true);

    QRadioButton *modeSliceRowRB = new QRadioButton();
    modeSliceRowRB->setText(QStringLiteral("Row Slice"));
    modeSliceRowRB->setChecked(false);

    QRadioButton *modeSliceColumnRB = new QRadioButton();
    modeSliceColumnRB->setText(QStringLiteral("Column Slice"));
    modeSliceColumnRB->setChecked(false);

    QVBoxLayout *selectionVBox = new QVBoxLayout;
    selectionVBox->addWidget(modeNoneRB);
    selectionVBox->addWidget(modeItemRB);
    selectionVBox->addWidget(modeSliceRowRB);
    selectionVBox->addWidget(modeSliceColumnRB);
    selectionGroupBox->setLayout(selectionVBox);
    vLayout->addWidget(selectionGroupBox);

    // X
    QSlider *axisMinSliderX = new QSlider(Qt::Horizontal);
    axisMinSliderX->setMinimum(0);
    axisMinSliderX->setTickInterval(1);
    axisMinSliderX->setEnabled(true);
    QSlider *axisMaxSliderX = new QSlider(Qt::Horizontal);
    axisMaxSliderX->setMinimum(1);
    axisMaxSliderX->setTickInterval(1);
    axisMaxSliderX->setEnabled(true);

    vLayout->addWidget(new QLabel(QStringLiteral("Column range")));
    vLayout->addWidget(axisMinSliderX);
    vLayout->addWidget(axisMaxSliderX);

    // Z
    QSlider *axisMinSliderZ = new QSlider(Qt::Horizontal);
    axisMinSliderZ->setMinimum(0);
    axisMinSliderZ->setTickInterval(1);
    axisMinSliderZ->setEnabled(true);
    QSlider *axisMaxSliderZ = new QSlider(Qt::Horizontal);
    axisMaxSliderZ->setMinimum(1);
    axisMaxSliderZ->setTickInterval(1);
    axisMaxSliderZ->setEnabled(true);
    vLayout->addWidget(new QLabel(QStringLiteral("Row range")));
    vLayout->addWidget(axisMinSliderZ);
    vLayout->addWidget(axisMaxSliderZ);



    // Theme
    QComboBox *themeList = new QComboBox();
    themeList->addItem(QStringLiteral("Qt"));
    themeList->addItem(QStringLiteral("Primary Colors"));
    themeList->addItem(QStringLiteral("Digia"));
    themeList->addItem(QStringLiteral("Stone Moss"));
    themeList->addItem(QStringLiteral("Army Blue"));
    themeList->addItem(QStringLiteral("Retro"));
    themeList->addItem(QStringLiteral("Ebony"));
    themeList->addItem(QStringLiteral("Isabelle"));
    themeList->setCurrentIndex(0);
    vLayout->addWidget(new QLabel(QStringLiteral("Theme")));
    vLayout->addWidget(themeList);

    // Draw mode
    QComboBox *drawMode = new QComboBox();
    drawMode->addItem(QStringLiteral("DrawWireframe"), QSurface3DSeries::DrawWireframe);
    drawMode->addItem(QStringLiteral("DrawSurface"), QSurface3DSeries::DrawSurface);
    drawMode->addItem(QStringLiteral("DrawSurfaceAndWireframe"), QSurface3DSeries::DrawSurfaceAndWireframe);
    drawMode->setCurrentIndex(2);
    vLayout->addWidget(new QLabel(QStringLiteral("draw Mode")));
    vLayout->addWidget(drawMode);

    // color
    QGroupBox *colorGroupBox = new QGroupBox(QStringLiteral("Custom gradient"));

    QLinearGradient grBtoY(0, 0, 1, 100);
    grBtoY.setColorAt(1.0, Qt::black);
    grBtoY.setColorAt(0.67, Qt::blue);
    grBtoY.setColorAt(0.33, Qt::red);
    grBtoY.setColorAt(0.0, Qt::yellow);
    QPixmap pm(24, 100);
    QPainter pmp(&pm);
    pmp.setBrush(QBrush(grBtoY));
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, 24, 100);
    QPushButton *gradientBtoYPB = new QPushButton();
    gradientBtoYPB->setIcon(QIcon(pm));
    gradientBtoYPB->setIconSize(QSize(24, 100));

    QLinearGradient grGtoR(0, 0, 1, 100);
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);
    pmp.setBrush(QBrush(grGtoR));
    pmp.drawRect(0, 0, 24, 100);
    QPushButton *gradientGtoRPB = new QPushButton();
    gradientGtoRPB->setIcon(QIcon(pm));
    gradientGtoRPB->setIconSize(QSize(24, 100));

    QHBoxLayout *colorHBox = new QHBoxLayout;
    colorHBox->addWidget(gradientBtoYPB);
    colorHBox->addWidget(gradientGtoRPB);
    colorGroupBox->setLayout(colorHBox);
    vLayout->addWidget(colorGroupBox);


    hLayout->addWidget(container,1);
    hLayout->addLayout(vLayout);

    SurfaceGraph *modifier = new SurfaceGraph(graph);
    modifier->setAxisMinSliderX(axisMinSliderX);
    modifier->setAxisMaxSliderX(axisMaxSliderX);
    modifier->setAxisMinSliderZ(axisMinSliderZ);
    modifier->setAxisMaxSliderZ(axisMaxSliderZ);
    modifier->resetAxisRange();


    QObject::connect(modeNoneRB, &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeNone);
    QObject::connect(modeItemRB,  &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeItem);
    QObject::connect(modeSliceRowRB,  &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeSliceRow);
    QObject::connect(modeSliceColumnRB,  &QRadioButton::toggled,
                     modifier, &SurfaceGraph::toggleModeSliceColumn);

    QObject::connect(axisMinSliderX, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustXMin);
    QObject::connect(axisMaxSliderX, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustXMax);
    QObject::connect(axisMinSliderZ, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustZMin);
    QObject::connect(axisMaxSliderZ, &QSlider::valueChanged,
                     modifier, &SurfaceGraph::adjustZMax);

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)),
                     modifier, SLOT(changeTheme(int)));

    QObject::connect(drawMode, SIGNAL(currentIndexChanged(int)),
                     modifier, SLOT(setDrawMode(int)));

    QObject::connect(gradientBtoYPB, &QPushButton::pressed,
                     modifier, &SurfaceGraph::setBlackToYellowGradient);
    QObject::connect(gradientGtoRPB, &QPushButton::pressed,
                     modifier, &SurfaceGraph::setGreenToRedGradient);


    QWidget* widget = new QWidget;
    widget->setLayout(hLayout);
    setWindowTitle("surface example");
    setCentralWidget(widget);
}

SurFace3D::~SurFace3D()
{
}

