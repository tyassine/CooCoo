#ifndef ENTIER_H
#define ENTIER_H

#include "constante.h"

class Entier : public Constante
{
    int valeur;
public:
    Entier(int aInt) : valeur(aInt) {}
    virtual const string afficher() const;
};

#endif // ENTIER_H
