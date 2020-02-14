#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
class QLabel;

class CustomSpinBox: public QSpinBox
{
    Q_OBJECT
public:
    CustomSpinBox(QWidget* parent = nullptr): QSpinBox(parent)
    {}
protected:
    virtual int valueFromText(const QString &text) const override;
    virtual QString textFromValue(int val) const override;
private slots:
   void onValueChanged(const QString&);

};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onMainWindowValueChanged(const QString&);
private:
    CustomSpinBox* pCustomSpinBox;
    QLabel *pLabel;
};
#endif // MAINWINDOW_H
