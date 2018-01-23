#include "item.h"

Item::Item(int ID, int quantaty)
{
    this->ID=ID;
    this->quantaty=quantaty;
}

int Item::getID() const
{
    return ID;
}

int Item::getQuantaty() const
{
    return quantaty;
}
QString Item::toString() const
{
    return QString::number(ID)+";"+QString::number(quantaty);
}
