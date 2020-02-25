#include "mainwindow.h"
#include "settingdialog.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTranslator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), settingDialog(new SettingDialog),pLabel(new QLabel),
      setting(new QPushButton),ok(new QPushButton), cannel(new QPushButton)
{
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    pLabel->setText(tr("display something"));
    vBoxLayout->addWidget(pLabel);

    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    setting->setText(tr("setting"));
    ok->setText(tr("ok"));
    cannel->setText(tr("cancel"));
    hBoxLayout->addWidget(setting);
    hBoxLayout->addWidget(ok);
    hBoxLayout->addWidget(cannel);

    vBoxLayout->addLayout(hBoxLayout);

    setWindowTitle(tr("main window"));

    connect(setting, SIGNAL(clicked()), this, SLOT(onSettingButtonClicked()));
    connect(settingDialog,SIGNAL(switchLanguage(LANGUAGE)),this, SLOT(onSwitchLanguage(LANGUAGE)));

    QWidget *widget = new QWidget(this);
    widget->setLayout(vBoxLayout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setTranslator(QTranslator *t)
{
    translator = t;
}

void MainWindow::onSettingButtonClicked()
{
    settingDialog->setModal(true);
    settingDialog->exec();
}

void MainWindow::onSwitchLanguage(LANGUAGE language)
{
    if(language == UI_EN)
    {
        translator->load(QString(":/qm/main_window_en"));
    } else if(language == UI_ZH)
    {
        translator->load(QString(":/qm/main_window_zh"));
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    Q_UNUSED(event)
    translateUI();
}

void MainWindow::translateUI()
{
    pLabel->setText(tr("display something"));
    setting->setText(tr("setting"));
    ok->setText(tr("ok"));
    cannel->setText(tr("cancel"));
    setWindowTitle(tr("main window"));
}

