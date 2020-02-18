#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QFontComboBox;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onCurrentFontChanged(const QFont& font);
private:
    QLabel *pLabel;
    QFontComboBox *pFontComboBox;
};
#endif // MAINWINDOW_H
