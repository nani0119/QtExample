#include "mainwindow.h"
#include <QLabel>
#include <QFontComboBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),pLabel(new QLabel), pFontComboBox(new QFontComboBox)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(pLabel);

    pFontComboBox->setFontFilters(QFontComboBox::AllFonts);
    layout->addWidget(pFontComboBox);
    onCurrentFontChanged(pFontComboBox->currentFont());
    connect(pFontComboBox, SIGNAL(currentFontChanged(const QFont&)), this, SLOT(onCurrentFontChanged(const QFont&)));


    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onCurrentFontChanged(const QFont &font)
{
    pLabel->clear();
    pLabel->setFont(font);
    QString str = "";
    str += QString("family: %1\n").arg(font.family());
    str += QString("pointSize: %1\n").arg(font.pointSize());
    str += QString("weight: %1\n").arg(font.weight());
    str += QString("italic: %1\n").arg(font.italic());
    pLabel->setText(str);
}

