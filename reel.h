#ifndef REEL_H
#define REEL_H

/*!
* \file reel.h
* \author Letellier/Yassine
*/


#include "constante.h"

class Entier;
class Rationnel;
class Complexe;


class Reel : public Constante
{
    double valeur;
public:
    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */
    Reel(double val=0) : valeur(val) {}
    Reel(const QString& aQString = "0") : valeur(aQString.toDouble()) {}
    Reel(const Reel* aReel) : valeur(aReel->valeur) {}
    Reel(const Entier* aEntier);
    Reel(const Rationnel* aRationnel);
    Reel(const Complexe* aComplexe);

    virtual QString toQString() const;

    double getValeur() const {return valeur;}
    void setValeur(double aValeur) {valeur = aValeur;}
    int getTaille() const {
       return toQString().section('.', 1,1).size();
    }

    Reel* sign(){
        Reel* res=new Reel(-valeur);
        return res;}
    Donnee* operator+(Donnee * t);
    Donnee* operator/(Donnee * t);
    Donnee* operator*(Donnee * t);
    Donnee* operator-(Donnee * t);
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

#endif // REEL_H
