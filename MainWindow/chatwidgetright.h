#ifndef CHATWIDGETRIGHT_H
#define CHATWIDGETRIGHT_H

#include <QWidget>
#include "User/user.h"
#include <QTextEdit>
class chatWidgetRight : public QWidget
{
    Q_OBJECT
public:
    explicit chatWidgetRight(User user, QWidget *parent = nullptr);
    User user;
    int id;
    QWidget *recordWidget;
    QTextEdit *edit;
    QString userName;
    void showRecord();
signals:
    void sendMsg(QString msg, int id);
};

#endif // CHATWIDGETRIGHT_H
