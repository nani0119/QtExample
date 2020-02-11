#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QPushButton;
class QLabel;
class QAction;
class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onSubAction(QAction *action);
private:
    QPushButton *pPushButton;
    QLabel *pLable;
    QActionGroup *pActionGroup;
};
#endif // MAINWINDOW_H
