#include "menuitem.h"

menuItem::menuItem(const int &id, const QString &name, const double &price)
{
    this->id=id;
    this->name=name;
    this->price=price;
}

QString menuItem::getName() const
{
    return name;
}

double menuItem::getPrice() const
{
    return price;
}

int menuItem::getId() const
{
    return id;
}

QString menuItem::getType() const
{
    return type;
}
