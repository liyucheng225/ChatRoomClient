#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include "public.h"


namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();
    static HomePage* instance();
    /*登陆页面初始化*/
    void loginPageInit();

    /*注册页面初始化*/
    void registerPageInit();

    /*忘记密码页面初始化*/
    void forgetPageInit();
    QPushButton* SearchButton(QLineEdit *edit);
    void registerBackMsgHandler(bool backMsg, QString userId = nullptr);
    void loginBackMsgHandler(int type);

    int currentId;

private slots:
    void on_exitButton_clicked();//关闭按钮关闭客户端

    void on_minButton_clicked();

    void on_forgetButton_clicked();

    void on_registerButton_clicked();

    void on_for_loginButton_clicked();

    void on_for_registerButton_clicked();

    void on_res_forgetButton_clicked();

    void on_res_loginButton_clicked();

    void on_loginConfirm_clicked();
    void on_registerConfirm_clicked();

signals:
    void loginToMainPage(QString account,QString passwd);
    void registerToMainPage(QString name, QString passwd, int index, QString answer);
    void loginOut();
private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
