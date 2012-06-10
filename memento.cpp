#include "memento.h"
#include "pile.h"

Gardien::Gardien()
{

}

static void Gardien::undo()
   {
       if (numGardien == 0)
       {
           throw ExceptionCooCoo("Vous ne pouvez pas Annuler d'avantage");
           return ;
       }
       gardienList[numGardien - 1]->receiver->reinstateMemento(mementoList[numGardien - 1]);
       numGardien--;
   }

void static Gardien::redo()
{
   if (numGardien > highWater)
   {
       throw ExceptionCooCoo("Vous ne pouvez pas Retablir d'avantage");
       return ;
   }
   (gardienList[numGardien]->receiver->*(gardienList[numGardien]->action))();
   numGardien++;
}


/*



void gardien::addMemento(Pile pile){
*/
