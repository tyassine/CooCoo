
#include "entier.h"
#include <sstream>

#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "fabriquedonnee.h"

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
    if (dynamic_cast<Entier*>(tmp)!= NULL)
        valeur= tmp->getValeur();
    else {
        // Besoin de l'instance factory... Du coup include sale, mais bon.
        FabriqueDonnee* factory = FabriqueDonnee::getInstance();
        Entier* tmp2 = static_cast<Entier*>(factory->creerDonnee(tmp, "Entier"));
        // static_cast pour permettre la conversion Donnee* ==> Entier*
        // On est surs que ça sera un Entier*, puisqu'on le demande spécifiquement!
        valeur = tmp2->getValeur();
        delete tmp2;
    }
    delete tmp;
}

Donnee* Entier::operator+(Donnee& t)
{
    //ici il faut mieux faire des try catch car les if nous obligent a faire 2 dynamic cast
    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Entier *res=new Entier(valeur+tmp->getValeur());
       return res;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *res=new reel(valeur+tmp->getValeur());
       return res;
    }
    catch(std::exception &e){}

    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t); //conversion de l'entier en rationnel
       Donnee* res;
       Rationnel cur(valeur,1);
       *res=tmp+cur;
       return res;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe cur(toQString()); //conversion de l'entier en complexe
       Donnee* res;
       *res=cur+tmp;
       return res;
    }
    catch(std::exception &e){}

    try{
       ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(t);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}



    throw exceptionCooCoo("erreur entier");

}



