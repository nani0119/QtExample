#include "graphmodifier.h"
#include "BarDataInterface.h"
#include "bar.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>
#include <QCheckBox>
#include <QFontComboBox>
#include <QMessageBox>
#include <QPluginLoader>
#include <QDir>

#include <QScrollArea>
#include <QtDataVisualization>
using namespace QtDataVisualization;

Bar::Bar(QWidget *parent) : QWidget(parent),barDataSource(nullptr)
{
    Q3DBars *widgetGraph = new Q3DBars;

    if (!widgetGraph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
        return;
    }

    QWidget *container = QWidget::createWindowContainer(widgetGraph);

    QSize screenSize = widgetGraph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width()/2, screenSize.height()/1.5));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    container->setFocusPolicy(Qt::StrongFocus);


    // 主布局　左：3DBar 右：操作
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(container,1);

    // 保存各种操作
    QVBoxLayout *vLayout = new QVBoxLayout;
    hLayout->addLayout(vLayout);

    //XY　rotate
    QLabel *hRotate = new QLabel(QStringLiteral("Rotate horizontally"));
    QSlider* rotationSliderX = new QSlider(Qt::Horizontal);
    rotationSliderX->setTickInterval(30);
    rotationSliderX->setTickPosition(QSlider::TicksBelow);
    rotationSliderX->setMinimum(-180);
    rotationSliderX->setValue(0);
    rotationSliderX->setMaximum(180);
    vLayout->addWidget(hRotate);
    vLayout->addWidget(rotationSliderX,0,Qt::AlignTop);

    QLabel *vRotate = new QLabel(QStringLiteral("Rotate vertically"));
    QSlider *rotationSliderY = new QSlider(Qt::Horizontal);
    rotationSliderY->setTickInterval(15);
    rotationSliderY->setTickPosition(QSlider::TicksAbove);
    rotationSliderY->setMinimum(-90);
    rotationSliderY->setValue(0);
    rotationSliderY->setMaximum(90);
    vLayout->addWidget(vRotate);
    vLayout->addWidget(rotationSliderY,0,Qt::AlignTop);

    QPushButton *labelButton = new QPushButton();
    labelButton->setText(QStringLiteral("Change label style"));
    vLayout->addWidget(labelButton, 0, Qt::AlignTop);


    QPushButton *cameraButton = new QPushButton();
    cameraButton->setText(QStringLiteral("Change camera preset"));
    vLayout->addWidget(cameraButton, 0, Qt::AlignTop);

    QPushButton *zoomToSelectedButton = new QPushButton();
    zoomToSelectedButton->setText(QStringLiteral("Zoom to selected bar"));
    vLayout->addWidget(zoomToSelectedButton, 0, Qt::AlignTop);

    QCheckBox *backgroundCheckBox = new QCheckBox();
    backgroundCheckBox->setText(QStringLiteral("Show background"));
    backgroundCheckBox->setChecked(false);
    vLayout->addWidget(backgroundCheckBox);

    QCheckBox *gridCheckBox = new QCheckBox();
    gridCheckBox->setText(QStringLiteral("Show grid"));
    gridCheckBox->setChecked(true);
    vLayout->addWidget(gridCheckBox);


    QCheckBox *smoothCheckBox = new QCheckBox();
    smoothCheckBox->setText(QStringLiteral("Smooth bars"));
    smoothCheckBox->setChecked(false);
    vLayout->addWidget(smoothCheckBox);

    QCheckBox *reflectionCheckBox = new QCheckBox();
    reflectionCheckBox->setText(QStringLiteral("Show reflections"));
    reflectionCheckBox->setChecked(false);
    vLayout->addWidget(reflectionCheckBox);

//    QCheckBox *seriesCheckBox = new QCheckBox();
//    seriesCheckBox->setText(QStringLiteral("Show second series"));
//    seriesCheckBox->setChecked(false);
//    vLayout->addWidget(seriesCheckBox);

    QCheckBox *reverseValueAxisCheckBox = new QCheckBox();
    reverseValueAxisCheckBox->setText(QStringLiteral("Reverse value axis"));
    reverseValueAxisCheckBox->setChecked(false);
    vLayout->addWidget(reverseValueAxisCheckBox);

    QCheckBox *axisTitlesVisibleCB = new QCheckBox();
    axisTitlesVisibleCB->setText(QStringLiteral("Axis titles visible"));
    axisTitlesVisibleCB->setChecked(true);
    vLayout->addWidget(axisTitlesVisibleCB);


    QCheckBox *axisTitlesFixedCB = new QCheckBox();
    axisTitlesFixedCB->setText(QStringLiteral("Axis titles fixed"));
    axisTitlesFixedCB->setChecked(true);
    vLayout->addWidget(axisTitlesFixedCB);

    QComboBox *barStyleList = new QComboBox();
    barStyleList->addItem(QStringLiteral("Bar"), int(QAbstract3DSeries::MeshBar));
    barStyleList->addItem(QStringLiteral("Pyramid"), int(QAbstract3DSeries::MeshPyramid));
    barStyleList->addItem(QStringLiteral("Cone"), int(QAbstract3DSeries::MeshCone));
    barStyleList->addItem(QStringLiteral("Cylinder"), int(QAbstract3DSeries::MeshCylinder));
    barStyleList->addItem(QStringLiteral("Bevel bar"), int(QAbstract3DSeries::MeshBevelBar));
    barStyleList->addItem(QStringLiteral("Sphere"), int(QAbstract3DSeries::MeshSphere));
    barStyleList->setCurrentIndex(4);
    vLayout->addWidget(new QLabel(QStringLiteral("Change bar style")));
    vLayout->addWidget(barStyleList);

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
    vLayout->addWidget(new QLabel(QStringLiteral("Change theme")));
    vLayout->addWidget(themeList);

    QComboBox *shadowQuality = new QComboBox();
    shadowQuality->addItem(QStringLiteral("None"));
    shadowQuality->addItem(QStringLiteral("Low"));
    shadowQuality->addItem(QStringLiteral("Medium"));
    shadowQuality->addItem(QStringLiteral("High"));
    shadowQuality->addItem(QStringLiteral("Low Soft"));
    shadowQuality->addItem(QStringLiteral("Medium Soft"));
    shadowQuality->addItem(QStringLiteral("High Soft"));
    shadowQuality->setCurrentIndex(5);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust shadow quality")));
    vLayout->addWidget(shadowQuality);


    QFontComboBox *fontList = new QFontComboBox();
    fontList->setCurrentFont(QFont("Times New Roman"));
    vLayout->addWidget(new QLabel(QStringLiteral("Change font")));
    vLayout->addWidget(fontList);


    QSlider *fontSizeSlider = new QSlider(Qt::Horizontal);
    fontSizeSlider->setTickInterval(10);
    fontSizeSlider->setTickPosition(QSlider::TicksBelow);
    fontSizeSlider->setMinimum(1);
    fontSizeSlider->setValue(30);
    fontSizeSlider->setMaximum(100);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust font size")));
    vLayout->addWidget(fontSizeSlider);

    QSlider *axisLabelRotationSlider = new QSlider(Qt::Horizontal);
    axisLabelRotationSlider->setTickInterval(10);
    axisLabelRotationSlider->setTickPosition(QSlider::TicksBelow);
    axisLabelRotationSlider->setMinimum(0);
    axisLabelRotationSlider->setValue(30);
    axisLabelRotationSlider->setMaximum(90);
    vLayout->addWidget(new QLabel(QStringLiteral("Axis label rotation")));
    vLayout->addWidget(axisLabelRotationSlider, 1, Qt::AlignTop);

    QComboBox *selectionModeList = new QComboBox();
    selectionModeList->addItem(QStringLiteral("None"),
                               int(QAbstract3DGraph::SelectionNone));
    selectionModeList->addItem(QStringLiteral("Bar"),
                               int(QAbstract3DGraph::SelectionItem));
    selectionModeList->addItem(QStringLiteral("Row"),
                               int(QAbstract3DGraph::SelectionRow));
    selectionModeList->addItem(QStringLiteral("Bar and Row"),
                               int(QAbstract3DGraph::SelectionItemAndRow));
    selectionModeList->addItem(QStringLiteral("Column"),
                               int(QAbstract3DGraph::SelectionColumn));
    selectionModeList->addItem(QStringLiteral("Bar and Column"),
                               int(QAbstract3DGraph::SelectionItemAndColumn));
    selectionModeList->addItem(QStringLiteral("Row and Column"),
                               int(QAbstract3DGraph::SelectionRowAndColumn));
    selectionModeList->addItem(QStringLiteral("Bar, Row and Column"),
                               int(QAbstract3DGraph::SelectionItemRowAndColumn));
    selectionModeList->addItem(QStringLiteral("Slice into Row"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionRow));
    selectionModeList->addItem(QStringLiteral("Slice into Row and Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndRow));
    selectionModeList->addItem(QStringLiteral("Slice into Column"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionColumn));
    selectionModeList->addItem(QStringLiteral("Slice into Column and Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndColumn));
    selectionModeList->addItem(QStringLiteral("Multi: Bar, Row, Col"),
                               int(QAbstract3DGraph::SelectionItemRowAndColumn
                                   | QAbstract3DGraph::SelectionMultiSeries));
    selectionModeList->addItem(QStringLiteral("Multi, Slice: Row, Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndRow
                                   | QAbstract3DGraph::SelectionMultiSeries));
    selectionModeList->addItem(QStringLiteral("Multi, Slice: Col, Item"),
                               int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndColumn
                                   | QAbstract3DGraph::SelectionMultiSeries));
    selectionModeList->setCurrentIndex(1);
    vLayout->addWidget(new QLabel(QStringLiteral("Change selection mode")));
    vLayout->addWidget(selectionModeList);


    rangeList = new QComboBox();
    vLayout->addWidget(new QLabel(QStringLiteral("Show Row Data")));
    rangeList->addItem("All");
    rangeList->setCurrentIndex(0);
    vLayout->addWidget(rangeList);

    seriesLabel = new QLabel(QStringLiteral("Show series"));
    vLayout->addWidget(seriesLabel);
    seriesComboBox = new QComboBox();
    vLayout->addWidget(seriesComboBox);
    connect(seriesComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onSeriesChanged(int)));


    vLayout->addWidget(new QLabel(QStringLiteral("data source")));
    dataSource = new QComboBox();
    loadDataSource();
    vLayout->addWidget(dataSource);

    modifier = new GraphModifier(widgetGraph);
    onDataSourceChanged(0);
    connect(dataSource, SIGNAL(currentIndexChanged(int)), this, SLOT(onDataSourceChanged(int)));



    QObject::connect(rotationSliderX, &QSlider::valueChanged, modifier, &GraphModifier::rotateX);

    QObject::connect(rotationSliderY, &QSlider::valueChanged, modifier, &GraphModifier::rotateY);

    QObject::connect(labelButton, &QPushButton::clicked, modifier,
                     &GraphModifier::changeLabelBackground);

    QObject::connect(cameraButton, &QPushButton::clicked, modifier,
                     &GraphModifier::changePresetCamera);

    QObject::connect(zoomToSelectedButton, &QPushButton::clicked, modifier,
                     &GraphModifier::zoomToSelectedBar);

    QObject::connect(backgroundCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setBackgroundEnabled);

    QObject::connect(gridCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setGridEnabled);

    QObject::connect(smoothCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setSmoothBars);

    QObject::connect(reverseValueAxisCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setReverseValueAxis);
    QObject::connect(reflectionCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setReflection);

    QObject::connect(modifier, &GraphModifier::backgroundEnabledChanged,
                     backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &GraphModifier::gridEnabledChanged,
                     gridCheckBox, &QCheckBox::setChecked);

    QObject::connect(rangeList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeRange(int)));

    QObject::connect(barStyleList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeStyle(int)));

    QObject::connect(selectionModeList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeSelectionMode(int)));

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeTheme(int)));

    QObject::connect(shadowQuality, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeShadowQuality(int)));

    QObject::connect(modifier, &GraphModifier::shadowQualityChanged, shadowQuality,
                     &QComboBox::setCurrentIndex);

    QObject::connect(widgetGraph, &Q3DBars::shadowQualityChanged, modifier,
                     &GraphModifier::shadowQualityUpdatedByVisual);

    QObject::connect(fontSizeSlider, &QSlider::valueChanged, modifier,
                     &GraphModifier::changeFontSize);

    QObject::connect(fontList, &QFontComboBox::currentFontChanged, modifier,
                     &GraphModifier::changeFont);

    QObject::connect(modifier, &GraphModifier::fontSizeChanged, fontSizeSlider,
                     &QSlider::setValue);
    QObject::connect(modifier, &GraphModifier::fontChanged, fontList,
                     &QFontComboBox::setCurrentFont);

    QObject::connect(axisTitlesVisibleCB, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setAxisTitleVisibility);

    QObject::connect(axisTitlesFixedCB, &QCheckBox::stateChanged, modifier,
                     &GraphModifier::setAxisTitleFixed);

    QObject::connect(axisLabelRotationSlider, &QSlider::valueChanged, modifier,
                     &GraphModifier::changeLabelRotation);

    setLayout(hLayout);
}

void Bar::onDataSourceChanged(int index)
{
    QString pluginFile = dataSource->itemData(index).toString();
    qDebug()<<__func__<<" plugin file:"<<pluginFile;

    QPluginLoader pluginLoader(pluginFile);
    QObject *plugin = pluginLoader.instance();
    if (plugin)
    {
        barDataSource = qobject_cast<IBarDataInterface *>(plugin);
        if(barDataSource)
        {
           barDataSource->echo("hello");
           modifier->setDataSource(barDataSource);
           QCategory3DAxis * row = modifier->getGraphModifierRowAxis();
           QStringList rowLabel = row->labels();
           qDebug()<<__func__<<" "<<rowLabel;
           rangeList->clear();
           int index = 0;
           for(index = 0; index <rowLabel.size();index++)
           {
                rangeList->addItem(rowLabel[index]);
           }
           rangeList->addItem("All");
           qDebug()<<__func__<<" index "<<index;
           rangeList->setCurrentIndex(index);



           QList<QBar3DSeries *> seriesList =  modifier->getseriesList();
           seriesComboBox->clear();

           for(index = 0; index < seriesList.count();index++)
           {
               seriesComboBox->addItem(seriesList[index]->name());
           }
           seriesComboBox->addItem("All");
           seriesComboBox->setCurrentIndex(index);
        }
    }
    else
    {
        qDebug()<<__func__<<" error: load plugin fail";
    }

}

void Bar::onSeriesChanged(int index)
{
    QString name = seriesComboBox->currentText();
    QList<QBar3DSeries *> seriesList =  modifier->getseriesList();
    if(seriesList.count() > 0)
    {
        if(name == "All")
        {
            foreach (QBar3DSeries * s, seriesList) {
                s->setVisible(true);
            }
        }
        else
        {
            foreach (QBar3DSeries * s, seriesList) {
                if(s->name() == name)
                {
                    s->setVisible(true);
                }
                else
                {
                    s->setVisible(false);
                }
            }
        }
    }
}

bool Bar::loadDataSource()
{
     QDir pluginsDir(qApp->applicationDirPath());
     pluginsDir.cdUp();
     pluginsDir.cdUp();
     pluginsDir.cd("plugins");
     foreach (QString fileName, pluginsDir.entryList(QDir::Files,QDir::Unsorted))
     {

         QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
         //qDebug()<<pluginsDir.absoluteFilePath(fileName);

         QObject *pluginObj = pluginLoader.instance();
         if(!pluginObj)
         {

             qDebug()<<"error: "<<pluginLoader.errorString();
             return false;
         }


         IBarDataInterface *plugin = qobject_cast<IBarDataInterface *>(pluginObj);
         if(plugin)
         {
             QString pluginName = plugin->getPluginId();
             qDebug()<<"plugin:"<<pluginName<<"   path:"<<pluginsDir.absoluteFilePath(fileName);
             dataSource->addItem(pluginName,pluginsDir.absoluteFilePath(fileName));
         }

     }
     return true;
}
