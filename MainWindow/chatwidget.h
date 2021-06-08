#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "scrollareamodel.h"
#include "User/user.h"
#include <QTextEdit>
#include "chatlabel.h"

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
    QWidget *recordWidget;
    QTextEdit *edit;
    QString userName;
    void showRecord();
    QVBoxLayout *chatLabelLayout;
    bool isStreath;
    void msgHandler(QString msg, int id);
signals:
    void sendMsg(QString msg, int id);
private:
    Ui::chatWidget *ui;
};

#endif // CHATWIDGET_H
