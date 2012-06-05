#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "entier.h"

class Rationnel : public Constante
{
    Entier ent1;
    Entier ent2;
public:
    Rationnel(const Entier& aEntier1, const Entier& aEntier2) : ent1(aEntier1), ent2(aEntier2){}
    virtual const string afficher() const;

};

#endif // RATIONNEL_H
