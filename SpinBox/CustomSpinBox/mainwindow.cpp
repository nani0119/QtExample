#include "mainwindow.h"
#include <QRegExp>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pCustomSpinBox(new CustomSpinBox), pLabel(new QLabel)
{
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(pLabel);

    layout->addWidget(pCustomSpinBox);
    connect(pCustomSpinBox,SIGNAL(valueChanged(const QString&)), pCustomSpinBox, SLOT(onValueChanged(const QString&)));
    connect(pCustomSpinBox,SIGNAL(valueChanged(const QString&)), this, SLOT(onMainWindowValueChanged(const QString&)));

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);}

MainWindow::~MainWindow()
{
}

void MainWindow::onMainWindowValueChanged(const QString &text)
{
    QString str = text +"    " + pCustomSpinBox->cleanText();
    pLabel->setText(str);
}


int CustomSpinBox::valueFromText(const QString &text) const
{
    QRegExp regExp(tr("(\\d+)(\\s*[xx]\\s*\\d+)?"));
    if (regExp.exactMatch(text)) {
        return regExp.cap(1).toInt();
    } else {
        return 0;
    }
}

QString CustomSpinBox::textFromValue(int val) const
{
    return tr("%1 x %1").arg(val);
}

void CustomSpinBox::onValueChanged(const QString & text)
{
    qDebug()<<__func__<<text;
}
