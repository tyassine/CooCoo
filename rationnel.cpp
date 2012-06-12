#include "rationnel.h"
#include <sstream>

Rationnel::Rationnel(const QString& aNum,const QString& aDenum)
{

    num = Entier(aNum);
    denum = Entier(aDenum);
}


QString Rationnel::toQString() const
{
    QString res = ent1.toQString() + "/" + ent2.toQString();
    return res;
}
