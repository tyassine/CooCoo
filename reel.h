#ifndef REEL_H
#define REEL_H

/*!
* \file reel.h
* \author Letellier/Yassine
*/

#include "constante.h"

class Reel : public Constante
{
    double valeur;
public:
    Reel(const QString& aQString = "0") : valeur(aQString.toDouble()) {}
    virtual QString toQString() const;
};

#endif // REEL_H
