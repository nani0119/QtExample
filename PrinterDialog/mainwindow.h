#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QPrinter;
class QPrintDialog;
class QPageSetupDialog;
class QPrintPreviewDialog;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onShowPrinterDialogClicked();
    void onPrintButtonClicked();
    void onPrintPreviewDialogPaintRequested(QPrinter *pPrinter);
private:
    void printFile(QString file);
    QLabel *pLabel;
    QPrinter *pPrinter;
    QPrintDialog *printerDialog;
    QPageSetupDialog *pageSetupDialog;
    QPrintPreviewDialog *printPreviewDialog;
};
#endif // MAINWINDOW_H
