#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>




class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget* parent=nullptr);
    ~MyLabel();
protected:
    bool event(QEvent *e) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
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


class MyApplication : public QApplication
{
    Q_OBJECT
public:
    MyApplication(int& argc, char**argv);
    ~MyApplication();
protected:
    bool notify(QObject *, QEvent *) override;
    bool event(QEvent *) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
};
#endif // MAINWINDOW_H
