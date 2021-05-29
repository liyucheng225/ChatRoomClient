#include "clientservice.h"

ClientService *ClientService::instance()
{
    static ClientService clientService;
    return &clientService;
}

ClientService::ClientService(QObject *parent) : QObject(parent)
{
    connect(HomePage::instance(), &HomePage::loginToMainPage, this,&ClientService::userLogin);
    connect(HomePage::instance(), &HomePage::registerToMainPage, this ,&ClientService::userRegister);
    connect(this,&ClientService::registerBackMsg, HomePage::instance(), &HomePage::registerBackMsgHandler);
    connect(this,&ClientService::loginBackMsg, HomePage::instance(), &HomePage::loginBackMsgHandler);
//    connect(HomePage::instance(),&HomePage::loginToMainPage,this,[=] () {
//        qDebug() << "用户准备登陆";
//    });
}
void ClientService::userLogin(QString account, QString passwd) {
    qDebug() << "用户准备登陆" << account << passwd;
    json js;
    js["msgId"] = LOG_MSG_GO;
    js["id"] = account.toStdString();
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
        int type = resJson["type"].get<int>();
        qDebug() << type;
//        switch (resJson["type"].get<int>()) {
//        case LOGIN_BACK_SUCCESS:
//            /*登陆成功*/
//            emit loginBackMsg(LOGIN_BACK_SUCCESS);
//            break;
//        case LOGIN_BACK_ISONLINE:
//            /*用户在线*/
//            break;
//        case LOGIN_BACK_EMPTY:
//            /*用户不存在*/
//            break;
//        }
        if (type == LOGIN_BACK_SUCCESS) {
            /*用户登陆成功，解析该用户好友信息等数据*/
            qDebug() << type << "1";
            emit loginBackMsg(type);
        } else {
            emit loginBackMsg(type);
            qDebug() << type << "2";
        }
    }

}

void ClientService::userRegister(QString name, QString passwd, int index, QString answer) {
    qDebug() << "用户准备注册" << name << passwd << index << answer;
    json js;
    js["msgId"] = REG_MSG_GO;
    js["name"] = name.toStdString();
    js["passwd"] = passwd.toStdString();
    js["questionIndex"] = index;
    js["answer"] = answer.toStdString();
    string request = js.dump();
    int len = send(Client::instance()->clientfd,request.c_str(),strlen(request.c_str()),0);
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
                emit registerBackMsg(resJson["success"], QString::fromStdString(resJson["id"]));
            else
                emit registerBackMsg(resJson["success"]);
        }
    }
}


