#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSpinBox;
class QDoubleSpinBox;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onValueChanged(const QString&);
    void onValueChanged(int);
private:
    QLabel *pLabel;
    QSpinBox *pSpinBox;
    QDoubleSpinBox *pDoubleSpinBox;
};
#endif // MAINWINDOW_H
