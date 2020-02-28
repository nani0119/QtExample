#include "mainwindow.h"
#include <QtPrintSupport>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pLabel(new QLabel),pPrinter(new QPrinter)
{

    printerDialog = new QPrintDialog(pPrinter);
    printerDialog->setWindowTitle("PrinterDialog");
    printerDialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

    pageSetupDialog = new QPageSetupDialog(pPrinter);
    pageSetupDialog->setWindowTitle("Page Setup Dialog");
    printPreviewDialog = new QPrintPreviewDialog(pPrinter);
    printPreviewDialog->setWindowTitle("PrintPreview Dialog");
    connect(printPreviewDialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(onPrintPreviewDialogPaintRequested(QPrinter*)));

    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *printButton = new QPushButton;
    printButton->setText("printFile");
    connect(printButton, SIGNAL(clicked()), this, SLOT(onPrintButtonClicked()));


    layout->addWidget(pLabel);
    layout->addWidget(printButton);


    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onShowPrinterDialogClicked()
{
    printerDialog->show();
}

void MainWindow::onPrintButtonClicked()
{

    QFileDialog *fileDialog = new QFileDialog;
    fileDialog->setOption(QFileDialog::DontUseNativeDialog);
    QString str = "";
    if(fileDialog->exec() == QDialog::Accepted)
    {
        QStringList fileList = fileDialog->selectedFiles();
        foreach (QString fileName, fileList) {
            str += fileName + "\n";
        }
        printFile(str);
    }
}

void MainWindow::onPrintPreviewDialogPaintRequested(QPrinter *pPrinter)
{
    pLabel->setText(pPrinter->docName());
    QTextEdit *textEdit = new QTextEdit;
    textEdit->setText(pPrinter->docName());
    textEdit->print(pPrinter);
}

void MainWindow::printFile(QString file)
{
    pLabel->setText(file);
    pPrinter->setDocName(file);
    QString str = "";

    pPrinter->setOutputFormat(QPrinter::PdfFormat);

    if(printerDialog->exec() == QDialog::Accepted)
    {
        QPrinter *printer = printerDialog->printer();
        str = "printer info:\n";
        str += QString("printer name: %1\n").arg(printer->printerName());
        str += QString("doc name: %1\n").arg(printer->docName());
        str += QString("output filename: %1\n").arg(printer->outputFileName());
        str += QString("printer program: %1\n").arg(printer->printProgram());
        str += QString("printer SelectionOption: %1\n").arg(printer->printerSelectionOption());
        str += QString("printer range: %1\n").arg(printerDialog->printRange());
        pLabel->setText(str);
    }

    if(pageSetupDialog->exec()== QDialog::Accepted)
    {

    }

    if(printPreviewDialog->exec() == QDialog::Accepted)
    {

    }

     QTextEdit *textEdit = new QTextEdit;
     textEdit->setText(file);
     textEdit->print(pPrinter);
}

