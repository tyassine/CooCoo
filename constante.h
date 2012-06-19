#ifndef CONSTANTE_H
#define CONSTANTE_H

/*!
* \file constante.h
* \author Letellier/Yassine
*/

#include "donnee.h"

// ABSTRAITE

class Constante : public Donnee
{
public:
    Constante();

    /*virtual Donnee* operator+(Donnee& t)=0;

    virtual Donnee* operator/(Donnee & t)=0;
    virtual Donnee* operator*(Donnee & t)=0;
    virtual Donnee* operator-(Donnee & t)=0;*/
    virtual Constante* sign()=0;
};

#endif // CONSTANTE_H
