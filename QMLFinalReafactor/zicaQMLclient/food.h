#ifndef FOOD_H
#define FOOD_H
#include <QString>

class Food
{
public:
    Food(const int& id=0,const QString& name="", const double& price=0.0);

    QString getName() const;
    double getPrice() const;
    int getId() const;
    QString toString() const;

private:
    int id;
    QString name;
    double price;
};

#endif // FOOD_H
