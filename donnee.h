#ifndef DONNEE_H
#define DONNEE_H

/*!
* \file donnee.h
* \author Letellier/Yassine
*/

#include <QString>
#include <QRegExp>
#include "exceptionCooCoo.h"

using namespace std;

// ABSTRAITE

class Donnee
{
public:

    /**
     * \brief       Constructeur sans arguments de Donnee
     */
    Donnee() {}

    /**
     * \brief      Méthode permettant d'obtenir l'objet sous la forme d'une QString
     * \return   Elle retourne un Qstring tel qu'un entier puisse etre construit à partir de ça, ou affiché.
     */
    virtual QString toQString() const = 0; // Méthode virtuelle pure, redéfinie à chaque fois, permet la conversion de la valeur en QString


    /*!
    * \brief Operateur +
    *
    * Méthode virtuelle pure pour l'opérateur binaire +
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual Donnee* operator+(Donnee * t)=0;

    /*!
    * \brief Operateur /
    *
    * Méthode virtuelle pure pour l'opérateur binaire /
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual Donnee* operator/(Donnee * t)=0;

    /*!
    * \brief Operateur *
    *
    * Méthode virtuelle pure pour l'opérateur binaire *
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual Donnee* operator*(Donnee * t)=0;

    /*!
    * \brief Operateur -
    *
    * Méthode virtuelle pure pour l'opérateur binaire -
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual Donnee* operator-(Donnee * t)=0;

    /*!
    * \brief puissance
    *
    * Méthode virtuelle pure pour l'opérateur binaire puissance
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* puissance(Donnee* t)=0;

    /*!
    * \brief mod
    *
    * Méthode virtuelle pure pour l'opérateur binaire modulo
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mod(Donnee* t)=0;

    /**
     * \brief      Retourne une Donnee ayant les memes valeurs mais avec le signe inversé
     * \return   Elle retourne le rationnel construit (=-this).
     */
    virtual Donnee* sign()=0;

    /*!
    * \brief mySin
    *
    * Méthode virtuelle pure pour l'opérateur unaire sinus
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mySin(int typeAngle)=0;

    /*!
    * \brief myCos
    *
    * Méthode virtuelle pure pour l'opérateur unaire cosinus
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myCos(int typeAngle)=0;

    /*!
    * \brief myTan
    *
    * Méthode virtuelle pure pour l'opérateur unaire tangente
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myTan(int typeAngle)=0;

    /*!
* \brief mySinh
*
* Méthode virtuelle pure pour de l'opérateur unaire sinush
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySinh(int typeAngle)=0;

    /*!
    * \brief myCosh
    *
    * Méthode virtuelle pure pour l'opérateur unaire cosinush
        * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
        * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myCosh(int typeAngle)=0;

    /*!
* \brief myTanh
*
* Méthode virtuelle pure pour l'opérateur unaire tangenteh
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myTanh(int typeAngle)=0;

    /*!
    * \brief myLn
    *
    * Méthode virtuelle pure pour l'opérateur unaire ln
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLn()=0;

    /*!
    * \brief myLog
    *
    * Méthode virtuelle pure pour l'opérateur unaire log
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLog()=0;

    /*!
* \brief myInv
*
* Méthode virtuelle pure pour l'opérateur unaire inv
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myInv()=0;

    /*!
* \brief mySqrt
*
* Méthode virtuelle pure pour l'opérateur unaire sqrt
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqrt()=0;

    /*!
* \brief mySqr
*
* Méthode virtuelle pure pour l'opérateur unaire sqr
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqr()=0;

    /*!
* \brief myCube
*
* Méthode virtuelle pure pour l'opérateur unaire Cube
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myCube()=0;

    /*!
* \brief myFact
*
* Méthode virtuelle pure pour l'opérateur unaire fact
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myFact()=0;




    /*!
 * \brief isEntier
 * Methode statique permettant de determiner le type avec Qregexp
 * \param Qstring s, chaine de caractere source
 * \return true si la chaine est construite comme un entier
 */
    static bool isEntier(const QString& s){
        QRegExp rx("^-?\\d+$");
        return s.contains (rx);
    }

    /*!
* \brief isReel
* Methode statique permettant de determiner le type
* \param Qstring s, chaine de caractere source
* \return true si la chaine est construite comme  un reel
*/
    static bool isReel(const QString& s){
        QRegExp rx("^-?\\d*\\.?\\d*$");
        return s.contains(rx);}


    /*!
 * \brief isRationnel
 * Methode statique permettant de determiner le type (Utiisation de regexp)
 * \param Qstring s, chaine de caractere source
 * \return true si la chaine ressemble a un rationnel,
 * false sinon
 */
    static bool isRationnel(const QString& s){
        QRegExp rx("^-?\\d*/-?\\d*$");
        return s.contains (rx);
    }


    /*!
* \brief isExpression
* Methode statique permettant de determiner le type
* \param Qstring s, chaine de caractere source
* \return true si la chaine ressemble a une expression
*/
    static bool isExpression(const QString& s){
        return s.count("'")==2;
    }

    /*!
* \brief isComplexe
* Methode statique permettant de determiner le type
* \param Qstring s, chaine de caractere source
* \return true si la chaine ressemble a un complexe,
* false sinon
*/
    static bool isComplexe(const QString& s){
        QRegExp rx("^-?\\d+((/|\\.)\\d+)?\\$-?\\d+((/|\\.)\\d+)?$");
        return s.contains (rx);
    }
    /*!
* \brief isZero
*
* Méthode permettant de savoir si la Donnee est egale à 0
* \return bool true si la Donnee est egale à 0
*
*/
    virtual bool isZero()=0;
    /*!
* \brief isNeg
*
* Méthode permettant de savoir si la Donnee est inferieure ou egale à 0
* \return bool true si la Donnee est inferieur ou egale à 0
*
*/
    virtual bool isNeg()=0;


};

#endif // DONNEE_H
