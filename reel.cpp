#include <typeinfo>
#include "reel.h"
#include <sstream>

#include "entier.h"
#include "rationnel.h"
#include "fabriquedonnee.h"

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
    if (static_cast<Reel*>(tmp)){
        Reel* tmp1=static_cast<Reel*>(tmp);
        valeur= tmp1->getValeur();
        delete tmp1;
    }
    else {
        // Besoin de l'instance factory... Du coup include sale, mais bon.
        FabriqueDonnee* factory = FabriqueDonnee::getInstance();
        Reel* tmp2 = static_cast<Reel*>(factory->creerDonnee(tmp, 2, 0));
        // static_cast pour permettre la conversion Donnee* ==> Reel*
        // On est surs que ça sera un Reel*, puisqu'on le demande spécifiquement!
        valeur = tmp2->getValeur();
        delete tmp2;
    }
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
       nouv = "'" + toQString() + " "+ tmp->toQString() + " +'";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur + avec un reel");


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
       nouv = "'" + toQString() + " "+ tmp->toQString() + " /'";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur / avec un reel");
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
       e = "'" + toQString() +" "+ tmp->toQString() + " *'";
       return new ConstanteExp(e);
    }

    throw ExceptionCooCoo("erreur sur operateur * avec un reel");
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
       e = "'" + toQString() + " "+ tmp->toQString() + " -'";
       return new ConstanteExp(e);
    }

    throw ExceptionCooCoo("erreur sur operateur - avec un reel");
}

