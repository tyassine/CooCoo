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

    virtual Donnee* puissance(Donnee* t);
    virtual Donnee* mod(Donnee* t); 
    QString getChaine()const{return chaine;}

    virtual ConstanteExp* sign();

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
    virtual Donnee* myFact();


};

#endif // CONSTANTEEXP_H
