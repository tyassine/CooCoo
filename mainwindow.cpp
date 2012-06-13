#include "mainwindow.h"
#include "ui_mainwindow.h"

// DANS LA FONCTION EMPILER IL FAUT EMPILER TORATIONNEL(S), TOREEL(S)...
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->grabKeyboard();
    instancePile = Pile::getInstance();
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
    QObject::connect(ui->bCE, SIGNAL(clicked()), this, SLOT(on_effacer_el()));
    //QObject::connect(ui->bParD, SIGNAL(clicked()), this, SLOT(on_parenthese_droite()));
    //QObject::connect(ui->bParG, SIGNAL(clicked()), this, SLOT(on_parenthese_gauche()));
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
    ui->Afficheur->insert("x");
}
void MainWindow::on_division(){
    ui->Afficheur->insert("/");
}
void MainWindow::on_effacer(){
    ui->Afficheur->clear();
}
void MainWindow::on_effacer_el(){
    if (ui->Afficheur->text().isEmpty())
        on_drop();
    else{
        QString aff = ui->Afficheur->text();
        aff.chop(1);
        ui->Afficheur->setText(aff);
    }

}

void MainWindow::on_dollar(){
   /* if (ui->Complexes->currentIndex()==0){// complexes non autorisés
        QMessageBox::warning(this, "Mode complexe", "Attention, le mode complexe doit être activé !");
    }
    else*/
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
    // ici il faut empiler =)
     ui->Afficheur->clear();
}

// Slots paramètres

void MainWindow::on_clavier(bool checked){
    if (checked){
        ui->Clavier->hide();
    }
    else
        ui->Clavier->show();
    setClavier(checked);
}
void MainWindow::on_Annuler_triggered(){
}
void MainWindow::on_Retablir_triggered(){
}

void MainWindow::on_complexe(int c){
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
    setAngle(TypeAngle(a));
}

void MainWindow::on_nbPile(int n){
    setNbPile(n);
    refresh();
}


void MainWindow::on_commit(){
    if (ui->Afficheur->text().isEmpty())
        on_dup();
    else{
    parser();
    ui->Afficheur->clear();
    refresh();
    }
}

//reimplémentation keyPressEvent pour le clavier
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
    /*case Qt::Key_ParenLeft:
        on_parenthese_gauche();
        break;
    case Qt::Key_ParenRight:
        on_parenthese_droite();
        break;*/
    case Qt::Key_Dollar:
        on_dollar();
        break;
    case Qt::Key_Enter:
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

/*
void MainWindow::on_commit(){
    QString s = ui->Afficheur->text();
    bool arret=0;
    /*list = st.split(" ");
    QStringListModel * modele = new QStringListModel(list);
    ui->AffichagePile->setModel(modele);
    ui->Afficheur->clear(); // c'est pas ça qu'il faut faire*/
/*    QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);
    if(exp.exactMatch(s)){pile->Empiler(new Expression(s));}
    else if(s.contains("$")){
        if(!complexe){
            arret=1;
            std::cout<<"Le mode complexe n'est pas activé"<<std::endl;
        }
        else{
            Complexe* c=ToComplexe(s);
            pile->Empiler(c);
        }
    }
    else if(s=="+"){arret=1; calcul_plus();}
    else if(s=="-"){arret=1; calcul_moins();}
    else if(s=="*"){arret=1; calcul_mult();}

    if(!arret){
        try {pile->Empiler(s);}
        catch(ExceptionCooCoo e){e.GetInfos();}
    }

    ui->Afficheur->clear();
    AffichageEcran();
}
*/
void MainWindow::on_swap(){
}
void MainWindow::on_sum(){
}
void MainWindow::on_dup(){
}
void MainWindow::on_mean(){
}
void MainWindow::on_clear(){
}
void MainWindow::on_drop(){
}

MainWindow::~MainWindow(){
    int maj = QMessageBox::question(this, "Sauvegarde contexte", "Voulez-vous sauvegarder la pile et les paramètres pour la prochaine utilisation ?", QMessageBox::Yes | QMessageBox::No);
    if (maj== QMessageBox::Yes){
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
/*

void MainWindow::AffichageEcran(){
    ui->AffichagePile->clear();

    std::deque<QString> ptr=pile->GetPtr();

    for(unsigned int i=0;i<ptr.size();i++)
       /*TODO AFFICHER LES LIGNES ui->AffichagePile->
                append(pile->GetVal(i));

faire avec des getstring
}*/

void MainWindow::InitParam(){
    std::ifstream fichier("sauvegarde_CooCoo.txt", std::ios::in); // Ouverture en lecture du fichier de sauvegarde
    if(fichier)
    {
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
                instancePile->empiler(FabriqueDonnee::creerDonnee((QString)pile.c_str()));
             }
        }
      }
    else{ // Sinon le fichier n'existait pas, on ouvre en écriture et on l'initialise avec les valeurs pas défaut
        QMessageBox::information(this, "Initialisation", "Il n'existe pas de fichier de sauvegarde.");
        std::ofstream fichier("sauvegarde_CooCoo.txt", std::ios::out);

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
            for(unsigned int i=0;i<=instancePile->getSommet();i++){
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

    QStringList listeTermes = tmp.split(" ");
    // ATTENTION, il peut y avoir des espaces dans les expressions-quote!!!
    for (unsigned int i=0; i<listeTermes.size(); i++)
    {
        // détecter nombre ou opérateur, coucou Perrine <3
        objetTerme = FabriqueDonnee::creerDonnee(listeTermes[i]);
        instancePile->empiler(objetTerme);
    }
}



void MainWindow::refresh()
{
    ui->AffichagePile->clear();
    Donnee** tab = instancePile->getTab();
    int taillePileInterne = instancePile->getSommet() + 1;
    int limite = min(nb_elem_affiche, taillePileInterne);

    if (!(instancePile->pileVide()))
    {
        QMessageBox::information(this, "blabla", tab[0]->toQString());

    }
/*
    for (unsigned int i=0; i<limite; i++)
        ui->AffichagePile->addItem(tab[i]->toQString());*/
    /*
    delete[] tab;
    delete tab;
    */
}

/*
// Fonctions post commit de calcul
void MainWindow::calcul_plus()
{
    if(pile->GetPtr().size()<2)
    {
        ExceptionCooCoo e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else
    {
        try
        {
            Constante* tmp1=&(pile->Depiler());
            Constante* tmp2=&(pile->Depiler());
            Constante* c;
            c = tmp2+ tmp1; //&(tmp2->operator +(tmp1));

            pile->Empiler(c);
         }
        catch(ExceptionCooCoo e){e.GetInfos();}

    }
    AffichageEcran();
}*/
/*

void MainWindow::calcul_moins()
{
    if(pile->GetPtr().size()<2)
    {
        ExceptionCooCoo e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else
    {
        try
        {
            Constante* tmp1=&(pile->Depiler());
            Constante* tmp2=&(pile->Depiler());
            Constante* c;
            c = tmp2-tmp1;

            pile->Empiler(c);
        }
        catch(ExceptionCooCoo e){e.GetInfos();}

    }
    AffichageEcran();
}*/
/*
void MainWindow::calcul_mult()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCooCoo e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else
    {
        try
        {
            Constante* tmp1=&(pile->Depiler());
            Constante* tmp2=&(pile->Depiler());
            Constante* c;
            c = tmp2 *tmp1;

            pile->Empiler(c);
        }
        catch(ExceptionCooCoo e){e.GetInfos();}
    }
    //pa->AffichagePile(); ps->AffichagePile();
    AffichageEcran();
}
*/
