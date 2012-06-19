
#ifndef RATIONNEL_H
#define RATIONNEL_H

/*!
* \file rationnel.h
* \author Letellier/Yassine
*/

#include "constante.h"

class Entier;
class Reel;
class Complexe;

class Rationnel : public Constante
{
    int num;
    int denom;
    // On aurait pu mettre des objets Entier mais ça devient vraiment trop lourd...
public:

    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */

    Rationnel(int aInt1 =0, int aInt2 =1) : num(aInt1), denom(aInt2) {simplifier();}
    Rationnel(const QString& s);

    Rationnel(const Rationnel* aRationnel) : num(aRationnel->num), denom(aRationnel->denom) {}  // Ne sera jamais appelé, mais nécessaire pour Donnee* FabriqueDonnee::creerDonnee(const Donnee*, const QString);
    Rationnel(const Entier* aEntier);
    Rationnel(const Reel* aReel);
    Rationnel(const Complexe* aComplexe);


    virtual QString toQString() const;
    Rationnel* sign(){
        Rationnel* res=new Rationnel(-num,denom);
        return res;
    }
    int getNum() const {return num;}
    int getDenom() const {return denom;}
    void setNum(int aNum) {num = aNum;}
    void setDenom(int adenom) {denom = adenom;}

    int pgcd(int a, int b) const;
    void simplifier();


    Donnee* operator+(Donnee & t);

    Donnee* operator/(Donnee & t);
    Donnee* operator*(Donnee & t);
    Donnee* operator-(Donnee & t);
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

#endif // RATIONNEL_H

