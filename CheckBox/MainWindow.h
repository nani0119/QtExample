#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLabel;
class QCheckBox;
class QButtonGroup;
class QAbstractButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onStateChanged(int state);
    void onButtonClicked(QAbstractButton *button);
private:
    QLabel *pLabel;
    QLabel *pButtonGroupLabel;
    QCheckBox *pCheckBox1;
    QCheckBox *pCheckBox2;
    QCheckBox *pCheckBox3;
    QButtonGroup *pButtonGroup;

};
#endif // MAINWINDOW_H
