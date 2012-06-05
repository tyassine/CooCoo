#ifndef PILE_H
#define PILE_H

#include "donnee.h"

// Design pattern Singleton

// Je préfère faire ma propre pile plutôt que de réutiliser QStack, ça évite de lire la doc et de prendre connaissance de la tonne d'attributs et méthodes... Et ça fait réviser les piles :p
// Et c'est plus sûr pour le Singleton

class Pile
{
    static Pile* instance;
    unsigned int sommet;
    unsigned int nbMax;
    Donnee** tab;

    // Constructeurs et destructeur en private pour interdire leur utilisation
    Pile(unsigned int n) : sommet(-1), nbMax(n), tab(new Donnee*[n]) {}
    Pile(const Pile&);
    void operator=(const Pile&);
    //~Pile()
    // Il faut depiler et empiler comme methodes

public:

};

#endif // PILE_H
