
#include "entier.h"
#include <sstream>

#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "fabriquedonnee.h"

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

Entier::Entier(const Complexe* aComplexe)
{
    // Perte d'information
    Constante* tmp = aComplexe->getPRe();
    // Besoin de l'instance factory... Du coup include sale, mais bon.
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    Entier* tmp2 = static_cast<Entier*>(factory->creerDonnee(tmp, "Entier"));
    // static_cast pour permettre la conversion Donnee* ==> Entier*
    // On est surs que ça sera un Entier*, puisqu'on le demande spécifiquement!
    valeur = tmp2->getValeur();
    delete tmp;
    delete tmp2;
}

Donnee* Entier::operator+(Donnee& t)
{
    /*
    if (dynamic_cast<Entier&>(t))
    {

    }
    if (dynamic_cast<Reel&>(t))
    {

    }
    if (dynamic_cast<Reel&>(t))
    {

    }
    if (dynamic_cast<Complexe&>(t))
    {

    }*/
}

