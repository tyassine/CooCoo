#include "pile.h"


Pile::Pile():nbElement(10){
   /* gard=new gardien;*/
}

Pile::~Pile(){
    for(int i=0; i<this->size(); i++){
       delete at(i);
    }
    /*
    if(gard)
    delete gard;*/
}

/*
Pile& Pile::cloner() const{
    Pile *p=new Pile(nbMax);
    for(int i=0; i<sommet; i++){
       // p->empiler(type_factory::getInstance().getType(at(i)->toQString()));
    }
    p->setgardien(this->getgardien());
    return *p;
}
*/

void Pile::swap(const unsigned int x, const unsigned int y){
    if (x < this->sommet && y < this->sommet){
        Donnee* tmp = (tab[sommet-x]);
        this->tab[sommet-x]=tab[sommet-y];
        this->tab[sommet-y]=tmp;
    }
}

void Pile::sum(const unsigned int x){
    if(!pileVide()){
        Donnee* res;
        *res=0;
        for(unsigned int i=0; i<x; i++){
            *res=*res+(*tab[sommet-i]);
        }
        empiler(res);
    }
}
/*
void Pile::mean(const unsigned int x){
    if(!pileVide()){
            Donnee* res;
            *res=0;
            for(unsigned int i=0; i<x; i++){
                *res=*res+(*tab[sommet-i]);
            }
            int taille=sommet+1;
            res=*res/taille;
            empiler(res);
    }
}
*/

void Pile::dup(){
    empiler(tab[sommet]);
}

void Pile::drop(){
    if(!pileVide()){
        depiler();
    }
}

