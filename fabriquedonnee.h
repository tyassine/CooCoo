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

    /*
    Deuxième fonction... Y'a peut etre mieux?:
    - récupère la valeur sous forme de string (pas le choix, car on ne connait pas son type à l'avance!)
         ===> ex rationnel : impossible à passer autrement qu'en string ?!
    - récupère l'entier décrivant le type final (correspondance liste déroulante)
        0 ==> entier
        1 ==> rationnel
        2 ==> réel
    - récupère un booléen précisant si l'on est en complexe ou non
    - détecte le type via les fonctions isEntier, isReel... comme dans la première fonction
    - le convertit vers le type désiré (encore un passage string ==> num ==> string?)
    - construit l'objet et le renvoie
    */

    static Donnee* creerDonnee(const QString& valeur, int typeFinal, bool complexeActive);

    // Méthodes de conversion, appelées dans creerDonnee et pourquoi pas ailleurs, plus tard...

    static double int2double(int x);


};


#endif // FABRIQUEDONNEE_H
