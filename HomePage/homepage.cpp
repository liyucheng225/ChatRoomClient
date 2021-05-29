#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//取消菜单栏
    ui->logo->setStyleSheet("QPushButton{border-radius:50px;}");//正方型按钮参数设置为一半即为圆

    /*最小化按钮*/
    ui->minButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->minButton->setFlat(true);

    /*关闭按钮*/
    ui->exitButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->exitButton->setFlat(true);
    ui->stackedWidget->setCurrentIndex(0);
    loginPageInit();
    registerPageInit();
    forgetPageInit();

}

HomePage::~HomePage()
{
    delete ui;
}

HomePage *HomePage::instance()
{
    static HomePage homePage;
    return &homePage;
}

void HomePage::loginPageInit()
{
    /*账号密码输入框*/
    ui->accLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->accLine->setPlaceholderText(QString::fromLocal8Bit("账号"));//设置密码提示
    ui->accLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                               "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->accLine->setMaxLength(20);//设置最大长度20位

    ui->pwdLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->pwdLine->setPlaceholderText(QString::fromLocal8Bit("密码"));//设置密码提示
    ui->pwdLine->setEchoMode(QLineEdit::Password);//设置密码隐藏
    ui->pwdLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                               "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->pwdLine->setMaxLength(20);//设置最大长度20位
//    QPushButton *loginConfirm = HomePage::SearchButton(ui->pwdLine);


    QHBoxLayout *layout = new QHBoxLayout();
    ui->loginConfirm->setCursor(QCursor(Qt::PointingHandCursor));
    ui->loginConfirm->setStyleSheet("QPushButton{border-radius:15px;}");//正方型按钮参数设置为一半即为圆
    layout->addStretch();
    layout->addWidget(ui->loginConfirm);
    layout->setContentsMargins(0,0,0,0);
    ui->pwdLine->setLayout(layout);



    /*忘记密码按钮*/
    ui->forgetButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->forgetButton->setFlat(true);

    /*注册按钮*/
    ui->registerButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->registerButton->setFlat(true);

}

void HomePage::registerPageInit()
{
    ui->res_accLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->res_accLine->setPlaceholderText(QString::fromLocal8Bit("账号"));//设置密码提示
    ui->res_accLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                                   "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->res_accLine->setMaxLength(20);//设置最大长度20位

    ui->res_pwdLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->res_pwdLine->setPlaceholderText(QString::fromLocal8Bit("密码"));//设置密码提示
    ui->res_pwdLine->setEchoMode(QLineEdit::Password);//设置密码隐藏
    ui->res_pwdLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                                   "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->res_pwdLine->setMaxLength(20);//设置最大长度20位

    ui->res_answerLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->res_answerLine->setPlaceholderText(QString::fromLocal8Bit("密保答案"));//设置密码提示
    ui->res_answerLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                                      "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->res_answerLine->setMaxLength(20);//设置最大长度20位

    QHBoxLayout *res_layout = new QHBoxLayout();
    ui->registerConfirm->setCursor(QCursor(Qt::PointingHandCursor));
    ui->registerConfirm->setStyleSheet("QPushButton{border-radius:15px;}");//正方型按钮参数设置为一半即为圆
    res_layout->addStretch();
    res_layout->addWidget(ui->registerConfirm);
    res_layout->setContentsMargins(0,0,0,0);
    ui->res_answerLine->setLayout(res_layout);

    ui->comboBox->addItem("您的小学名称？");
    ui->comboBox->addItem("您最好的朋友的名称？");

    /*忘记密码按钮*/
    ui->res_loginButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->res_loginButton->setFlat(true);

    /*注册按钮*/
    ui->res_forgetButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->res_forgetButton->setFlat(true);
}
void HomePage::forgetPageInit()
{
    ui->for_accLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->for_accLine->setPlaceholderText(QString::fromLocal8Bit("您的密保答案"));//设置密码提示
    ui->for_accLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                                   "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->for_accLine->setMaxLength(20);//设置最大长度20位

    ui->for_pwdLine->setContextMenuPolicy(Qt::NoContextMenu);//设置无右键菜单
    ui->for_pwdLine->setPlaceholderText(QString::fromLocal8Bit("新密码"));//设置密码提示
    ui->for_pwdLine->setEchoMode(QLineEdit::Password);//设置密码隐藏
    ui->for_pwdLine->setStyleSheet("QLineEdit{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid gray;}"
                                   "QLineEdit:hover{border-width:1px;border-radius:4px;font-size:12px;color:black;border:1px solid rgb(70,200,50);}");
    ui->for_pwdLine->setMaxLength(20);//设置最大长度20位

    QHBoxLayout *res_layout = new QHBoxLayout();
    ui->forgetConfirm->setCursor(QCursor(Qt::PointingHandCursor));
    ui->forgetConfirm->setStyleSheet("QPushButton{border-radius:15px;}");//正方型按钮参数设置为一半即为圆
    res_layout->addStretch();
    res_layout->addWidget(ui->forgetConfirm);
    res_layout->setContentsMargins(0,0,0,0);
    ui->for_pwdLine->setLayout(res_layout);

    /*忘记密码按钮*/
    ui->for_loginButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->for_loginButton->setFlat(true);

    /*注册按钮*/
    ui->for_registerButton->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    ui->for_registerButton->setFlat(true);
}

QPushButton* HomePage::SearchButton(QLineEdit *edit)
{
    QPushButton *button = new QPushButton();
    QHBoxLayout *layout = new QHBoxLayout();
    button->setCursor(QCursor(Qt::PointingHandCursor));
    button->setStyleSheet("QPushButton{border-radius:15px;}");//正方型按钮参数设置为一半即为圆
    layout->addStretch();
    layout->addWidget(button);
    layout->setContentsMargins(0,0,0,0);
    edit->setLayout(layout);
    return button;
}

void HomePage::on_exitButton_clicked()
{
    qDebug() << "关闭" << endl;
    this->close();
}

void HomePage::on_minButton_clicked()
{
    this->showMinimized();
}

void HomePage::on_forgetButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void HomePage::on_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void HomePage::on_for_loginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomePage::on_for_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void HomePage::on_res_forgetButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void HomePage::on_res_loginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomePage::on_loginConfirm_clicked()
{
    if (ui->accLine->text() == nullptr) {
       QMessageBox::critical(this,tr("账号不能为空"),tr("请输入用户账号"),"ok",0);
    } else if (ui->pwdLine->text() == nullptr) {
        QMessageBox::critical(this,tr("密码不能为空"),tr("请输入用户密码"),"ok",0);
    } else {
        qDebug() <<"emit";
        emit loginToMainPage(ui->accLine->text(),ui->pwdLine->text());
    }
}

void HomePage::on_registerConfirm_clicked() {
    QString name = ui->res_accLine->text();
    QString passwd = ui->res_pwdLine->text();
    QString answer = ui->res_answerLine->text();
    if (name == nullptr) {
        QMessageBox::critical(this,tr("用户名不能为空"),tr("请输入用户名"),"ok",0);
    } else if (passwd == nullptr) {
        QMessageBox::critical(this,tr("密码不能为空"),tr("请输入用户密码"),"ok",0);
    } else if(answer == nullptr) {
        QMessageBox::critical(this,tr("密保答案不能为空"),tr("请输入用户答案"),"ok",0);
    } else {
        qDebug() << "emit register";
        emit registerToMainPage(name, passwd, ui->comboBox->currentIndex(), answer);
    }
}

void HomePage::registerBackMsgHandler(bool backMsg, QString userId)
{
    qDebug() << "注册返回处理"<< endl;
    ui->res_accLine->clear();
    ui->res_pwdLine->clear();
    ui->res_answerLine->clear();
    ui->comboBox->setCurrentIndex(0);
    if(backMsg){
        QMessageBox::information(this,tr("用户注册成功"),tr("您的账号是:")+userId,QMessageBox::Ok);
    } else {
        QMessageBox::critical(this,tr("用户注册失败"),tr("请稍后再试！"),QMessageBox::Ok);
    }
}

void HomePage::loginBackMsgHandler(int type)
{
    qDebug() << "登陆";
    switch (type) {
    case LOGIN_BACK_SUCCESS:
        /*登陆成功*/
        QMessageBox::information(this,tr("登陆成功"), tr("登陆成功!"), QMessageBox::Ok);
        break;
    case LOGIN_BACK_ISONLINE:
        /*用户在线*/
        QMessageBox::critical(this, tr("登陆失败"), tr("用户已在线，请不要重复登陆!"), QMessageBox::Ok);
        break;
    case LOGIN_BACK_EMPTY:
        /*用户不存在*/
        QMessageBox::critical(this, tr("登陆失败"), tr("用户不存在，请输入正确的用户名或密码!"), QMessageBox::Ok);
        break;
    }
}
