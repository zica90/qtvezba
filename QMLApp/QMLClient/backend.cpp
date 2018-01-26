#include "backend.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
BackEnd::BackEnd(QObject *parent):QObject(parent)
{

}

void BackEnd::connectToServer()
{
    socket.reset(new QTcpSocket(this));
    connect( socket.data(), SIGNAL(readyRead()), SLOT(readData()));
    socket->connectToHost("127.0.0.1", 1234);
}

QString BackEnd::getName()
{
    QString data;
    for(auto a:menu)
        data+=a.toString()+"|";
    return data;
}

void BackEnd::addItemToBasket(const QString& str)
{
    int id=str.toInt();
    if(basket.count(id)){
        basket[id].incrementQ();
    }
    else
    {
       basket[id]=Item(id,1);
    }

    qDebug()<<basket[id].getQuant();
}

void BackEnd::sendData(const QString& str)
{
    QString data;
    int i=0;

    QJsonObject json;
    json["type"]=1;
    json["objects"]=basket.size();
    json["pay"]=str;
    for(auto a:basket)
    {
         json[QString::number(i++)]=a.toString();
    }
    socket->write(QJsonDocument(json).toBinaryData());
}
void BackEnd::setSendButton(QObject* qmlObject)

{
    obj=qmlObject;
 //   connect(this,SIGNAL(billRecieved()),this,SLOT(setVisibility()));
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
           menu[list.at(0).toInt()]=Food(list.at(0).toInt(),list.at(1),list.at(2).toDouble(),"1");
           qDebug()<<menu.last().toString();
        }
        break;
    case 2:
        QMetaObject::invokeMethod(obj->findChild<QObject*>("listModelBasket"), "showBill",Q_ARG(QVariant, jo["data"].toString()));
        basket.clear();
        menu.clear();

        break;
    default:
        qDebug()<<"xxx";
        break;
    }
}
