#ifndef RATIONNEL_H
#define RATIONNEL_H

/*!
* \file rationnel.h
* \author Letellier/Yassine
*/

#include "entier.h"

class Rationnel : public Constante
{
    Entier num;
    Entier denum;
public:
    // Rationnel : plutôt le construire avec une QString!
    // Le seul intérêt de stocker sous valeur numérique est pour faire les calculs.
    // Tout le reste, les entrées, les sorties, c'est du QString!
    Rationnel(const QString& aQString1 = "0", const QString &aQString2 = "1")
        : num(Entier(aQString1)), denum(Entier(aQString2)) {}
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

#endif // RATIONNEL_H
