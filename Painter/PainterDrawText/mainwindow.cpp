#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);

    painter.setPen(QColor(0, 160, 230));
    QFont font;
    font.setFamily("Ubuntu");
    font.setPointSize(50);
    font.setItalic(true);
    painter.setFont(font);

    painter.drawText(rect(),Qt::AlignCenter, "Qt");
}

