#ifndef PUSHBUTTONMODEL_H
#define PUSHBUTTONMODEL_H

#include <QWidget>
#include <QPushButton>
class PushButtonModel : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonModel(QWidget *parent = nullptr);

signals:

};

#endif // PUSHBUTTONMODEL_H
