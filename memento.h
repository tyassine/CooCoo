#ifndef MEMENTO_H
#define MEMENTO_H

/*!
* \file memento.h
* \author Letellier/Yassine
* \brief Implementation du systeme de sauvegarde des etats de la pile pour annuler et retablir
*/





#include <QVector>
#include "donnee.h"

class Pile;
/*! \class gardien
* \brief Classe de gardien
* La classe permet de sauvegarder les etats d'une pile, dans le but de pouvoir les restaurer
* Partie du design pattern "Memento"
*
*
*/
class Gardien
{
    QVector<Pile*> tabPile; /*!< Vecteur de pointeur vers piles*/
    int current; /*!< Position de la Pile*/


public:
    /*!
 * \brief Constructeur
 *
 * Construit un gardien
 *
 */
    Gardien() : tabPile(QVector<Pile*>(200)), current(-1) {}
    /*!
  * \brief Destructeur
  *
  *
  */
    ~Gardien();
    /*!
* \brief addMemento
* Permet d'ajouter un etat dans le vecteur de pile
* \param pile: pile a ajouter
*/
    void addMemento(Pile* aPile);

    /*!
* \brief Undo
* Permet de restaurer l'etat precedent
* \return Pile a restaurer
*
*/
    Pile* undo();
    /*!
* \brief Redo
* Permet de restaurer l'etat suivant
* \return Pile a restaurer
*
*/
    Pile* redo();

};



#endif // MEMENTO_H
