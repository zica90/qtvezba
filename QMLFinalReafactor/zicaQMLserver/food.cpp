#include "food.h"

Food::Food(const int& id,const QString& name, const double& price):menuItem(id,name,price)
{
    this->type="food";
}

QString Food::getName() const
{
    return name;
}

QString Food::toString() const
{
    return QString::number(id)+";"+name+";"+QString::number(price,'d',2);
}
