#ifndef CONSTANTEEXP_H
#define CONSTANTEEXP_H

#include "donnee.h"

class ConstanteExp : public Donnee
{
    QString chaine;
public:
    ConstanteExp(const QString& aQString) : chaine(aQString) {}
    virtual QString toQString() const {return chaine;}
};

#endif // CONSTANTEEXP_H
