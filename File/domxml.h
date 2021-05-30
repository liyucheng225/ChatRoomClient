#ifndef DOMXML_H
#define DOMXML_H
#include <QString>
#include <QDomComment> //文件
#include <QDomProcessingInstruction> //格式头部
#include <QDomElement>
#include <QDebug>
#include <QFile>
class DomXml
{
public:
    DomXml();
    static void createXML(QString fileName);
};

#endif // DOMXML_H
