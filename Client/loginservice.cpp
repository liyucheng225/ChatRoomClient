#include "loginservice.h"

LoginService::LoginService(QObject *parent) : QObject(parent) {

}

void LoginService::userLogin(QString account, QString passwd)
{
    qDebug() << "用户准备登陆" << account << passwd;
//    json js;
//    js["msgId"] = LOG_MSG_GO;
//    js["account"] = account.toStdString();
//    js["passwd"] = passwd.toStdString();
//    string request = js.dump();
//    int len = send(Client::instance()->clientfd,request.c_str(),strlen(request.c_str()),0);
//    if (len == -1) {
//        perror("send msg error!");
//    } else {

//    }

}
LoginService::~LoginService() {

}
