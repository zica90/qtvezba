#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
   DB = QSqlDatabase::addDatabase("QSQLITE");
   DB.setDatabaseName("C:/Users/nikolaz/Desktop/ComicBookStoreFinal/CbSotre.db");

   if (!DB.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

bool DatabaseManager::insertComicBook(const ComicBook &cb)
{
    QSqlQuery query;


    query.prepare("INSERT INTO comics (id,name,price,stock) VALUES (:id,:name,:price,:stock)");
    query.bindValue(":id", cb.getId());
    query.bindValue(":name", cb.getName());
    query.bindValue(":price", cb.getPrice());
    query.bindValue(":stock", cb.getStock());

    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DatabaseManager::getAllComics(QMap<int, ComicBook> &comics)
{
    QSqlQuery query("SELECT * FROM comics");
    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idPrice = query.record().indexOf("price");
    int idStock = query.record().indexOf("stock");

    while (query.next())
    {
       int id = query.value(idId).toInt();
       QString name = query.value(idName).toString();
       double price = query.value(idPrice).toDouble();
       int  stock = query.value(idStock).toInt();
       comics[id] = ComicBook(id,name,price,stock);
    }
}

bool DatabaseManager::upgradeDB(const ComicBook &cb)
{
    QSqlQuery query;
    query.prepare("UPDATE comics SET stock=:stock WHERE id=:id");
    query.bindValue(":id", cb.getId());
    query.bindValue(":stock", cb.getStock());
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool DatabaseManager::deleteCBfromDB(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM comics WHERE id = (:id)");
    query.bindValue(":id", id);
    bool success = query.exec();
    return success;
}
