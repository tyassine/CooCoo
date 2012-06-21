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
 * \details    Pour foncionner cette classe encapsule un entier.
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
     * \brief      Retourne un Entier ayant les meme valeur mais avec le signe inversé
     * \details   Pour fonctionner, elle utilise le constructeut Entier par valeur
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
    Donnee* operator /(Donnee* t);

    /*!
    * \brief Operateur *
    *
    * Implementation de l'operateur binaire * (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator*(Donnee* t);

        /*!
    * \brief Operateur -
    *
    * Implementation de l'operateur binaire - (methode virtuelle dans la classe mere)
    * \param t : Pointeur sur un type
    * \return Pointeur sur type, resultat de l'operation
    *
    */
    Donnee* operator-(Donnee* t);


    virtual Donnee* puissance(Donnee* t);
    virtual Donnee* mod(Donnee* t);


    virtual Donnee* mySin(int typeAngle);
    virtual Donnee* myCos(int typeAngle);
    virtual Donnee* myTan(int typeAngle);
    virtual Donnee* mySinh(int typeAngle);
    virtual Donnee* myCosh(int typeAngle);
    virtual Donnee* myTanh(int typeAngle);/*


    virtual Donnee* ln();
    virtual Donnee* log();
    virtual Donnee* inv();
    virtual Donnee* sqrt();
    virtual Donnee* sqr();
    virtual Donnee* cube();
    virtual Donnee* fact();
    virtual Donnee* eval();
    */

};

#endif // ENTIER_H
