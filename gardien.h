#ifndef GARDIEN_H
#define GARDIEN_H


#include <QVector>
#include <QStack>
#include "type.h"

/*!
* \file gardien.h
* \author Le Feurmou/Leleu
*/

/*! \class gardien
* \brief Classe representant un gardien
*
* La classe permet de sauvegarder les etats d'une pile, dans le but de pouvoir les restaurer
* Partie du design pattern "Memento"
*
*
*/


class Pile;

class gardien
{
    int currentStack;/*!< Position de la Pile actuelle*/
    QVector <Pile> tabPile;/*!< Vector de pile*/

public:
    /*!
* \brief Constructeur
*
* Construit un gardien
*
*/
    gardien();

    /*!
* \brief Undo
* Permet de restaurer l'etat precedent
* \return Pile suivante
*
*/
    Pile* undo();




    /*!
* \brief Redo
* Permet de restaurer l'etat suivant
* \return Pile suivante
*
*/
    Pile* redo();

    /*!
* \brief addMemento
* Permet d'ajouter un etat dans le vecteur de pile
* \param pile: pile a ajouter
*/
    void addMemento(Pile pile);
};

#endif // GARDIEN_H
