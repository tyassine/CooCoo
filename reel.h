#ifndef REEL_H
#define REEL_H

/*!
* \file reel.h
* \author Letellier/Yassine
*/


#include "constante.h"

class Entier;
class Rationnel;


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
    Reel(Entier* aEntier);
    Reel(Rationnel* aRationnel);

    virtual QString toQString() const;

    double getValeur() const {return valeur;}
    void setValeur(double aValeur) {valeur = aValeur;}


    virtual Donnee* operator+(Donnee & t) {}
    // Surcharger? Ou tester le type de l'argument dans la méthode?
    // Qu'est-ce qui marche? Qu'est-ce qu'on peut changer sans nous séparer
    // des méthodes virtuelles pures de la classe Donnee?
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

#endif // REEL_H
