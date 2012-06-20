#include "constanteexp.h"

Donnee* ConstanteExp::operator +(Donnee * t){
    QString op= chaine.at(chaine.size()-1);
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + op + ' ' + "+'";
    return new ConstanteExp(exp);
}

Donnee* ConstanteExp::operator -(Donnee * t){
    QString op= chaine.at(chaine.size()-1);
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + op + ' ' + "-'";
    return new ConstanteExp(exp);
}


Donnee* ConstanteExp::operator *(Donnee * t){
    QString op= chaine.at(chaine.size()-1);
    QString exp = chaine.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + op + ' ' + "*'";
    return new ConstanteExp(exp);
}


Donnee* ConstanteExp::operator /(Donnee * t){
    QString op= chaine.at(chaine.size()-1);
    QString exp = exp.remove(chaine.size()-1,chaine.size()-1) + ' ' + t->toQString() + op + ' ' + "/'";
    return new ConstanteExp(exp);
}

