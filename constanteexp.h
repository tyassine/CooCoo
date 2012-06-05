#ifndef CONSTANTEEXP_H
#define CONSTANTEEXP_H

#include "donnee.h"

class ConstanteExp : public Donnee
{
    string chaine;
public:
    ConstanteExp(const string& aString) : chaine(aString) {}
    virtual const string afficher() const {return chaine;}
};

#endif // CONSTANTEEXP_H
