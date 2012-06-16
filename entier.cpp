#include "entier.h"
#include <sstream>

#include "reel.h"
#include "rationnel.h"

QString Entier::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}

Entier::Entier(Reel* aReel)
{
    // Perte d'information
    valeur = static_cast<int>(aReel->getValeur());
}

Entier::Entier(Rationnel* aRationnel)
{
    // Perte d'information
    double num = static_cast<double>(aRationnel->getNum());
    double denum = static_cast<double>(aRationnel->getDenum());
    double nombre = num/denum;
    // Ex : pour convertir 70/8 en entier, on fait 70/8 ==> 8,75 ==> 8
    valeur = static_cast<int>(nombre);
}


