#ifndef FOOD_H
#define FOOD_H
#include <QString>
#include <menuitem.h>

class Food:public menuItem
{
public:
    Food(const int& id=0,const QString& name="", const double& price=0.0);

    QString toString() const;
    QString getName() const;
};

#endif // FOOD_H
