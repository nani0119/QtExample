#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QProgressBar;
class QSlider;
class QProgressDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onProgressDialogCanceled();
private:
    QProgressBar* pProgressBarBusy;
    QProgressBar* pProgressBar;
    QProgressBar* pInvertedProgressBar;
    QProgressBar* pVProgressBar;
    QProgressDialog *pProgressDialog;

    QSlider *pSlider;
};
#endif // MAINWINDOW_H
