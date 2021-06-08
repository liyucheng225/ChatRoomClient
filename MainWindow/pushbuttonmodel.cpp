#include "pushbuttonmodel.h"

PushButtonModel::PushButtonModel(QWidget *parent) : QPushButton(parent)
{
    this->setIcon(QIcon(":/new/prefix1/image/我的.png"));
    this->setIconSize(QSize(40,40));
    this->setFixedHeight(50);
    this->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);text-align: left;"
                        "font-family:'Microsoft YaHei';font-size:20px;color:black;}"
                        "QPushButton:hover{background: rgb(242,242,242)}");
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}
