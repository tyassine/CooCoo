#include "fabriquedonnee.h"
#include <QStringList>

// Initialisation du membre statique du singleton
FabriqueDonnee* FabriqueDonnee::instance = 0;

FabriqueDonnee* FabriqueDonnee::getInstance()
{
    if (!instance) instance = new FabriqueDonnee;
    return instance;
}

void FabriqueDonnee::libereInstance()
{
    if (instance) delete instance;
}

Donnee* FabriqueDonnee::creerDonnee(const QString& terme)
{

    if(Donnee::isComplexe(terme))
    {
        QStringList nombres = terme.split("$");
        // Static cast car on est SUR que l'on n'obtiendra jamais une ConstanteExp, et donc que le résultat sera toujours de type Constante!
        Constante* pRe = static_cast<Constante*>(creerDonnee(nombres[0]));
        Constante* pIm = static_cast<Constante*>(creerDonnee(nombres[1]));
        return new Complexe(pRe, pIm);
    }

    if(Donnee::isEntier(terme))
        return new Entier(terme);

    if(Donnee::isReel(terme))
        return new Reel(terme);

    if(Donnee::isRationnel(terme))
    {
        QStringList nombres = terme.split("/");
        return new Rationnel(nombres[0], nombres[1]);
    }

    if(Donnee::isExpression(terme))
        return new ConstanteExp(terme);
    else
        return NULL;
}




