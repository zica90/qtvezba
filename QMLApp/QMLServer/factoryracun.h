#ifndef FACTORYRACUN_H
#define FACTORYRACUN_H
#include <racun.h>
#include <QString>
#include <QScopedPointer>

class factoryRacun
{
public:
    factoryRacun();
    Racun* getRacun(const QString& str);
};

#endif // FACTORYRACUN_H
