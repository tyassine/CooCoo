#ifndef FABRIQUEDONNEE_H
#define FABRIQUEDONNEE_H

/*!
* \file fabriquedonne.h
* \author Letellier/Yassine
*/

#include "complexe.h"
#include "rationnel.h"
#include "reel.h"
#include "exceptionCooCoo.h"
#include <QString>

// Implémentation du design pattern factory

// 1 seule factory ==> utiliser un singleton, pour faire 1 unique instance qui fait tout?
// Ou la mettre en statique, et en faire une sorte d'agglomérat de méthodes?

class FabriqueDonnee
{
public:

    static Donnee* creerDonnee(const QString& typeDonnee, const QString& valeur);

};


#endif // FABRIQUEDONNEE_H
