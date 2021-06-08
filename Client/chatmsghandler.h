#ifndef CHATMSGHANDLER_H
#define CHATMSGHANDLER_H

#include <QObject>
#include <QThread>
#include "client.h"
using namespace std;
class ChatMsgHandler : public QThread
{
    Q_OBJECT
public:
     explicit ChatMsgHandler(int currentId, QObject *parent = nullptr);
     int currentId;
signals:
    void oneChatMsg(QString msg);
protected:
     void run();
};

#endif // CHATMSGHANDLER_H
