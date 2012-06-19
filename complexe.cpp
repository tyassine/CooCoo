#include "Complexe.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "constanteexp.h"
#include "fabriquedonnee.h"


Complexe::Complexe(const Complexe* aComplexe)
{
   /* Donnee* pRe=aComplexe->getPRe();
    Donnee* pIm=aComplexe->getpIm();
    */
    // Traitement différent ici, ne pas simplement copier les pointeurs mais faire de nouveaux objets
    // A traiter si le temps... Cette fonction ne sera jamais appelée.
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
    pRe=dynamic_cast<Constante*>(factory->creerDonnee((copie.section('$', 0,0))));
    pIm=dynamic_cast<Constante*>(factory->creerDonnee((copie.section('$', 1,1))));
}

Donnee* Complexe::conj(){
    Constante* pIm_sign;
    pIm_sign=dynamic_cast<Constante*>(pIm->sign());
    Complexe *res =new Complexe(pRe,pIm_sign);
    return res;
}


Donnee* Complexe::operator +(Donnee & t){
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       if ((*pIm + *tmp.getPIm())->toQString()=="0")
           return *pRe + *tmp.pRe;
       Complexe *res=new Complexe;
       res->pRe= dynamic_cast<Constante*> (*pRe + *tmp.getPRe());
       res->pIm= dynamic_cast<Constante*>(*pIm + *tmp.getPIm());
       return res;
    }
    catch(std::exception &e){}


    try{
       Constante &tmp=dynamic_cast<Constante&>(t);
       Donnee * res;
       res=tmp+*this;
       return res;
    }
    catch(std::exception &e){}

    try{
        ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(t);
        QString nouv;
        nouv = "'" + toQString() + " "+ tmp.toQString() + " +'";
        return new ConstanteExp(nouv);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur sur operateur + avec un complexe");


}

Donnee* Complexe::operator /(Donnee & t)
{
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Donnee *res;
       res= *(*this * *(tmp.conj())) / *(tmp * *(tmp.conj())) ;
       return res;
    }
    catch(std::exception &e){}

    try{
       Constante *tmp=dynamic_cast<Constante*>(&t);
       if (tmp)
       {
       Complexe *res=new Complexe;
       res->pRe= dynamic_cast<Constante*> (*pRe / *tmp);
       res->pIm= dynamic_cast<Constante*>(*pIm / *tmp);
       return res;
       }
    }
    catch(std::exception &e){}

    try{
           ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(t);
           QString e;
           e = "'" + toQString() + " "+ tmp.toQString() + " /'";
           return new ConstanteExp(e);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur sur operateur / avec un complexe");
}

Donnee* Complexe::operator*(Donnee& t){
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       if ((*(*pRe * *tmp.pIm)+*(*pIm * *tmp.pRe))->toQString()=="0")
           return FabriqueDonnee::getInstance()->creerDonnee((*(*pRe * *tmp.pRe)-*(*pIm * *tmp.pIm))->toQString());
       Complexe *res=new Complexe;
       res->pRe= dynamic_cast<Constante*> (*(*pRe * *tmp.pRe)-*(*pIm * *tmp.pIm));
       res->pIm= dynamic_cast<Constante*>(*(*pRe * *tmp.pIm)+*(*pIm * *tmp.pRe));
       return res;
    }
    catch(std::exception &e){}

    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Complexe cur(&tmp);
       Donnee* res;
       res=cur*(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Complexe cur(&tmp);
       Donnee * res;
       res=cur*(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Complexe cur(&tmp);
       Donnee * res;
       res=cur*(*this);
       return res;
    }
    catch(std::exception &e){}


    try{
        ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(t);
        QString e;
        e = "'" + toQString() + " "+ tmp.toQString() + " *'";
        return new ConstanteExp(e);
    }
    catch(std::exception &e){}

    throw ExceptionCooCoo("erreur sur operateur * avec un complexe");
}

Donnee* Complexe::operator-(Donnee& t){
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe *res=new Complexe;
       res->pRe= dynamic_cast<Constante*> (*pRe - *tmp.pRe);
       res->pIm= dynamic_cast<Constante*>(*pIm - *tmp.pIm);

       return res;
    }
    catch(std::exception &e){}

    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Complexe cur(tmp.toQString());
       Donnee * res;
       res=cur-(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Complexe cur(tmp.toQString());
       Donnee * res;
       res=cur-(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
        ConstanteExp &tmp=dynamic_cast<ConstanteExp&>(t);
        QString e;
        e = "'" + toQString() + " "+ tmp.toQString() + " -'";
        return new ConstanteExp(e);
    }
    catch(std::exception &e){}

    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Complexe cur(tmp.toQString());
       Donnee * res;
       res=cur-(*this);
       return res;
    }
    catch(std::exception &e){}
    throw ExceptionCooCoo("erreur sur operateur - avec un complexe");
}
