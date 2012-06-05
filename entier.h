#ifndef ENTIER_H
#define ENTIER_H

#include "constante.h"

class Entier : public Constante
{
    int valeur;
public:
    Entier(const QString& aQString ="0") : valeur(aQString.toInt()) {}
    virtual QString toQString() const;
};

#endif // ENTIER_H
