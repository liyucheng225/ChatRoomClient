#ifndef PUSHBUTTONMODEL_H
#define PUSHBUTTONMODEL_H

#include <QWidget>
#include <QPushButton>
class PushButtonModel : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonModel(QWidget *parent = nullptr);
    int id;
signals:

};

#endif // PUSHBUTTONMODEL_H
