#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTimer;
class QProgressBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onMainWindowTimeout();
    void onMainWindowStartTimer();
    void onMainWindowStopTimer();
    void onMainWindowValueChanged(int val);
private:
    QTimer *pTimer;
    QProgressBar *pProgressBar;
};
#endif // MAINWINDOW_H
