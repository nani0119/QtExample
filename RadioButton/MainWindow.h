#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QRadioButton;
class QLabel;
class QButtonGroup;
class QAbstractButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onToggled(bool checked);
    void onButtonClicked(QAbstractButton *button);
private:
    QLabel *pLabel;
    QLabel *pRadioLabel;
    QRadioButton *pRadioButton1;
    QRadioButton *pRadioButton2;
    QRadioButton *pRadioButton3;
    QButtonGroup *pButtonGroup;
};
#endif // MAINWINDOW_H
