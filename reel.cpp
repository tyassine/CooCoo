#include "reel.h"
#include <sstream>

#include "entier.h"
#include "rationnel.h"

QString Reel::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}

Reel::Reel(Entier* aEntier)
{
    valeur = static_cast<double>(aEntier->getValeur());
}

Reel::Reel(Rationnel* aRationnel)
{
    // Perte d'information
    double num = static_cast<double>(aRationnel->getNum());
    double denum = static_cast<double>(aRationnel->getDenum());
    valeur = num/denum;
}
