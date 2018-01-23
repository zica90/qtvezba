#include "myserver.h"
#include "comicbook.h"
#include <QMap>
#include <mainwindow.h>
extern QScopedPointer<MainWindow> w;
MyServer::MyServer(QObject *parent) :
    QObject(parent)
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

void MyServer::newConnection()
{

    QString data;
    socket.reset(server->nextPendingConnection());
    connect(socket.data(), SIGNAL(readyRead()), this, SLOT(readData()));
    for(auto a:w->getComics())
    {
        data+=a.toString();
    }
    data=data.left(data.size()-1);
    socket->write(data.toUtf8());
}

void MyServer::readData()
{
    QByteArray data = socket->readAll();
    QString stringData = QString::fromUtf8(data);
    w->processOrder(stringData);
}

void MyServer::orderProcessed(bool done)
{
    QString process;
    if(done)
        process="successful order";
    else
        process="error";

    socket->write(process.toUtf8());
}
