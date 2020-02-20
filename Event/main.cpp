#include "mainwindow.h"

#include <QApplication>

// notify->发生事件组件eventFilter－>发生事件组件event->[组件的event handler]
//　->如果没有上层组件继续循环
int main(int argc, char *argv[])
{
    MyApplication a(argc, argv);
    a.setObjectName("MyApplication");
    ObjectFilter* mainWindowEventFilter = new ObjectFilter;
    MyMainWindow myWindow;
    myWindow.setObjectName("myWindow");
    myWindow.installEventFilter(mainWindowEventFilter);
    myWindow.show();
    return a.exec();
}
