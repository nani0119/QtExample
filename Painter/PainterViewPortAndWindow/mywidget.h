#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int windowX READ windowX WRITE setWindowX RESET resetWindowX  NOTIFY windowXChanged)
    Q_PROPERTY(int windowY READ windowY WRITE setWindowY RESET resetWindowY  NOTIFY windowYChanged)
    Q_PROPERTY(int windowWidth READ windowWidth WRITE setWindowWidth RESET resetWindowWidth  NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowHeight READ windowHeight WRITE setWindowHeight RESET resetWindowHeight  NOTIFY windowHeightChanged)

    Q_PROPERTY(int viewPortX READ viewPortX WRITE setViewPortX RESET resetViewPortX  NOTIFY viewPortXChanged)
    Q_PROPERTY(int viewPortY READ viewPortY WRITE setViewPortY RESET resetViewPortY  NOTIFY viewPortYChanged)
    Q_PROPERTY(int viewPortWidth READ viewPortWidth WRITE setViewPortWidth RESET resetViewPortWidth  NOTIFY viewPortWidthChanged)
    Q_PROPERTY(int viewPortHeight READ viewPortHeight WRITE setViewPortHeight RESET resetViewPortHeight  NOTIFY viewPortHeightChanged)

    Q_PROPERTY(int drawRectX READ drawRectX WRITE setDrawRectX RESET resetDrawRectX  NOTIFY drawRectXChanged)
    Q_PROPERTY(int drawRectY READ drawRectY WRITE setDrawRectY RESET resetDrawRectY  NOTIFY drawRectYChanged)
    Q_PROPERTY(int drawRectWidth READ drawRectWidth WRITE setDrawRectWidth RESET resetDrawRectWidth  NOTIFY drawRectWidthChanged)
    Q_PROPERTY(int drawRectHeight READ drawRectHeight WRITE setDrawRectHeight RESET resetDrawRectHeight  NOTIFY drawRectHeightChanged)
public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

     int windowX();
     int windowY();
     int windowWidth();
     int windowHeight();
     void resetWindowX();
     void resetWindowY();
     void resetWindowWidth();
     void resetWindowHeight();

     int viewPortX();
     int viewPortY();
     int viewPortWidth();
     int viewPortHeight();
     void resetViewPortX();
     void resetViewPortY();
     void resetViewPortWidth();
     void resetViewPortHeight();

     int drawRectX();
     int drawRectY();
     int drawRectWidth();
     int drawRectHeight();
     void resetDrawRectX();
     void resetDrawRectY();
     void resetDrawRectWidth();
     void resetDrawRectHeight();
signals:
     void windowXChanged(int val);
     void windowYChanged(int val);
     void windowWidthChanged(int val);
     void windowHeightChanged(int val);

     void viewPortXChanged(int val);
     void viewPortYChanged(int val);
     void viewPortWidthChanged(int val);
     void viewPortHeightChanged(int val);

     void drawRectXChanged(int val);
     void drawRectYChanged(int val);
     void drawRectWidthChanged(int val);
     void drawRectHeightChanged(int val);

private slots:
     void onWindowChanged(int val);

     void setWindowX(int val);
     void setWindowY(int val);
     void setWindowWidth(int val);
     void setWindowHeight(int val);

     void setViewPortX(int val);
     void setViewPortY(int val);
     void setViewPortWidth(int val);
     void setViewPortHeight(int val);

     void setDrawRectX(int val);
     void setDrawRectY(int val);
     void setDrawRectWidth(int val);
     void setDrawRectHeight(int val);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private:
    int mWindowX;
    int mWindowY;
    int mWindowWidth;
    int mWindowHeight;

    int mViewPortX;
    int mViewPortY;
    int mViewPortWidth;
    int mViewPortHeight;

    int mDrawRectX;
    int mDrawRectY;
    int mDrawRectWidth;
    int mDrawRectHeight;
};

#endif // MYWIDGET_H
