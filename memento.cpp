#include "memento.h"
#include "pile.h"

/*
Gardien::Gardien()
{
    curPile = -1;
}

void static Gardien::undo()
   {
    if(curPile > 0)
        {
         curPile -= 1;
         return &tabPile.at(curPile).clone();
        }
        return;
   }

void static Gardien::redo()
{
    if(curPile >= 0 && curPile < tabPile.size()-1)
        {
         curPile += 1;
         return &tabPile.at(curPile).clone();
        }
        return 0;
}

void Gardien::execute(Pile p){
    tabPile.append(p.clone);
    curPile++;

}

*/

