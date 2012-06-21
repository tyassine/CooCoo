#include "constanteexp.h"
#include <iostream>

Donnee* ConstanteExp::operator +(Donnee * t){
    std::cout<<"rentré"<<std::endl;
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + " + '";
    std::cout<<"chaine construite"<<std::endl;
    std::cout<<exp.toStdString()<<std::endl;
    Donnee * res=new ConstanteExp(exp);
    return res;
}

Donnee* ConstanteExp::operator -(Donnee * t){
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + " - '";
    return new ConstanteExp(exp);
}


Donnee* ConstanteExp::operator *(Donnee * t){
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + " * '";
    return new ConstanteExp(exp);
}


Donnee* ConstanteExp::operator /(Donnee * t){
    std::cout<<"dans div"<<std::endl;
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + " / '";
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::puissance(Donnee * t){
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + " pow '";
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::mod(Donnee * t){
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + " mod '";
    return new ConstanteExp(exp);
}

// ConstanteExp? Pas Donnee?
ConstanteExp* ConstanteExp::sign()
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + " sign '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::mySin(int typeAngle)
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + " sin '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myCos(int typeAngle)
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1)  + " cos '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myTan(int typeAngle)
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1)  + " tan '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::mySinh(int typeAngle)
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + " sinh '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myCosh(int typeAngle)
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " cosh '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myTanh(int typeAngle)
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " tanh '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myLn()
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " ln '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myLog()
{
    QString op= chaine.at(chaine.size()-1);
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " log '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myInv()
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " inv '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::mySqrt()
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " sqrt '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::mySqr()
{
    QString op= chaine.at(chaine.size()-1);
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " sqr '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myCube()
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + " cube '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::myFact()
{
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) +  " fact '";
    // Opérateur unaire : pas sûr du tout!
    return new ConstanteExp(exp);
}
