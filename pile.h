
#ifndef PILE_H
#define PILE_H


/**
 * \file       pile.h
 * \author	 Letellier/Yassine
 * \brief      Fichier contenant la définition de la clase pile
 */

//#include <QStack>


#include "donnee.h"
class Gardien;


/**
 * \class     Pile
 * \brief      C'est une simple Implémentation de std::stack<Donnee *> 
 *
 * \details    La fonction stack n'a pas été utilisée car des fonctions vitales n'auraient pu etre implémentées.
 */
class Pile//: public QStack<Donnee*>
{
    Donnee** tab; /*!< Tableau de pointeurs sur Donnee, contient les objets de la pile */
    int sommet;/*!< Numéro de la case contenant le dernier élément ajouté*/
    int nbMax;/*!< Taille maximale du tableau */
    Gardien* gard; /*!< Pointeur de Gardien permettant d'assurer undo/redo */
    // Attention, vérifier que le gardien soit sauvegardé quand on quitte/relance le programme
    // Ou alors qu'on lui en refasse un nouveau!


public:

/**
 * \brief       Constructeur de pile à partir d'un unsigned int
 *
 * \param   n       Il s'agit de la taille maximale voulue pour la pile
 * \return   Elle retourne la pile construite.
 */
    Pile(unsigned int n=100);

/**
 * \brief       Constructeur de recopie de piler
 *
 * \param   p     Une réf de pile depuis laquelle recopiait la nouvelle pile.
 * \return   Elle retourne la pile construite.
 */
    Pile(const Pile& p);
	
/**
 * \brief        Desctruteur de pile qui desalloue toute la mémoire

 */
    ~Pile();
	
/**
 * \brief       Accesseur nombre d'objet dans pile.
 *
 * \return   Retourne le nombre d'objet dans la pile
 */
    int size() {return sommet+1;}
	
/**
 * \brief       Accesseur sur le tableau de donnée
 *
 * \return   Retourne le tableau de donnée de la pile
 */
    Donnee** getTab() const {return tab;}
	

/**
 * \brief       Accesseur sur sommet de la pile
 *
 * \return   Retourne l'indice du sommet de pile
 */
    int getSommet() const {return sommet;}
	
/**
 * \brief       Modificateur du gardien de la pile
 *
 * \param    aGardien  Le gardien que l'on veux assigner à la pile
 */
    void setGardien(Gardien* aGardien) {gard = aGardien;}
	
/**
 * \brief       Accesseur sur le gardien de la pile
 *
 * \return   Retourne le gardien de la pile
 */
    Gardien* getGardien() const {return gard;}


    /**
    * \fn void empiler(Donnee* aDonnee);
    * \brief Fonction : Empiler un objet sur la pile
    *
    * \param aDonnee pointeur vers l'objet à empiler
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
    bool pileVide() const;

    /**
    * \fn bool pilePleine()
    * \brief Fonction : Tester si la pile est pleine
    *
    * \return true si la pile est pleine et false si la pile est non-pleine
    */
    bool pilePleine() const;

    /**
    * \fn void clear()
    * \brief Fonction : Vider la pile
    */
    void clear();
/**
 * \brief       Méhode permettant de cloner la pile
 *
 * \return   Retourne le clone de this.
 */
    Pile* cloner() const;
	
/**
 * \brief       Echange de deux éléments de la pile
 *
 * \param nb1   Place dans tab du premier élément
  * \param nb2   Place dans tab du deuxiéme élément
 */
    void swap(int nb1,int nb2);
	
	
/**
 * \brief       effectue la somme des donnee de la pile sur n étage et empile le résultat.
 *
 * \param nb   Le nombre d'étage qu'il faudra sommer.
 */
    void sum(unsigned int nb);
	
	
/**
 * \brief       effectue la moyenne des donnee de la pile sur n étage et empile le résultat.
 *
 * \param nb   Le nombre d'étage qu'il faudra moyenner.
 */
    void mean(unsigned int nb);
	
/**
 * \brief       Duplique le sommet de la pile.
 *
 */
    void dup();
	
	
/**
 * \brief       Supprime le sommet de la pile.
 *
 */
    void drop();
};



#endif // PILE_H
