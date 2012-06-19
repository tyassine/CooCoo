#ifndef COMPLEXE_H
#define COMPLEXE_H

/*!
* \file complexe.h
* \author Letellier/Yassine
*/

#include "constante.h"
#include <sstream>

class Entier;
class Reel;
class Rationnel;

class Complexe : public Donnee
{
    Constante* pRe;
    Constante* pIm;
public:

    Complexe(Constante* D1=0, Constante* D2=0) : pRe(D1), pIm(D2) {}
    Complexe(const Complexe* aComplexe);    // Ne sera jamais appelé, mais nécessaire pour Donnee* FabriqueDonnee::creerDonnee(const Donnee*, const QString);
    Complexe(const Entier* aEntier);
    Complexe(const Reel* aReel);
    Complexe(const Rationnel* aRationnel);
    Complexe(const QString &s);


    ~Complexe() {delete pRe; delete pIm;}

    virtual QString toQString() const
    {
        QString res = pRe->toQString() + "$" + pIm->toQString();
        return res;
    }

    Constante* getPRe() const {return pRe;}
    Constante* getPIm() const {return pIm;}
    Donnee* conj();


    Donnee* operator+(Donnee & t);

    Donnee* operator/(Donnee & t);
    Donnee* operator*(Donnee & t);
    Donnee* operator-(Donnee & t);
    Complexe* sign(){
        Complexe* res=new Complexe(pRe->sign(),pIm->sign());
        return res;}
/*
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
