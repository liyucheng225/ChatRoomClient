#include "chatstackwidget.h"

ChatStackWidget::ChatStackWidget(QWidget *parent) : QStackedWidget(parent)
{
    QWidget *startWidget = new QWidget(this);
    startWidget->setStyleSheet("border-image: url(:/new/prefix1/image/开始.png);");
    this->addWidget(startWidget);
    this->setStyleSheet("QStackedWidget{border:1px solid rgb(0,0,0);background: rgb(242,242,242)}");
}
