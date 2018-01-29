#include "backend.h"

BackEnd::BackEnd(QObject *parent):QObject(parent)
{
    DBManager.reset(new DatabaseManager());
    DBManager->getFood(menu);
    DBManager->getDrinks(menu);
}

BackEnd::~BackEnd()
{
    for(auto a:menu)
        delete a;
}

QSharedPointer<DatabaseManager> BackEnd::getDBManager() const
{
    return DBManager;
}

bool BackEnd::insertFoodinDB(const QString &id, const QString &name, const QString &price)
{
    return DBManager->insertFood(id,name,price);
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
    qDebug()<<"sendBill";
    socket->write(QJsonDocument(json).toBinaryData());
}

void BackEnd::setQObject(QSharedPointer<QObject> qmlObject)
{
    this->qmlObject=qmlObject;
}

void BackEnd::showBill(const QString &str)
{
    QMetaObject::invokeMethod(qmlObject->findChild<QObject*>("listModelBill"), "showBill",Q_ARG(QVariant, str));
}
void BackEnd::newConnection()
{
    int i=0;
    socket.reset(server->nextPendingConnection());
    connect(socket.data(), SIGNAL(readyRead()), this, SLOT(readData()));

    QJsonObject json;
    json["instraction"]=1;
    json["objects"]=menu.size();
    for(auto a:menu)
    {
         json[QString::number(i++)]=a->toString();
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
        showBill(bill->getData());
        qmlObject->findChild<QObject*>("buttonSendData")->setProperty("visible", true);
        break;
    default:

        break;
    }
}
