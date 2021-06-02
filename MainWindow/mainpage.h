#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "scrollareamodel.h"
#include "stackwidgetmodel.h"
namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();
    static MainPage *instance();
    void currentUserInfoRecv(User currentUser, vector<User> friendList, vector<Group> groupList);
private:
    Ui::MainPage *ui;
    User currentUser; //当前登陆对象
    vector<User> friendList;
    vector<Group> groupList; //群组列表
signals:
    void showWidget(int index);
};

#endif // MAINPAGE_H
