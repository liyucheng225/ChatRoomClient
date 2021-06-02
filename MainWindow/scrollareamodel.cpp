#include "scrollareamodel.h"

ScrollAreaModel::ScrollAreaModel(QWidget *parent) : QScrollArea(parent)
{

    this->setBackgroundRole(QPalette::Light);
    //scrollArea->setWidgetResizable(true);   //小部件适应QScrollArea自动改变大小
    this->setAlignment(Qt::AlignCenter);    //居中对齐
//    scrollArea->setGeometry(40,70,290,400);
    this->setStyleSheet("QScrollArea{border: 0px solid;border-right-width: 1px;border-right-color: #dcdbdc;background-color: #f5f5f7;}"
                              "QScrollBar:vertical {border: none;background: #f5f5f7;width: 10px;margin: 0px 0 0px 0;}"
                              "QScrollBar::handle:vertical {background: Gainsboro;min-height: 20px;border-radius: 5px;border: none;}"
                              "QScrollBar::add-line:vertical {border: 0px solid grey;background: #32CC99;height: 0px;subcontrol-position: bottom;subcontrol-origin: margin;}"
                              "QScrollBar::sub-line:vertical {border: 0px solid grey;background: #32CC99;height: 0px;subcontrol-position: top;subcontrol-origin: margin;}"
                              "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;width: 0px;height: 0px;}");
    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setFixedWidth(280);
    this->setContentsMargins(0,0,0,0);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    qDebug() << "scrollArea size1:"<< this->size();
//    scrollAreaWidgetContents = new QWidget(this);
//    scrollAreaWidgetContents->setMinimumSize(QSize(268,489));
//    scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//    scrollAreaWidgetContents->setContentsMargins(0,0,0,0);
//    scrollAreaWidgetContents->setFixedWidth(260);
//     qDebug()<<"setContentsMargins size:"<< scrollAreaWidgetContents->size();
//    scrollAreaWidgetContents->setStyleSheet("QWidget{border:1px solid rgb(0,0,0);background: rgba(242,242,242)}");
//    friendLayout = new QVBoxLayout(scrollAreaWidgetContents);
//    friendLayout->setMargin(0);
//    friendLayout->setSpacing(0);
//    scrollAreaWidgetContents->setLayout(friendLayout);
//    this->scrollAreaWidgetContents = new QWidget();
//    this->scrollAreaWidgetContents->setMinimumSize(QSize(268, 1000));
//    this->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//    this->setWidget(scrollAreaWidgetContents);
    this->setContentsMargins(0,0,0,0);
}
