#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QMenuBar;
class QToolBar;
class QToolButton;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
   void onTrigerMenu(QAction* action);
   void onTimeout();
   void onHovered(QAction* action);
private:
    QAction *addAction;
    QAction *delAction;
    QAction *cancelAction;
    QAction *settingAction;
    QAction *backAction;
    QToolBar *pToolBar;
    QToolButton *pToolButton;
    QLabel* pLabel;
    QLabel *statusBarLabel;
    QLabel *permanentLabel;
    QTimer* pTimer;
};
#endif // MAINWINDOW_H
