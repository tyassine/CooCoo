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

    virtual Donnee* puissance(Donnee* t);
    virtual Donnee* mod(Donnee* t)
    {throw ExceptionCooCoo("Pas de calcul de mod avec un réel : non géré.");}


    virtual Donnee* mySin(int typeAngle);
    virtual Donnee* myCos(int typeAngle);
    virtual Donnee* myTan(int typeAngle);
    virtual Donnee* mySinh(int typeAngle);
    virtual Donnee* myCosh(int typeAngle);
    virtual Donnee* myTanh(int typeAngle);

    virtual Donnee* myLn();
    virtual Donnee* myLog();
    virtual Donnee* myInv();
    virtual Donnee* mySqrt();
    virtual Donnee* mySqr();
    virtual Donnee* myCube();
    virtual Donnee* myFact()
    {throw ExceptionCooCoo("Pas de calcul de fact avec un réel : non géré.");}



};

#endif // REEL_H
