#ifndef RACUN_H
#define RACUN_H
#include <QString>
#include <food.h>
#include <QMap>
#include <QJsonObject>
#include <menuitem.h>
#include <QSharedPointer>

class Racun
{
public:
    Racun();
    virtual void getFinal(const QJsonObject& jo,const QMap<int, QSharedPointer<menuItem>>& menu){}
    QString getData() const;

    void setData(const QString &value);

protected:
    QString data;
};

#endif // RACUN_H
