#ifndef DONNEE_H
#define DONNEE_H

/*!
* \file donnee.h
* \author Letellier/Yassine
*/

#include <QString>
#include <QRegExp>

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
/*
    virtual Donnee* pow(Donnee & t)=0;
    virtual Donnee* mod(Donnee & t)=0;
    virtual Donnee* sign()=0;

    virtual Donnee* sin()=0;
    virtual Donnee* cos()=0;
    virtual Donnee* tan()=0;
    virtual Donnee* sinh()=0;
    virtual Donnee* cosh()=0;
    virtual Donnee* tanh()=0;

    virtual Donnee* ln()=0;
    virtual Donnee* log()=0;
    virtual Donnee* inv()=0;
    virtual Donnee* sqrt()=0;
    virtual Donnee* sqr()=0;
    virtual Donnee* cube()=0;
    virtual Donnee* fact()=0;
    virtual Donnee* eval()=0;

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
