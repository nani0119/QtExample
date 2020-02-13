#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QLabel;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onNormalTextEdited(const QString&);
    void onNormalTextChanged(const QString&);
    void onNormalSelectionChanged();
    void onNormalReturnPressed();
    void onNormalEditingFinished();
    void onNormalInputRejected();
    void onNormalCursorPositionChanged(int, int);

protected:
    bool eventFilter(QObject *obj, QEvent *e);
private:
    QLabel *pNormalLabel;
    QLabel *pNoEchoLabel;
    QLabel *pPasswordLabel;
    QLabel *pPasswordEchoOnEditLabel;
    QLabel *pNormalReadOnlyLabel;
    QLabel *pNormalOtherLabel;

    QLineEdit *pNormalLineEdit;
    QLineEdit *pNoEchoLineEdit;
    QLineEdit *pPasswordLineEdit;
    QLineEdit *pPasswordEchoOnEditLineEdit;
    QLineEdit *pNormalReadOnlyLineEdit;
    QLineEdit *pNormalOtherLineEdit;

};
#endif // MAINWINDOW_H
