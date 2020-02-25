#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingdialog.h"
#include <QMainWindow>
class QPushButton;
class QLabel;
class QTranslator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void setTranslator(QTranslator* t);
private slots:
    void onSettingButtonClicked();
    void onSwitchLanguage(LANGUAGE);
protected:
    virtual void changeEvent(QEvent *) override;
private:
    void translateUI();
    SettingDialog* settingDialog;
    QLabel *pLabel;
    QPushButton *setting;
    QPushButton *ok;
    QPushButton *cannel;
    QTranslator *translator;
};
#endif // MAINWINDOW_H
