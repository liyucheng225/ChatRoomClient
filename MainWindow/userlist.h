#ifndef USERLIST_H
#define USERLIST_H

#include <QWidget>
#include <QLabel>
class UserList : public QWidget
{
    Q_OBJECT
public:
    explicit UserList(QWidget *parent = nullptr);
    void initUI();//初始化ui
    QWidget *head;  //头像
    QLabel *name;
    QLabel *sign;
    QString headPath;
//    bool eventFilter(QObject *obj, QEvent *event);//事件过滤器
signals:

};

#endif // USERLIST_H
