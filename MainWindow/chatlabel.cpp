#include "chatlabel.h"
#include <QHBoxLayout>
#include <QLabel>
chatLabel::chatLabel(QString msg, bool flags, QWidget *parent) : QWidget(parent)
{
//    this->setStyleSheet("QWidget{background-color: rgb(255, 255, 255);}");
    this->setFixedSize(350,40);
//    this->setFixedWidth(350);
    this->setContentsMargins(0,0,0,0);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setMargin(0);

    QPushButton *icon = new QPushButton(this);
    icon->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);}");
    icon->setIcon(QIcon(":/new/prefix1/image/我的.png"));
    icon->setFixedSize(40,40);
    icon->setIconSize(QSize(40,40));

    QLabel *label = new QLabel(this);
    label->setText(msg);
    label->setStyleSheet("QLabel{background-color: rgb(255, 255, 255);}");
    label->setFixedSize(300,40);

    if (flags) {
        layout->addWidget(icon);
        layout->addStretch();
        layout->addWidget(label);
    } else {
        layout->addWidget(label);
        layout->addStretch();
        layout->addWidget(icon);

    }
    this->setLayout(layout);
}
