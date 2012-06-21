#ifndef CONSTANTE_H
#define CONSTANTE_H

/*!
* \file constante.h
* \author Letellier/Yassine
*/

/*! \class constante
* \brief Classe representant les types de constantes non complexes
*
* La classe derive de donnee
*
*
*/
#include "donnee.h"

// ABSTRAITE

class Constante : public Donnee
{
public:
    /*!
* \brief Constructeur
*
*/
    Constante();
    /*!
    * \brief sign
    * Methode virtuelle pure
    *
    */
    virtual Constante* sign()=0;
};

#endif // CONSTANTE_H
