#include <QApplication>
#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel* pLabel = new QLabel();

    QString strHTML = QString("<html> \
                                    <head> \
                                        <style> \
                                            font{color:white;} #f{font-size:18px; color: green;} \
                                        </style> \
                                    </head> \
                                    <body>\
                                        <font>%1</font><font id=\"f\">%2</font> \
                                    </body> \
                               </html>").arg("I am a ").arg("Qter");


    pLabel->setText(strHTML);
    //对齐方式
    pLabel->setAlignment(Qt::AlignCenter);


    pLabel->show();


    return a.exec();
}
