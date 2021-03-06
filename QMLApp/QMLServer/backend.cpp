#include "backend.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <dinari.h>
#include <factoryracun.h>
#include <euri.h>
#include <racun.h>
BackEnd::BackEnd(QObject *parent):QObject(parent)
{
    DBManager.reset(new DatabaseManager());
    DBManager->getMenu(menu);


}

void BackEnd::startServer()
{
    server.reset(new QTcpServer(this));

    connect(server.data(), SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void BackEnd::sendBill()
{
     QJsonObject json;
    json["instraction"]=2;
    json["data"]=bill->getData();


    socket->write(QJsonDocument(json).toBinaryData());
}

void BackEnd::setSendButton(QObject* qmlObject)

{
    obj=qmlObject;
    connect(this,SIGNAL(billRecieved()),this,SLOT(setVisibility()));
}


QSharedPointer<DatabaseManager> BackEnd::getDBManager() const
{
    return DBManager;
}

void BackEnd::showBill(const QString &str)
{

    QObject *qmlObjectlist = obj->findChild<QObject*>("listModel");
    QMetaObject::invokeMethod(qmlObjectlist, "showBill",
                              //  Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, str));
}

void BackEnd::newConnection()
{
    QString data;
    int i=0;
    socket.reset(server->nextPendingConnection());
    connect(socket.data(), SIGNAL(readyRead()), this, SLOT(readData()));

    QJsonObject json;
    json["instraction"]=1;
    json["objects"]=menu.size();
    for(auto a:menu)
    {
         json[QString::number(i++)]=a.toString();
    }


    socket->write(QJsonDocument(json).toBinaryData());
}
void BackEnd::readData()
{
    QByteArray data = socket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromBinaryData(data);
    QJsonObject jo=jsonDoc.object();
    switch (jo["type"].toInt()) {
    case 1:
       bill.reset(std::move(factoryRacun().getRacun(jo["pay"].toString())));
       bill->getFinal(jo,menu);
       // qDebug()<<bill->getData();
        showBill(bill->getData());
        emit billRecieved();

        break;
    default:

        break;
    }
}

void BackEnd::setVisibility()
{
    obj->findChild<QObject*>("sendBill")->setProperty("visible", true);
}



