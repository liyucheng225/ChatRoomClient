#include "chatmsghandler.h"

ChatMsgHandler::ChatMsgHandler(int currentId, QObject *parent)
{
    this->currentId = currentId;
}

void ChatMsgHandler::run()
{
    sleep(3);
    qDebug() <<"线程启动";
    while(true) {
        char buf[1024] = {0};
        int len = recv(Client::instance()->clientfd, buf,1024,0);
        if (len <= 0) {
            close(Client::instance()->clientfd);
            exit(-1);
        }
        string str(buf);
        qDebug() <<"收到消息返回：" << QString::fromStdString(str);
        emit oneChatMsg(QString::fromStdString(str));
    }
}
