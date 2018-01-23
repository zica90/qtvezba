#ifndef COMICBOOK_H
#define COMICBOOK_H
#include <QString>
#include <QLabel>
#include <QMouseEvent>
class ComicBook:public QLabel
{
public:
    ComicBook(int id=0,QString name="",double price=0.0,int stock=0, QWidget *parent=0);


    QString getName() const;
    qreal getPrice() const;
    int getStock() const;
    int getId() const;

    void mousePressEvent(QMouseEvent *event);

    void setStock(int value);

private:
    QString name;
    qreal price;
    int stock;
    int id;
};

#endif // COMICBOOK_H
