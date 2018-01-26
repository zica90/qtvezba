#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QScopedPointer>
#include <QString>
#include <QByteArray>
#include <databasemanager.h>
#include <QSharedPointer>
#include <food.h>
#include <QMap>
#include <factoryracun.h>

class BackEnd:public QObject
{
    Q_OBJECT
public:
    explicit BackEnd(QObject *parent=0);
    Q_INVOKABLE void startServer();
    Q_INVOKABLE void sendBill();
    void setSendButton(QObject* qmlObject);
    QSharedPointer<DatabaseManager> getDBManager() const;
    void showBill(const QString& str);


signals:
    void billRecieved();
public slots:
    void newConnection();
    void readData();
    void setVisibility();


private:
    QScopedPointer<QTcpServer> server;
    QScopedPointer<QTcpSocket> socket;
    QSharedPointer<DatabaseManager> DBManager;
    QMap<int, Food> menu;
    QScopedPointer<Racun> bill;
    QObject *obj;
};

#endif // BACKEND_H
