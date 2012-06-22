#include <typeinfo>
#include "reel.h"
#include <sstream>

#include "entier.h"
#include "rationnel.h"
#include "fabriquedonnee.h"
#include <math.h>

QString Reel::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}

Reel::Reel(const Entier* aEntier)
{
    valeur = static_cast<double>(aEntier->getValeur());
}

Reel::Reel(const Rationnel* aRationnel)
{
    // Perte d'information
    double num = static_cast<double>(aRationnel->getNum());
    double denom = static_cast<double>(aRationnel->getDenom());
    valeur = num/denom;
}

Reel::Reel(const Complexe* aComplexe)
{
    // Perte d'information
    Constante* tmp = aComplexe->getPRe();
    // Besoin de l'instance factory... Du coup include sale, mais bon.
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    Reel* tmp2 = static_cast<Reel*>(factory->creerDonnee(tmp, 2, 0));
    // static_cast pour permettre la conversion Donnee* ==> Reel*
    // On est surs que ça sera un Reel*, puisqu'on le demande spécifiquement!
    valeur = tmp2->getValeur();
    delete tmp2;
    delete tmp;
}

Donnee* Reel::operator +(Donnee* d){

    if (typeid(*d)==typeid(Entier)){

       Entier *tmp=static_cast<Entier*>(d);
       Reel *res=new Reel(valeur+tmp->getValeur());
       return res;
    }

    if (typeid(*d)==typeid(Reel)){

       Reel *tmp=static_cast<Reel*>(d);
       Reel *res=new Reel(valeur+tmp->getValeur());
       return res;
    }

    if (typeid(*d)==typeid(Rationnel)){

       Rationnel *tmp=static_cast<Rationnel*>(d);
       Rationnel cur(this);
       Donnee* res;
       res=cur+tmp; // simplification dans le + du rationnel
       return res;
    }

    if (typeid(*d)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur+tmp;
       return res;
    }

    if (typeid(*d)==typeid(ConstanteExp)){

       ConstanteExp *tmp=static_cast<ConstanteExp*>(d);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString().remove("'") + " + '";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur opérateur + avec un reel");


}

Donnee* Reel::operator /(Donnee* d){
    if (typeid(*d)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(d);
       Rationnel cur(this);
       Rationnel *ent=new Rationnel(tmp);
       Donnee *res=cur/ent;
       return res;


    }

    if (typeid(*d)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(d); // pour eviter la perte de données
       Rationnel cur(this);
       Rationnel *re=new Rationnel(tmp);
       Donnee *res=cur/re;
       return res;
    }

    if (typeid(*d)==typeid(Rationnel)){

       Rationnel *tmp=static_cast<Rationnel*>(d);
       Rationnel cur(this);
       Donnee* res;
       res=cur/tmp;
       return res;
    }

    if (typeid(*d)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur/tmp;
       return res;
    }

    if (typeid(*d)==typeid(ConstanteExp)){

       ConstanteExp *tmp=static_cast<ConstanteExp*>(d);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString().remove("'") + " / '";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur opérateur / avec un reel");
}

Donnee* Reel::operator*(Donnee* d){
    if (typeid(*d)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(d);
       Reel *res=new Reel(valeur*tmp->getValeur());
       return res;
    }

    if (typeid(*d)==typeid(Entier)){

       Entier *tmp=static_cast<Entier*>(d);
       Reel *res=new Reel(valeur*tmp->getValeur());
       return res;
    }

    if (typeid(*d)==typeid(Rationnel)){

       Rationnel *tmp=static_cast<Rationnel*>(d);
       Rationnel cur(this);
       Donnee *res=cur*tmp;
       return res;
    }

    if (typeid(*d)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur*tmp;
       return res;
    }

    if (typeid(*d)==typeid(ConstanteExp)){

       ConstanteExp *tmp=static_cast<ConstanteExp*>(d);
       QString e;
       e = "'" + toQString() +" "+ tmp->toQString().remove("'") + " * '";
       return new ConstanteExp(e);
    }

    throw ExceptionCooCoo("erreur sur opérateur * avec un reel");
}

Donnee* Reel::operator-(Donnee* d){
    if (typeid(*d)==typeid(Entier)){

       Entier *tmp=static_cast<Entier*>(d);
       Reel *res=new Reel(valeur-tmp->getValeur());
       return res;
    }

    if (typeid(*d)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(d);
       Reel *res=new Reel(valeur-tmp->getValeur());
       return res;
    }


    if (typeid(*d)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(d);
       Rationnel cur(this);
       Donnee *res=cur-tmp;
       return res;
    }

    if (typeid(*d)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur-tmp;
       return res;
    }

    if (typeid(*d)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(d);
       QString e;
       e = "'" + toQString() + " "+ tmp->toQString().remove("'") + " - '";
       return new ConstanteExp(e);
    }

    throw ExceptionCooCoo("erreur sur opérateur - avec un reel");
}

Donnee* Reel::puissance(Donnee* t)
{
    if (typeid(*t)==typeid(Entier)){
        Entier *tmp=static_cast<Entier*>(t);
        return new Reel(pow(valeur, tmp->getValeur()));
    }
    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       return new Reel(pow(valeur, tmp->getValeur()));
    }
    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Reel *tmp2 = new Reel(tmp);
       return new Reel(pow(valeur, tmp2->getValeur()));
    }
    if (typeid(*t)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString() + " pow'";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("Erreur sur opérateur pow avec un reel");
}

Donnee* Reel::mySin(int typeAngle)
{
    if (typeAngle == 0) // Degrés
        return new Reel(sin(valeur*M_PI/180));
    else    // Radians
        return new Reel(sin(valeur));
}

Donnee* Reel::myCos(int typeAngle)
{
    if (typeAngle == 0) // Degrés
        return new Reel(cos(valeur*M_PI/180));
    else    // Radians
        return new Reel(cos(valeur));
}

Donnee* Reel::myTan(int typeAngle)
{
    if (typeAngle == 0) // Degrés
        return new Reel(tan(valeur*M_PI/180));
    else    // Radians
        return new Reel(tan(valeur));
}

Donnee* Reel::mySinh(int typeAngle)
{
    if (typeAngle == 0) // Degrés
        return new Reel(sinh(valeur*M_PI/180));
    else    // Radians
        return new Reel(sinh(valeur));
}

Donnee* Reel::myCosh(int typeAngle)
{
    if (typeAngle == 0) // Degrés
        return new Reel(cosh(valeur*M_PI/180));
    else    // Radians
        return new Reel(cosh(valeur));
}

Donnee* Reel::myTanh(int typeAngle)
{
    if (typeAngle == 0) // Degrés
        return new Reel(tanh(valeur*M_PI/180));
    else    // Radians
        return new Reel(tanh(valeur));
}

Donnee* Reel::myLn()
{
    return new Reel(log(valeur));
}

Donnee* Reel::myLog()
{
    return new Reel(log10(valeur));
}

Donnee* Reel::myInv()
{
    return new Rationnel(1, valeur);
}

Donnee* Reel::mySqrt()
{
    return new Reel(sqrt(valeur));
}

Donnee* Reel::mySqr()
{
    return new Reel(valeur*valeur);
}

Donnee* Reel::myCube()
{
    return new Reel(valeur*valeur*valeur);
}
