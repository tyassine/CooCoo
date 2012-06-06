#ifndef RATIONNEL_H
#define RATIONNEL_H

/*!
* \file rationnel.h
* \author Letellier/Yassine
*/

#include "entier.h"

class Rationnel : public Constante
{
    // Pas forcément nécessaire, on pourrait mettre des entiers tout simple... Mais ça serait moins stylé sur l'UML ^^
    Entier ent1;
    Entier ent2;
public:
    // Rationnel : plutôt le construire avec une QString!
    // Le seul intérêt de stocker sous valeur numérique est pour faire les calculs.
    // Tout le reste, les entrées, les sorties, c'est du QString!
    Rationnel(const QString& aQString = "0/1");
    virtual QString toQString() const;

};

#endif // RATIONNEL_H
