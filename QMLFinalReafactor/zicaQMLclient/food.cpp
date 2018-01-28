#include "food.h"

Food::Food(const int& id,const QString& name, const double& price)
{
    this->id=id;
    this->name=name;
    this->price=price;
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


QString Food::toString() const
{
    return QString::number(id)+";"+name+";"+QString::number(price,'d',2);
}
