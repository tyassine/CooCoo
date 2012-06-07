#ifndef ENTIER_H
#define ENTIER_H

/*!
* \file entier.h
* \author Letellier/Yassine
*/

#include "constante.h"

class Entier : public Constante
{
    int valeur;
public:
    Entier(const QString& aQString ="0") : valeur(aQString.toInt()) {}
    virtual QString toQString() const;

    /*
    virtual Donnee* operator+(Donnee & t);
    virtual Donnee* operator/(Donnee & t);
    virtual Donnee* operator*(Donnee & t);
    virtual Donnee* operator-(Donnee & t);

    virtual Donnee* pow(Donnee & t);
    virtual Donnee* mod(Donnee & t);
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

#endif // ENTIER_H
