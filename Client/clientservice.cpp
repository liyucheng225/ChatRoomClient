#include "clientservice.h"

ClientService *ClientService::instance()
{
    static ClientService clientService;
    return &clientService;
}

ClientService::ClientService(QObject *parent) : QObject(parent)
{
    //登陆页面发送跳转信号，
    connect(HomePage::instance(), &HomePage::loginToMainPage, this,&ClientService::userLogin);

    //注册页面发送信号
    connect(HomePage::instance(), &HomePage::registerToMainPage, this ,&ClientService::userRegister);

    //业务处理模块发送注册返回信号
    connect(this,&ClientService::registerBackMsg, HomePage::instance(), &HomePage::registerBackMsgHandler);

    //业务处理模块发送登陆返回信号
    connect(this,&ClientService::loginBackMsg, HomePage::instance(), &HomePage::loginBackMsgHandler);

    //用户注销服务
    connect(HomePage::instance(), &HomePage::loginOut, this, &ClientService::userLoginOutService);

    //解析好用户数据后发送信号
    connect(this, &ClientService::currentUserInfo, MainPage::instance(), &MainPage::currentUserInfoRecv);
}
/*
    用户登陆业务处理函数
*/
void ClientService::userLogin(QString account, QString passwd) {
    qDebug() << "用户准备登陆" << account << passwd;
    json js;
    js["msgId"] = LOG_MSG_GO;
    js["id"] = account.toInt();
    js["passwd"] = passwd.toStdString();
    string request = js.dump();
    int len = send(Client::instance()->clientfd,request.c_str(),strlen(request.c_str()),0);
    if (len == -1) {
        perror("send msg error!");
    } else {
        char buf[1024] = {0};
        //从服务器接受数据
        len = recv(Client::instance()->clientfd, buf, 1024, 0);
        qDebug() << buf;
        string response(buf);
        json resJson = json::parse(response);
        cout << resJson << endl;
        int type = resJson["type"].get<int>();
        qDebug() << "type:" << type;

        if (type == LOGIN_BACK_SUCCESS) {
            /*用户登陆成功，解析该用户好友信息等数据*/
            //当前用户信息解析
            User currentUser;
            currentUser.setUserId(resJson["id"].get<int>());
            currentUser.setUserName(resJson["name"]);
            qDebug() << "当前用户的id：" << currentUser.getUserId() << "name：" <<
                        QString::fromStdString(currentUser.getUserName());

            //当前用户的好友信息
            vector<User> friends;
            if (resJson.contains("friend")) { //判断json对象中该字段是否存在
                vector<string> friendTemp = resJson["friend"];
                for (string &str : friendTemp) {
                    json js = json::parse(str);
                    User user;
                    user.setUserId(js["id"]);
                    user.setUserName(js["name"]);
                    user.setUserState(js["state"]);
                    if (user.getUserstate() == LOGIN_BACK_NOONLINE) qDebug() << "17";
                    friends.push_back(user);
                    qDebug() << "当前用户的好友：" << "id：" << currentUser.getUserId() << "name：" <<
                                QString::fromStdString(currentUser.getUserName()) << "state" << currentUser.getUserstate();
                }
            }

            //获取当前用户所在群组的信息
            vector<Group> groups;
            if (resJson.contains("groups")) {
                vector<string> groupTemp = resJson["groups"];
                for (string &str : groupTemp) {
                    Group group;
                    json groupJs = json::parse(str);
                    group.setGroupId(groupJs["id"]);
                    group.setGroupName(groupJs["name"]);
                    group.setGroupoDesc(groupJs["desc"]);
                    qDebug() << "当前用户所在群聊id:" << group.getGroupId() << "name:" <<
                              QString::fromStdString(group.getGroupName()) << "desc:" <<
                              QString::fromStdString(group.getGroupDesc());
                    if (groupJs.contains("users")) {
                        vector<string> userTemp = groupJs["users"];
                        for (string &uStr : userTemp) {
                            GroupUser groupUser;
                            json js = json::parse(uStr);
                            groupUser.setUserId(js["id"]);
                            groupUser.setUserName(js["name"]);
                            groupUser.setUserState(js["state"]);
                            groupUser.setRole(js["role"]);
                            group.getUser().push_back(groupUser);
                            qDebug() << "当前用户所在群的好友：" << "id：" << currentUser.getUserId() << "name：" <<
                                        QString::fromStdString(currentUser.getUserName()) << "state" << currentUser.getUserstate();
                        }
                    }
                }
            }
            emit currentUserInfo(currentUser, friends , groups);
        }
        emit loginBackMsg(type);
    }

}
/*
    用户注册业务处理函数
*/
void ClientService::userRegister(QString name, QString passwd, int index, QString answer) {
    qDebug() << "用户准备注册" << name << passwd << index << answer;
    json js;
    js["msgId"] = REG_MSG_GO;
    js["name"] = name.toStdString();
    js["passwd"] = passwd.toStdString();
    js["questionIndex"] = index;
    js["answer"] = answer.toStdString();
    string request = js.dump();
    int len = send(Client::instance()->clientfd, request.c_str(), strlen(request.c_str()), 0);
    if (len == -1) {
        perror("send register msg error!");
    } else {
        char buf[1024] = {0};
        len =recv(Client::instance()->clientfd, buf, 1024, 0);
        if (len == -1) {
            qDebug() << "register error!";
        } else {
            qDebug() << "register back: " << buf << ",len:" << len;
            string response(buf);
            json resJson = json::parse(response);
            if (resJson["success"])
                emit registerBackMsg(resJson["success"], QString::number(resJson["id"].get<int>()));
            else
                emit registerBackMsg(resJson["success"]);
        }
    }
}

void ClientService::userLoginOutService()
{
    qDebug() <<"ahuxiao";
    json js;
    js["msgId"] = LOGINOUT_MSG;
    js["id"] = 111111111;
    string request = js.dump();
    int len = send(Client::instance()->clientfd, request.c_str(), strlen(request.c_str()), 0);
    if (len == -1) {
        perror("user login out error!");
    }
}


