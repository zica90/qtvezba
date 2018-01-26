#ifndef BACKEND_H
#define BACKEND_H
#include <QObject>
#include <QTcpSocket>
#include <QScopedPointer>
#include <QString>
#include <QByteArray>
#include <food.h>
#include <QMap>
#include <QDebug>
#include <item.h>

class BackEnd:public QObject
{
    Q_OBJECT
public:
    explicit BackEnd(QObject *parent=0);
    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE QString getName();
    Q_INVOKABLE void addItemToBasket(const QString& str);
    Q_INVOKABLE void sendData(const QString& str);
    void setSendButton(QObject* qmlObject);
signals:
    void nekiSignal();

private slots:
    void readData();
private:
    QScopedPointer<QTcpSocket> socket;
    QMap<int,Food> menu;
    QMap<int,Item> basket;
    QObject *obj;
};

#endif // BACKEND_H
