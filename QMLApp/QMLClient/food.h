#ifndef FOOD_H
#define FOOD_H
#include <QString>

class Food
{
public:
    Food(const int& id=0,const QString& name="", const double& price=0.0, const QString& type="");

    QString getName() const;
    double getPrice() const;
    int getId() const;
    QString getType() const;
    QString toString() const;

private:
    int id;
    QString name;
    double price;
    QString type;
};

#endif // FOOD_H
