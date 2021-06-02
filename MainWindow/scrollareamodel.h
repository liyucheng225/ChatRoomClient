#ifndef SCROLLAREAMODEL_H
#define SCROLLAREAMODEL_H

#include <QWidget>
#include <QScrollArea>
#include <QDebug>
#include <QVBoxLayout>
class ScrollAreaModel : public QScrollArea
{
    Q_OBJECT
public:
    explicit ScrollAreaModel(QWidget *parent = nullptr);
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *friendLayout;
signals:

};

#endif // SCROLLAREAMODEL_H
