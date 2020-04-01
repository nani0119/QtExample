#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCaptureImage();
    void onSaveImage();
    void displayImage(int , QImage image);

private:
    Ui::MainWindow *ui;
    QCamera* camera;
    QCameraImageCapture *imageCapture;
};
#endif // MAINWINDOW_H
