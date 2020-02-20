#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>

class ObjectFilter: public QObject
{
    Q_OBJECT
public:
    ObjectFilter(QObject *parent = nullptr);
    ~ObjectFilter();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

class MyApplication : public QApplication
{
    Q_OBJECT
public:
    MyApplication(int& argc, char**argv);
    ~MyApplication();
protected:
    bool notify(QObject *, QEvent *) override;
    bool event(QEvent *) override;
};


class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget* parent=nullptr);
    ~MyLabel();
protected:
    bool event(QEvent *e) override;
    //void mousePressEvent(QMouseEvent *event);
};

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
protected:
    bool event(QEvent *event) override;
    //void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    MyLabel *pMyLabel;
};
#endif // MAINWINDOW_H
