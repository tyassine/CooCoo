#ifndef PILE_H
#define PILE_H

/*!
* \file pile.h
* \author Letellier/Yassine
*/

#include"memento.h"
#include "donnee.h"


// Design pattern Singleton

// Je préfère faire ma propre pile plutôt que de réutiliser QStack, ça évite de lire la doc et de prendre connaissance de la tonne d'attributs et méthodes... Et ça fait réviser les piles :p
// Et c'est plus sûr pour le Singleton


// on peut faire
//QStack<Donnee *> pile;
//avec un singleton plutot sur la classe du "groupe de piles" si on traite les onglets

class Pile
{
    static Pile* instance;
    Donnee** tab; /*!< Tableau de pointeurs sur Donnee, contient les objets de la pile */
    unsigned int sommet;/*!< Nombre d'éléments dans le tableau */
    unsigned int nbMax;/*!< Taille maximale du tableau */
    // unsigned int nbCur; /*!< Nombre d'éléments qui sont dans la pile */

    // Constructeurs et destructeur en private pour interdire leur utilisation
    /**
    * \fn Pile(unsigned int n=10)
    * \brief Fonction : Créer une nouvelle instance de l'objet Pile
    * \param n taille initiale de la pile, optionnel
    */
    Pile(unsigned int n=100) : sommet(-1), nbMax(n), tab(new Donnee*[n]) {}

    /**
    * \fn Pile(const Pile& p)
    * \brief Fonction : Créer une nouvelle instance de l'objet Pile à partir d'une autre instance passée en paramètre
    * \param p instance de pile à copier
    */

    Pile(const Pile& p);
    /**
    * \fn void operator=(const Pile& p)
    * \brief Fonction : copier une instance de l'objet Pile dans cette instance de l'objet Pile
    *
    * \param p instance de pile à copier
    */
    void operator=(const Pile& p);

    /**
    * \fn ~Pile()
    * \brief Fonction : destruction de l'objet pile
    */
    ~Pile();


public:
    static Pile& getInstance();
    static void libereInstance();
    /**
    * \fn void push(Donnee* aDonnee);
    * \brief Fonction : Empiler un objet sur la pile
    *
    * \param pointeur vers l'objet à empiler
    */
    void push(Donnee* aDonnee);

    /**
    * \fn Donnee* pop()
    * \brief Fonction : Dépiler la pile et renvoyer l'objet dépilé
    *
    * \return pointeur vers l'objet dépilé
    */
    Donnee* pop();

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
    * \fn void viderPile()
    * \brief Fonction : Vider la pile
    */
    void viderPile();

/*
    Memento *createMemento()
       {
           return new Memento(tab, sommet, nbMax);
       }

   void reinstateMemento(Memento *mem)
   {
       tab = mem->tabCur;
       sommet = mem->sommetCur;
       nbMax = mem->maxCur;
   }
*/
    // En profiter pour glisser un iterator? oui
};



#endif // PILE_H
