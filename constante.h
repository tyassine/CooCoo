#ifndef CONSTANTE_H
#define CONSTANTE_H

/*!
* \file constante.h
* \author Letellier/Yassine
*/


#include "donnee.h"


/**
 * \class     Constante
 * \author    Letellier/Yassine
 * \brief       Classe representant les types de constantes non complexes. Il s'agit d'une classe abstraite dérivant de Donnee.
 *
 *
 *
 */
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
    * Méthode virtuelle pure
    *
    */
    virtual Constante* sign()=0;
};

#endif // CONSTANTE_H
