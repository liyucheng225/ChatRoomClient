#include "stackwidgetmodel.h"
#include <QHBoxLayout>
#include "chatstackwidget.h"
#include "userstackwidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
StackWidgetModel::StackWidgetModel(QWidget *parent) : QStackedWidget(parent)
{
    chatIndex = 0;
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//    this->setStyleSheet("QStackedWidget{border:1px solid rgb(244,66,244)}");
    this->isFriend = false;

    //聊天窗口
    QWidget *chatWidget = new QWidget(this);
    chatWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//    chatWidget->setStyleSheet("QWidget{border:1px solid rgb(0,244,244);background:rgba(0,0,0)}");
    //聊天窗口左边栏
    QWidget *leftWidgetChat = new QWidget(chatWidget);
    leftWidgetChat->setFixedWidth(280);
//    leftWidgetChat->setStyleSheet("QWidget{border:1px solid rgb(244,244,25)}");
    //聊天窗口左边导航栏
    chatScrollArea = new ScrollAreaModel(leftWidgetChat);
    chatScrollArea->setMinimumSize(QSize(268,leftWidgetChat->height() - 5));
//    chatScrollArea->setStyleSheet("QWidget{border:1px solid rgb(244,2,25)}");
    qDebug()<<"scrollArea size1:"<<chatScrollArea->height();
    //左边搜索栏
    QWidget *searchWidget = new QWidget(leftWidgetChat);
    searchWidget->setFixedSize(280,65);
    searchWidget->setStyleSheet("background-color:rgb(255,255,255)");
    QLineEdit *serchLine = new QLineEdit(searchWidget);
    serchLine->move(10,30);
    serchLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    serchLine->setPlaceholderText(QString::fromLocal8Bit("搜索"));//设置提示
    serchLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                             "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    serchLine->resize(200,30);
    //    serchLine->setMaxLength(20);//设置最大长度20位

    //左边栏布局
    QVBoxLayout *leftLayout=new QVBoxLayout(leftWidgetChat);
    leftLayout->setMargin(0);
    leftLayout->setSpacing(0);
    leftLayout->addWidget(searchWidget);
    leftLayout->addWidget(chatScrollArea);
    leftWidgetChat->setLayout(leftLayout);

    //聊天窗口右边stack容器
    chatStackedWidget = new ChatStackWidget(chatWidget);
    chatStackedWidget->setStyleSheet("QScrollArea{border:1px solid rgb(244,244,244)}");
//    chatStackedWidget->setStyleSheet("QStackedWidget{border:1px solid rgb(24,66,244)}");
    //聊天窗口布局
    QHBoxLayout *chatLayout=new QHBoxLayout(chatWidget);
    chatLayout->setMargin(0);
    chatLayout->setSpacing(0);
    chatLayout->addWidget(leftWidgetChat);
    chatLayout->addWidget(chatStackedWidget);
    chatWidget->setLayout(chatLayout);

    //向statck容器中添加页面
    this->addWidget(chatWidget);

//    QHBoxLayout *chatStackLayout=new QHBoxLayout(this);
//    chatStackLayout->setMargin(0);
//    chatStackLayout->setSpacing(0);
//    chatStackLayout->addWidget(chatWidget);
//    chatStackLayout->setLayout(chatStackLayout);



    //用户窗口
    QWidget * userWidget = new QWidget(this);
    //用户窗口左边栏
    QWidget * leftWidgetUser = new QWidget(userWidget);
    leftWidgetUser->setFixedWidth(280);
    //leftWidget->setStyleSheet("QWidget{border:1px solid rgb(244,244,244)");
    QStackedWidget *swapStackWidget = new QStackedWidget(leftWidgetUser);
    //用户窗口左边导航栏
    this->groupScrollArea = new ScrollAreaModel(swapStackWidget);
    groupScrollArea->setStyleSheet("QScrollArea{border:1px solid rgb(244,244,244)}");
    //用户窗口左边导航栏
    this->friendScrollArea = new ScrollAreaModel(swapStackWidget);
    friendScrollArea->setMinimumSize(QSize(268,leftWidgetUser->height() - 5));
    friendScrollArea->setStyleSheet("QScrollArea{border:1px solid rgb(244,244,244)}");
    swapStackWidget->addWidget(friendScrollArea);
    swapStackWidget->addWidget(groupScrollArea);
    //左边搜索栏
    QWidget *searchWidgetUser = new QWidget(leftWidgetUser);
    searchWidgetUser->setStyleSheet("QWidget{border:1px solid rgb(244,244,244);background-color:rgb(255,255,255);}");

    searchWidgetUser->setFixedSize(280,90);
//    searchWidgetUser->setStyleSheet("background-color:rgb(255,255,255)");
    QLineEdit *serchLineUser = new QLineEdit(searchWidgetUser);
    serchLineUser->move(10,30);
    serchLineUser->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    serchLineUser->setPlaceholderText(QString::fromLocal8Bit("用户"));//设置提示
    serchLineUser->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                                 "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    serchLineUser->resize(200,30);
    //    serchLine->setMaxLength(20);//设置最大长度20位

    QPushButton *friendButton = new QPushButton("好友",searchWidgetUser);
    friendButton->setCheckable(true);
    friendButton->setFixedSize(40,40);
    friendButton->move(70,50);
    friendButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}"
                               "QPushButton:checked {color: rgba(8,60,255)}"
                               "QPushButton:unchecked {color:black}"
                               );
    connect(friendButton, &QPushButton::clicked, [=]() {
        qDebug() << "好友";
        swapStackWidget->setCurrentIndex(0);
    });
    QPushButton *groupButton = new QPushButton("群聊",searchWidgetUser);
    groupButton->setCheckable(true);
    groupButton->setFixedSize(40,40);
    groupButton->move(170,50);
    groupButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}"
                               "QPushButton:checked {color: rgba(8,60,255)}"
                               "QPushButton:unchecked {color:black}"
                               );
    connect(groupButton, &QPushButton::clicked, [=]() {
        qDebug() << "群聊";
        swapStackWidget->setCurrentIndex(1);
    });

    //左边栏布局
    QVBoxLayout *leftLayoutUser=new QVBoxLayout();
    leftLayoutUser->setMargin(0);
    leftLayoutUser->setSpacing(0);
    leftLayoutUser->addWidget(searchWidgetUser);
    leftLayoutUser->addWidget(swapStackWidget);
    leftWidgetUser->setLayout(leftLayoutUser);

    //聊天窗口右边stack容器
    userStackedWidget = new UserStackWidget(userWidget);
    userStackedWidget->setStyleSheet("QScrollArea{border:1px solid rgb(244,244,244)}");
    userStackedWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    leftWidgetUser->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //聊天窗口布局
    QHBoxLayout *userLayout = new QHBoxLayout();
    userLayout->setMargin(0);
    userLayout->setSpacing(0);
    userLayout->addWidget(leftWidgetUser);
    userLayout->addWidget(userStackedWidget);
    userWidget->setLayout(userLayout);
    //向statck容器中添加页面
    this->addWidget(userWidget);

//    signalMapper = new QSignalMapper(this);
    //    connect(signalMapper, SIGNAL(mapped(const int)),this,SLOT(showUserChat(const int)));
}

void StackWidgetModel::showFriendList()
{
    for (int i = 0; i < 5; i++) {
        User user1(i,"阿福0" + to_string(i),"132",1,1,"af");
        friendList.push_back(user1);
    }
    if (!isFriend) {
        qDebug() << "到达页面1";
        if (friendScrollAreaWidgetContents == nullptr) {
            qDebug() << "创建展示";
            //创建好友列表展示窗口
            friendScrollAreaWidgetContents = new QWidget(friendScrollArea);
            friendScrollAreaWidgetContents->setMinimumSize(QSize(268,this->friendScrollArea->height() - 5));
            friendScrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            friendScrollAreaWidgetContents->setContentsMargins(0,0,0,0);
            friendScrollAreaWidgetContents->setFixedWidth(260);
        //           scrollAreaWidgetContents->setStyleSheet("QWidget{border:1px solid rgb(0,0,0);background: rgba(242,242,242)}");
            //创建好友列表展示窗口布局
            friendLayout = new QVBoxLayout(friendScrollAreaWidgetContents);
            friendLayout->setMargin(0);
            friendLayout->setSpacing(0);
        }
        for (auto friend_ : friendList) {
            QPushButton *pushButton = new QPushButton(QIcon(":/new/prefix1/image/我的.png"),
                     QString::fromStdString(" " + friend_.getUserName()),friendScrollAreaWidgetContents);
            pushButton->setIconSize(QSize(40,40));
            pushButton->setFixedHeight(50);
            pushButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);text-align: left;"
                                      "font-family:'Microsoft YaHei';font-size:20px;color:black;}"
                                      "QPushButton:hover{background: rgba(242,242,242)}");
            pushButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            connect(pushButton, &QPushButton::clicked, [=]() {
                qDebug() << "emit chat";
    //                   emit userChat(friend_);
                chatFriend.push_back(friend_);
                showUserChat(friend_);
                qDebug() << "emit chat";
            });
    //               signalMapper->setMapping(pushButton,friend_.getUserId());
            friendMap.insert({friend_.getUserId(),pushButton});
            friendLayout->addWidget(pushButton);
        }
        friendLayout->addStretch();
        friendScrollAreaWidgetContents->setLayout(friendLayout);
        this->friendScrollArea->setWidget(friendScrollAreaWidgetContents);
        isFriend = true;
    }
}


void StackWidgetModel::showStackWidget(int index)
{

    qDebug() << "跳转：" << index;
    this->setCurrentIndex(index);
    if (index == 1) {
        showFriendList();
    } else if (index == 0) {

    }
}

void StackWidgetModel::showUserChat(User  _friend)
{
    qDebug() << chatIndex;
    auto it = id_index_map.find(_friend.getUserId());
    if (it == id_index_map.end()) {
        if (chatScrollAreaWidgetContents == nullptr) {
            qDebug() << "创建展示";
            //创建好友列表展示窗口
            chatScrollAreaWidgetContents = new QWidget(chatScrollArea);
            chatScrollAreaWidgetContents->setMinimumSize(QSize(268,this->chatScrollArea->height() - 5));
            chatScrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            chatScrollAreaWidgetContents->setContentsMargins(0,0,0,0);
            chatScrollAreaWidgetContents->setFixedWidth(260);
        //           scrollAreaWidgetContents->setStyleSheet("QWidget{border:1px solid rgb(0,0,0);background: rgba(242,242,242)}");
            //创建好友列表展示窗口布局
            chatListLayout = new QVBoxLayout(chatScrollAreaWidgetContents);
            chatListLayout->setMargin(0);
            chatListLayout->setSpacing(0);
        }
//        QWidget *userChatWidget = new QWidget(chatStackedWidget);
//        qDebug() << QString::fromStdString(_friend.getUserName());
//        chatStackedWidget->addWidget(userChatWidget);
        //创建展示菜单栏
        QPushButton *pushButton = new QPushButton(QIcon(":/new/prefix1/image/我的.png"),
                                                  QString::fromStdString(" " + _friend.getUserName()),chatScrollAreaWidgetContents);
        pushButton->setIconSize(QSize(40,40));
        pushButton->setFixedHeight(50);
        pushButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);text-align: left;"
                                  "font-family:'Microsoft YaHei';font-size:20px;color:black;}"
                                  "QPushButton:hover{background: rgba(242,242,242)}");
        pushButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        chatListLayout->addWidget(pushButton);
        chatScrollAreaWidgetContents->setLayout(chatListLayout);
        this->chatScrollArea->setWidget(chatScrollAreaWidgetContents);
        id_index_map.insert({_friend.getUserId(),chatIndex});
        chatStackedWidget->setCurrentIndex(chatIndex++);
    } else {
        chatStackedWidget->setCurrentIndex(id_index_map[_friend.getUserId()]);
    }
    this->setCurrentIndex(0);
}

