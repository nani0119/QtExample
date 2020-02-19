#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_CLASSINFO("Position", "MainWindow")
    Q_CLASSINFO("MainWindow", "description")


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};


class MyMainWindow :public MainWindow
{
    Q_OBJECT
    Q_CLASSINFO("author", "zhaorj")
    Q_CLASSINFO("desc", "test meta object")

public:
    //Note that only constructors that are declared with the Q_INVOKABLE modifier are made available through the meta-object system.
    Q_INVOKABLE MyMainWindow(QWidget *parent = nullptr);
    Q_INVOKABLE MyMainWindow(int,QWidget *parent = nullptr);
    ~MyMainWindow();
    Q_INVOKABLE int echo(int i);
public slots:
    int getVal();
private:
    int val;
};
#endif // MAINWINDOW_H
