#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class QSystemTrayIcon;
class QLabel;
class QPushButton;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPushButtonClicked();
    void onShowMessageReturnPressed();
    void onShowWindow();
    void onHideWindow();
    void OnSystemTrayActivated(QSystemTrayIcon::ActivationReason);
    void OnSystemTrayMessageClicked();
private:
    QSystemTrayIcon* pSystemTrayIcon;
    QLabel *pLabel;
    QPushButton *pPushButton;
    QPushButton *pHideToSystemTray;
    QLineEdit* pShowMessage;

};
#endif // MAINWINDOW_H
