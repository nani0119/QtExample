#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLabel;
class QLineEdit;
class QPushButton;
class QImageReader;
class QListWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onSelectFileButtonClicked();
private:
    QLabel *pImageLabel;
    QLineEdit *pImageFilePath;
    QPushButton *pSelectFile;
    QImageReader *pImageReader;
    QListWidget *pImageList;
};
#endif // MAINWINDOW_H
