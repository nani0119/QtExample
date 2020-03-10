#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mywidget.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    MyWidget* myWidget;
};
#endif // MAINWINDOW_H
