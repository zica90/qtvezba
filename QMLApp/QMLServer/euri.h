#ifndef EURI_H
#define EURI_H
#include <racun.h>

class Euri:public Racun
{
public:
    Euri();
    void getFinal(const QJsonObject& jo,const QMap<int, Food>& menu);
};

#endif // EURI_H
