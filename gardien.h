#ifndef GARDIEN_H
#define GARDIEN_H


#include <QVector>
#include <QStack>

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

public:
    gardien();
    Pile* undo();
    Pile* redo();

    void addMemento(Pile pile);
};

#endif // GARDIEN_H
