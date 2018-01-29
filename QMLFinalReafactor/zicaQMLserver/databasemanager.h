#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMap>
#include <food.h>
#include <QObject>
#include <QDebug>
#include <QSharedPointer>

class DatabaseManager
{
public:
    DatabaseManager();
    Q_INVOKABLE bool insertFood(const QString &id,const QString &name,const QString &price);
    bool getFood(QMap<int, QSharedPointer<menuItem>>& maps);
    bool getDrinks(QMap<int, QSharedPointer<menuItem>>& maps);
private:
    QSqlDatabase DB;
};

#endif // DATABASEMANAGER_H
