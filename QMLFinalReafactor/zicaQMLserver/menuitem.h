#ifndef MENUITEM_H
#define MENUITEM_H
#include <QString>

class menuItem
{
public:
    menuItem(const int& id,const QString& name, const double& price);
    virtual QString getName() const;
    double getPrice() const;
    int getId() const;
    virtual QString toString() const{}

    QString getType() const;

protected:
    int id;
    QString name;
    double price;
    QString type;
};

#endif // MENUITEM_H
