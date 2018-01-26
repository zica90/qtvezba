#include "food.h"

Food::Food(const int& id,const QString& name, const double& price, const QString& type)
{
    this->id=id;
    this->name=name;
    this->price=price;
    this->type=type;
}

QString Food::getName() const
{
    return name;
}

double Food::getPrice() const
{
    return price;
}

int Food::getId() const
{
    return id;
}

QString Food::getType() const
{
    return type;
}

QString Food::toString() const
{
    return QString::number(id)+";"+name+";"+QString::number(price,'d',2);
}
