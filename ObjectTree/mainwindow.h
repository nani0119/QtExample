#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QPushButton;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void customClicked();

private slots:
    void onTrggered(bool);
    void onTextChange(const QString&);
    void onReturnPressed();

private:
    QPushButton *pPushButton;
    QLineEdit *pLineEdit;
};
#endif // MAINWINDOW_H
