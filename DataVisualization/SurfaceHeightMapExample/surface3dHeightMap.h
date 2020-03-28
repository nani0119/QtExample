#ifndef SURFACE3D_H
#define SURFACE3D_H

#include <QMainWindow>
class QCheckBox;
class SurFace3D : public QMainWindow
{
    Q_OBJECT

signals:
       void updateHeightMap(QString file);

private slots:
    void onSelectHightMapClick();
public:
    SurFace3D(QWidget *parent = nullptr);
    ~SurFace3D();

private:
    QCheckBox *enableTexture;
};
#endif // SURFACE3D_H
