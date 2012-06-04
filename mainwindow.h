#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

    // slotsdes fonctions de la pile
    void on_swap();
    void on_sum();
    void on_dup();

    // slots des paramètres
    void on_clavier(bool);

    // slots des fonctions
    void on_quote();
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
    void on_sqr();
    void on_sqrt();
    void on_sign();
    void on_pow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
