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
/*
void MainWindow::on_virguleBouton_clicked(){
    ui->Afficheur->setText(ui->Afficheur->toPlainText() + ".");
}
*/
MainWindow::~MainWindow(){
    delete ui;
}
