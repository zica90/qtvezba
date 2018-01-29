#include "backend.h"

BackEnd::BackEnd(QObject *parent):QObject(parent)
{
}
BackEnd::~BackEnd()
{
}
void BackEnd::connectToServer()
{
    socket.reset(new QTcpSocket(this));
    connect( socket.data(), SIGNAL(readyRead()), SLOT(readData()));
    socket->connectToHost("127.0.0.1", 1234);
}
void BackEnd::sendData(const QString& str)
{
    int i=0;

    QJsonObject json;
    json["type"]=1;
    json["objects"]=Basket.size();
    json["pay"]=str;
    for(auto a:Basket)
    {
         json[QString::number(i++)]=a.toString();
    }
    socket->write(QJsonDocument(json).toBinaryData());
}

void BackEnd::addToBasket(const QString &str)
{
    int id=str.toInt();
    if(Basket.count(id))
    {
        Basket[id].incrementQuant();
    }
    else
    {
        Basket[id]=BasketItems(id);
    }

}

void BackEnd::setQObject(QSharedPointer<QObject> qmlObject)
{
    this->qmlObject=qmlObject;
}

void BackEnd::readData()
{
    QByteArray data = socket->readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromBinaryData(data);
    QJsonObject jo=jsonDoc.object();

    switch (jo["instraction"].toInt()) {
    case 1:

        for(int i=0;i<jo["objects"].toInt();i++)
        {
           QStringList list=jo[QString::number(i)].toString().split(';');
           menuList[list.at(0).toInt()]=Food(list.at(0).toInt(),list.at(1),list.at(2).toDouble());
           QMetaObject::invokeMethod(qmlObject->findChild<QObject*>("listModelMenu"), "listModelAppend",Q_ARG(QVariant, menuList.last().toString()));
        }
        break;
    case 2:
        qDebug()<<"xxx";
        qDebug()<<jo["data"].toString();
          QMetaObject::invokeMethod(qmlObject->findChild<QObject*>("listModelBasket"), "showBill",Q_ARG(QVariant, jo["data"].toString()));
          Basket.clear();
          menuList.clear();
        break;
    default:
        break;
    }
}
