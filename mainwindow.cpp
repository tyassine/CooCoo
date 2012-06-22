#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <typeinfo>
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "memento.h"
#include "logsystem.h"

// DANS LA FONCTION EMPILER IL FAUT EMPILER TORATIONNEL(S), TOREEL(S)...
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->grabKeyboard();
    instancePile = new Pile;
    instanceFD = FabriqueDonnee::getInstance();
    // Sauvegarde de l'état initial dans le memento
    instancePile->getGardien()->addMemento(instancePile);
    redoPossible = false;
    this->setWindowTitle("CooCoo");
    this->setWindowIcon(QIcon(QString("E:/Dropbox/LO21/CooCoo/CooCoo.png")));
    redoPossible = false;



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
    QObject::connect(ui->bCE, SIGNAL(clicked()), this, SLOT(on_effacer_el()));
    QObject::connect(ui->bDollar, SIGNAL(clicked()), this, SLOT(on_dollar()));

    // Connections slot/signaux des boutons des fonctions de la pile
    QObject::connect(ui->bSwap, SIGNAL(clicked()), this, SLOT(on_swap()));
    QObject::connect(ui->bSum, SIGNAL(clicked()), this, SLOT(on_sum()));
    QObject::connect(ui->bDup, SIGNAL(clicked()), this, SLOT(on_dup()));
    QObject::connect(ui->bMean, SIGNAL(clicked()), this, SLOT(on_mean()));
    QObject::connect(ui->bDrop, SIGNAL(clicked()), this, SLOT(on_drop()));
    QObject::connect(ui->bClear, SIGNAL(clicked()), this, SLOT(on_clear()));
    ui->bClear->setShortcut(QKeySequence("Ctrl+C"));

    // Connections slot/signaux des boutons des paramètres
    QObject::connect(ui->cClavier, SIGNAL(toggled(bool)), this, SLOT(on_clavier(bool)));
    QObject::connect(ui->NbElementPile, SIGNAL(valueChanged(int)), this, SLOT(on_nbPile(int)));
    QObject::connect(ui->Complexes, SIGNAL(currentIndexChanged(int)), this, SLOT(on_complexe(int)));
    QObject::connect(ui->UniteAngle, SIGNAL(currentIndexChanged(int)), this, SLOT(on_angle(int)));
    QObject::connect(ui->TypeConstante, SIGNAL(currentIndexChanged(int)), this, SLOT(on_constante(int)));
    QObject::connect(ui->actionAnnuler, SIGNAL(triggered()), this, SLOT(on_Annuler_triggered()));
    QObject::connect(ui->actionRetablir, SIGNAL(triggered()), this, SLOT(on_Retablir_triggered()));
    ui->actionAnnuler->setShortcut(QKeySequence("Ctrl+Z"));
    ui->actionRetablir->setShortcut(QKeySequence("Ctrl+Y"));

    // Connections slot/signaux des boutons des fonctions
    QObject::connect(ui->bQuote, SIGNAL(clicked()), this, SLOT(on_quote()));
    QObject::connect(ui->bEval, SIGNAL(clicked()), this, SLOT(on_eval()));

    QObject::connect(ui->bCos, SIGNAL(clicked()), this, SLOT(on_cos()));
    QObject::connect(ui->bSin, SIGNAL(clicked()), this, SLOT(on_sin()));
    QObject::connect(ui->bTan, SIGNAL(clicked()), this, SLOT(on_tan()));
    QObject::connect(ui->bCosh, SIGNAL(clicked()), this, SLOT(on_cosh()));
    QObject::connect(ui->bSinh, SIGNAL(clicked()), this, SLOT(on_sinh()));
    QObject::connect(ui->bTanh, SIGNAL(clicked()), this, SLOT(on_tanh()));

    QObject::connect(ui->bMod, SIGNAL(clicked()), this, SLOT(on_mod()));
    QObject::connect(ui->bLn, SIGNAL(clicked()), this, SLOT(on_ln()));
    QObject::connect(ui->bLog, SIGNAL(clicked()), this, SLOT(on_log()));
    QObject::connect(ui->bInv, SIGNAL(clicked()), this, SLOT(on_inv()));
    QObject::connect(ui->bCarre, SIGNAL(clicked()), this, SLOT(on_sqr()));
    QObject::connect(ui->bRacine, SIGNAL(clicked()), this, SLOT(on_sqrt()));
    QObject::connect(ui->bCube, SIGNAL(clicked()), this, SLOT(on_cube()));
    QObject::connect(ui->bSign, SIGNAL(clicked()), this, SLOT(on_sign()));
    QObject::connect(ui->bPow, SIGNAL(clicked()), this, SLOT(on_pow()));
    QObject::connect(ui->bFact, SIGNAL(clicked()), this, SLOT(on_fact()));

}


// Slot clavier
void MainWindow::on_1(){
    ui->Afficheur->insert("1");
}
void MainWindow::on_2(){
    ui->Afficheur->insert("2");
}
void MainWindow::on_3(){
    ui->Afficheur->insert("3");
}
void MainWindow::on_4(){
    ui->Afficheur->insert("4");
}
void MainWindow::on_5(){
    ui->Afficheur->insert("5");
}
void MainWindow::on_6(){
    ui->Afficheur->insert("6");
}
void MainWindow::on_7(){
    ui->Afficheur->insert("7");
}
void MainWindow::on_8(){
    ui->Afficheur->insert("8");
}
void MainWindow::on_9(){
    ui->Afficheur->insert("9");
}
void MainWindow::on_0(){
    ui->Afficheur->insert("0");
}
void MainWindow::on_virgule(){
    ui->Afficheur->insert(".");
}
void MainWindow::on_espace(){
    QString str = ui->Afficheur->text();
    if (str.endsWith(" ", Qt::CaseInsensitive))
        QMessageBox::warning(this, "Insertion d'espace", "Attention, il y a déjà un espace d'entré !");
    else
    ui->Afficheur->insert(" ");
}
void MainWindow::on_addition(){
    ui->Afficheur->insert("+");
}
void MainWindow::on_soustraction(){
    ui->Afficheur->insert("-");
}
void MainWindow::on_multiplication(){
    ui->Afficheur->insert("*");
}
void MainWindow::on_division(){
    ui->Afficheur->insert("/");
}
void MainWindow::on_effacer(){
    if (ui->Afficheur->text().isEmpty()){

         LogSystem::imprim(LogMessage("La ligne est deja vide", 1));
    }
    else
    ui->Afficheur->clear();
}
void MainWindow::on_effacer_el(){
    if (ui->Afficheur->text().isEmpty()){
         on_drop();
         LogSystem::imprim(LogMessage("La ligne est deja vide, suppression du dernier element de la pile", 1));
    }
    else{
        QString aff = ui->Afficheur->text();
        aff.chop(1);
        ui->Afficheur->setText(aff);
    }

}

void MainWindow::on_dollar(){
        ui->Afficheur->insert("$");
}

// Slots fonctions
void MainWindow::on_quote(){
      ui->Afficheur->insert("'");
}
void MainWindow::on_cos(){
    ui->Afficheur->insert("cos");
}
void MainWindow::on_sin(){
    ui->Afficheur->insert("sin");
}
void MainWindow::on_tan(){
    ui->Afficheur->insert("tan");
}
void MainWindow::on_cosh(){
    ui->Afficheur->insert("cosh");
}
void MainWindow::on_sinh(){
    ui->Afficheur->insert("sinh");
}
void MainWindow::on_tanh(){
    ui->Afficheur->insert("tanh");
}
void MainWindow::on_mod(){
   ui->Afficheur->insert("mod");
}
void MainWindow::on_fact(){
    ui->Afficheur->insert("!");
}
void MainWindow::on_ln(){
    ui->Afficheur->insert("ln");
 }
void MainWindow::on_log(){
    ui->Afficheur->insert("log");
 }
void MainWindow::on_inv(){
    ui->Afficheur->insert("inv");
 }
void MainWindow::on_sqr(){
    ui->Afficheur->insert("sqr");
 }
void MainWindow::on_sqrt(){
    ui->Afficheur->insert("sqrt");
 }
void MainWindow::on_cube(){
    ui->Afficheur->insert("cube");
 }
void MainWindow::on_sign(){
    ui->Afficheur->insert("sign");
 }
void MainWindow::on_pow(){
    ui->Afficheur->insert("pow");
 }
void MainWindow::on_eval(){
    if (!instancePile->pileVide()){
     Donnee* tmp=instancePile->depiler();
     if (typeid(*tmp)==typeid(ConstanteExp)){
         ConstanteExp *exp=static_cast<ConstanteExp*>(tmp);
         ui->Afficheur->clear();
         ui->Afficheur->insert(exp->getChaine().remove("'"));
         parser();
         ui->Afficheur->clear();
         refresh();
         instancePile->getGardien()->addMemento(instancePile);
         redoPossible = false;
     }
     else{
         instancePile->empiler(tmp);
         QMessageBox::information(this, "Evaluation", "La dernière donnée entrée dans la pile doit être une expression");
         LogSystem::imprim(LogMessage("Dernière donnée entrée non valide pour une évaluation", 2));
     }
    }
}

// Slots paramètres

void MainWindow::on_clavier(bool checked){
    if (checked){
        LogSystem::imprim(LogMessage("Clavier numerique caché", 1));
        ui->Clavier->hide();
    }
    else{
        LogSystem::imprim(LogMessage("Affichage du clavier numerique", 1));
        ui->Clavier->show();}
    setClavier(checked);
}
void MainWindow::on_Annuler_triggered()
{
    Pile* tmp = instancePile->getGardien()->undo();
    if (tmp)
    {
        delete instancePile;
        instancePile = tmp;
        redoPossible = true;
    }else
    {
        QMessageBox::information(this, "Annulation impossible","Plus d'opérations à annuler");
        LogSystem::imprim(LogMessage("Plus d'opérations à annuler", 2));
    }
    refresh();
}
void MainWindow::on_Retablir_triggered()
{
    if (redoPossible)
    {
        Pile* tmp = instancePile->getGardien()->redo();
        if (tmp)    // Le redo a été accepté
        {
            delete instancePile;
            instancePile = tmp;
        }
        else
        {
            QMessageBox::information(this, "Rétablir impossible","Aucune opération à rétablir");
            LogSystem::imprim(LogMessage("Aucune opération à rétablir", 2));
        }
        refresh();
    }else
    {
        QMessageBox::information(this, "Rétablir impossible","Aucune opération à rétablir");
        LogSystem::imprim(LogMessage("Aucune opération à rétablir", 2));
    }
}

void MainWindow::on_complexe(int c){
    LogSystem::imprim(LogMessage("Modification du mode complexe", 1));
    if (c==1){// complexes
        setComplexe(1);
        if (getConstante()==1){ // entiers
            refresh_complexe(ui);
        }
        else {//Reels & rationnels
            refresh_complexe(ui);
        }
    }
    else{ // non complexes
        setComplexe(0);
        if (getConstante()==0){//Entiers
            refresh_entier(ui);
        }
        else {//Reels & rationnels
            refresh_reel_rationnel(ui);
        }
    }

}

void MainWindow::on_constante(int c){
    LogSystem::imprim(LogMessage("Modification de la constante", 1));

    setConstante(TypeConstante(c));
    if (c==0){//entiers
        if (getComplexe()==1){//complexes
            refresh_complexe(ui);
        }
        else // entiers non complexes
            refresh_entier(ui);
    }
    else {//reels et rationnels
        if (getComplexe()==1){//complexes
            refresh_complexe(ui);
        }
        else //reels et rationnels non complexes
            refresh_reel_rationnel(ui);
    }
}
void MainWindow::on_angle(int a){
    LogSystem::imprim(LogMessage("Modification de l'unité d'angle", 1));
    setAngle(TypeAngle(a));
}

void MainWindow::on_nbPile(int n){
    LogSystem::imprim(LogMessage("Modification du nombre d'element de la pile a afficher", 1));
    setNbPile(n);
    refresh();
}


void MainWindow::on_commit(){
    if (ui->Afficheur->text().isEmpty())
    {
        LogSystem::imprim(LogMessage("Aucune entree, duplication du dernier element de la pile", 2));
        on_dup();
        instancePile->getGardien()->addMemento(instancePile);
        redoPossible = false;
    }
    else{
    parser();
    ui->Afficheur->clear();
    refresh();
    }
}

//reImplémentation keyPressEvent pour le clavier
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_0:
        on_0();
        break;
    case Qt::Key_1:
        on_1();
        break;
    case Qt::Key_2:
        on_2();
        break;
    case Qt::Key_3:
        on_3();
        break;
    case Qt::Key_4:
        on_4();
        break;
    case Qt::Key_5:
        on_5();
        break;
    case Qt::Key_6:
        on_6();
        break;
    case Qt::Key_7:
        on_7();
        break;
    case Qt::Key_8:
        on_8();
        break;
    case Qt::Key_9:
        on_9();
        break;
    case Qt::Key_Comma:
        on_virgule();
        break;
    case Qt::Key_Space:
        on_espace();
        break;
    case Qt::Key_Plus:
        on_addition();
        break;
    case Qt::Key_Minus:
        on_soustraction();
        break;
    case Qt::Key_Asterisk:
        on_multiplication();
        break;
    case Qt::Key_Slash:
        on_division();
        break;
    case Qt::Key_Dollar:
        on_dollar();
        break;
    case Qt::Key_Return:
        on_commit();
        break;
    case Qt::Key_C:
        on_effacer();
        break;
    case Qt::Key_Backspace:
        on_effacer_el();
        break;
    }
}

void MainWindow::on_swap(){
    ui->Afficheur->insert("SWAP");
    refresh();
}
void MainWindow::on_sum(){
    ui->Afficheur->insert("SUM");
    refresh();
}
void MainWindow::on_dup(){
    if (!(instancePile->pileVide()))
    {
        instancePile->dup();
        instancePile->getGardien()->addMemento(instancePile);
        redoPossible = false;
        // Régler le problème gardien <-> dup
        refresh();
    }
}
void MainWindow::on_mean(){
    ui->Afficheur->insert("MEAN");
    refresh();
}
void MainWindow::on_clear(){
    instancePile->clear();
    instancePile->getGardien()->addMemento(instancePile);
    redoPossible = false;
    refresh();
}
void MainWindow::on_drop(){
    if (!(instancePile->pileVide()))
    {
        instancePile->drop();
        instancePile->getGardien()->addMemento(instancePile);
        redoPossible = false;
        refresh();
    }
}

MainWindow::~MainWindow(){
    int maj = QMessageBox::question(this, "Sauvegarde contexte", "Voulez-vous sauvegarder la pile et les paramètres pour la prochaine utilisation ?", QMessageBox::Yes | QMessageBox::No);
    if (maj== QMessageBox::Yes){
        LogSystem::imprim(LogMessage("Sauvegarde du contexte", 1));
        MAJParam();
    }
    else{
        if(remove("sauvegarde_CooCoo.txt")!= 0)
            std::cerr << "Fichier inexistant" << std::endl;
    }
    delete ui;
}

// Fonctions refresh affichage boutons
void refresh_entier(Ui::MainWindow *ui){
    ui->bCarre->setEnabled(true);//sqr
    ui->bRacine->setEnabled(true);//sqrt
    ui->bCube->setEnabled(true);
    ui->bSign->setEnabled(true);
    ui->bFact->setEnabled(true);
    ui->bPow->setEnabled(true);
    ui->bMod->setEnabled(true);
    ui->bLn->setEnabled(true);
    ui->bLog->setEnabled(true);
    ui->bInv->setEnabled(true);
    ui->bCos->setEnabled(true);
    ui->bSin->setEnabled(true);
    ui->bTan->setEnabled(true);
    ui->bCosh->setEnabled(true);
    ui->bSinh->setEnabled(true);
    ui->bTanh->setEnabled(true);
}

void refresh_reel_rationnel(Ui::MainWindow *ui){
    ui->bMod->setEnabled(false);
    ui->bFact->setEnabled(false);

    ui->bCarre->setEnabled(true);//sqr
    ui->bRacine->setEnabled(true);//sqrt
    ui->bCube->setEnabled(true);
    ui->bSign->setEnabled(true);
    ui->bPow->setEnabled(true);
    ui->bLn->setEnabled(true);
    ui->bLog->setEnabled(true);
    ui->bInv->setEnabled(true);
    ui->bCos->setEnabled(true);
    ui->bSin->setEnabled(true);
    ui->bTan->setEnabled(true);
    ui->bCosh->setEnabled(true);
    ui->bSinh->setEnabled(true);
    ui->bTanh->setEnabled(true);

}

void refresh_complexe(Ui::MainWindow *ui){
    ui->bCarre->setEnabled(true);//sqr
    ui->bCube->setEnabled(true);
    ui->bSign->setEnabled(true);

    ui->bRacine->setEnabled(false);//sqrt
    ui->bFact->setEnabled(false);
    ui->bPow->setEnabled(false);
    ui->bMod->setEnabled(false);
    ui->bLn->setEnabled(false);
    ui->bLog->setEnabled(false);
    ui->bInv->setEnabled(false);
    ui->bCos->setEnabled(false);
    ui->bSin->setEnabled(false);
    ui->bTan->setEnabled(false);
    ui->bCosh->setEnabled(false);
    ui->bSinh->setEnabled(false);
    ui->bTanh->setEnabled(false);
}

// fonctions de récupération ou suppression d'historique
// quelque part parmi elles, s'occuper de récupérer le gardien? Ou au moins en faire un nouveau

void MainWindow::InitParam(){
    std::ifstream fichier("sauvegarde_CooCoo.txt", std::ios::in); // Ouverture en lecture du fichier de sauvegarde
    if(fichier)
    {
        LogSystem::imprim(LogMessage("Chargement du contexte de dernière utilisation", 1));
        QMessageBox::information(this, "Initialisation", "Initialisation des paramètres et de la pile avec la sauvegarde de la dernière utilisation de CooCoo.");
        // le fichier contient : complexe(0-1), clavier(0-1), constante (0,1,2), Angle (0,1), NbElementAffichés, Pile
        std::string tmp, pile;

        getline(fichier, tmp);
        setComplexe(atoi(tmp.c_str()));
        ui->Complexes->setCurrentIndex(getComplexe());

        getline(fichier, tmp);
        setClavier(atoi(tmp.c_str()));
        ui->cClavier->setChecked(getClavier());

        getline(fichier, tmp);
        setConstante(TypeConstante(atoi(tmp.c_str())));
        ui->TypeConstante->setCurrentIndex(getConstante());

        getline(fichier, tmp);
        setAngle(TypeAngle(atoi(tmp.c_str())));
        ui->UniteAngle->setCurrentIndex(getAngle());

        getline(fichier, tmp);
        setNbPile(atoi(tmp.c_str()));
        ui->NbElementPile->setValue(getNbPile());

        getline(fichier, pile);
        if(pile!="pile vide"){
            while(getline(fichier, pile)){

                std::cout<<pile.c_str()<<std::endl;
                instancePile->empiler(instanceFD->creerDonnee((QString)pile.c_str()));
             }
        }
      }
    else{ // Sinon le fichier n'existait pas, on ouvre en écriture et on l'initialise avec les valeurs pas défaut
        QMessageBox::information(this, "Initialisation", "Il n'existe pas de fichier de sauvegarde.");
        std::ofstream fichier("sauvegarde_CooCoo.txt", std::ios::out);
        LogSystem::imprim(LogMessage("Aucun fichier de sauvegarde", 1));
        if(fichier)
        {   // le fichier contient : complexe(0-1), clavier(0-1), constante (0,1,2), Angle (0,1), Pile
            fichier<<0<<std::endl;
            setComplexe(0);
            fichier<<0<<std::endl;
            setClavier(0);
            fichier<<0<<std::endl;
            setConstante(TypeConstante(0));
            fichier<<0<<std::endl;
            setAngle(TypeAngle(0));
            fichier<<10<<std::endl;
            setNbPile(10);
            fichier<<"pile vide"<<std::endl;
        }
        else
            std::cerr << "Erreur à l'ouverture !" << std::endl;

    }
    fichier.close();
}

void MainWindow::MAJParam(){
    std::ofstream fichier("sauvegarde_CooCoo.txt", std::ios::out | std::ios::trunc); //ouverture du fichier

    if(fichier) // si l'ouverture a réussi
    {
        fichier<<getComplexe()<<std::endl;
        fichier<<getClavier()<<std::endl;
        fichier<<getConstante()<<std::endl;
        std::cout<<getConstante()<<std::endl;
        fichier<<getAngle()<<std::endl;
        fichier<<getNbPile()<<std::endl;
        if (instancePile->pileVide())//sauvegarde de la pile
            fichier<<"pile vide"<<std::endl;
        else {
            fichier<<"pile remplie"<<std::endl;
            Donnee** tab=instancePile->getTab();
            for(int i=0;i<=instancePile->getSommet();i++){
                fichier<<tab[i]->toQString().toStdString()<<std::endl;
            }
        }
        fichier.close();
    }
    else // sinon
        std::cerr << "Erreur à l'ouverture !" << std::endl;
}

void MainWindow::parser()
{

    QString tmp = ui->Afficheur->text();
    Donnee* objetTerme;
    if (tmp.contains("'")&&(tmp.count("'")%2!=0)){
        QMessageBox::information(this,"Erreur de saisie", "Il faut fermer les expressions");
    LogSystem::imprim(LogMessage("Erreur de saisie, impossible d'empiler", 3));}
    else{
    QStringList listeTermes = tmp.split(" ");

    QString opBinaires = "+-/*powmodSWAP";
    QString opUnaires = "SUMMEANsignsincostansinhcoshtanhlnloginvsqrtsqrcube!";
    for (int i=0; i<listeTermes.size(); i++)
    {
        if (listeTermes[i].contains("'")){
            i++;
            QString s("' ");
            while(!listeTermes[i].contains("'")){
                s=s+listeTermes[i]+" ";
                i++;
            }
            s=s+"'";
            ConstanteExp *exp=new ConstanteExp(s);
            if(exp->getChaine()=="' '"){
                delete exp;
            }
            else instancePile->empiler(exp);
        }
        else if (opBinaires.contains(listeTermes[i])&&listeTermes[i]!="")
        {
            // Opérateur binaire
            if (instancePile->size() >= 2)  // Au moins 2 éléments
            {
                Donnee* tmpdte = instancePile->depiler();
                Donnee* tmpgch = instancePile->depiler();
                if (listeTermes[i]=="SWAP"){
                    Entier *x=static_cast<Entier*>(FabriqueDonnee::getInstance()->creerDonnee(tmpdte, 0, 0));
                    Entier *y=static_cast<Entier*>(FabriqueDonnee::getInstance()->creerDonnee(tmpgch, 0, 0));
                    instancePile->swap(x->getValeur(),y->getValeur());
                    delete y;
                    delete x;
                }

                else
                {
                    try{
                        Donnee* res;

                        if (listeTermes[i]=="+"){ // 4 5 +
                           res=*tmpgch+tmpdte;
                        }
                        else if (listeTermes[i]=="-"){
                            res=*tmpgch-tmpdte;
                        }
                        else if (listeTermes[i]=="/"){
                            if(tmpdte->isZero()){
                                throw ExceptionCooCoo("Division par 0");}
                            else
                                res=*tmpgch/tmpdte;

                        }
                        else if (listeTermes[i]=="*"){
                            res=*tmpgch*tmpdte;
                        }
                        else if (listeTermes[i]=="pow"){
                            res = tmpgch->puissance(tmpdte);
                        }
                        else if (listeTermes[i]=="mod"){
                            res = tmpgch->mod(tmpdte);
                        }

                        Donnee * res_final= instanceFD->creerDonnee(res, getConstante(), getComplexe());
                        instancePile->empiler(res_final);

                    } catch(ExceptionCooCoo &e){

                        QMessageBox msgBox;
                        msgBox.setText(e.GetInfos());
                        msgBox.exec();
                        LogSystem::imprim(LogMessage(e.GetInfos(), 3));
                    }
                }

                delete tmpdte;
                delete tmpgch;
            }
        }
        else if (opUnaires.contains(listeTermes[i])&&listeTermes[i]!="")
        {
            // Opérateur unaire
            if (!(instancePile->pileVide()))    // Au moins 1 élément
            {
                Donnee* tmp = instancePile->depiler();
                if (listeTermes[i]=="SUM"){
                    Entier *x=static_cast<Entier*>(FabriqueDonnee::getInstance()->creerDonnee(tmp, 0, 0));
                    instancePile->sum(x->getValeur());
                }
                else if (listeTermes[i]=="MEAN"){
                    Entier *x=static_cast<Entier*>(FabriqueDonnee::getInstance()->creerDonnee(tmp, 0, 0));
                    instancePile->mean(x->getValeur());
                }

                else
                {   try{
                        Donnee* res;
                        if (listeTermes[i]=="sign"){
                        res = tmp->sign();
                        }
                        else if (listeTermes[i]=="sin"){
                        res = tmp->mySin(angle);
                        }
                        else if (listeTermes[i]=="cos"){
                        res = tmp->myCos(angle);
                        }
                        else if (listeTermes[i]=="tan"){
                        res = tmp->myTan(angle);
                        }
                        else if (listeTermes[i]=="sinh"){
                        res = tmp->mySinh(angle);
                        }
                        else if (listeTermes[i]=="cosh"){
                        res = tmp->myCosh(angle);
                        }
                        else if (listeTermes[i]=="tanh"){
                        res = tmp->myTanh(angle);
                        }
                        else if (listeTermes[i]=="ln"){
                            if(tmp->isNeg()){
                                throw ExceptionCooCoo("Ln d'un nombre négatif");}
                            else
                                res = tmp->myLn();
                        }
                        else if (listeTermes[i]=="log"){
                            if(tmp->isNeg()){
                                throw ExceptionCooCoo("Log d'un nombre négatif");}
                            else
                                res = tmp->myLog();
                        }
                        else if (listeTermes[i]=="inv"){
                            if(tmp->isZero()){
                                throw ExceptionCooCoo("Division par 0");}
                            else
                                res = tmp->myInv();
                        }
                        else if (listeTermes[i]=="sqrt"){
                        res = tmp->mySqrt();
                        }
                        else if (listeTermes[i]=="sqr"){
                        res = tmp->mySqr();
                        }
                        else if (listeTermes[i]=="cube"){
                        res = tmp->myCube();
                        }
                        else if (listeTermes[i]=="!"){
                            res = tmp->myFact();
                            }

                        Donnee* res_final = instanceFD->creerDonnee(res, getConstante(), getComplexe());
                        instancePile->empiler(res_final);
                        } catch(ExceptionCooCoo &e){
                            QMessageBox msgBox;
                            msgBox.setText(e.GetInfos());
                            msgBox.exec();
                            LogSystem::imprim(LogMessage(e.GetInfos(), 3));
                       }
                    }


                delete tmp;
            }
        }
        else
        {
            // Constante
            if(listeTermes[i]!=""){
                objetTerme = instanceFD->creerDonnee(listeTermes[i]);
                if (objetTerme)
                    instancePile->empiler(objetTerme);
                else{
                    QMessageBox::information(this,"Erreur de saisie", "Type de constante non reconnu !");
                    LogSystem::imprim(LogMessage("Erreur de saisie, type non reconnu", 3));
                }
            }
        }

    }
    // Sauvegarder l'état de la pile : il faudrait le faire seulement s'il n'y a pas eu d'erreur
    instancePile->getGardien()->addMemento(instancePile);
    redoPossible = false;
}

}

void MainWindow::refresh()
{
    ui->AffichagePile->clear();
    Donnee** tab = instancePile->getTab();
    int taillePileInterne = instancePile->size();
    unsigned int limite = min(nb_elem_affiche, taillePileInterne);

    for (unsigned int i=0; i<limite; i++)
        ui->AffichagePile->insertItem(0, tab[instancePile->getSommet() - i]->toQString());

}

