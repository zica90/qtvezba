#include "item.h"

Item::Item(const int id, const int quant)
{
    this->id=id;
    this->quant=quant;

}

int Item::getId() const
{
    return id;
}

int Item::getQuant() const
{
    return quant;
}

void Item::incrementQ()
{
    quant++;
}

void Item::setQuant(int value)
{
    quant = value;
}

QString Item::toString() const
{
    return QString::number(id)+";"+QString::number(quant);
}
