#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QScopedPointer>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
//    ~MyServer();
signals:

public slots:
    void newConnection();
    void readData();
    void orderProcessed(bool done);

private:
    QScopedPointer<QTcpServer> server;
    QScopedPointer<QTcpSocket> socket;

};

#endif // MYSERVER_H
