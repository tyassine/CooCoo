#ifndef ENTIER_H
#define ENTIER_H



/*!
* \file entier.h
* \author Letellier/Yassine
*/

#include "constante.h"

class Reel;
class Rationnel;

class Entier : public Constante
{
    int valeur;
public:

    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */


    Entier(int val=0) : valeur(val) {}
    Entier(const QString& aQString ="0") : valeur(aQString.toInt()) {}
    Entier(const Entier* aEntier) : valeur(aEntier->valeur) {}
    Entier(const Reel* aReel);
    Entier(const Rationnel* aRationnel);


    virtual QString toQString() const;

    int getValeur() const {return valeur;}
    void setValeur(int aValeur) {valeur = aValeur;}


    virtual Donnee* operator+(Donnee& t) {}
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

#endif // ENTIER_H
