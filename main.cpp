#include "mainwindow.h"
#include "HomePage/homepage.h"
#include "Client/client.h"
#include "MainWindow/chatwidget.h"
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
//    chatWidget chatWidget;
//    chatWidget.show();
    return a.exec();
}
