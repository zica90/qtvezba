#include "factoryracun.h"
#include <euri.h>
#include <dinari.h>
factoryRacun::factoryRacun()
{

}

Racun*  factoryRacun::getRacun(const QString &str)
{
    if(str=="EU")
    {
        return new Euri();
    }

        return new Dinari();


}
