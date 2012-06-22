
#ifndef RATIONNEL_H
#define RATIONNEL_H

/**
 * \file       rationnel.h
 * \author    Letellier/Yassine
 * \brief      Fichier contenant la définition de la classe rationnel
 */

#include "constante.h"

class Entier;
class Reel;
class Complexe;

/**
 * \class     Rationnel
 * \author    Letellier/Yassine
 * \brief       Classe des rationnels héritant de Constante
 *
 * \details    Pour fonctionner cette classe encapsule deux entiers (numérateur et dénominateur).
 *				Tout les opérateurs sont égalements redéfinis.
 */
class Rationnel : public Constante
{
    int num;   /*!< Numérateur du rationnel */
    int denom; /*!< Dénominateur du rationnel */
    // On aurait pu mettre des objets Entier mais ça devient vraiment trop lourd...
public:

    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */

/**
 * \brief       Constructeur de rationnel à partir de 2 constantes
 * \details   Les deux paramètres sont évalués pour pouvoir obtenir un entier.
 *
 * \param   aInt1        Premier paramètre = numérateur
 * \param    aInt2         deuxiéme paramètre = dénominateur.
 * \return   Elle retourne le rationnel construit.
 */
    Rationnel(int aInt1 =0, int aInt2 =1) : num(aInt1), denom(aInt2) {simplifier();}
	
/**
 * \brief       Constructeur de rationnel à partir d'une QString
 * \details   Le QString est splité  au niveau du / puis les valeurs séparé donne le numérateur et le dénominateur.
 *
 * \param   s        Une Qstring de la forme '\\d+/\\d+'
 * \return   Elle retourne le rationnel construit.
 */
    Rationnel(const QString& s);
/**
 * \brief       Constructeur de recopie
 *
 * \param   aRationnel       Un pointeur vers un autre rationnel
 * \return   Elle retourne le rationnel construit.
 */
    Rationnel(const Rationnel* aRationnel) : num(aRationnel->num), denom(aRationnel->denom) {}
	
	
/**
 * \brief       Constructeur de rationnel à partir d'entier
 * \details   Le rationnel construit aura la forme aEntier/1
 *
 * \param   aEntier       Un entier
 * \return   Elle retourne le rationnel construit.
 */
    Rationnel(const Entier* aEntier);
	
/**
 * \brief       Constructeur de rationnel à partir d'entier
 * \details   Le rationnel construit aura la forme aReel/1
 *
 * \param   aReel       Un reel
 * \return   Elle retourne le rationnel construit.
 */
    Rationnel(const Reel* aReel);
/**
 * \brief       Constructeur de rationnel à partir d'entier
 * \details   Le rationnel construit aura la forme aComplexe/1
 *
 * \param   aComplexe       Un complexe
 * \return   Elle retourne le rationnel construit.
 */
    Rationnel(const Complexe* aComplexe);

/**
 * \brief     Méthode permettant d'obtenir l'objet sous la forme d'une Qstring
 *
 * \return   Elle retourne un Qstring tel qu'un rationnel puisse etre construit à partir de ça.
 */
    QString toQString() const;
	
	
/**
 * \brief      Retourne un Rationnel ayant les meme valeur mais avec le sign inversé
 * \details   Pour fonctionner, elle utilise le constructeur Rationnel(Constante *,Constante *)
 *
 * \return   Elle retourne le rationnel construit (=-this).
 */
    Rationnel* sign(){
        Rationnel* res=new Rationnel(-num,denom);
        return res;
    }
	
	
/**
 * \brief      Acccesseur au numérateur
 *
 * \return   Elle retourne le numérateu du rationnel
 */
    int getNum() const {return num;}
	
	
/**
 * \brief      Acccesseur au dénominateur
 *
 * \return   Elle retourne le dénominateur du rationnel
 */
    int getDenom() const {return denom;}
	
	
/**
 * \brief      Modificateur du numérateur
 *
 * \param  aNum Le nouveau numérateu du rationnel
 */
    void setNum(int aNum) {num = aNum;}
	
	
/**
 * \brief      Modificateur du dénominateur
 *
 * \param   adenom   Le nouveau dénominateur du rationnel
 */
    void setDenom(int adenom) {denom = adenom;}

	
	/**
 * \brief       Calcul du pgcd entre 2 nombre
 * \details  Méthode utilisé pour simplifier une fraction
 *
 * \param   a       Le premier entier
 * \param   b		Le deuxiéme entier
 * \return   Elle retourne le pgcd entre a et b
 */
    int pgcd(int a, int b) const;
	

/**
 * \brief       simplifie this pour que num et denum soit premier entre eux.
 * \details  Cette méthode utilise pgcd() pour déterminer comment simplifier this

 */
    void simplifier();
    /*!
    * \brief Operateur +
    *
    * Implementation de l'opérateur binaire + (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator+(Donnee * t);

    /*!
    * \brief Operateur /
    *
    * Implementation de l'opérateur binaire / (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator/(Donnee * t);
    /*!
    * \brief Operateur *
    *
    * Implementation de l'opérateur binaire * (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator*(Donnee * t);
    /*!
    * \brief Operateur -
    *
    * Implementation de l'opérateur binaire - (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator-(Donnee * t);
    /*!
    * \brief puissance
    *
    * Implementation de l'opérateur binaire puissance (methode virtuelle dans la classe mere)
    * \param t: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* puissance(Donnee* t);
    /*!
    * \brief mod
    *
    * Implementation de l'opérateur binaire modulo (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* mod(Donnee* t)
    {throw ExceptionCooCoo("Pas de calcul de mod avec un rationnel : non géré.");}


    /*!
    * \brief mySin
    *
    * Implementation de l'opérateur unaire sinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* mySin(int typeAngle);

    /*!
    * \brief myCos
    *
    * Implementation de l'opérateur unaire cosinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* myCos(int typeAngle);

    /*!
    * \brief myTan
    *
    * Implementation de l'opérateur unaire tangente (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* myTan(int typeAngle);

    /*!
* \brief mySinh
*
* Implementation de l'opérateur unaire sinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* mySinh(int typeAngle);

    /*!
* \brief myCosh
*
* Implementation de l'opérateur unaire cosinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myCosh(int typeAngle);


    /*!
* \brief myTanh
*
* Implementation de l'opérateur unaire tangenteh (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myTanh(int typeAngle);


    /*!
    * \brief myLn
    *
    * Implementation de l'opérateur unaire ln (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* myLn();

    /*!
* \brief myLog
*
* Implementation de l'opérateur unaire log (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myLog();

    /*!
* \brief myInv
*
* Implementation de l'opérateur unaire inv (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myInv();

    /*!
* \brief mySqrt
*
* Implementation de l'opérateur unaire sqrt (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* mySqrt();

    /*!
* \brief mySqr
*
* Implementation de l'opérateur unaire sqr (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* mySqr();

    /*!
* \brief myCube
*
* Implementation de l'opérateur unaire Cube (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myCube();

    /*!
* \brief myFact
*
* Implementation de l'opérateur unaire fact (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myFact()
    {throw ExceptionCooCoo("Pas de calcul de fact avec un rationnel : non géré.");}
    /*!
* \brief isZero
*
* Mathode permettant de savoir si la Donnee est egale à 0
* \return bool true si la Donnee est egale à 0
*
*/
    bool isZero(){
        return(num==0);
    }
    /*!
* \brief isNeg
*
* Mathode permettant de savoir si la Donnee est inferieure ou egale à 0
* \return bool true si la Donnee est inferieur ou egale à 0
*
*/
    bool isNeg(){
        return((num<=0&&denom>0)||(num>0&&denom<0));
    }

};

#endif // RATIONNEL_H

