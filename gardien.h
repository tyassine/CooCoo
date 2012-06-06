#ifndef GARDIEN_H
#define GARDIEN_H


#include <QVector>
#include <QStack>
#include "type.h"

/*!
* \file gardien.h
* \author Letellier/Yassine
*/

/*! \class gardien
* \brief Classe representant un gardien
*/


class Pile;

class gardien
{
    int currentStack;/*!< Position de la Pile actuelle*/
    QVector <Pile> tabPile;/*!< Vector de pile*/

public:
    gardien();
    Pile* undo();
    Pile* redo();

    void addMemento(Pile pile);
};

#endif // GARDIEN_H
