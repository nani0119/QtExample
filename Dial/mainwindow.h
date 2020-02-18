#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QDial;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDialValueChanged(int val);
    void onDialsliderMoved(int val);
    void onDialSliderPressed();

private:
    QLabel *pLabel;
    QDial *pDial;
};
#endif // MAINWINDOW_H
