#include "rationnel.h"
#include <sstream>

QString Rationnel::toQString() const
{
    QString resNum, resDenum, res;
    resNum.setNum(num);
    resDenum.setNum(denum);
    res = resNum + "/" + resDenum;
    return res;
}

Rationnel::Rationnel(Entier* aEntier)
{
    num = aEntier->getValeur();
    denum = 1;
}

Rationnel::Rationnel(Reel* aReel)
{
    double fractpart, intpart;
    float numerateur(0);
    float denominateur(0);
    float pgcd(0);
    //on cherche si le réel est fini ou pas
    fractpart = std::modf(aReel, &intpart);
    fractpart *= 1000000; // on le récupère en "entier"
    if(std::fmod(fractpart, 10) == 0){ // ici le réel est fini, il n'y a pas de reste car ce sera divisible par 10
        numerateur = fractpart + 1000000*intpart; // on lui met la partie entière avant
        //On simplifie la fraction
        pgcd = pgcd(numerateur, 1000000);
        numerateur /= pgcd;
        denominateur = 1000000 / pgcd;
    }
    else //Si le reel a a une partie décimal infinie
    {/*
        numerateur = fractpart + 999999*intpart;
        //On simplifie la fraction
        pgcd = pgcd(numerateur, 999999);
        numerateur /= P;
        denominateur = 999999 / P;*/
    }
    num=numerateur;
    denum=denominateur;
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

void Rationnel::simplifier(){
    if (num==0) {
        denum=1; return;
    }
    if (denum==0) return;
    int p=pgcd(num,denum);
    num/=p;
    denum/=p;
    if (denum<0) {
        denum=-denum;
        num=-num;
    }
}
/*
Rationnel::Rationnel(Complexe* aComplexe){
    if (dynamic_cast<Rationnel>(aComplexe->pRe)){
        num=aComplexe->pRe->num;
        denum=aComplexe->pRe->denum;
    }
    else {
        num=Entier(aComplexe->pRe);
        denum=1;
        simplifier();
    }
}
*/
