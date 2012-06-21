
#ifndef RATIONNEL_H
#define RATIONNEL_H

/**
 * \file       rationnel.h
 * \author    Letellier/Yassine
 * \brief      Fichier contenant la définition de la clase rationnel
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
 * \details    Pour foncionner cette classe encapsule deux entiers (numérateur et dénominateur).
 *				Tout les opérateurs sont égalements redéfinit.
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
 * \details   Les deux paramétres sont évalué pour pouvoir obtenir un entier.
 *
 * \param   aInt1        Premier paramétre = numérateur
 * \param    aInt2         deuxiéme paramétre = dénominateur.
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
 * \details   Pour fonctionner, elle utilise le constructeut Rationnel(Constante *,Constante *)
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
    Donnee* puissance(Donnee* t);
    /*!
    * \brief mod
    *
    * Implementation de l'operateur binaire modulo (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* mod(Donnee* t)
    {throw ExceptionCooCoo("Pas de calcul de mod avec un rationnel : non géré.");}


    /*!
    * \brief mySin
    *
    * Implementation de l'operateur unaire sinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degre, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* mySin(int typeAngle);

    /*!
    * \brief myCos
    *
    * Implementation de l'operateur unaire cosinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degre, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* myCos(int typeAngle);
    /*!
    * \brief myTan
    *
    * Implementation de l'operateur unaire tangente (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degre, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    Donnee* myTan(int typeAngle);
    /*!
* \brief mySinh
*
* Implementation de l'operateur unaire sinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degre, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* mySinh(int typeAngle);
    /*!
* \brief myCosh
*
* Implementation de l'operateur unaire cosinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degre, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    Donnee* myCosh(int typeAngle);
    /*!
* \brief myTanh
*
* Implementation de l'operateur unaire tangenteh (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degre, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/

    /*!
    * \brief Ln
    *
    * Implementation de l'operateur unaire ln (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    //virtual Donnee* ln();
    /*!
* \brief Log
*
* Implementation de l'operateur unaire log (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    //virtual Donnee* log();
    /*!
* \brief Inv
*
* Implementation de l'operateur unaire inv (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    //virtual Donnee* inv();
    /*!
* \brief Sqrt
*
* Implementation de l'operateur unaire sqrt (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    //virtual Donnee* sqrt();

    /*!
* \brief Sqr
*
* Implementation de l'operateur unaire sqr (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    //virtual Donnee* sqr();
    /*!
* \brief Cube
*
* Implementation de l'operateur unaire Cube (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    //virtual Donnee* cube();
    /*!
* \brief Fact
*
* Implementation de l'operateur unaire fact (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    //virtual Donnee* fact();


};

#endif // RATIONNEL_H

