#include "pile.h"

// Initialisation du membre statique du singleton
Pile* Pile::instance = 0;

Pile::~Pile()
{
    for(unsigned int i=0; i<=sommet; ++i)
        delete tab[i];
    delete[] tab;
}


Pile& Pile::getInstance()
{
    if (!instance) instance = new Pile;
    return *instance;
}

void Pile::libereInstance()
{
    if (instance) delete instance;
}

void Pile::push(Donnee* aDonnee)
{
    if ( pilePleine() )
    {
        nbMax += 10;
        Donnee** newtab = new Donnee*[nbMax];
        for (unsigned int i=0; i<=sommet; i++) newtab[i] = tab[i];

        delete[] tab;
        tab = newtab;
    }
    tab[sommet] = aDonnee;
    sommet++;
}

Donnee* Pile::pop()
{
    if (!pileVide())
    {
        sommet--;
        return tab[sommet+1];
    }
    // Sinon, glisser une exception?
}


bool Pile::pileVide()
{
    return(sommet==-1);
}

bool Pile::pilePleine()
{
    return(sommet==nbMax-1);
}

void Pile::viderPile(){
    if(!pileVide()){
        for(unsigned int i=0; i<=sommet; ++i)
            delete tab[i];
        sommet=-1;
    }
}
