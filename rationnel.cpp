#include <typeinfo>
#include "Rationnel.h"
#include <sstream>
#include <cmath>
#include <QStringList>
#include "Entier.h"
#include "Reel.h"
#include "fabriquedonnee.h"
#include "exceptionCooCoo.h"

QString Rationnel::toQString() const
{
    QString resNum, resDenom, res;
    resNum.setNum(num);
    resDenom.setNum(denom);
    res = resNum + "/" + resDenom;
    return res;
}


Rationnel::Rationnel(const QString& s) {
    QString copie(s);
    num=(copie.section('/', 0,0)).toInt();
    denom=(copie.section('/', 1,1)).toInt();
    if (denom==0) throw ExceptionCooCoo("Division par 0");
    simplifier();
}

Rationnel::Rationnel(const Entier* aEntier)
{
    num = aEntier->getValeur();
    denom = 1;
}

Rationnel::Rationnel(const Reel* aReel)
{
    num=aReel->getValeur()*aReel->getTaille()*10;
    denom=aReel->getTaille()*10;
    simplifier();
}

int Rationnel::pgcd(int a, int b) const {
    if (a==0||b==0) return 0;
    if (a<0) a=-a;
    if (b<0) b=-b;
    while(a!=b){
        if (a>b) a=a-b; else b=b-a;
    }
    return a;
}

// Puisque c'est une méthode de la classe, pourquoi ne pas utiliser num et denom plutôt que a et b...?

void Rationnel::simplifier(){
    if (num==0) {
        denom=1; return;
    }
    if (denom==0) return;
    int p=pgcd(num,denom);
    num/=p;
    denom/=p;
    if (denom<0) {
        denom=-denom;
        num=-num;
    }
}

Rationnel::Rationnel(const Complexe* aComplexe)
{
    // Perte d'information
    Constante* tmp = aComplexe->getPRe();
    // Besoin de l'instance factory... Du coup include sale, mais bon.
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    Rationnel* tmp2 = static_cast<Rationnel*>(factory->creerDonnee(tmp, "Rationnel"));
    // static_cast pour permettre la curersion Donnee* ==> Rationnel*
    // On est surs que ça sera un Rationnel*, puisqu'on le demande spécifiquement!
    num = tmp2->getNum();
    denom = tmp2->getDenom();
    delete tmp2;
    delete tmp;
}

Donnee* Rationnel::operator +(Donnee * t){
    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Rationnel *res=new Rationnel(num*tmp->denom+tmp->num*denom,denom*tmp->denom);
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Rationnel cur=Rationnel(tmp);
       return cur+this;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Rationnel cur=Rationnel(tmp);
       return cur+this;
    }

    if (typeid(*t)==typeid(Complexe)){
       Complexe *tmp=static_cast<Complexe*>(t);
       Complexe cur(this);
       Donnee * res;
       res=cur+tmp;
       return res;
    }

    if (typeid(*t)==typeid(ConstanteExp)){
       ConstanteExp *tmp=static_cast<ConstanteExp*>(t);
       QString nouv;
       nouv = "'" + toQString() + " "+ tmp->toQString() + " +'";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur + avec un rationnel");
}

Donnee* Rationnel::operator -(Donnee * t){
    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Rationnel *res=new Rationnel(num*tmp->denom-tmp->num*denom,denom*tmp->denom);
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Rationnel *cur=new Rationnel(tmp);
       return *this-cur;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Rationnel *cur=new Rationnel(tmp);
       return *this-cur;
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
       nouv = "'" + toQString() + " "+ tmp->toQString() + " -'";
       return new ConstanteExp(nouv);
    }


    throw ExceptionCooCoo("erreur sur operateur - avec un rationnel");
}

Donnee* Rationnel::operator /(Donnee * t){
    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Rationnel *cur=new Rationnel(tmp->denom,tmp->num);//inverse
       Donnee* res=*this*cur;
       delete cur;
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Rationnel *cur=new Rationnel(tmp);
       Donnee* res=*this/cur;
       delete cur;
       return res;
    }


    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Rationnel *cur=new Rationnel(tmp);
       Donnee *res=*this*cur;
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
       QString e;
       e = "'" + toQString() + " "+ tmp->toQString() + " /'";
       return new ConstanteExp(e);
    }


    throw ExceptionCooCoo("erreur sur operateur / avec un rationnel");
}

Donnee* Rationnel::operator*(Donnee* t)
{
    if (typeid(*t)==typeid(Rationnel)){
       Rationnel *tmp=static_cast<Rationnel*>(t);
       Rationnel *res=new Rationnel(num*tmp->num,denom*tmp->denom);
       return res;
    }

    if (typeid(*t)==typeid(Entier)){
       Entier *tmp=static_cast<Entier*>(t);
       Rationnel *cur=new Rationnel(tmp);
       Donnee * res=*tmp*cur;
       delete cur;
       return res;
    }

    if (typeid(*t)==typeid(Reel)){
       Reel *tmp=static_cast<Reel*>(t);
       Rationnel *cur=new Rationnel(tmp);
       Donnee * res=*tmp*cur;
       delete cur;
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
       nouv = "'" + toQString() +" "+ tmp->toQString() + " *'";
       return new ConstanteExp(nouv);
    }

    throw ExceptionCooCoo("erreur sur operateur avec un rationnel");
}

