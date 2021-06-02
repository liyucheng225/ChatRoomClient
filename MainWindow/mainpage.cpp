#include "mainpage.h"
#include "ui_mainpage.h"
#include <QPushButton>
#include <QScrollArea>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    //取消边距
    this->setContentsMargins(0,0,0,0);
    //    ScrollAreaModel *scrollArea = new  ScrollAreaModel(this);

    //右边栈容器
    StackWidgetModel *mianStackWidget = new StackWidgetModel();

    //左边控制栏
    QWidget *leftControl = new QWidget(this);
    leftControl->setContentsMargins(0,0,0,0);
    leftControl->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    leftControl->setFixedWidth(50);
    leftControl->setAttribute(Qt::WA_StyledBackground,true);
    leftControl->setStyleSheet("background-color: rgb(255,255,255)");

    QWidget *topWidget = new QWidget(leftControl);
    QPushButton *Avatar = new QPushButton(topWidget);
    Avatar->setFixedSize(40,40);
    Avatar->setIcon(QIcon(":/new/prefix1/image/男头像.png"));
    Avatar->setIconSize(QSize(40,40));
    Avatar->move(5,25);
    Avatar->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    QPushButton *chat = new QPushButton(topWidget);
    chat->setFixedSize(40,40);
    chat->setIcon(QIcon(":/new/prefix1/image/聊天.png"));
    chat->setIconSize(QSize(40,40));
    chat->move(5,100);
    chat->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");

    connect(chat, &QPushButton::clicked, mianStackWidget, [=]() {
        qDebug() << "发送0";
        emit showWidget(0);
    });
    connect(this, &MainPage::showWidget, mianStackWidget, &StackWidgetModel::showStackWidget);

    QPushButton *user = new QPushButton(topWidget);
    user->setFixedSize(40,40);
    user->setIcon(QIcon(":/new/prefix1/image/我的.png"));
    user->setIconSize(QSize(40,40));
    user->move(5,150);
    user->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    connect(user, &QPushButton::clicked, mianStackWidget, [=]() {
       emit showWidget(1);
        qDebug() << "发送1";
    });
    connect(this, &MainPage::showWidget, mianStackWidget, &StackWidgetModel::showStackWidget);

    QWidget *buttonWidget = new QWidget(leftControl);
//    buttonWidget->setStyleSheet("QWidget{border:1px solid rgb(0,0,0)}");
    buttonWidget->setFixedHeight(50);
    QPushButton *setting = new QPushButton(buttonWidget);
    setting->setFixedSize(40,40);
    setting->setIcon(QIcon(":/new/prefix1/image/列表.png"));
    setting->setIconSize(QSize(40,40));
    setting->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
//    connect(user, &QPushButton::click, mianStackWidget, [=]() {
//        emit show(0);
//    });
//    connect(this, &MainPage::show, mianStackWidget, &StackWidgetModel::showStackWidget);

    QVBoxLayout *leftControlLayout = new QVBoxLayout(leftControl);
    leftControlLayout->addWidget(topWidget);
    leftControlLayout->addWidget(buttonWidget);
    leftControlLayout->setMargin(0);
    leftControlLayout->setSpacing(0);
    leftControl->setLayout(leftControlLayout);

    //主页面布局
    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(leftControl);
    mainLayout->addWidget(mianStackWidget);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    //    leftControl->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    //    mainLayout->addWidget(leftControl);
    //    mainLayout->addWidget(scrollArea);

    //    QWidget *widget = new QWidget(this);
    //    mainLayout->addWidget(widget);
    //    widget->resize(500,700);
    //    widget->setAttribute(Qt::WA_StyledBackground,true);
    //    widget->setStyleSheet("background-color: rgb(125,155,225)");
    //    this->setLayout(mainLayout);
    //    this->setStyleSheet("QWidget{border:1px solid rgb(0,0,0)}");
    //    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

}

MainPage::~MainPage()
{
    delete ui;
}

MainPage *MainPage::instance()
{
    static MainPage mainPage;
    return &mainPage;
}

void MainPage::currentUserInfoRecv(User currentUser, vector<User> friendList, vector<Group> groupList)
{
    this->groupList = groupList;
    this->friendList = friendList;
    this->currentUser = currentUser;
    this->show();
}
