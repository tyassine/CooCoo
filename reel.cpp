
#include "Reel.h"
#include <sstream>

#include "Entier.h"
#include "Rationnel.h"
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
    if (dynamic_cast<Reel*>(tmp)){
        Reel* tmp1=dynamic_cast<Reel*>(tmp);
        valeur= tmp1->getValeur();
        delete tmp1;
    }
    else {
        // Besoin de l'instance factory... Du coup include sale, mais bon.
        FabriqueDonnee* factory = FabriqueDonnee::getInstance();
        Reel* tmp2 = static_cast<Reel*>(factory->creerDonnee(tmp, "Reel"));
        // static_cast pour permettre la conversion Donnee* ==> Reel*
        // On est surs que ça sera un Reel*, puisqu'on le demande spécifiquement!
        valeur = tmp2->getValeur();
        delete tmp2;
    }
    delete tmp;
}

Donnee* Reel::operator +(Donnee& d){

    try{

       Entier &tmp=dynamic_cast<Entier&>(d);
       Reel *res=new Reel(valeur+tmp.getValeur());
       return res;
    }
    catch(std::exception &e){}

    try{

       Reel &tmp=dynamic_cast<Reel&>(d);
       Reel *res=new Reel(valeur+tmp.getValeur());
       return res;
    }
    catch(std::exception &e){}

    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(d);
       Rationnel cur(this);
       Donnee* res;
       res=tmp+cur; // simplification dans le + du rationnel
       return res;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur+tmp;
       return res;
    }
    catch(std::exception &e){}

    try{

       ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(d);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new ConstanteExp(e);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur sur operateur avec un reel");


}

Donnee* Reel::operator /(Donnee& d){
    try{
       Entier &tmp=dynamic_cast<Entier&>(d);
       Rationnel cur(this);
       Rationnel ent(tmp);
       Donnee *res=cur/ent;
       return res;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(d); // pour eviter la perte de données
       Rationnel cur(this);
       Rationnel re(tmp);
       Donnee *res=cur/re;
       return res;
    }
    catch(std::exception &e){}

    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(d);
       Rationnel cur(this);
       Donnee* res;
       res=tmp+cur;
       return res;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur/tmp;
       return res;
    }
    catch(std::exception &e){}

    try{

       ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(d);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new ConstanteExp(nouv);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur sur operateur avec un reel");
}

Donnee* Reel::operator*(Donnee& d){
    try{
       Reel &tmp=dynamic_cast<Reel&>(d);
       Reel *res=new Reel(valeur*tmp.getValeur());
       return res;
    }
    catch(std::exception &e){}

    try{

       Entier &tmp=dynamic_cast<Entier&>(d);
       Reel *res=new Reel(valeur*tmp.getValeur());
       return res;
    }
    catch(std::exception &e){}


    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(d);
       Rationnel cur(this);
       Donnee *res=cur*tmp;
       return res;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur*tmp;
       return res;
    }
    catch(std::exception &e){}

    try{

       ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(d);
       QString e;
       e = "'" + toQString() +" "+ tmp.toQString().remove("'") + " *'";
       return new ConstanteExp(e);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur Reel");
}

Donnee* Reel::operator-(Donnee& d){

    try{

       Entier &tmp=dynamic_cast<Entier&>(d);
       Reel *res=new Reel(valeur-tmp.getValeur());
       return res;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(d);
       Reel *res=new Reel(valeur-tmp.getValeur());
       return res;
    }
    catch(std::exception &e){}


    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(d);
       Rationnel r(this);
       Donnee *res=r-tmp;
       return res;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(d);
       Complexe cur(this);
       Donnee * res;
       res=cur-tmp;
       return res;
    }
    catch(std::exception &e){}

    try{

       ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(d);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " -'";
       return new ConstanteExp(e);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur Reel");
}


