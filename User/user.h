#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
# include <stdlib.h>
using namespace std;

class User
{
public:
    User(int userId, string userName, string userPasswd, int questionIndex, int state, string answer);
    void setUserName(string userName);
    void setUserPasswd(string userPasswd);
    void setUserId(int userId);
    void setUserState(int state);
    void setUserQuestionIndex(int index);
    void setUserAnswer(string answer);

    int getUserId();
    string getUserName();
    string getUserPasswd();
    int getUserstate();
    int getUserQuestionIndex();
    string getUserAnswer();
    User();
    ~User();
private:
    /* data */
    string userName; //用户名
    int userId; //用户登录帐号
    string userPasswd; //用户密码
    int questionIndex;//密保问题序号
    string answer; //密保答案
    int state; //用户在线状态
};

#endif
