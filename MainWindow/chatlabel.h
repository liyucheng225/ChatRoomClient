#ifndef CHATLABEL_H
#define CHATLABEL_H

#include <QWidget>
#include <QPushButton>
class chatLabel : public QWidget
{
    Q_OBJECT
public:
    explicit chatLabel(QString msg ,bool flags = true, QWidget *parent = nullptr);

signals:

};

#endif // CHATLABEL_H
