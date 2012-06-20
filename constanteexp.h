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


    Donnee* operator+(Donnee* t);

    Donnee* operator/(Donnee * t);
    Donnee* operator*(Donnee * t);
    Donnee* operator-(Donnee * t);
    QString getChaine(){return chaine;}

    virtual Donnee* puissance(Donnee* t);
    virtual Donnee* mod(Donnee* t); /*
    virtual Donnee* sign();

    virtual Donnee* sin();
    virtual Donnee* cos();
    virtual Donnee* tan();
    virtual Donnee* sinh();
    virtual Donnee* cosh();
    virtual Donnee* tanh();

    virtual Donnee* ln();
    virtual Donnee* log();
    virtual Donnee* inv();
    virtual Donnee* sqrt();
    virtual Donnee* sqr();
    virtual Donnee* cube();
    virtual Donnee* fact();
    virtual Donnee* eval();
    */

};

#endif // CONSTANTEEXP_H
