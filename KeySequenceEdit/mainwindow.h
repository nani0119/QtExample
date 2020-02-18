#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLabel;
class QKeySequenceEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onEditingFinished();
    void onKeySequenceChanged(const QKeySequence& keySeq);
private:
    QLabel *pLabel;
    QKeySequenceEdit* pKeySequenceEdit;
};
#endif // MAINWINDOW_H
