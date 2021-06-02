#ifndef CHATLABEL_H
#define CHATLABEL_H

#include <QWidget>
#include <QLabel>
class ChatLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ChatLabel(QWidget *parent = nullptr);

signals:

};

#endif // CHATLABEL_H
