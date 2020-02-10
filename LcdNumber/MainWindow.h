#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QLCDNumber;
class QHBoxLayout;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel* pLabel;
    QLCDNumber* pLCDNumber;
    QHBoxLayout* pLayout;
    QTimer* pTimer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   void onOverflow();
   void onTimeOut();
};
#endif // MAINWINDOW_H
