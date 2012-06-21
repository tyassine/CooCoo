#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QKeyEvent>
#include <QMessageBox>
#include <QMetaEnum>
#include <QChar>
#include <QString>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include "exceptionCooCoo.h"
#include "pile.h"
#include "fabriquedonnee.h"

/*!
* \file mainwindow.h
* \author Letellier/Yassine
* \brief Fenêtre principale
*/


namespace Ui {

/*! \class MainWindow
* \brief Classe s'occupant de l'affichage et de l'interface avec l'utilisateur
* Elle herite de la classe QMainWindow.
*/
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(angle)
    Q_ENUMS(cste)

private:
    Ui::MainWindow *ui; /*!< Fenêtre*/
    Pile* instancePile; /*!< Pile de Donnee */
    FabriqueDonnee* instanceFD; /*!< Fabrique de Donnee */
    bool complexe; /*!< booleen d'etat 0 si non complexe souahitez 1 sinon */
    bool clavier; /*!< booleen pour affichage du clavier */
    enum TypeAngle {DEGRE, RADIAN};
    TypeAngle angle; /*!< type d'angle actuellement utilisé */
    enum TypeConstante {ENTIER, RATIONNEL, REEL};
    TypeConstante cste;/*!< type de constante actuellement utilisée */
    int nb_elem_affiche;/*!< nombre d'elements de la pile a afficher dans la Qlistview */


public:
    /*!
    * \brief Constructeur
    *
    * Constructeur de la classe MainWindow
    *
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
    * \brief Destructeur
    *
    * Destructeur de la classe MainWindow
    *
    */
    ~MainWindow();
    /*!
    * \brief InitParam
    * Initialisation des listes de selections, checkbox et afficheur de pile à l'ouverture de l'application
    */
    void InitParam();
    /*!
    * \brief MAJParam
    * Mise à jour des paramètres dans le fichier de sauvegarde
    */
    void MAJParam();
    /*!
    * \brief parser
    * Parser de l'afficheur pour empiler des donnees ou effectuer des operations
    */
    void parser();
    /*!
    * \brief refresh
    * Mise à jour de l'affichage de la pile
    */
    void refresh();
    /*!
    * \brief keyPressEvent
    * Redefinition de la methode keyPressEvent pour capter des evenements bien definis
    * \param QKeyEvent *, evenements à capter
    */
    void keyPressEvent(QKeyEvent *);
    /*!
    * \brief setAngle
    * Modificateur permettant de changer le mode d'angle en cours (Degre, Radian).
    * \param TypeAngle a, instance de l'enum TypeAngle
    */
    void setAngle(TypeAngle a){
        angle=a;
    }
    /*!
    * \brief getAngle
    * Accesseur permettant d'obtenir le mode d'angle en cours (Degre, Radian).
    * \return Le mode actuel de la calculatrice.
    */
    TypeAngle getAngle(){
        return angle;
    }
    /*!
    * \brief setConstante
    * Modificateur permettant de changer le mode de constante en cours (Entier, Rationnel, Reel).
    * \param TypeConstante c, instance de l'enum TypeConstante
    */
    void setConstante(TypeConstante c){
        cste=c;
    }
    /*!
    * \brief getConstante
    * Accesseur permettant d'obtenir le mode de constante en cours (Entier, Rationnel, Reel).
    * \return Le mode actuel de la calculatrice.
    */
    TypeConstante getConstante(){
        return cste;
    }
    /*!
    * \brief getComplexe
    * Accesseur permettant le mode de complexe (Oui ou non).
    * \return Le mode actuel de la calculatrice.
    */
    bool getComplexe(){
        return complexe;
    }
    /*!
    * \brief setComplexe
    * Modificateur permettant de choisir ou non le mode complexe.
    * \param bool c, choix du mode complexe
    */
    void setComplexe(bool c){
        complexe=c;
    }
    /*!
    * \brief getClavier
    * Accesseur permettant de recuperer le mode d'affichage du clavier (oui ou non)
    * \return Le mode actuel de la calculatrice.
    */
    bool getClavier(){
        return clavier;
    }
    /*!
    * \brief setClavier
    * Modificateur permettant de choisir ou non l'affichage du clavier numerique
    * \param bool c, choix de l'affichage
    */
    void setClavier(bool c){
        clavier=c;
    }
    /*!
    * \brief getNbPile
    * Accesseur permettant de recuperer le nombre actuel de Donnee de la pile a afficher
    * \return Le mode actuel de la calculatrice.
    */
    int getNbPile(){
        return nb_elem_affiche;
    }
    /*!
    * \brief setNbPile
    * Modificateur permettant de choisir le nombre de Donnee a afficher dans la pile
    * \param int n, nombre a afficher
    */
    void setNbPile(int n){
        nb_elem_affiche=n;
    }


private slots:

    void on_0();
    void on_1();
    void on_2();
    void on_3();
    void on_4();
    void on_5();
    void on_6();
    void on_7();
    void on_8();
    void on_9();
    void on_espace();
    void on_virgule();
    void on_commit();
    void on_addition();
    void on_soustraction();
    void on_multiplication();
    void on_division();
    void on_effacer();
    void on_effacer_el();
    //void on_parenthese_droite();
    //void on_parenthese_gauche();
    void on_dollar();

    // slots des opérations sur la pile
    void on_swap();
    void on_sum();
    void on_dup();
    void on_mean();
    void on_clear();
    void on_drop();


    // slots des paramètres
    void on_clavier(bool);
    void on_nbPile(int);
    void on_complexe(int);
    void on_angle(int);
    void on_constante(int);

    void on_Annuler_triggered();
    void on_Retablir_triggered();

    // slots des fonctions
    void on_quote();
    void on_eval();

    void on_cos();
    void on_sin();
    void on_tan();

    void on_cosh();
    void on_sinh();
    void on_tanh();

    void on_mod();

    void on_ln();
    void on_log();

    void on_inv();
    void on_sign();

    void on_pow();
    void on_cube();
    void on_sqr();
    void on_sqrt();
    void on_fact();





};


/*!
* \brief refresh_entier
* Fonction d'actualisation des boutons cachés selon les paramètres demandés par l'utilisateur
* \param Ui::MainWindow *, fenêtre concernee
*
*/
void refresh_entier(Ui::MainWindow *);
/*!
* \brief refresh_reel_rationnel
* Fonction d'actualisation des boutons cachés selon les paramètres demandés par l'utilisateur
* \param Ui::MainWindow *, fenêtre concernee
*
*/
void refresh_reel_rationnel(Ui::MainWindow *);
/*!
* \brief refresh_complexe
* Fonction d'actualisation des boutons cachés selon les paramètres demandés par l'utilisateur
* \param Ui::MainWindow *, fenêtre concernee
*
*/
void refresh_complexe(Ui::MainWindow *);


#endif // MAINWINDOW_H
