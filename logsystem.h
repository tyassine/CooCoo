#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QString>
#include <sstream>

/*!
* \file logsystem.h
* \author Letellier/Yassine
* \brief Gestion de messages log
* \details    Les classes permettent de creer des messages relatifs à l'execution de l'application
*               et de les afficher en console et dans un fichier relatif pour l'historique
*
*/


/*! \class LogMessage
* \brief Classe de message log pour garder une trace de l'execution
*
*/

class LogMessage
{
    QString log;/*!< Message à transmettre*/
    unsigned int imp;/*!< Degree d'importance du message*/

public:
    /*!
    * \brief Constructeur
    *
    * Constructeur de la classe LogMessage
    * \param const std::string&, chaine de caractere servant à l'initialisation de l'attribut log
    * \param unsigned int, entier servant à l'initialisation du degree du message imp
    */
    LogMessage(const std::string&,unsigned int);
    /*!
    * \brief getLog
    * Methode retournant le message formaté avec la chaine de caractère et le degré d'importance
    * \return la chaine de caractère concatenant les deux informations: importance et signalisation de l'action effectuee
    *
    */
    QString getLog()const{

        std::stringstream str;
        str<<"("<<imp<<")";
        return QString(str.str().c_str()+log);

        }
};

/*! \class LogSystem
* \brief Classe permettant la recuperation du message et son affichage dans la console ou son impression dans un fichier
*
*/
class LogSystem
{
public:
    /*!
    * \brief imprim
    * Methode static imprimant le message
    *
    */
    static void imprim(const LogMessage &);
};

#endif // LOGSYSTEM_H
