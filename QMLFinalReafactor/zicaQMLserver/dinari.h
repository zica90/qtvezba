#ifndef GOTOVINA_H
#define GOTOVINA_H
#include <QString>
#include <racun.h>
#include <QMap>
#include <QJsonObject>
#include "food.h"

class Dinari:public Racun
{
public:
    Dinari();
    void getFinal(const QJsonObject& jo,const QMap<int, Food>& menu);
};

#endif // GOTOVINA_H
