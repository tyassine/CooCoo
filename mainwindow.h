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
    void slot1();
    void slot2();
    void slot3();
    void slot4();
    void slot5();
    void slot6();
    void slot7();
    void slot8();
    void slot9();
    void slot0();
    void on_espace();
    void on_virgule();
    void on_commit();
    void on_addition();
    void on_soustraction();
    void on_multiplication();
    void on_division();
    void on_effacer();
    void on_swap();
    void on_sum();
    void on_dup();
    void on_clavier(bool);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
