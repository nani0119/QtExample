#include "settingdialog.h"
#include <QLabel>
#include <QComboBox>
#include <QEvent>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDebug>

SettingDialog::SettingDialog(QWidget *parent):
    QDialog(parent), pContext(new QLabel),pLabel(new QLabel), pComboBox(new QComboBox)
{
    qRegisterMetaType<LANGUAGE>("LANGUAGE");

    pContext->setText(tr("use language"));

    QFormLayout *formlayout = new QFormLayout;
    pLabel->setText(tr("language"));

    pComboBox->addItem(tr("english"), UI_EN);
    pComboBox->addItem(tr("chinese"), UI_ZH);
    connect(pComboBox,SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentIndexChanged(int)));
    formlayout->addRow(pLabel, pComboBox);

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    vBoxLayout->addStretch();
    vBoxLayout->addWidget(pContext);
    vBoxLayout->addStretch();
    vBoxLayout->addLayout(formlayout);

    setWindowTitle(tr("language dialog"));



    setLayout(vBoxLayout);
}

SettingDialog::~SettingDialog()
{

}

void SettingDialog::changeEvent(QEvent *e)
{
    qDebug()<<"SettingDialog - "<<__func__;
    if(e->type() == QEvent::LanguageChange)
    {
        translateUI();
    }
    else
    {
        QDialog::changeEvent(e);
    }
}

void SettingDialog::onCurrentIndexChanged(int index)
{
    Q_UNUSED(index)
    LANGUAGE language = pComboBox->currentData().value<LANGUAGE>();
    emit switchLanguage(language);
}

QSize SettingDialog::sizeHint() const
{
    qDebug()<<"SettingDialog - "<<__func__;
    return QSize(300,150);
}

QSize SettingDialog::minimumSizeHint() const
{
    qDebug()<<"SettingDialog - "<<__func__;
    return QSize(80,40);
}

void SettingDialog::translateUI()
{
    qDebug()<<"SettingDialog - "<<__func__;
    this->setWindowTitle(tr("language dialog"));
    pContext->setText(tr("use language"));
    pLabel->setText(tr("language"));
    pComboBox->setItemText(UI_EN, "english");
    pComboBox->setItemText(UI_ZH, "chinese");

}
