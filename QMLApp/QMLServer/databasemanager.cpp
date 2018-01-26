#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent):QObject(parent)
{
   DB = QSqlDatabase::addDatabase("QSQLITE");
   DB.setDatabaseName("C:/Users/nikolaz/Desktop/QMLApp/baza.db");

   if (!DB.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}


bool DatabaseManager::insertComicBook(const QString &id,const QString &name,const QString &price,const QString &stock)
{
    QSqlQuery query;

    query.prepare("INSERT INTO food (id,name,price,type) VALUES (:id,:name,:price,:stock)");
    query.bindValue(":id", id.toInt());
    query.bindValue(":name", name);
    query.bindValue(":price", price.toDouble());
    query.bindValue(":stock", stock.toInt());
    qDebug()<<"ss";
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DatabaseManager::getMenu(QMap<int, Food>& menu)
{
    QSqlQuery query("SELECT * FROM food");
    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idPrice = query.record().indexOf("price");
    int idType = query.record().indexOf("type");

    while (query.next())
    {
       int id = query.value(idId).toInt();
       QString name = query.value(idName).toString();
       double price = query.value(idPrice).toDouble();
       QString  type = query.value(idType).toString();
       menu[id] = Food(id,name,price,type);
    }
}
