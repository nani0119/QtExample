#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QMetaType>

typedef enum{
    UI_ZH,
    UI_EN
} LANGUAGE;

Q_DECLARE_METATYPE(LANGUAGE);

class QLabel;
class QComboBox;
class SettingDialog : public QDialog
{
    Q_OBJECT
public:
    SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog() override;
    virtual QSize sizeHint() const override;
    virtual QSize minimumSizeHint() const override;
protected:
    virtual void changeEvent(QEvent* e) override;

signals:
    void switchLanguage(LANGUAGE);

private slots:
    void onCurrentIndexChanged(int index);
private:
    void translateUI();
    QLabel *pContext;
    QLabel *pLabel;
    QComboBox *pComboBox;

    // QWidget interface

};

#endif // SETTINGDIALOG_H
