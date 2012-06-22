#ifndef ENTIER_H
#define ENTIER_H



/**
 * \file       entier.h
 * \author    Letellier/Yassine
 * \brief      Fichier contenant la définition de la clase entier
 */

#include "constante.h"

class Reel;
class Rationnel;
class Complexe;
/**
 * \class     Entier
 * \brief       Classe des rationnels héritant de Constante
 *
 * \details    Pour fonctionner cette classe encapsule un entier.
 *				Tout les opérateurs sont égalements redéfinit.
 */
class Entier : public Constante
{
    int valeur; /*!< valeur de l'entier */
public:

    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */

    /**
     * \brief       Constructeur d'entier à partir d'un int
     * \details   Constructeur par valeur
     *
     * \param   val        pour initialiser la valeur
     */
    Entier(int val=0) : valeur(val) {}
    /**
     * \brief       Constructeur d'entier à partir d'une QString
     *
     */
    Entier(const QString& aQString ="0") : valeur(aQString.toInt()) {}
    /**
     * \brief       Constructeur de recopie
     *
     * \param   aEntier       Un pointeur vers un autre entier
     */
    Entier(const Entier* aEntier) : valeur(aEntier->valeur) {}
    /**
     * \brief       Constructeur d'entier à partir de reel
     * \details   On effectue un cast en ajoutant + 0,5 pour avoir un arrondi et non une troncature
     *
     * \param   aReel pointeur sur le reel qui sert de modele à la construction
     */
    Entier(const Reel* aReel);
    /**
     * \brief       Constructeur d'entier à partir de rationnel
     *
     * \param   aReel pointeur sur le rationnel qui sert de modele à la construction
     */
    Entier(const Rationnel* aRationnel);
    /**
     * \brief       Constructeur d'entier à partir de complexe
     *
     * \param   aReel pointeur sur le complexe qui sert de modele à la construction
     */
    Entier(const Complexe* aComplexe);

    /**
     * \brief     Méthode permettant d'obtenir l'objet sous la forme d'une Qstring
     *
     * \return   Elle retourne un Qstring tel qu'un entier puisse etre construit à partir de ça, ou affiché.
     */
    virtual QString toQString() const;
    /**
     * \brief      Retourne un Entier ayant les memes valeurs mais avec le signe inversé
     * \details   Pour fonctionner, elle utilise le constructeur Entier par valeur
     *
     * \return   Elle retourne le rationnel construit (=-this).
     */
    Entier* sign(){
        Entier* res=new Entier(-valeur);
        return res;}
    /**
     * \brief      Acccesseur à la valeur
     *
     * \return   Elle retourne la valeur de l'Entier
     */
    int getValeur() const {return valeur;}
    /**
     * \brief      Modificateur de valeur
     *
     * \param  aValeur La nouvelle valeur de l'entier
     */
    void setValeur(int aValeur) {valeur = aValeur;}

    /*!
    * \brief Operateur +
    *
    * Implementation de l'opérateur binaire + (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator+(Donnee* t);

    /*!
    * \brief Operateur /
    *
    * Implementation de l'opérateur binaire / (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator /(Donnee* t);

    /*!
    * \brief Operateur *
    *
    * Implementation de l'opérateur binaire * (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator*(Donnee* t);

        /*!
    * \brief Operateur -
    *
    * Implementation de l'opérateur binaire - (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator-(Donnee* t);

    int facto(int n);


    /*!
    * \brief puissance
    *
    * Implementation de l'opérateur binaire puissance (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* puissance(Donnee* t);

    /*!
    * \brief mod
    *
    * Implementation de l'opérateur binaire modulo (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mod(Donnee* t);

    /*!
    * \brief mySin
    *
    * Implementation de l'opérateur unaire sinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mySin(int typeAngle);

    /*!
    * \brief myCos
    *
    * Implementation de l'opérateur unaire cosinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myCos(int typeAngle);

    /*!
    * \brief myTan
    *
    * Implementation de l'opérateur unaire tangente (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myTan(int typeAngle);

    /*!
* \brief mySinh
*
* Implementation de l'opérateur unaire sinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySinh(int typeAngle);
    /*!
    * \brief myCosh
    *
    * Implementation de l'opérateur unaire cosinush (methode virtuelle dans la classe mere)
        * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
        * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myCosh(int typeAngle);

    /*!
* \brief myTanh
*
* Implementation de l'opérateur unaire tangenteh (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myTanh(int typeAngle);

    /*!
    * \brief myLn
    *
    * Implementation de l'opérateur unaire ln (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLn();


    /*!
    * \brief myLog
    *
    * Implementation de l'opérateur unaire log (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLog();

    /*!
* \brief myInv
*
* Implementation de l'opérateur unaire inv (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myInv();

    /*!
* \brief mySqrt
*
* Implementation de l'opérateur unaire sqrt (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqrt();

    /*!
* \brief mySqr
*
* Implementation de l'opérateur unaire sqr (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqr();

    /*!
* \brief myCube
*
* Implementation de l'opérateur unaire Cube (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myCube();

    /*!
* \brief myFact
*
* Implementation de l'opérateur unaire fact (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myFact();
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

#endif // ENTIER_H
