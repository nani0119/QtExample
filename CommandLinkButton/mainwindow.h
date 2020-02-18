#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QCommandLinkButton;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInstallClicked();
    void onFormatClicked();
    void onSkipClicked();

private:
    QLabel *pLabel;
    QCommandLinkButton *pInstall;
    QCommandLinkButton *pFormat;
    QCommandLinkButton *pSkip;
};
#endif // MAINWINDOW_H
