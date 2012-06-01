#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("CooCoo");
    this->setWindowIcon(QIcon(QString("E:/Dropbox/LO21/CooCoo/CooCoo.png")));
    QObject::connect(ui->b0, SIGNAL(clicked()), this, SLOT(slot0()));
    QObject::connect(ui->b1, SIGNAL(clicked()), this, SLOT(slot1()));
    QObject::connect(ui->b2, SIGNAL(clicked()), this, SLOT(slot2()));
    QObject::connect(ui->b3, SIGNAL(clicked()), this, SLOT(slot3()));
    QObject::connect(ui->b4, SIGNAL(clicked()), this, SLOT(slot4()));
    QObject::connect(ui->b5, SIGNAL(clicked()), this, SLOT(slot5()));
    QObject::connect(ui->b6, SIGNAL(clicked()), this, SLOT(slot6()));
    QObject::connect(ui->b7, SIGNAL(clicked()), this, SLOT(slot7()));
    QObject::connect(ui->b8, SIGNAL(clicked()), this, SLOT(slot8()));
    QObject::connect(ui->b9, SIGNAL(clicked()), this, SLOT(slot9()));
    QObject::connect(ui->bEsp, SIGNAL(clicked()), this, SLOT(on_espace()));
    QObject::connect(ui->bVirg, SIGNAL(clicked()), this, SLOT(on_virgule()));
    QObject::connect(ui->bCommit, SIGNAL(clicked()), this, SLOT(on_commit()));
    QObject::connect(ui->bAdd, SIGNAL(clicked()), this, SLOT(on_addition()));
    QObject::connect(ui->bSoustr, SIGNAL(clicked()), this, SLOT(on_soustraction()));
    QObject::connect(ui->bMult, SIGNAL(clicked()), this, SLOT(on_multiplication()));
    QObject::connect(ui->bDiv, SIGNAL(clicked()), this, SLOT(on_division()));
    QObject::connect(ui->bC, SIGNAL(clicked()), this, SLOT(on_effacer()));
    QObject::connect(ui->bSwap, SIGNAL(clicked()), this, SLOT(on_swap()));
    QObject::connect(ui->bSum, SIGNAL(clicked()), this, SLOT(on_sum()));
    QObject::connect(ui->bDup, SIGNAL(clicked()), this, SLOT(on_dup()));
    QObject::connect(ui->cClavier, SIGNAL(toggled(bool)), this, SLOT(on_clavier(bool)));
   // QObject::connect(ui->cClavier, SIGNAL(released()), this, SLOT(on_clavier()));
}

void MainWindow::slot1(){
    ui->Afficheur->setText(ui->Afficheur->text() + "1");
}

void MainWindow::slot2(){
    ui->Afficheur->setText(ui->Afficheur->text() + "2");
}

void MainWindow::slot3(){
    ui->Afficheur->setText(ui->Afficheur->text() + "3");
}

void MainWindow::slot4(){
    ui->Afficheur->setText(ui->Afficheur->text() + "4");
}

void MainWindow::slot5(){
    ui->Afficheur->setText(ui->Afficheur->text() + "5");
}

void MainWindow::slot6(){
    ui->Afficheur->setText(ui->Afficheur->text() + "6");
}

void MainWindow::slot7(){
    ui->Afficheur->setText(ui->Afficheur->text() + "7");
}

void MainWindow::slot8(){
    ui->Afficheur->setText(ui->Afficheur->text() + "8");
}

void MainWindow::slot9(){
    ui->Afficheur->setText(ui->Afficheur->text() + "9");
}

void MainWindow::slot0(){
    ui->Afficheur->setText(ui->Afficheur->text() + "0");
}

void MainWindow::on_virgule(){
    ui->Afficheur->setText(ui->Afficheur->text() + ".");
}

void MainWindow::on_espace(){
    ui->Afficheur->setText(ui->Afficheur->text() + " ");
}


void MainWindow::on_addition(){
    ui->Afficheur->setText(ui->Afficheur->text() + "+");
}
void MainWindow::on_soustraction(){
    ui->Afficheur->setText(ui->Afficheur->text() + "-");
}

void MainWindow::on_multiplication(){
    ui->Afficheur->setText(ui->Afficheur->text() + "x");
}
void MainWindow::on_division(){
    ui->Afficheur->setText(ui->Afficheur->text() + "/");
}
void MainWindow::on_effacer(){
    ui->Afficheur->setText("");
}

void MainWindow::on_clavier(bool checked){
    if (checked)
        ui->Clavier->hide();
    else
        ui->Clavier->show();
}



void MainWindow::on_commit(){

}
void MainWindow::on_swap(){
}
void MainWindow::on_sum(){
}
void MainWindow::on_dup(){
}


MainWindow::~MainWindow(){
    delete ui;
}
