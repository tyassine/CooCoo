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
    QString infos;/*!< Description de l'exception*/

public:
    /*!
    * \brief Constructeur
    *
    * Construit une exception a partir d'une chaine de caractere
    *
    */
    ExceptionCooCoo(QString s="") : infos(s){}
    /*!
    * \brief GetInfos
    *
    * Permet d'en savoir plus sur la cause de l'erreur
    */
    void GetInfos() const {std::cout<<infos.toStdString()<<std::endl;}

};

#endif // EXCEPTIONCOOCOO_H
