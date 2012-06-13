#ifndef FABRIQUEDONNEE_H
#define FABRIQUEDONNEE_H

/*!
* \file fabriquedonne.h
* \author Letellier/Yassine
*/

#include "complexe.h"
#include "rationnel.h"
#include "reel.h"
#include "constanteexp.h"
#include "exceptionCooCoo.h"
#include <QString>

// Implémentation d'un design pattern de type factory

// 1 seule factory ==> utiliser un singleton, pour faire 1 unique instance qui fait tout?
// Ou la mettre en statique, et en faire une sorte d'agglomérat de méthodes?

class FabriqueDonnee
{
public:

    /*
    Première fonction :
    - récupère un terme envoyé par le parser,
    - teste son type (méthodes statiques isEntier, isReel...)
    - construit l'objet correspondant et le renvoie
    */
    static Donnee* creerDonnee(const QString& terme);


    // Autres : VOIR ORGANISATION FEUILLE !


};


#endif // FABRIQUEDONNEE_H
