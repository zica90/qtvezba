#include "comicbook.h"
#include <QDebug>
ComicBook::ComicBook(int id,QString name,qreal price,int stock)
{
    this->id=id;
    this->name=name;
    this->price=price;
    this->stock=stock;
}

QString ComicBook::getName() const
{
    return name;
}

qreal ComicBook::getPrice() const
{
    return price;
}

int ComicBook::getStock() const
{
    return stock;
}

int ComicBook::getId() const
{
    return id;
}

QString ComicBook::toString() const
{
    return QString::number(id)+";"+name+";"+QString::number(price, 'f', 2)+";"+QString::number(stock)+"|";
}

void ComicBook::setStock(int value)
{
    this->stock += value;
    qDebug()<<stock;
}
