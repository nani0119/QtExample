#include <QApplication>
#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel* pLabel = new QLabel();

    QString strText = "一去二三里，烟村四五家。亭台六七座，八九十枝花";

    // 使用用省略号显示过长文本
    QString strElidedText = pLabel->fontMetrics().elidedText(strText,Qt::ElideRight, 300, Qt::TextShowMnemonic);
    qDebug()<<"使用用省略号显示过长文本"<< strElidedText;


    QString strHeightText  = "<p style=\"line-height:%1%\">%2<p>";

    // 设置行高
    strText = strHeightText.arg(150).arg(strText);


    pLabel->setText(strText);

    //文字颜色
    pLabel->setStyleSheet("color:red");

    //对齐方式
    pLabel->setAlignment(Qt::AlignCenter);

    //自动换行
    pLabel->setWordWrap(true);


    pLabel->show();


    return a.exec();
}
