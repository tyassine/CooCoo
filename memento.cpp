#include "memento.h"
#include "pile.h"
#include <iostream>

Gardien::~Gardien()
{
    for (int i=0; i<tabPile.size(); i++) delete tabPile[i];
}

void Gardien::addMemento(Pile* aPile)
{
    current++;
    tabPile[current] = aPile->cloner();
}

Pile* Gardien::undo()
{
    if(current > 0)
    {
        current--;
        return tabPile[current]->cloner();
    }
    return 0; // NULL
    // Gérer le cas de pile vide, ce qu'il doit renvoyer!
    // C'est la fonction appelante qui devra vérifier si elle n'obtient pas 0!
}

Pile* Gardien::redo()
{
    if (current < tabPile.size()-1)
    {
        // Probleme, il rentre quand-meme... size doit pas etre adapté, à revoir!
        current++;
        return tabPile[current]->cloner();
    }
    return 0;   // Idem qu'au dessus
}

/*
void Gardien::execute(Pile p){
    tabPile.append(p.clone);
    curPile++;

}

*/

