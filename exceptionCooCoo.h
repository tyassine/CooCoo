#ifndef EXCEPTIONCOOCOO_H
#define EXCEPTIONCOOCOO_H

/*!
* \file exceptionCooCoo.h
* \author Letellier/Yassine
*/

#include <QString>
#include <iostream>
#include <exception>

using namespace std;

class ExceptionCooCoo :public exception
{
    std::string infos;/*!< Description de l'exception*/

public:
    /*!
    * \brief Constructeur
    *
    * Construit une exception a partir d'une chaine de caractere
    *
    */
    ExceptionCooCoo(const char * s="") : infos(s){}
    /*!
    * \brief GetInfos
    *
    * Permet d'en savoir plus sur la cause de l'erreur
    */
    const char* GetInfos() const throw(){return infos.c_str();}
    ~ExceptionCooCoo() throw(){}

};

#endif // EXCEPTIONCOOCOO_H
