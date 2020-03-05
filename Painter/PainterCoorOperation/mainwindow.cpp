#include "mainwindow.h"
#include <QPainter>
#include <QTransform>
#include <QGridLayout>
#include <QSlider>
#include <QImage>
#include <QSpinBox>
#include <QDebug>
#include <QDoubleSpinBox>
#include <QLabel>


Widget::Widget(QWidget* parent) :QWidget(parent)
{
    x= 0;
    y= 0;
    xRotate = 0;
    yRotate = 0;
    zRotate = 0;
    sx = 1.0;
    sy = 1.0;
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
    painter.drawRect(0, 0, 100, 100);

    QTransform transform;
    transform.translate(getX(), getY()); //沿着XY轴前进

    transform.rotate(getXRotate(),Qt::XAxis);
    transform.rotate(getYRotate(),Qt::YAxis);
    transform.rotate(getZRotate(),Qt::ZAxis);

    transform.scale(getSx(), getSy());


    painter.setTransform(transform);
    QImage image(":/img/logo");
    painter.drawImage(0,0,image);
    painter.end();

}

void Widget::setX(int val)
{
    x = val;
}

int Widget::getX()
{
    return  x;
}

int Widget::getY()
{
    return  y;
}

void Widget::setXRotate(int val)
{
    xRotate = val;
}
void Widget::setYRotate(int val)
{
    yRotate = val;
}
void Widget::setZRotate(int val)
{
    zRotate = val;
}

int Widget::getXRotate()
{
    return xRotate;
}

int Widget::getYRotate()
{
    return yRotate;
}
int Widget::getZRotate()
{
    return zRotate;
}

qreal Widget::getSx()
{
    return  sx;
}
void Widget::setY(int val)
{
    y = val;
}

qreal Widget::getSy()
{
    return  sy;
}

void Widget::setSx(qreal val)
{
    sx = val;
}
void Widget::setSy(qreal val)
{
    sy = val;
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),myWidget(new Widget),
      xSpinBox(new QSpinBox),XAxis(new QSlider),
      ySpinBox(new QSpinBox),YAxis(new QSlider),
      xRotateSpinBox(new QSpinBox),XAxisRotate(new QSlider),
      yRotateSpinBox(new QSpinBox),YAxisRotate(new QSlider),
      zRotateSpinBox(new QSpinBox),ZAxisRotate(new QSlider),
      scaleX(new QDoubleSpinBox),scaleY(new QDoubleSpinBox)
{
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(myWidget,0,0,1,4);


    QLabel *xAixsLabel = new QLabel("x轴变换:");
    xSpinBox->setRange(0, 1000);
    xSpinBox->setSingleStep(1);
    XAxis->setOrientation(Qt::Horizontal);
    XAxis->setRange(0, 1000);
    XAxis->setSingleStep(1);
    connect(xSpinBox, SIGNAL(valueChanged(int)),XAxis, SLOT(setValue(int)));
    connect(XAxis, SIGNAL(valueChanged(int)),xSpinBox, SLOT(setValue(int)));
    connect(XAxis, SIGNAL(valueChanged(int)), this, SLOT(onWidgetXAxisUpdate(int)));
    connect(xSpinBox, SIGNAL(valueChanged(int)),this, SLOT(onWidgetXAxisUpdate(int)));

    layout->addWidget(xAixsLabel,1,0);
    layout->addWidget(xSpinBox,1,1);
    layout->addWidget(XAxis,1,2);

    QLabel *yAixsLabel = new QLabel("y轴变换:");
    ySpinBox->setRange(0, 1000);
    ySpinBox->setSingleStep(1);
    YAxis->setOrientation(Qt::Horizontal);
    YAxis->setRange(0, 1000);
    YAxis->setSingleStep(1);
    connect(ySpinBox, SIGNAL(valueChanged(int)),YAxis, SLOT(setValue(int)));
    connect(YAxis, SIGNAL(valueChanged(int)),ySpinBox, SLOT(setValue(int)));
    connect(YAxis, SIGNAL(valueChanged(int)), this, SLOT(onWidgetYAxisUpdate(int)));
    connect(ySpinBox, SIGNAL(valueChanged(int)),this, SLOT(onWidgetYAxisUpdate(int)));

    layout->addWidget(yAixsLabel,2,0);
    layout->addWidget(ySpinBox,2,1);
    layout->addWidget(YAxis,2,2);


    QLabel *xAixsRotateLabel = new QLabel("绕x轴旋转:");
    xRotateSpinBox->setRange(0, 360);
    xRotateSpinBox->setSingleStep(1);
    XAxisRotate->setOrientation(Qt::Horizontal);
    XAxisRotate->setRange(0, 360);
    XAxisRotate->setSingleStep(1);
    connect(xRotateSpinBox, SIGNAL(valueChanged(int)),XAxisRotate, SLOT(setValue(int)));
    connect(XAxisRotate, SIGNAL(valueChanged(int)),xRotateSpinBox, SLOT(setValue(int)));
    connect(XAxisRotate, SIGNAL(valueChanged(int)), this, SLOT(onWidgetXAxisRotateUpdate(int)));
    connect(xRotateSpinBox, SIGNAL(valueChanged(int)),this, SLOT(onWidgetXAxisRotateUpdate(int)));

    layout->addWidget(xAixsRotateLabel,3,0);
    layout->addWidget(xRotateSpinBox,3,1);
    layout->addWidget(XAxisRotate,3,2);

    QLabel *yAixsRotateLabel = new QLabel("绕y轴旋转:");
    yRotateSpinBox->setRange(0, 360);
    yRotateSpinBox->setSingleStep(1);
    YAxisRotate->setOrientation(Qt::Horizontal);
    YAxisRotate->setRange(0, 360);
    YAxisRotate->setSingleStep(1);
    connect(yRotateSpinBox, SIGNAL(valueChanged(int)),YAxisRotate, SLOT(setValue(int)));
    connect(YAxisRotate, SIGNAL(valueChanged(int)),yRotateSpinBox, SLOT(setValue(int)));
    connect(YAxisRotate, SIGNAL(valueChanged(int)), this, SLOT(onWidgetYAxisRotateUpdate(int)));
    connect(yRotateSpinBox, SIGNAL(valueChanged(int)),this, SLOT(onWidgetYAxisRotateUpdate(int)));

    layout->addWidget(yAixsRotateLabel,4,0);
    layout->addWidget(yRotateSpinBox,4,1);
    layout->addWidget(YAxisRotate,4,2);


    QLabel *zAixsRotateLabel = new QLabel("绕z轴旋转:");
    zRotateSpinBox->setRange(0, 360);
    zRotateSpinBox->setSingleStep(1);
    ZAxisRotate->setOrientation(Qt::Horizontal);
    ZAxisRotate->setRange(0, 360);
    ZAxisRotate->setSingleStep(1);
    connect(zRotateSpinBox, SIGNAL(valueChanged(int)),ZAxisRotate, SLOT(setValue(int)));
    connect(ZAxisRotate, SIGNAL(valueChanged(int)),zRotateSpinBox, SLOT(setValue(int)));
    connect(ZAxisRotate, SIGNAL(valueChanged(int)), this, SLOT(onWidgetZAxisRotateUpdate(int)));
    connect(zRotateSpinBox, SIGNAL(valueChanged(int)),this, SLOT(onWidgetZAxisRotateUpdate(int)));

    layout->addWidget(zAixsRotateLabel,5,0);
    layout->addWidget(zRotateSpinBox,5,1);
    layout->addWidget(ZAxisRotate,5,2);

    QLabel *xScaleLabel = new QLabel("x轴缩放:");
    scaleX->setRange(0.0, 10.0);
    scaleX->setSingleStep(0.1);
    scaleX->setValue(1.0);
    connect(scaleX, SIGNAL(valueChanged(double)),this, SLOT(onWidgeXscaleUpdate(double)));
    layout->addWidget(xScaleLabel,6,0);
    layout->addWidget(scaleX,6,1);

    QLabel *yScaleLabel = new QLabel("y轴缩放:");
    scaleY->setRange(0.0, 10.0);
    scaleY->setSingleStep(0.1);
    scaleY->setValue(1.0);
    connect(scaleY, SIGNAL(valueChanged(double)),this, SLOT(onWidgeYscaleUpdate(double)));
    layout->addWidget(yScaleLabel,6,2);
    layout->addWidget(scaleY,6,3);


    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onWidgetXAxisUpdate(int val)
{
    myWidget->setX(val);
    myWidget->update();
}

void MainWindow::onWidgetYAxisUpdate(int val)
{
    myWidget->setY(val);
    myWidget->update();
}

void MainWindow::onWidgetXAxisRotateUpdate(int val)
{
    myWidget->setXRotate(val);
    myWidget->update();
}

void MainWindow::onWidgetYAxisRotateUpdate(int val)
{
    myWidget->setYRotate(val);
    myWidget->update();
}

void MainWindow::onWidgetZAxisRotateUpdate(int val)
{
    myWidget->setZRotate(val);
    myWidget->update();
}

void MainWindow::onWidgeXscaleUpdate(double val)
{
    myWidget->setSx(val);
    myWidget->update();
}

void MainWindow::onWidgeYscaleUpdate(double val)
{
    myWidget->setSy(val);
    myWidget->update();
}
