#ifndef STACKWIDGETMODEL_H
#define STACKWIDGETMODEL_H

#include <QWidget>
#include <QStackedWidget>
#include <unordered_map>
#include <QSignalMapper>
#include <QListWidget>
#include "scrollareamodel.h"
#include <QPushButton>
#include "User/group.h"
#include "User/groupuser.h"
#include "User/user.h"
class StackWidgetModel : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackWidgetModel(QWidget *parent = nullptr);
    unordered_map<int,QPushButton*> friendMap;
     unordered_map<int,int> id_index_map;
    ScrollAreaModel *groupScrollArea;
    ScrollAreaModel *friendScrollArea;
    ScrollAreaModel *chatScrollArea;
    User currentUser; //当前登陆对象
    vector<User> friendList;
    vector<Group> groupList; //群组列表
    bool isFriend;
    QSignalMapper *signalMapper;
    void setMapper(QPushButton*, User&);    //设置转发
    void connectMapper();   //连接转发器
    int chatIndex;
    QStackedWidget *chatStackedWidget;
    QStackedWidget *userStackedWidget;
    void showFriendList();

    //滑动界面窗口
    QWidget *friendScrollAreaWidgetContents;
    QWidget *groupScrollAreaWidgetContents;
    QWidget *chatScrollAreaWidgetContents;

    //滑动界面布局
    QVBoxLayout *friendLayout;
    QVBoxLayout *chatListLayout;
    QVBoxLayout *groupLayout;

    vector<User> chatFriend;

public slots:
    void showStackWidget(int index);
    void showUserChat(User _friend);
signals:
    void userChat(User _friend);
};

#endif // CHATSTACKWIDGET_H
