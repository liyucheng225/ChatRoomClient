#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QCloseEvent>
#include "scrollareamodel.h"
#include "stackwidgetmodel.h"
namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();
    static MainPage *instance();
    void currentUserInfoRecv(User currentUser, vector<User> friendList, vector<Group> groupList);
    void messageArriveHandler(QString msg,int id);
    void closeEvent(QCloseEvent *event);
private:
    Ui::MainPage *ui;
    User currentUser; //当前登陆对象
    vector<User> friendList;
    vector<Group> groupList; //群组列表
signals:
    void showWidget(int index, User currentUser, vector<User> friendList, vector<Group> groupList);
    void sendMsg(QString msg,int id, int uid);
    void loginOut();
    void msgFrom(QString msg, int id);
};

#endif // MAINPAGE_H
