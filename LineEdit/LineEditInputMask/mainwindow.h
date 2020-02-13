#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QLineEdit *pIPLineEdit;
    QLineEdit *pMACLineEdit;
    QLineEdit *pDateLineEdit;
    QLineEdit *pLicenseLineEdit;

};
#endif // MAINWINDOW_H
