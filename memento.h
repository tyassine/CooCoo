#ifndef MEMENTO_H
#define MEMENTO_H


/*!
* \file memento.h
* \author Letellier/Yassine
*/

/*! \class gardien
* \brief Classe representant un gardien
*/

#include "donnee.h"

class Pile;

class Gardien
{
    protected:
        Pile *receiver;
        static Gardien *gardienList[20];
        static Memento *mementoList[20];
        static int numGardien;
        static int highWater;

    public:
        Gardien();
        static void undo();
        static void redo();

        void addMemento(Pile pile);

};


class Memento
{

    public:
        Memento(Donnee** tabCur, unsigned int sommetCur, unsigned int maxCur);

        void addMemento(Pile pile);
    private:
        friend class Pile;
        Donnee** tabCur; /*!< Tableau de pointeurs sur Donnee, contient les objets de la pile */
        unsigned int sommetCur;/*!< Nombre d'éléments dans le tableau */
        unsigned int maxCur;/*!< Taille maximale du tableau */

};

#endif // MEMENTO_H
