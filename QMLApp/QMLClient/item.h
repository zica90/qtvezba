#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item
{
public:
    Item(const int id=0, const int quant=0);

    int getId() const;
    int getQuant() const;
    void incrementQ();
    void setQuant(int value);
    QString toString() const;

private:
    int id;
    int quant;
};

#endif // ITEM_H
