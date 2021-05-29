#ifndef LOGINSERVICE_H
#define LOGINSERVICE_H

#include <QObject>
#include <QDebug>
//#include "client.h"
#include "HomePage/homepage.h"
#include "public.h"
class LoginService : public QObject
{
    Q_OBJECT
public:
    explicit LoginService(QObject *parent = nullptr);
    ~LoginService();

signals:

public slots:
    void userLogin(QString account, QString passwd);
};

#endif // LOGINSERVICE_H
