#include "chatwidget.h"
#include "ui_chatwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
chatWidget::chatWidget(User user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatWidget)
{
    this->user = user;
    ui->setupUi(this);
    QVBoxLayout *chat = new QVBoxLayout(this);
    chat->setSpacing(0);
    this->setStyleSheet("QWidget{background:rgb(245,246,247)}");

    //上层窗口
    QWidget *topWidget = new QWidget(this);
    topWidget->setFixedHeight(50);
    topWidget->setStyleSheet("QWidget{border:1px solid rgb(224,224,224)}");

    //上层窗口布局
    QHBoxLayout *topLayout = new QHBoxLayout(this);
    topLayout->setSpacing(0);
    topLayout->setMargin(10);


    //上层窗口设置按钮
    QPushButton *name = new QPushButton(QString::fromStdString(user.getUserName()),topWidget);
    name->setFixedSize(100,30);
    QPushButton *setting = new QPushButton(topWidget);
    name->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}"
                        "QPushButton:hover {color: rgba(8,60,255)}");
    setting->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    setting->setIcon(QIcon(":/new/prefix1/image/设置.png"));
    setting->setFixedSize(20,20);
    topLayout->addWidget(name);
    topLayout->addStretch();
    topLayout->addWidget(setting);

    topWidget->setLayout(topLayout);

    chat->addWidget(topWidget);
    chat->setContentsMargins(0,0,0,0);


    ScrollAreaModel *scrollAreaModel = new ScrollAreaModel(this);
    scrollAreaModel->setWidgetResizable(true);
    QWidget *recordWidget = new QWidget(scrollAreaModel);
//    friendScrollAreaWidgetContents->setMinimumSize(QSize(268,489));
    recordWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    recordWidget->setContentsMargins(0,0,0,0);
//    recordWidget->setStyleSheet("QWidget{border:1px solid rgb(224,224,224)}");
    recordWidget->setMinimumSize(this->width() - 15,this->height() - 305);
    qDebug() << "sc" << recordWidget->size();
    qDebug() << "re" << scrollAreaModel->size();
    //创建好友列表展示窗口布局
//    scrollAreaModel->setStyleSheet("QScrollArea{border:1px solid rgb(244,244,244)}");

    scrollAreaModel->setWidget(recordWidget);
    chat->addWidget(scrollAreaModel);

    QWidget *editWidget = new QWidget(this);
    editWidget->setStyleSheet("QWidget{border:1px solid rgb(224,224,224)}");
    editWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    editWidget->setFixedHeight(250);

    QWidget *editControlWidget = new QWidget(editWidget);
//    editControlWidget->setStyleSheet("QWidget{border:0px solid rgb(224,224,224)}");
    editControlWidget->setFixedHeight(50);
    QPushButton *record = new QPushButton(editControlWidget);
    record->setIcon(QIcon(":/new/prefix1/image/line-chat history（聊天历史）.png"));
    record->setStyleSheet("QPushButton{border: 1px solid rgba(0,0,0,0);background: rbga(0,0,0,0);}");
    record->setFixedSize(30,30);
    QHBoxLayout  *controlLayout = new QHBoxLayout(editControlWidget);
    controlLayout->setSpacing(0);
    controlLayout->setMargin(10);
    controlLayout->addStretch();
    controlLayout->addWidget(record);
    editControlWidget->setLayout(controlLayout);

    QTextEdit *edit = new  QTextEdit(editWidget);
    edit->setStyleSheet("QTextEdit{border:0px solid rgb(224,224,224)}");
    edit->setFixedHeight(150);
    edit->setText(userName);


    QWidget *confrimWidget = new QWidget(editWidget);
//    confrimWidget->setStyleSheet("QWidget{border:0px solid rgb(224,224,224)}");
    confrimWidget->setFixedHeight(50);
    QHBoxLayout *confrimLayout = new QHBoxLayout(confrimWidget);
    confrimLayout->addStretch();
    QPushButton *confirm = new QPushButton("发送", confrimWidget);
    connect(confirm, &QPushButton::clicked, this, [=]() {
        QString msg = edit->toPlainText();
        qDebug() << "发送消息" << msg << userName;
        emit sendMsg(msg,this->id);
        edit->clear();
    });
    confrimLayout->addWidget(confirm);
    confrimLayout->setMargin(10);
    confirm->setFixedSize(70,30);
//    "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
    confirm-> setStyleSheet(
                //正常状态样式
                "QPushButton{"
                "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
                "border-style:outset;"                  //边框样式（inset/outset）
                "border-width:4px;"                     //边框宽度像素
                "border-radius:10px;"                   //边框圆角半径像素
                "border-color:rgba(255,255,255,30);"    //边框颜色
                "font:bold 10px;"                       //字体，字体大小
                "color:rgba(0,0,0,100);"                //字体颜色
                "padding:6px;"                          //填衬
                "}"
                //鼠标按下样式
                "QPushButton:pressed{"
                "background-color:rgba(100,255,100,200);"
                "border-color:rgba(255,255,255,30);"
                "border-style:inset;"
                "color:rgba(0,0,0,100);"
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:rgba(100,255,100,100);"
                "border-color:rgba(255,255,255,200);"
                "color:rgba(0,0,0,200);"
                "}");

    QVBoxLayout *editLayout = new QVBoxLayout(editWidget);
    editLayout->setSpacing(0);
    editLayout->setMargin(0);
    editLayout->addWidget(editControlWidget);
    editLayout->addWidget(edit);
    editLayout->addWidget(confrimWidget);
    editWidget->setLayout(editLayout);


    chat->addWidget(editWidget);
    this->setLayout(chat);

}

chatWidget::~chatWidget()
{
    delete ui;
}
