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
    connect(HomePage::instance(), &HomePage::userLoginOut, this, &ClientService::userLoginOutService);
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
        int type = resJson["type"].get<int>();
        qDebug() << type;
        if (type == LOGIN_BACK_SUCCESS) {
            /*用户登陆成功，解析该用户好友信息等数据*/
            emit loginBackMsg(type);
        } else {
            emit loginBackMsg(type);
        }
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

void ClientService::userLoginOutService(int id)
{
    json js;
    js["msgId"] = LOGINOUT_MSG;
    js["id"] = id;
    string request = js.dump();
    int len = send(Client::instance()->clientfd, request.c_str(), strlen(request.c_str()), 0);
    if (len == -1) {
        perror("user login out error!");
    }
}


