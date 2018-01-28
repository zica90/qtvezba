#include "basketitems.h"

BasketItems::BasketItems(const int &id)
{
    this->id=id;
    this->quant=1;
}

int BasketItems::getId() const
{
    return id;
}

int BasketItems::getQuant() const
{
    return quant;
}

void BasketItems::setQuant(int value)
{
    quant = value;
}

void BasketItems::incrementQuant()
{
    quant++;
}
QString BasketItems::toString() const
{
    return QString::number(id)+";"+QString::number(quant);
}

