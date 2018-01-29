#include "drink.h"

Drink::Drink(const int &id, const QString &name, const double &price, const double &size):menuItem(id,name,price)
{
   this->size=size;
   this->type="drink";
}

double Drink::getSize() const
{
    return size;
}

QString Drink::toString() const
{
    return QString::number(id)+";"+name+" "+QString::number(size,'d',2)+";"+QString::number(price,'d',2);
}

QString Drink::getName() const
{
    return name+" "+QString::number(size,'d',2);
}
