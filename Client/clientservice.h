#ifndef CLIENTSERVICE_H
#define CLIENTSERVICE_H

#include <QObject>
#include "HomePage/homepage.h"
#include "loginservice.h"
#include <iostream>
#include "client.h"
//#include "User/user.h"
//#include "User/group.h"
//#include "User/groupuser.h"
#include "MainWindow/mainpage.h"
class ClientService : public QObject
{
    Q_OBJECT
public:
    explicit ClientService(QObject *parent = nullptr);
    static ClientService *instance();

signals:
    void registerBackMsg(bool backMsg, QString userId = nullptr);
    void loginBackMsg(int type);
    void currentUserInfo(User currentUser, vector<User> friendList, vector<Group> groupList);

private:
    LoginService loginService;
public slots:
    /*用户登陆*/
    void userLogin(QString account, QString passwd);

    /*用户注册账号*/
    void userRegister(QString name, QString passwd, int index, QString answer);

    /*用户注销服务*/
    void userLoginOutService();
};

#endif // CLIENTSERVICE_H
