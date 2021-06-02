#include "mainwindow.h"
#include "HomePage/homepage.h"
#include "Client/client.h"
#include <QApplication>
#include "Client/ClientService.h"
#include "public.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    HomePage::instance()->show();
//    Client::instance();
//    ClientService::instance();
    MainPage::instance()->show();
    return a.exec();
}
