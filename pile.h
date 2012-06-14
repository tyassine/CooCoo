#ifndef PILE_H
#define PILE_H

/*!
* \file pile.h
* \author Letellier/Yassine
*/

#include "memento.h"
#include "donnee.h"




class Pile
{
    Donnee** tab; /*!< Tableau de pointeurs sur Donnee, contient les objets de la pile */
    unsigned int sommet;/*!< Numéro de la case contenant le dernier élément ajouté*/
    unsigned int nbMax;/*!< Taille maximale du tableau */
    //Gardien* gard;


public:
    Pile(unsigned int n=100) : sommet(-1), nbMax(n), tab(new Donnee*[n]) {}
    Pile(const Pile& p) : sommet(p.sommet), nbMax(p.nbMax), tab(new Donnee*[p.nbMax])
        {for (unsigned int i=0; i<p.nbMax; i++) tab[i] = p.tab[i]; }
    ~Pile();

    Donnee** getTab() const {return tab;}
    int getSommet() const {return sommet;}

    /**
    * \fn void empiler(Donnee* aDonnee);
    * \brief Fonction : Empiler un objet sur la pile
    *
    * \param pointeur vers l'objet à empiler
    */

    void empiler(Donnee* aDonnee);

    /**
    * \fn Donnee* depiler()
    * \brief Fonction : Dépiler la pile et renvoyer l'objet dépilé
    *
    * \return pointeur vers l'objet dépilé
    */
    Donnee* depiler();

    /**
    * \fn bool pileVide()
    * \brief Fonction : Tester si la pile est vide
    *
    * \return true si la pile est vide et false si la pile est non-vide
    */
    bool pileVide();

    /**
    * \fn bool pilePleine()
    * \brief Fonction : Tester si la pile est pleine
    *
    * \return true si la pile est pleine et false si la pile est non-pleine
    */
    bool pilePleine();

    /**
    * \fn void clear()
    * \brief Fonction : Vider la pile
    */
    void clear();

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
