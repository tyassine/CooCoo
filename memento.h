#ifndef MEMENTO_H
#define MEMENTO_H


/*!
* \file memento.h
* \author Letellier/Yassine
*/

/*! \class gardien
* \brief Classe representant un gardien
*/

#include <QVector>
#include "donnee.h"
/*
class Pile;
class Memento
{

    public:
        Memento(Pile current);

    private:
        friend class Pile;
        Pile* current;

};

class Gardien
{
    protected:
        QVector <Pile> tabPile;
        int curPile;

    public:
        Gardien();
        static void undo();
        static void redo();
        virtual void execute();

};

*/

#endif // MEMENTO_H
