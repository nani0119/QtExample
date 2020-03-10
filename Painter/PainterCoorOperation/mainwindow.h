#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
class QSlider;
class QPainter;
class QSpinBox;
class QDoubleSpinBox;

class Widget :public QWidget
{
public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
    void setX(int val);
    int getX();
    void setY(int val);
    int getY();
    void setXRotate(int val);
    void setYRotate(int val);
    void setZRotate(int val);
    int getXRotate();
    int getYRotate();
    int getZRotate();
    qreal getSx();
    qreal getSy();
    void setSx(qreal);
    void setSy(qreal);
    qreal getSh();
    qreal getSv();
    void setSh(qreal);
    void setSv(qreal);
protected:
    void paintEvent(QPaintEvent *event);
private:
    int x;
    int y;
    int xRotate;
    int yRotate;
    int zRotate;
    qreal sx;
    qreal sy;
    qreal sh;
    qreal sv;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onWidgetXAxisUpdate(int val);
    void onWidgetYAxisUpdate(int val);
    void onWidgetXAxisRotateUpdate(int val);
    void onWidgetYAxisRotateUpdate(int val);
    void onWidgetZAxisRotateUpdate(int val);
    void onWidgeXscaleUpdate(double);
    void onWidgeYscaleUpdate(double);
    void onWidgeHShearUpdate(double);
    void onWidgeVShearUpdate(double);
private:
    Widget* myWidget;
    QSpinBox *xSpinBox;
    QSlider *XAxis;
    QSpinBox *ySpinBox;
    QSlider *YAxis;

    QSpinBox *xRotateSpinBox;
    QSlider *XAxisRotate;
    QSpinBox *yRotateSpinBox;
    QSlider *YAxisRotate;
    QSpinBox *zRotateSpinBox;
    QSlider *ZAxisRotate;

    QDoubleSpinBox *scaleX;
    QDoubleSpinBox *scaleY;
    QDoubleSpinBox *shearH;
    QDoubleSpinBox *shearV;
};
#endif // MAINWINDOW_H
