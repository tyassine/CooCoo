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
    Donnee() {}
    virtual QString toQString() const = 0; // Méthode virtuelle pure, redéfinie à chaque fois, permet la conversion de la valeur en QString


    virtual Donnee* operator+(Donnee * t)=0;

    virtual Donnee* operator/(Donnee * t)=0;
    virtual Donnee* operator*(Donnee * t)=0;
    virtual Donnee* operator-(Donnee * t)=0;

    virtual Donnee* puissance(Donnee* t)=0;
    virtual Donnee* mod(Donnee* t)=0;
    virtual Donnee* sign()=0;

    virtual Donnee* mySin(int typeAngle)=0;
    virtual Donnee* myCos(int typeAngle)=0;
    virtual Donnee* myTan(int typeAngle)=0;
    virtual Donnee* mySinh(int typeAngle)=0;
    virtual Donnee* myCosh(int typeAngle)=0;
    virtual Donnee* myTanh(int typeAngle)=0;

    virtual Donnee* myLn()=0;
    virtual Donnee* myLog()=0;
    virtual Donnee* myInv()=0;
    virtual Donnee* mySqrt()=0;
    virtual Donnee* mySqr()=0;
    virtual Donnee* myCube()=0;
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
* Mathode permettant de savoir si la Donnee est egale à 0
* \return bool true si la Donnee est egale à 0
*
*/
    virtual bool isZero()=0;
    /*!
* \brief isNeg
*
* Mathode permettant de savoir si la Donnee est inferieure ou egale à 0
* \return bool true si la Donnee est inferieur ou egale à 0
*
*/
    virtual bool isNeg()=0;


};

#endif // DONNEE_H
