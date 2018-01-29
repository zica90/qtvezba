#ifndef BACKEND_H
#define BACKEND_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>
#include <QScopedPointer>
#include <QSharedPointer>
#include <databasemanager.h>
#include <instruction.h>
#include <euri.h>
#include <dinari.h>
#include <factoryracun.h>
class BackEnd:public QObject
{
    Q_OBJECT
public:
    explicit BackEnd(QObject *parent=0);
    ~BackEnd();
    QSharedPointer<DatabaseManager> getDBManager() const;
    Q_INVOKABLE bool insertFoodinDB(const QString &id, const QString &name, const QString &price);
    Q_INVOKABLE void startServer();
    Q_INVOKABLE void sendBill();
    void setQObject(QSharedPointer<QObject> qmlObject);
    void showBill(const QString& str);


public slots:
    void newConnection();
    void readData();

private:

    QScopedPointer<QTcpServer> server;
    QScopedPointer<QTcpSocket> socket;
    QSharedPointer<DatabaseManager> DBManager;
    QSharedPointer<QObject> qmlObject;
    QScopedPointer<Racun> bill;

    QMap<int,QSharedPointer<menuItem>> menu;
};

#endif // BACKEND_H
