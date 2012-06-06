#ifndef CONSTANTEEXP_H
#define CONSTANTEEXP_H

/*!
* \file constanteExp.h
* \brief definition de la classe des constantes expression qui herite de la classe Donnee
* \author Letellier/Yassine
*/

#include "donnee.h"

class ConstanteExp : public Donnee
{
    QString chaine;
public:
    ConstanteExp(const QString& aQString) : chaine(aQString) {}
    virtual QString toQString() const {return chaine;}
};

#endif // CONSTANTEEXP_H
