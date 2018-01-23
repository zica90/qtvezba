#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <comicbook.h>

class DatabaseManager
{
public:
    DatabaseManager();
    bool insertComicBook(const ComicBook& cb);
    bool getAllComics(QMap<int,ComicBook>& comics);
    bool upgradeDB(const ComicBook& cb);
    bool deleteCBfromDB(int id);
private:
    QSqlDatabase DB;
};

#endif // DATABASEMANAGER_H
