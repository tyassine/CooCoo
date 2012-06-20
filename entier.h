#ifndef ENTIER_H
#define ENTIER_H



/*!
* \file entier.h
* \author Letellier/Yassine
*/

#include "constante.h"

class Reel;
class Rationnel;
class Complexe;

class Entier : public Constante
{
    int valeur;
public:

    /*
      Constructeur par QString : utilisé par la factory lors du parsing
      Constructeurs par valeur : utilisés par la factory pour les conversions
    */


    Entier(int val=0) : valeur(val) {}
    Entier(const QString& aQString ="0") : valeur(aQString.toInt()) {}
    Entier(const Entier* aEntier) : valeur(aEntier->valeur) {}
    Entier(const Reel* aReel);
    Entier(const Rationnel* aRationnel);
    Entier(const Complexe* aComplexe);


    virtual QString toQString() const;
    Entier* sign(){
        Entier* res=new Entier(-valeur);
        return res;}
    int getValeur() const {return valeur;}
    void setValeur(int aValeur) {valeur = aValeur;}


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
    virtual Donnee* mod(Donnee* t);/*
    virtual Donnee* sign();

    virtual Donnee* sin();
    virtual Donnee* cos();
    virtual Donnee* tan();
    virtual Donnee* sinh();
    virtual Donnee* cosh();
    virtual Donnee* tanh();

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
