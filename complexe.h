#ifndef COMPLEXE_H
#define COMPLEXE_H

/*!
* \file complexe.h
* \author Letellier/Yassine
*/

#include "constante.h"
#include <sstream>

class Entier;
class Reel;
class Rationnel;

/**
 * \class     Complexe
 * \author    Letellier/Yassine
 * \brief       Classe modélisant les complexes. Elle hérite de Donnee.
 *
 * \details    Pour fonctionner cette classe encapsule deux Constantes : sa partie réelle et sa partie imaginaire.
 *				Tous les opérateurs sont égalements redéfinis.
 */
class Complexe : public Donnee
{
    Constante* pRe; /*!< Pointeur vers la constante contenant la partie réelle*/
    Constante* pIm; /*!< Pointeur vers la constante contenant la partie imaginaire*/
public:
    /**
     * \brief       Constructeur de Complexe à partir d'une Donnee initiale et selon un type souhaité
     *
     * \param   donneeDepart       Pointeur vers la Donnee contenant les valeurs nous intéressant
     * \param   typeSouhaite       Descripteur du type qui formatera les attributs de ce Complexe
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(const Donnee* donneeDepart, int typeSouhaite);

    /**
     * \brief       Constructeur de Complexe à partir de 2 pointeurs de Constantes
     *
     * \param   D1       Constante initialisant la partie réelle
     * \param   D2       Constante initialisant la partie imaginaire
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(Constante* D1=0, Constante* D2=0) : pRe(D1), pIm(D2) {}

    /**
     * \brief       Constructeur de Complexe à partir d'un pointeur vers Complexe
     *
     * \param   aComplexe       Pointeur vers un Complexe
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(const Complexe* aComplexe);

    /**
     * \brief       Constructeur de Complexe à partir d'un pointeur vers Entier
     *
     * \param   aEntier       Pointeur vers un Entier
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(const Entier* aEntier);

    /**
     * \brief       Constructeur de Complexe à partir d'un pointeur vers Reel
     *
     * \param   aReel      Pointeur vers un Reel
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(const Reel* aReel);

    /**
     * \brief       Constructeur de Complexe à partir d'un pointeur vers Rationnel
     *
     * \param   aRationnel       Pointeur vers un Rationnel
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(const Rationnel* aRationnel);

    /**
     * \brief       Constructeur de Complexe à partir d'une QString
     *
     * \param   s       QString de la forme reel$imaginaire
     * \return   Elle retourne le Complexe construit.
     */
    Complexe(const QString &s);

    /**
     * \brief       Destructeur
     *
     */
    ~Complexe() {delete pRe; delete pIm;}

    /**
 * \brief     Méthode permettant d'obtenir l'objet sous la forme d'une Qstring
 *
 * \return   Elle retourne une QString définissant et représentant le Complexe.
 */
    virtual QString toQString() const
    {
        QString res = pRe->toQString() + "$" + pIm->toQString();
        return res;
    }

    /**
     * \brief      Accesseur à la partie réelle
     *
     * \return   Retourne l'attribut-pointeur vers la partie réelle du Complexe.
     */
    Constante* getPRe() const {return pRe;}

    /**
     * \brief      Accesseur à la partie imaginaire
     *
     * \return   Retourne l'attribut-pointeur vers la partie imaginaire du Complexe.
     */
    Constante* getPIm() const {return pIm;}

    /**
     * \brief      Construit le conjugué du Complexe
     *
     * \return   Retourne un pointeur vers ce nouveau Complexe.
     */
    Donnee* conj();


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

    /**
     * \brief      Retourne un Complexe ayant les memes valeurs mais avec le signe inversé
     * \details   Pour fonctionner, elle utilise le constructeur Complexe(Constante*, Constante*)
     *
     * \return   Elle retourne le Complexe construit.
     */
    Complexe* sign(){
        Complexe* res=new Complexe(pRe->sign(),pIm->sign());
        return res;}

    /*!
    * \brief puissance
    *
    * Implementation de l'operateur binaire puissance (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* puissance(Donnee* t)
    {throw ExceptionCooCoo("Pas de calcul de puissance avec un complexe : non géré");}

    /*!
    * \brief mod
    *
    * Implementation de l'operateur binaire modulo (methode virtuelle dans la classe mere)
    * \param Donnee*: Pointeur sur une donnee
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mod(Donnee* t)
    {throw ExceptionCooCoo("Pas de calcul de mod avec un complexe : non géré.");}

    /*!
    * \brief mySin
    *
    * Implementation de l'operateur unaire sinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* mySin(int typeAngle)
    {throw ExceptionCooCoo("Pas de calcul de sin avec un complexe : non géré.");}

    /*!
    * \brief myCos
    *
    * Implementation de l'operateur unaire cosinus (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myCos(int typeAngle)
    {throw ExceptionCooCoo("Pas de calcul de cos avec un complexe : non géré.");}

    /*!
    * \brief myTan
    *
    * Implementation de l'operateur unaire tangente (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myTan(int typeAngle)
    {throw ExceptionCooCoo("Pas de calcul de tan avec un complexe : non géré.");}

    /*!
* \brief mySinh
*
* Implementation de l'operateur unaire sinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySinh(int typeAngle)
    {throw ExceptionCooCoo("Pas de calcul de sinh avec un complexe : non géré.");}

    /*!
* \brief myCosh
*
* Implementation de l'operateur unaire cosinush (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myCosh(int typeAngle)
    {throw ExceptionCooCoo("Pas de calcul de cosh avec un complexe : non géré.");}

    /*!
* \brief myTanh
*
* Implementation de l'operateur unaire tangenteh (methode virtuelle dans la classe mere)
    * \param typeAngle : entier, 0 si utilisation des degres, 1 si utilisation des radians
    * \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myTanh(int typeAngle)
    {throw ExceptionCooCoo("Pas de calcul de tanh avec un complexe : non géré.");}

    /*!
    * \brief myLn
    *
    * Implementation de l'operateur unaire ln (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLn()
    {throw ExceptionCooCoo("Pas de calcul de ln avec un complexe : non géré.");}

    /*!
    * \brief myLog
    *
    * Implementation de l'operateur unaire log (methode virtuelle dans la classe mere)
    * \return Pointeur sur donnee, resultat de l'operation
    *
    */
    virtual Donnee* myLog()
    {throw ExceptionCooCoo("Pas de calcul de log avec un complexe : non géré.");}

    /*!
* \brief myInv
*
* Implementation de l'operateur unaire inv (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* myInv()
    {throw ExceptionCooCoo("Pas de calcul de inv avec un complexe : non géré.");}

    /*!
* \brief mySqrt
*
* Implementation de l'operateur unaire sqrt (methode virtuelle dans la classe mere)
* \return Pointeur sur donnee, resultat de l'operation
*
*/
    virtual Donnee* mySqrt()
    {throw ExceptionCooCoo("Pas de calcul de sqrt avec un complexe : non géré.");}

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
    {throw ExceptionCooCoo("Pas de calcul de fact avec un complexe : non géré.");}
    /*!
* \brief isZero
*
* Mathode permettant de savoir si la Donnee est egale à 0
* \return bool true si la Donnee est egale à 0
*
*/
    bool isZero(){
        return(pRe->isZero()&& pIm->isZero());
    }
    /*!
* \brief isNeg
*
* Mathode permettant de savoir si la Donnee est inferieure ou egale à 0
* \return bool true si la Donnee est inferieur ou egale à 0
*
*/
    bool isNeg(){
        return(pRe->isNeg()&&pIm->isNeg());
    }

};

#endif // COMPLEXE_H
