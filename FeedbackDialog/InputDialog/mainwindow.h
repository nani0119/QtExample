#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
class MyInputDialog :public QInputDialog
{
    Q_OBJECT
public:
    MyInputDialog(QWidget *parent = nullptr);
    ~MyInputDialog() override;

    // QDialog interface
public slots:
    void done(int) override;
    void accept() override;
    void reject() override;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private slots:
    void onTextValueChanged(const QString&text);
    void onAccepted();
    void onRejected();
    void onFinished(int r);
    void onMyInputDialogAccepted();
private:
    QInputDialog *pInputDialog;
};
#endif // MAINWINDOW_H
