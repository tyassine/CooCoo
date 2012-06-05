#include "reel.h"
#include <sstream>

QString Reel::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}
