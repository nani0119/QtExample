#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>

class QLabel;
class QComboBox;

class MyValidator: public QValidator
{
    Q_OBJECT

public:
    explicit MyValidator(QStringList stringList,QObject *parent = nullptr);
    ~MyValidator();
    QValidator::State validate(QString& input, int& pos) const override;
private:
    QStringList provinceList;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onActivated(int);
    void onActivated(const QString&);
    void onCurrentIndexChanged(int);
    void onCurrentIndexChanged(const QString&);
    void onHighlighted(int);
    void onHighlighted(const QString&);
    void onCurrentTextChanged(const QString&);
    void onEitTextChanged(const QString&);
private:
    QLabel *pLabel;
    QComboBox *pComboBox;
};
#endif // MAINWINDOW_H
