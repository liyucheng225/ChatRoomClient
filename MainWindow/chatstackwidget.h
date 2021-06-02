#ifndef CHATSTACKWIDGET_H
#define CHATSTACKWIDGET_H

#include <QWidget>
#include <QStackedWidget>
class ChatStackWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit ChatStackWidget(QWidget *parent = nullptr);

signals:

};

#endif // CHATSTACKWIDGET_H
