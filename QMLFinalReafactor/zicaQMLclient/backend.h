#ifndef BACKEND_H
#define BACKEND_H
#include <QTcpSocket>
#include <QObject>
#include <QScopedPointer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include "food.h"
#include <basketitems.h>
#include <QSharedPointer>
#include <QWeakPointer>

class BackEnd:public QObject
{
    Q_OBJECT
public:
    BackEnd(QObject *parent=0);
    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE void addToBasket(const QString& str);
    Q_INVOKABLE void sendData(const QString& str);
    void setQObject(QSharedPointer<QObject> qmlObject);
    ~BackEnd();

public slots:
    void readData();
private:
    QScopedPointer<QTcpSocket> socket;
    QMap<int, Food> menuList;
    QMap<int, BasketItems> Basket;
    QSharedPointer<QObject> qmlObject;
};

#endif // BACKEND_H
