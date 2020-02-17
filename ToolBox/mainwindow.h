#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QToolBox;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onCurrentChanged(int index);
private:
    QToolBox *pToolBox;
    QLabel* pLabel;
};
#endif // MAINWINDOW_H
