#include "pile.h"

// Initialisation du membre statique du singleton
Pile* Pile::instance = 0;

Pile::~Pile()
{
    // Faire suppression propre
}


Pile& Pile::getInstance()
{
    if (!instance) instance = new Pile(100);
    return *instance;
}

void Pile::libereInstance()
{
    if (instance) delete instance;
}

void Pile::push(Donnee* aDonnee)
{
    if ( (sommet+1) == nbMax )  // Pile pleine
    {
        Donnee** newtab = new Donnee*[nbMax+10];
        for (unsigned int i=0; i<sommet; i++) newtab[i] = tab[i];
        nbMax += 10;
        delete[] tab;
        tab = newtab;
    }
    sommet++;
    tab[sommet] = aDonnee;
}

Donnee* Pile::pop() const
{
    if (sommet != -1)   // La pile n'est pas vide
    {
        sommet--;
        return tab[sommet+1];
    }
    // Sinon, glisser une exception?
}
