#ifndef BASKETITEMS_H
#define BASKETITEMS_H
#include <QString>
class BasketItems
{
public:
    BasketItems(const int& id=0);
    int getId() const;

    int getQuant() const;
    void setQuant(int value);
    void incrementQuant();
    QString toString() const;


private:
    int id;
    int quant;
};

#endif // BASKETITEMS_H
