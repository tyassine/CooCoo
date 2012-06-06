#include "entier.h"
#include <sstream>

QString Entier::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}
