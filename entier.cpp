
#include "entier.h"
#include <sstream>

#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "fabriquedonnee.h"
#include <typeinfo>
#include <math.h>

QString Entier::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}

Entier::Entier(const Reel* aReel)
{
    // On ne veut pas une troncature mais un arrondi donc ce n'est pas un static cast simple
    valeur = static_cast<int>(aReel->getValeur()>=0 ? aReel->getValeur() + 0.5 : aReel->getValeur() - 0.5);
}

Entier::Entier(const Rationnel* aRationnel)
{
    // Perte d'information
    double num = static_cast<double>(aRationnel->getNum());
    double denom = static_cast<double>(aRationnel->getDenom());
    double nombre = num/denom;
    // Ex : pour convertir 70/8 en entier, on fait 70/8 ==> 8,75 ==> 9
    valeur = static_cast<int>(nombre>= 0? nombre +0.5 : nombre -0.5);
}

Entier::Entier(const Complexe* aComplexe)
{
    // Perte d'information
    Constante* tmp = aComplexe->getPRe();
    // Besoin de l'instance factory... Du coup include sale, mais bon.
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    Entier* tmp2 = static_cast<Entier*>(factory->creerDonnee(tmp, 0, 0));
    // static_cast pour permettre la conversion Donnee* ==> Entier*
    // On est surs que ça sera un Entier*, puisqu'on le demande spécifiquement!
    valeur = tmp2->getValeur();
    delete tmp2;
    delete tmp;
}

Donnee* Entier::operator+(Donnee* t)
{
    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Entier *res=new Entier(valeur+tmp->getValeur());
       return res;
    }

    if (typeid(*t)==typeid(Reel)){

       Reel *tmp=static_cast<Reel*>(t);
       Reel *res=new Reel(valeur+tmp->getValeur());
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t); //conversion de l'entier en rationnel
       Donnee* res;
       Rationnel cur(this); //appel du constructeur avec conversion
       res=cur+tmp;
       return res;
    }

    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       Complexe cur(this); //conversion de l'entier en complexe
       Donnee* res;
       res=cur+tmp; // pas *res car les opérateurs retournent deja des pointeurs
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString().remove("'") + " + '";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("Erreur sur operateur + avec un entier");
}

Donnee* Entier::operator /(Donnee* t)
{
    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Rationnel *res=new Rationnel(valeur,tmp->getValeur()); // la meilleur solution pour ne pas perdre d'information
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Reel *res=new Reel(valeur/tmp->getValeur());
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Rationnel *res=new Rationnel(valeur*tmp->getDenom(), tmp->getNum());
       return res;
    }

    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       Complexe cur(this);
       Donnee * res;
       res=cur/tmp;
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString().remove("'") + " / '";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("Erreur sur operateur / avec un entier");
}

Donnee* Entier::operator*(Donnee* t){
    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Entier *res=new Entier(valeur*tmp->getValeur());
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Reel *res=new Reel(valeur*tmp->getValeur());
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Rationnel *res=new Rationnel(valeur*tmp->getNum(), tmp->getDenom());
       return res;
    }

    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       Complexe cur(this);
       Donnee * res;
       res=cur*tmp;
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
       QString nouv;
       nouv = "'" + toQString() +" "+ tmp->toQString().remove("'") + " * '";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("Erreur sur operateur * avec un entier");
}

Donnee* Entier::operator-(Donnee* t){
    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Entier *res=new Entier(valeur-(tmp->getValeur()));
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Reel *res=new Reel(valeur-tmp->getValeur());
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Donnee* res;
       Rationnel cur(this);
       res=cur-tmp;
       return res;
    }

    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       Complexe cur(this);
       Donnee * res;
       res=cur-tmp;
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString().remove("'") + " - '";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("Erreur sur operateur - avec un entier");
}

Donnee* Entier::puissance(Donnee* t)

{
    if (typeid(*t)==typeid(Entier)){
        Entier *tmp=static_cast<Entier*>(t);
        if (tmp->getValeur() >= 0)  // puissance positive
            return new Entier(pow(valeur,tmp->getValeur()));
       else // puissance négative
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

    throw ExceptionCooCoo("Erreur sur operateur pow avec un entier");
}

Donnee* Entier::mod(Donnee* t)
{
    if (typeid(*t)==typeid(Entier)){
        Entier *tmp=static_cast<Entier*>(t);
        return new Entier( valeur % tmp->getValeur());
    }

    throw ExceptionCooCoo("Erreur sur operateur mod avec un entier");
}
