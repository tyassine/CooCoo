#ifndef PILE_H
#define PILE_H

/*!
* \file pile.h
* \author Letellier/Yassine
*/

#include <QStack>
#include "memento.h"
#include "donnee.h"




class Pile: public QStack <Donnee *>
{
    unsigned int nbElement;/*!< Numéro de la case contenant le dernier élément ajouté*/
    //Gardien* gard;


public:
    Pile();
    ~Pile();

    Pile& cloner() const;
    void swap(unsigned int, unsigned int);
    void sum(unsigned int);
    void mean(unsigned int);
    void dup();
    void drop();

/*
    void setgardien(Gardien* g)
    {
        gard=g;
    }
    Gardien* getgardien()const
    {
        return gard;
    }*/

/*

    Memento *createMemento()
       {
           return new Memento(tab, sommet, nbMax);
       }

   void reinstateMemento(Memento *mem)
   {
       tab = mem->tabCur;
   }
*/
    // En profiter pour glisser un iterator? oui
};



#endif // PILE_H
