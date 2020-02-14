#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSlider;
class QSpinBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSlider* pHSlider;
    QSlider* pVSlider;
    QSpinBox* pSpinBox;

};
#endif // MAINWINDOW_H
