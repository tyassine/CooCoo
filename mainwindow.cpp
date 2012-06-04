#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("CooCoo");
    this->setWindowIcon(QIcon(QString("E:/Dropbox/LO21/CooCoo/CooCoo.png")));

    // Connections slot/signaux des boutons du clavier
    QObject::connect(ui->b0, SIGNAL(clicked()), this, SLOT(on_0()));
    QObject::connect(ui->b1, SIGNAL(clicked()), this, SLOT(on_1()));
    QObject::connect(ui->b2, SIGNAL(clicked()), this, SLOT(on_2()));
    QObject::connect(ui->b3, SIGNAL(clicked()), this, SLOT(on_3()));
    QObject::connect(ui->b4, SIGNAL(clicked()), this, SLOT(on_4()));
    QObject::connect(ui->b5, SIGNAL(clicked()), this, SLOT(on_5()));
    QObject::connect(ui->b6, SIGNAL(clicked()), this, SLOT(on_6()));
    QObject::connect(ui->b7, SIGNAL(clicked()), this, SLOT(on_7()));
    QObject::connect(ui->b8, SIGNAL(clicked()), this, SLOT(on_8()));
    QObject::connect(ui->b9, SIGNAL(clicked()), this, SLOT(on_9()));
    QObject::connect(ui->bEsp, SIGNAL(clicked()), this, SLOT(on_espace()));
    QObject::connect(ui->bVirg, SIGNAL(clicked()), this, SLOT(on_virgule()));
    QObject::connect(ui->bCommit, SIGNAL(clicked()), this, SLOT(on_commit()));
    QObject::connect(ui->bAdd, SIGNAL(clicked()), this, SLOT(on_addition()));
    QObject::connect(ui->bSoustr, SIGNAL(clicked()), this, SLOT(on_soustraction()));
    QObject::connect(ui->bMult, SIGNAL(clicked()), this, SLOT(on_multiplication()));
    QObject::connect(ui->bDiv, SIGNAL(clicked()), this, SLOT(on_division()));
    QObject::connect(ui->bC, SIGNAL(clicked()), this, SLOT(on_effacer()));
    QObject::connect(ui->bParD, SIGNAL(clicked()), this, SLOT(on_parenthese_droite()));
    QObject::connect(ui->bParG, SIGNAL(clicked()), this, SLOT(on_parenthese_gauche()));

    ui->b0->setShortcut(Qt::Key_0);
    ui->b1->setShortcut(Qt::Key_1);
    ui->b2->setShortcut(Qt::Key_2);
    ui->b3->setShortcut(Qt::Key_3);
    ui->b4->setShortcut(Qt::Key_4);
    ui->b5->setShortcut(Qt::Key_5);
    ui->b6->setShortcut(Qt::Key_6);
    ui->b7->setShortcut(Qt::Key_7);
    ui->b8->setShortcut(Qt::Key_8);
    ui->b9->setShortcut(Qt::Key_9);

    // Connections slot/signaux des boutons des fonctions de la pile
    QObject::connect(ui->bSwap, SIGNAL(clicked()), this, SLOT(on_swap()));
    QObject::connect(ui->bSum, SIGNAL(clicked()), this, SLOT(on_sum()));
    QObject::connect(ui->bDup, SIGNAL(clicked()), this, SLOT(on_dup()));

    // Connections slot/signaux des boutons des paramètres
    QObject::connect(ui->cClavier, SIGNAL(toggled(bool)), this, SLOT(on_clavier(bool)));

    // Connections slot/signaux des boutons des fonctions
    QObject::connect(ui->bQuote, SIGNAL(clicked()), this, SLOT(on_quote()));
    QObject::connect(ui->bCos, SIGNAL(clicked()), this, SLOT(on_cos()));
    QObject::connect(ui->bSin, SIGNAL(clicked()), this, SLOT(on_sin()));
    QObject::connect(ui->bTan, SIGNAL(clicked()), this, SLOT(on_tan()));
    QObject::connect(ui->bCosh, SIGNAL(clicked()), this, SLOT(on_cosh()));
    QObject::connect(ui->bSinh, SIGNAL(clicked()), this, SLOT(on_sinh()));
    QObject::connect(ui->bTanh, SIGNAL(clicked()), this, SLOT(on_tanh()));
}


// Slot clavier
void MainWindow::on_1(){
    ui->Afficheur->setText(ui->Afficheur->text() + "1");
}
void MainWindow::on_2(){
    ui->Afficheur->setText(ui->Afficheur->text() + "2");
}
void MainWindow::on_3(){
    ui->Afficheur->setText(ui->Afficheur->text() + "3");
}
void MainWindow::on_4(){
    ui->Afficheur->setText(ui->Afficheur->text() + "4");
}
void MainWindow::on_5(){
    ui->Afficheur->setText(ui->Afficheur->text() + "5");
}
void MainWindow::on_6(){
    ui->Afficheur->setText(ui->Afficheur->text() + "6");
}
void MainWindow::on_7(){
    ui->Afficheur->setText(ui->Afficheur->text() + "7");
}
void MainWindow::on_8(){
    ui->Afficheur->setText(ui->Afficheur->text() + "8");
}
void MainWindow::on_9(){
    ui->Afficheur->setText(ui->Afficheur->text() + "9");
}
void MainWindow::on_0(){
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
void MainWindow::on_parenthese_gauche(){
      ui->Afficheur->setText(ui->Afficheur->text()+"(");
}
void MainWindow::on_parenthese_droite(){
      ui->Afficheur->setText(ui->Afficheur->text()+")");
}

// Slots fonctions
void MainWindow::on_quote(){
      ui->Afficheur->setText(ui->Afficheur->text()+"'");
}
void MainWindow::on_cos(){
    ui->Afficheur->setText(ui->Afficheur->text()+"cos");
}
void MainWindow::on_sin(){
    ui->Afficheur->setText(ui->Afficheur->text()+"sin");
}
void MainWindow::on_tan(){
    ui->Afficheur->setText(ui->Afficheur->text()+"tan");
}
void MainWindow::on_cosh(){
    ui->Afficheur->setText(ui->Afficheur->text()+"cosh");
}
void MainWindow::on_sinh(){
    ui->Afficheur->setText(ui->Afficheur->text()+"sinh");
}
void MainWindow::on_tanh(){
    ui->Afficheur->setText(ui->Afficheur->text()+"tanh");
}
void MainWindow::on_mod(){
   ui->Afficheur->setText(ui->Afficheur->text()+"mod");
}

void MainWindow::on_ln(){
    ui->Afficheur->setText(ui->Afficheur->text()+"ln");
 }
void MainWindow::on_log(){
    ui->Afficheur->setText(ui->Afficheur->text()+"log");
 }
void MainWindow::on_inv(){
    ui->Afficheur->setText(ui->Afficheur->text()+"inv");
 }
void MainWindow::on_sqr(){
    ui->Afficheur->setText(ui->Afficheur->text()+"sqr");
 }
void MainWindow::on_sqrt(){
    ui->Afficheur->setText(ui->Afficheur->text()+"sqrt");
 }
void MainWindow::on_sign(){
    ui->Afficheur->setText(ui->Afficheur->text()+"sign");
 }
void MainWindow::on_pow(){
    ui->Afficheur->setText(ui->Afficheur->text()+"pow");
 }


// Slots paramètres

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
