#include "rationnel.h"
#include <sstream>


QString Rationnel::toQString() const
{
    QString res = num.toQString() + "/" + denum.toQString();
    return res;
}
