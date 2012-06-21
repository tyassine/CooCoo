#ifndef CONSTANTEEXP_H
#define CONSTANTEEXP_H

/*!
* \file constanteExp.h
* \brief Definition de la classe des constantes expression. Herite de la classe Donnee.
* \author Letellier/Yassine
*/

#include "donnee.h"

/**
 * \class     ConstanteExp
 * \author    Letellier/Yassine
 * \brief       Classe regroupant les Constantes Expressions
 *
 * \details    Les objets de cette classe travaillent autour d'une chaine de caractères.
 *              Celle-ci décrit une expression.
 */
class ConstanteExp : public Donnee
{
    QString chaine; /*!< Chaine de caractères représentant une expression */
public:
    /**
     * \brief       Constructeur de ConstanteExp à partir d'une chaîne de caractères.
     *
     * \param   aQString       Chaîne de caractères à recopier.
     * \return   Elle retourne la ConstanteExp construite.
     */
    ConstanteExp(const QString& aQString) : chaine(aQString) {}

    /**
     * \brief       Renvoie l'expression sous forme de chaine de caractères.
     *
     * \return   La chaine de caractères contenant l'expression est retournée.
     */
    virtual QString toQString() const {return chaine;}

    /*!
    * \brief Operateur +
    *
    * Implementation de l'operateur binaire + (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator+(Donnee* t);

    /*!
    * \brief Operateur /
    *
    * Implementation de l'operateur binaire / (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator/(Donnee * t);

    /*!
    * \brief Operateur *
    *
    * Implementation de l'operateur binaire * (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator*(Donnee * t);

    /*!
    * \brief Operateur -
    *
    * Implementation de l'operateur binaire - (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator-(Donnee * t);

    /*!
    * \brief puissance
    *
    * Implementation de l'operateur binaire puissance (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* puissance(Donnee* t);

    /*!
    * \brief mod
    *
    * Implementation de l'operateur binaire modulo (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mod(Donnee* t); 

    /*!
    * \brief Accesseur vers l'attribut chaine.
    *
    * \return Une QString recopiée depuis l'attribut chaine.
    *
    */
    QString getChaine()const{return chaine;}

    /**
     * \brief      Concatène l'opérateur unaire sign() avec l'expression.
     *
     * \return   Elle retourne le nouvel objet.
     */
    virtual ConstanteExp* sign();

    /*!
    * \brief mySin
    *
    * Implementation de l'operateur unaire sinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mySin(int typeAngle);

    /*!
    * \brief myCos
    *
    * Implementation de l'operateur unaire cosinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myCos(int typeAngle);

    /*!
    * \brief myTan
    *
    * Implementation de l'operateur unaire tangente (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myTan(int typeAngle);

    /*!
* \brief mySinh
*
* Implementation de l'operateur unaire sinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySinh(int typeAngle);

    /*!
* \brief myCosh
*
* Implementation de l'operateur unaire cosinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myCosh(int typeAngle);

    /*!
* \brief myTanh
*
* Implementation de l'operateur unaire tangenteh (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myTanh(int typeAngle);

    /*!
    * \brief myLn
    *
    * Implementation de l'operateur unaire ln (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLn();

    /*!
    * \brief myLog
    *
    * Implementation de l'operateur unaire log (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLog();

    /*!
* \brief myInv
*
* Implementation de l'operateur unaire inv (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myInv();

    /*!
* \brief mySqrt
*
* Implementation de l'operateur unaire sqrt (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqrt();

    /*!
* \brief mySqr
*
* Implementation de l'operateur unaire sqr (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqr();

    /*!
* \brief myCube
*
* Implementation de l'operateur unaire Cube (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myCube();

    /*!
* \brief myFact
*
* Implementation de l'operateur unaire fact (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myFact();


};

#endif // CONSTANTEEXP_H
