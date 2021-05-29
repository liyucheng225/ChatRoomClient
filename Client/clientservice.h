#ifndef CLIENTSERVICE_H
#define CLIENTSERVICE_H

#include <QObject>
#include "HomePage/homepage.h"
#include "loginservice.h"
#include <iostream>
#include "client.h"

class ClientService : public QObject
{
    Q_OBJECT
public:
    explicit ClientService(QObject *parent = nullptr);
    static ClientService *instance();

signals:
    void registerBackMsg(bool backMsg, QString userId = nullptr);
    void loginBackMsg(int type);

private:
    LoginService loginService;
public slots:
    /*用户登陆*/
    void userLogin(QString account, QString passwd);

    /*用户注册账号*/
    void userRegister(QString name, QString passwd, int index, QString answer);

};

#endif // CLIENTSERVICE_H
