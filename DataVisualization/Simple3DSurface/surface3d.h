#ifndef SURFACE3D_H
#define SURFACE3D_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Surface3D; }
QT_END_NAMESPACE

class Surface3D : public QMainWindow
{
    Q_OBJECT

public:
    Surface3D(QWidget *parent = nullptr);
    ~Surface3D();

private:
    Ui::Surface3D *ui;
};
#endif // SURFACE3D_H
