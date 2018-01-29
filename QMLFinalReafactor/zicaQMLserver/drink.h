#ifndef DRINK_H
#define DRINK_H
#include <menuitem.h>

class Drink:public menuItem
{
public:
    Drink(const int& id=0,const QString& name="", const double& price=0.0,const double& size=0.0);
    double getSize() const;
    QString toString() const;
    QString getName() const;

private:
    double size;
};

#endif // DRINK_H
