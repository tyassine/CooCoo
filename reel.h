#ifndef REEL_H
#define REEL_H

#include "constante.h"

class Reel : public Constante
{
    float valeur;
public:
    Reel(const float aReel) : valeur(aReel) {}
    virtual const string afficher() const;
};

#endif // REEL_H
