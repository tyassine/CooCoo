
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

Entier::Entier(const Reel* aReel)
{
    // Perte d'information
    valeur = static_cast<int>(aReel->getValeur());
}

Entier::Entier(const Rationnel* aRationnel)
{
    // Perte d'information
    double num = static_cast<double>(aRationnel->getNum());
    double denom = static_cast<double>(aRationnel->getDenom());
    double nombre = num/denom;
    // Ex : pour convertir 70/8 en entier, on fait 70/8 ==> 8,75 ==> 8
    valeur = static_cast<int>(nombre);
}
