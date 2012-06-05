#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QKeyEvent>
#include <QStack>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
//#include "exceptionCooCoo.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AffichageEcran();
    void InitParam();
    void MAJParam();

    void calcul_plus();
    void calcul_moins();
    void calcul_mult();
    void keyPressEvent(QKeyEvent *);

/* TODO    signals:
        void pushStack_signal(const QString&);
        void cleanList_signal();
        void refresh_signal();
*/


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
    void on_parenthese_droite();
    void on_parenthese_gauche();
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
    void on_complexe();
    void on_angle();
    void on_constante();

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




    void on_Annuler_triggered();
    void on_Retablir_triggered();




private:
    Ui::MainWindow *ui;
    QStack<int> *pile;
    bool complexe; //0 pour non complexe et 1 pour complexe
    std::string typeDeCste;
    bool clavier; //0 pour caché et 1 pour visible
    std::string operateur;
    std::string angle;

};



void refresh_entier(Ui::MainWindow *);
void refresh_reel_rationnel(Ui::MainWindow *);
void refresh_complexe(Ui::MainWindow *);


#endif // MAINWINDOW_H
