#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item
{
public:
    Item(int ID=0, int quantaty=0);

    int getID() const;
    int getQuantaty() const;
    QString toString() const;

private:
    int ID;
    int quantaty;
};

#endif // ITEM_H
