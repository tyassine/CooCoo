#ifndef FABRIQUEDONNEE_H
#define FABRIQUEDONNEE_H

/*!
* \file fabriquedonne.h
* \author Letellier/Yassine
* \brief Fabriquation de Donnee à partir d'autres
* \details    Cette classe permet de fabriquer des donnee d'un type demande à partir de n'importe quel autre type
*                  selon les parametres donnees.
*/



#include "complexe.h"
#include "rationnel.h"
#include "reel.h"
#include "entier.h"
#include "constanteexp.h"
#include "exceptionCooCoo.h"
#include <QString>

/*!
* \class FabriqueDonnee
* \brief Classe fabrique de donnee
*
* \details La classe est un singleton, implementation du design pattern Factory
*/



class FabriqueDonnee
{
    static FabriqueDonnee* instance; /*!< Instance unique de la classe*/
    /*!
    * \brief Constructeur
    *
    * Constructeur (prive) de la classe FabriqueDonne
    *
    */
    FabriqueDonnee() {}
    /*!
    * \brief Constructeur par recopie
    *
    * Constructeur par recopie (prive) de la classe FabriqueDonnee
    * Non implemente pour le rendre inoperant
    * \param fd Instance à recopier
    */
    FabriqueDonnee(const FabriqueDonnee& fd) {}
    /*!
    * \brief Operateur =
    *
    * Operateur = (prive) de la classe FabriqueDonne
    * Non implemente pour le rendre inoperant
    * \param fd Instance à recopier
    */
    void operator=(const FabriqueDonnee& fd) {}
    /*!
    * \brief Destructeur
    *
    * Destructeur (prive) de la classe FabriqueDonnee
    *
    */
    ~FabriqueDonnee() {}

public:
    /*!
    * \brief getInstance
    * Methode retournant l'instance unique de la classe FabriqueDonne
    * \return Instance unique de la classe
    *
    */
    static FabriqueDonnee* getInstance();
    /*!
     * \brief libereInstance
     * Methode liberant l'instance unique de la classe
     *
     *
     */
    static void libereInstance();

    /*!
    * \brief creerDonnee
    * Methode permettant de creer une nouvelle Donnee, teste le type represente par la chaine et cree
    *       la Donnee correspondante en appellant le constructeur de son type
    * \param terme, chaine de caractere source
    * \return Pointeur sur Donnee, nouvelle Donnee cree
    */
    Donnee* creerDonnee(const QString& terme);

    /*!
    * \brief creerDonnee
    * Methode surchargée permettant de convertir des objets d'une classe fille de Donnee en une autre
    * \param donneeDepart pointeur const de Donnee, la donnée que l'on veut convertir
    * \param typeSouhaite entier indiquant le type de retour souhaité (0=reel, 1=rationnel, 2=reel)
    * \param complexe entier indiquant si le retour doit être complexe ou non
    * \return Pointeur sur Donnee, nouvelle Donnee cree
    */
    Donnee* creerDonnee(const Donnee* donneeDepart, int typeSouhaite, int complexe);

private:
    /*!
    * \brief creerDonneeStatic
    * Methode privee appellee par creerDonnee, le type de donneeDepart est connu, on appelle le constructeur correspondant au type souhaite
    * \param donneeDepart pointeur const de Donnee, la donnée que l'on veut convertir, T est une classe fille de Donnee
    * \param typeSouhaite entier indiquant le type de retour souhaité (0=reel, 1=rationnel, 2=reel)
    * \param complexe entier indiquant si le retour doit être complexe ou non
    * \return Pointeur sur Donnee, nouvelle Donnee cree
    */

    template<typename T>
    inline Donnee* creerDonneeStatic(const T* donneeDepart, int typeSouhaite, int complexe) {
        Donnee* d;
        if (complexe==0){
            if (typeSouhaite == 0){
                d=new Entier(donneeDepart);
            }
            if (typeSouhaite == 2){
                d=new Reel(donneeDepart);
            }
            if (typeSouhaite == 1){
                d=new Rationnel(donneeDepart);
            }
        }
        else
            d= new Complexe(donneeDepart, typeSouhaite);

        return d;
    }


};


#endif // FABRIQUEDONNEE_H
