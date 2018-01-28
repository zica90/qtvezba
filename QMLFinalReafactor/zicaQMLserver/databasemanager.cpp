#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
   DB = QSqlDatabase::addDatabase("QSQLITE");
   DB.setDatabaseName("C:/Users/nikolaz/Desktop/QML/baza.db");

   if (!DB.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

bool DatabaseManager::insertFood(const QString &id, const QString &name, const QString &price)
{
    QSqlQuery query;

    query.prepare("INSERT INTO food (id,name,price) VALUES (:id,:name,:price)");
    query.bindValue(":id", id.toInt());
    query.bindValue(":name", name);
    query.bindValue(":price", price.toDouble());
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DatabaseManager::getFood(QMap<int, Food> &menu)
{
    QSqlQuery query("SELECT * FROM food");
    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idPrice = query.record().indexOf("price");
    while (query.next())
    {
       int id = query.value(idId).toInt();
       QString name = query.value(idName).toString();
       double price = query.value(idPrice).toDouble();
       menu[id] = Food(id,name,price);
    }
}
