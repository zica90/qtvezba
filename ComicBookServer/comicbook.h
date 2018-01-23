#ifndef COMICBOOK_H
#define COMICBOOK_H
#include <QString>

class ComicBook
{
public:
    ComicBook(int id=0,QString name="",qreal price=0.0,int stock=0);

    QString getName() const;
    qreal getPrice() const;
    int getStock() const;
    int getId() const;
    QString toString() const;

    void setStock(int value);

private:
    QString name;
    qreal price;
    int stock;
    int id;
};

#endif // COMICBOOK_H
