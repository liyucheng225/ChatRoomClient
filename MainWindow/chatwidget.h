#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "scrollareamodel.h"
#include "User/user.h"
namespace Ui {
class chatWidget;
}

class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(User user ,QWidget *parent = nullptr);
    ~chatWidget();
    User user;
    int id;
    QString userName;
signals:
    void sendMsg(QString msg, int id);
private:
    Ui::chatWidget *ui;
};

#endif // CHATWIDGET_H
