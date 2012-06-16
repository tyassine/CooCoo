
#include "rationnel.h"
#include <sstream>
#include <cmath>
#include "entier.h"
#include "reel.h"

QString Rationnel::toQString() const
{
    QString resNum, resDenom, res;
    resNum.setNum(num);
    resDenom.setNum(denom);
    res = resNum + "/" + resDenom;
    return res;
}

Rationnel::Rationnel(const Entier* aEntier)
{
    num = aEntier->getValeur();
    denom = 1;
}

Rationnel::Rationnel(const Reel* aReel)
{
    double fractpart, intpart;
    float numerateur(0);
    float denominateur(0);
    float resPGCD(0);
    //on cherche si le réel est fini ou pas
    fractpart = std::modf(aReel->getValeur(), &intpart);
    fractpart *= 1000000; // on le récupère en "entier"
    if(std::fmod(fractpart, 10) == 0){ // ici le réel est fini, il n'y a pas de reste car ce sera divisible par 10
        numerateur = fractpart + 1000000*intpart; // on lui met la partie entière avant
        //On simplifie la fraction
        resPGCD = pgcd(numerateur, 1000000);
        numerateur /= resPGCD;
        denominateur = 1000000 / resPGCD;
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
    denom=denominateur;
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
