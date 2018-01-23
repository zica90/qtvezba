#include "comicbook.h"
#include <mainwindow.h>
#include <QInputDialog>
extern QScopedPointer<MainWindow> w;
ComicBook::ComicBook(int id,QString name,double price,int stock, QWidget *parent):QLabel(parent)
{
    this->id=id;
    this->name=name;
    this->price=price;
    this->stock=stock;
    setText(name+" price: "+QString::number(price, 'f', 2));
}
void ComicBook::mousePressEvent(QMouseEvent *event)
{
    int x=QInputDialog::getInt(this,"quantity","How much og this article you want to buy?",1,1,stock);
    w->addToBasket(id,x);


}

void ComicBook::setStock(int value)
{
    stock = value;
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
