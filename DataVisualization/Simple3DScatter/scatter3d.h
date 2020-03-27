#ifndef SCATTER3D_H
#define SCATTER3D_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Scatter3D; }
QT_END_NAMESPACE

class Scatter3D : public QMainWindow
{
    Q_OBJECT

public:
    Scatter3D(QWidget *parent = nullptr);
    ~Scatter3D();

private:
    Ui::Scatter3D *ui;
};
#endif // SCATTER3D_H
