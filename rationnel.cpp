#include "rationnel.h"
#include <sstream>

Rationnel::Rationnel(const QString& aQString)
{
    // En attendant de trouver comment parser, je mets des valeurs factices pour pouvoir compiler
    ent1 = Entier("0");
    ent2 = Entier("1");
}




QString Rationnel::toQString() const
{
    QString res = ent1.toQString() + "/" + ent2.toQString();
    return res;
}
