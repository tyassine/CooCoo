#include "Complexe.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "constanteexp.h"
#include "fabriquedonnee.h"
#include <typeinfo>


Complexe::Complexe(const Complexe* aComplexe)
{
    // IMPORTANT A TRAITER POUR LE MEMENTO
    //Donnee* pRe=aComplexe->getPRe();
    //Donnee* pIm=aComplexe->getpIm();

    // On va faire une copie des objets vers lesquels pointent pRe et pIm.
    // Comme on ne sait pas de quel type ils sont, on les convertit en QString et on les passe à la factory.
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    pRe = static_cast<Constante*>(factory->creerDonnee(aComplexe->getPRe()->toQString()));
    pIm = static_cast<Constante*>(factory->creerDonnee(aComplexe->getPIm()->toQString()));
}

Complexe::Complexe(const Entier* aEntier)
{
    pRe = new Entier(aEntier->getValeur()); // Pour en faire une copie
    pIm = new Entier(0);
}

Complexe::Complexe(const Reel* aReel)
{
    pRe = new Reel(aReel->getValeur()); // Pour en faire une copie
    pIm = new Entier(0);
}

Complexe::Complexe(const Rationnel *aRationnel)
{
    pRe = new Rationnel(aRationnel);
    pIm = new Entier(0);    // Ou alors faire un 0/1 si on tient vraiment à avoir un Rationnel aussi en partie imaginaire...
}
Complexe::Complexe(const QString &s)
{
    QString copie(s);
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    pRe=static_cast<Constante*>(factory->creerDonnee((copie.section('$', 0,0))));
    pIm=static_cast<Constante*>(factory->creerDonnee((copie.section('$', 1,1))));
}

Donnee* Complexe::conj(){
    Constante* pIm_sign;
    pIm_sign=static_cast<Constante*>(pIm->sign());
    Complexe *res =new Complexe(pRe,pIm_sign);
    return res;
}


Donnee* Complexe::operator +(Donnee * t){
    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       if ((*pIm + (tmp->getPIm()))->toQString()=="0")
           return *pRe + tmp->getPRe();
       Complexe *res=new Complexe;
       res->pRe= static_cast<Constante*> (*pRe + tmp->getPRe());
       res->pIm= static_cast<Constante*>(*pIm + tmp->getPIm());
       return res;
    }


    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Donnee * res;
       res=*tmp+this;
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Donnee * res;
       res=*tmp+this;
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Donnee * res;
       res=*tmp+this;
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
        ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
        QString nouv;
        nouv = "'" + toQString() + " "+ tmp->toQString() + " +'";
        return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur + avec un complexe");


}

Donnee* Complexe::operator /(Donnee * t)
{
    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       Donnee *res;
       res= *(*this * (tmp->conj())) / (*tmp * (tmp->conj())) ;
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Constante *tmp=static_cast<Entier*>(t);
       if (tmp)
       {
       Constante* pre= static_cast<Constante*> (*pRe / tmp);
       Constante* pim= static_cast<Constante*>(*pIm / tmp);
       Complexe *res=new Complexe(pre,pim);
       return res;
       }
    }

    if (typeid(*t)==typeid(Reel)){
       Constante *tmp=static_cast<Reel*>(t);
       if (tmp)
       {
       Constante* pre= static_cast<Constante*> (*pRe / tmp);
       Constante* pim= static_cast<Constante*>(*pIm / tmp);
       Complexe *res=new Complexe(pre,pim);
       return res;
       }
    }

    if (typeid(*t)==typeid(Rationnel)){
       Constante *tmp=static_cast<Rationnel*>(t);
       if (tmp)
       {
       Constante* pre= static_cast<Constante*> (*pRe / tmp);
       Constante* pim= static_cast<Constante*>(*pIm / tmp);
       Complexe *res=new Complexe(pre,pim);
       return res;
       }
    }

    if (typeid(*t)==typeid(ConstanteExp)){
           ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
           QString nouv;
           nouv = "'" + toQString() + " "+ tmp->toQString() + " /'";
           return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur / avec un complexe");
}

Donnee* Complexe::operator*(Donnee* t){
    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       if ((*(*pRe * tmp->getPIm())+(*pIm * tmp->getPRe()))->toQString()=="0")
           return FabriqueDonnee::getInstance()->creerDonnee((*(*pRe * tmp->getPRe())-(*pIm * tmp->getPIm()))->toQString());

       Constante* pre= static_cast<Constante*> (*(*pRe * tmp->getPRe())-(*pIm * tmp->getPIm()));
       Constante* pim= static_cast<Constante*>(*(*pRe * tmp->getPIm())+(*pIm *tmp->getPRe()));
       Complexe *res=new Complexe(pre,pim);
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Complexe cur(tmp);
       Donnee* res;
       res=cur*(this);
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Complexe cur(tmp);
       Donnee * res;
       res=cur*(this);
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Complexe cur(tmp);
       Donnee * res;
       res=cur*(this);
       return res;
    }


    if (typeid(*t)==typeid(ConstanteExp)){
        ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
        QString nouv;
        nouv = "'" + toQString() + " "+ tmp->toQString() + " *'";
        return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur * avec un complexe");
}

Donnee* Complexe::operator-(Donnee* t){
    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);

       Constante* pre= static_cast<Constante*> (*pRe - tmp->getPRe());
       Constante* pim= static_cast<Constante*>(*pIm - tmp->getPIm());
       Complexe *res=new Complexe(pre,pim);
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Complexe *cur=new Complexe(tmp);
       Donnee * res;
       res=*this-cur;
       delete cur;
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Complexe *cur=new Complexe(tmp);
       Donnee * res;
       res=*this-cur;
       delete cur;
       return res;
    }

    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Complexe *cur=new Complexe(tmp);
       Donnee * res;
       res=*this-cur;
       delete cur;
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
        ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
        QString nouv;
        nouv = "'" + toQString() + " "+ tmp->toQString() + " -'";
        return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur - avec un complexe");
}
