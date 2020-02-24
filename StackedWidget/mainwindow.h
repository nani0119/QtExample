#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLabel;
class QStackedWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onStackedLayoutCurrentChanged(int index);
    void onFirstButtonClick();
    void onLastButtonClick();
    void onPreviousClick();
    void onNextButtonClick();
private:
    QLabel *firstLabel;
    QLabel *lastLabel;
    QStackedWidget *pStackedWidget;
};
#endif // MAINWINDOW_H
