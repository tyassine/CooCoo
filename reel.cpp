
#include "reel.h"
#include <sstream>

#include "entier.h"
#include "rationnel.h"
#include "fabriquedonnee.h"

QString Reel::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}

Reel::Reel(const Entier* aEntier)
{
    valeur = static_cast<double>(aEntier->getValeur());
}

Reel::Reel(const Rationnel* aRationnel)
{
    // Perte d'information
    double num = static_cast<double>(aRationnel->getNum());
    double denom = static_cast<double>(aRationnel->getDenom());
    valeur = num/denom;
}

Reel::Reel(const Complexe* aComplexe)
{
    // Perte d'information
    Constante* tmp = aComplexe->getPRe();
    // Besoin de l'instance factory... Du coup include sale, mais bon.
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    Reel* tmp2 = static_cast<Reel*>(factory->creerDonnee(tmp, "Reel"));
    // static_cast pour permettre la conversion Donnee* ==> Reel*
    // On est surs que ça sera un Reel*, puisqu'on le demande spécifiquement!
    valeur = tmp2->getValeur();
    delete tmp;
    delete tmp2;
}
