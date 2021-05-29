#include "mainwindow.h"
#include "HomePage/homepage.h"
#include "Client/client.h"
#include <QApplication>
#include "Client/ClientService.h"
#include "public.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage::instance()->show();
    Client::instance();
    ClientService::instance();
//    json js;
//    js["msgid"] = REG_MSG_GO;
//    js["name"] = "阿的方法";
//    js["password"] = "wee";
//    string request = js.dump();
//    json res = json::parse(request);
//    string name = res["name"];
//    qDebug() << QString::fromStdString(name);;
    return a.exec();
}
