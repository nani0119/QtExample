#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      camera(new QCamera)

{
    ui->setupUi(this);
    ui->imageCaptureDisplayLabel->setScaledContents(false);

    imageCapture = new QCameraImageCapture(camera);
    camera->setViewfinder(ui->viewfinder);
    camera->start();

    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(ui->captureButton, SIGNAL(clicked()), this, SLOT(onCaptureImage()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveImage()));
    connect(ui->quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCaptureImage()
{
    ui->statusbar->showMessage(tr("capturing..."), 1000);
    imageCapture->capture();
}

void MainWindow::onSaveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), QDir::homePath(), tr("jpegfile(*.jpg)"));
    if(fileName.isEmpty())
    {
        ui->statusbar->showMessage(tr("save cancel"), 5000);
        return;
    }
    const QPixmap* pixmap=ui->imageCaptureDisplayLabel->pixmap();
    if(pixmap)
    {
        pixmap->save(fileName);
        ui->statusbar->showMessage(tr("save OK"), 5000);
    }
}

void MainWindow::displayImage(int, QImage image)
{
    QImage scaledImage = image.scaled(ui->imageCaptureDisplayLabel->size(),
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation);
    ui->imageCaptureDisplayLabel->setPixmap(QPixmap::fromImage(scaledImage));
    ui->statusbar->showMessage(tr("capture OK!"), 5000);
}

