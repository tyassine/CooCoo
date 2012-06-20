#ifndef DONNEE_H
#define DONNEE_H

/*!
* \file donnee.h
* \author Letellier/Yassine
*/

#include <QString>
#include <QRegExp>
#include "exceptionCooCoo.h"

using namespace std;

// ABSTRAITE

class Donnee
{
public:
    Donnee() {}
    virtual QString toQString() const = 0; // Méthode virtuelle pure, redéfinie à chaque fois, permet la conversion de la valeur en QString


    virtual Donnee* operator+(Donnee * t)=0;

    virtual Donnee* operator/(Donnee * t)=0;
    virtual Donnee* operator*(Donnee * t)=0;
    virtual Donnee* operator-(Donnee * t)=0;

    virtual Donnee* puissance(Donnee* t)=0;
    virtual Donnee* mod(Donnee* t)=0;
    virtual Donnee* sign()=0;

    virtual Donnee* mySin(int typeAngle)=0;/*
    virtual Donnee* myCos(int typeAngle)=0;
    virtual Donnee* myTan(int typeAngle)=0;
    virtual Donnee* mySinh(int typeAngle)=0;
    virtual Donnee* myCosh(int typeAngle)=0;
    virtual Donnee* myTanh(int typeAngle)=0;

    virtual Donnee* myLn()=0;
    virtual Donnee* myLog()=0;
    virtual Donnee* myInv()=0;
    virtual Donnee* mySqrt()=0;
    virtual Donnee* mySqr()=0;
    virtual Donnee* myCube()=0;
    virtual Donnee* myFact()=0;
    virtual Donnee* myEval()=0;

    */

    static bool isEntier(const QString& s){
        QRegExp rx("^-?\\d+$");
        return s.contains (rx);
    }

    static bool isReel(const QString& s){
        QRegExp rx("^-?\\d*\\.?\\d*$");
        return s.contains(rx);}

    static bool isRationnel(const QString& s){
        QRegExp rx("^-?\\d*/-?\\d*$");
        return s.contains (rx);
    }

    static bool isExpression(const QString& s){
        return s.contains ("'*'");
    }

    static bool isComplexe(const QString& s){
        QRegExp rx("^-?\\d+((/|\\.)\\d+)?\\$-?\\d+((/|\\.)\\d+)?$");
        return s.contains (rx);
    }


};

#endif // DONNEE_H
