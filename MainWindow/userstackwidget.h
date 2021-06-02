#ifndef USERSTACKWIDGET_H
#define USERSTACKWIDGET_H

#include <QWidget>
#include <QStackedWidget>
class UserStackWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit UserStackWidget(QWidget *parent = nullptr);

signals:

};

#endif // USERSTACKWIDGET_H
