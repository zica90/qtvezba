#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMap>
#include <food.h>

class DatabaseManager:public QObject
{
    Q_OBJECT
public:
    DatabaseManager(QObject *parent=0);
    Q_INVOKABLE bool insertComicBook(const QString &id,const QString &name,const QString &price,const QString &stock);
    Q_INVOKABLE bool getMenu(QMap<int, Food>& menu);

  /*  bool getAllComics(QMap<int,ComicBook>& comics);
    bool upgradeDB(const ComicBook& cb);
    bool deleteCBfromDB(int id);*/
private:
    QSqlDatabase DB;
};

#endif // DATABASEMANAGER_H
