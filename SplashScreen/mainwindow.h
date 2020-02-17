#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplashScreen>
#include <QDebug>

class MySplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    MySplashScreen(QWidget *parent = nullptr);
    ~MySplashScreen();

private slots:
    void onMessageChanged(const QString& message);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
