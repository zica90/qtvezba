#include "euri.h"

Euri::Euri()
{

}

void Euri::getFinal(const QJsonObject &jo, const QMap<int, Food> &menu)
{

    QString str="name\tquan.\tprice\n";
    str+="-----------------------------------------\n";
    int id;
    double price=0;
    for(int i=0;i<jo["objects"].toInt();i++)
    {
       QStringList list=jo[QString::number(i)].toString().split(';');
       id=list.at(0).toInt();
       str+=menu[id].getName()+"\t"+list.at(1)+"\t"+QString::number(menu[id].getPrice()/120,'d',2)+"\n";
       price+=(menu[id].getPrice()/120*list.at(1).toInt());
    }
    str+="-----------------------------------------\n";
    str+="total:\t\t"+QString::number(price/120,'d',2);

    setData(str);


}
