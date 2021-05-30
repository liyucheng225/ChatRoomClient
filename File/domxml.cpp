#include "domxml.h"

DomXml::DomXml() {

}

void DomXml::createXML(QString filePath)
{
    QFile file(filePath);
    if (file.exists()) {
        qDebug() << "文件以存在!";
        return;
    } else {
        //文件不存在
        bool isOk = file.open(QIODevice::WriteOnly);
        if (isOk) {
            QDomDocument doc; //创建xml文件
            QDomProcessingInstruction ins;
            ins = doc.createProcessingInstruction("xml", "version=\'1.0\' encoding=\'utf-8\'");
            //根节点元素
            QDomElement root = doc.createElement("用户");
            //保存
            QTextStream stream(&file);
            doc.save(stream, 4);
            file.close();
        }
    }
}
