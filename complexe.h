#ifndef COMPLEXE_H
#define COMPLEXE_H

/*!
* \file complexe.h
* \author Letellier/Yassine
*/

#include "constante.h"
#include <sstream>


class Complexe : public Donnee
{
    Constante* pRe;
    Constante* pIm;
public:

    Complexe(Constante* D1, Constante* D2) : pRe(D1), pIm(D2) {}
    ~Complexe() {delete pRe; delete pIm;}

    virtual QString toQString() const
    {
        QString res = pRe->toQString() + "$" + pIm->toQString();
        return res;
    }


    virtual Donnee* operator+(Donnee & t) {}
    /*
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

#endif // COMPLEXE_H
