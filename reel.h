#ifndef REEL_H
#define REEL_H

/**
 * \file       reel.h
 * \author    Letellier/Yassine
 * \brief      Fichier contenant la définition de la classe Reel
 */

#include "constante.h"

class Entier;
class Rationnel;
class Complexe;

/**
 * \class     Reel
 * \author    Letellier/Yassine
 * \brief       Classe des reels héritant de Constante
 *
 * \details    Pour fonctionner cette classe encapsule un double.
 *				Tout les opérateurs sont également redéfinis.
 */
class Reel : public Constante
{
    double valeur; /*!< Valeur du réel*/
public:
    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */
/**
 * \brief       Constructeur de reel à partir d'un double
 *
 * \param   val       Valeur d'initialisation de la valeur de this
 * \return   Elle retourne le reel construit.
 */
    Reel(double val=0) : valeur(val) {}
/**
 * \brief       Constructeur de reel à partir d'une Qstring
 *
 * \param   aQstring       Il s'agit d'un Qstring de la forme '\\d+((\\.|\) \\d+)?)
 * \return   Elle retourne le reel construit.
 */
    Reel(const QString& aQString = "0") : valeur(aQString.toDouble()) {}
	
	
	/**
 * \brief       Constructeur de recopie d'un reel
 *
 * \param   aReeel       Un pointeur vers un Reel
 * \return   Elle retourne le reel construit.
 */
    Reel(const Reel* aReel) : valeur(aReel->valeur) {}
	
	/**
 * \brief       Constructeur de reel à partir d'entier
 * \details   Le reel construit aura la forme aEntier
 *
 * \param   aEntier       Un entier
 * \return   Elle retourne le reel construit.
 */
    Reel(const Entier* aEntier);
	
	/**
 * \brief       Constructeur de reel à partir d'un rationnel
 * \details   Le reel construit aura la forme aReel/1
 *
 * \param   aRationnel       Un Rationnel
 * \return   Elle retourne le reel construit.
 */
    Reel(const Rationnel* aRationnel);
	
	
/**
 * \brief       Constructeur de reel à partir d'entier
 * \details   Le reel construit aura la forme aComplexe->getPRe()
 *
 * \param   aComplexe       Un complexe
 * \return   Elle retourne le reel construit.
 */
    Reel(const Complexe* aComplexe);

	
	/**
 * \brief     Méthode permettant d'obtenir l'objet sous la forme d'une Qstring
 *
 * \return   Elle retourne un Qstring tel qu'un reel puisse etre construit à partir de ça.
 */
    virtual QString toQString() const;

	
/**
 * \brief      Accesseur à la valeur du reel
 *
 * \return   Elle retourne la valeur de l'objet
 */
    double getValeur() const {return valeur;}
	
	
/**
 * \brief      Modificateur de la valeur du reel
 *
 * \param  aValeur		 La nouvelle valeur de this.
 */
    void setValeur(double aValeur) {valeur = aValeur;}
/**
 * \brief      Fonction permettant de calculer le nombre digit de this après la virgule.
 *
 * \return Elle retourne le nombre de de chiffre après la virgule.
 */
    int getTaille() const {
       return toQString().section('.', 1,1).size();
    }

	

/**
 * \brief      Retourne un reel ayant les meme valeur mais avec le sign inversé
 * \details   Pour fonctionner, elle utilise le constructeut Reel(double)
 *
 * \return   Elle retourne le reel construit (=-this).
 */
    Reel* sign(){
        Reel* res=new Reel(-valeur);
        return res;}
    /*!
    * \brief Operateur +
    *
    * Implementation de l'operateur binaire + (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator+(Donnee * t);
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
    virtual Donnee* mod(Donnee* t)
    {throw ExceptionCooCoo("Pas de calcul de mod avec un réel : non géré.");}

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
    virtual Donnee* myFact()
    {throw ExceptionCooCoo("Pas de calcul de fact avec un réel : non géré.");}
    /*!
* \brief isZero
*
* Mathode permettant de savoir si la Donnee est egale à 0
* \return bool true si la Donnee est egale à 0
*
*/
    bool isZero(){
        return(valeur==0);
    }
    /*!
* \brief isNeg
*
* Mathode permettant de savoir si la Donnee est inferieure ou egale à 0
* \return bool true si la Donnee est inferieur ou egale à 0
*
*/
    bool isNeg(){
        return(valeur<=0);
    }

};

#endif // REEL_H
