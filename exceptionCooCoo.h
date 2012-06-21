#ifndef EXCEPTIONCOOCOO_H
#define EXCEPTIONCOOCOO_H

/*!
* \file exceptionCooCoo.h
* \author Letellier/Yassine
* \brief Gestion d'exceptions
*/



#include <QString>
#include <iostream>
#include <exception>

using namespace std;


/*! \class ExceptionCooCoo
* \brief Classe d'exception
*
* Derive de std::exception
*
*
*/
class ExceptionCooCoo :public exception
{
    std::string infos;/*!< Description de l'exception*/

public:
    /*!
    * \brief Constructeur
    *
    * Construit une exception a partir d'une chaine de caracteres
    *
    */
    ExceptionCooCoo(const char * s="") : infos(s){}
    /*!
    * \brief GetInfos
    *
    * Permet d'en savoir plus sur la cause de l'erreur
    */
    const char* GetInfos() const throw(){return infos.c_str();}
    /*!
* \brief Destructeur
*
*
*/
    ~ExceptionCooCoo() throw(){}

};

#endif // EXCEPTIONCOOCOO_H
