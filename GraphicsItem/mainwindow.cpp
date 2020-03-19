#include "mainwindow.h"
#include "graphicsitem.h"
#include <QGraphicsView>
#include <QGraphicsScene>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    GraphicsItem *itemParent = new GraphicsItem(QColor(255,0,0),200);
    itemParent->setLabel("Parent");

    GraphicsItem *itemChild = new GraphicsItem(QColor(0,0,255),100,itemParent);
    itemChild->setLabel("Child");

    GraphicsScene *scene = new GraphicsScene;

    scene->addItem(itemParent);
    itemParent->setPos(15,15);
    itemParent->setPoint(QPoint(10,10));

    //itemParent->setRotation(15);
    itemChild->setPos(15,15);
    itemChild->setPoint(QPoint(10,10));
    //itemChild->setRotation(15);

    GraphicsView *view = new GraphicsView;
    view->setScene(scene);

    setGeometry(0,0,900,900);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
}

