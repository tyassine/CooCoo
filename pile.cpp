#include "exceptionCooCoo.h"
#include "pile.h"
#include "fabriquedonnee.h"
#include "memento.h"
#include <QMessageBox>

Pile::Pile(unsigned int n)
{
    tab = new Donnee*[n];
    sommet = -1;
    nbMax = n;
    gard = new Gardien;
}


Pile::Pile(const Pile& p)
// L'important ici est de reconstruire chaque objet, et pas simplement recopier les pointeurs!
{
    tab = new Donnee*[p.nbMax];
    sommet = p.sommet;
    nbMax = p.nbMax;
    gard = p.gard;
    FabriqueDonnee* factory = FabriqueDonnee::getInstance();
    QString muh;
    for (int i=0; i<=sommet; i++)
    {
        // Recopie en convertissant en QString et en l'envoyant � la factory... Il y a surement plus propre.
        tab[i] = factory->creerDonnee(p.tab[i]->toQString());
    }
}

Pile::~Pile()
{
    for(int i=0; i<=sommet; ++i)
        delete tab[i];
    delete[] tab;
    // Il ne faut pas delete le gardien ici! Voir o�
}

void Pile::empiler(Donnee* aDonnee)
{
    if ( pilePleine() )
    {
        nbMax += 10;
        Donnee** newtab = new Donnee*[nbMax];
        for (int i=0; i<=sommet; i++) newtab[i] = tab[i];

        delete[] tab;
        tab = newtab;
    }
    sommet++;
    tab[sommet] = aDonnee;
}

Donnee* Pile::depiler()
{
    if (!pileVide())
    {
        sommet--;
        return tab[sommet+1];
    }
    throw ExceptionCooCoo("Pile vide");
}


bool Pile::pileVide() const
{
    return(static_cast<int>(sommet)==-1);
}

bool Pile::pilePleine() const
{
    return(sommet==nbMax-1);
}

void Pile::clear(){
    if(!pileVide()){
        for(int i=0; i<=sommet; ++i)
            delete tab[i];
        sommet=-1;
    }
}


Pile* Pile::cloner() const{
    // Il suffit d'appeler le constructeur par recopie sur l'objet courant.
    // Attention, v�rifier � ce que ce constructeur soit correctement impl�ment�.
    return new Pile(*this);
}


void Pile::swap(const int x, const int y){
    if (x < this->sommet && y < this->sommet){
        Donnee* tmp = (tab[sommet-x]);
        this->tab[sommet-x]=tab[sommet-y];
        this->tab[sommet-y]=tmp;
    }
}

void Pile::sum(const unsigned int x){
if (static_cast<unsigned int>(size()) >= x){
    Donnee* res=new Entier(0);
        Donnee*tmp;
        for(unsigned int i=0; i<x; i++){
            tmp=res;
            res=*tmp+tab[sommet-i];
            delete tmp;
        }
        empiler(res);
    }
    else
        {
            QMessageBox msgBox;
            msgBox.setText("Il n'y a pas assez d'�l�ments dans la pile !");
            msgBox.exec();
        }
}

void Pile::mean(const unsigned int x){
    if (static_cast<unsigned int>(size()) >= x){
        Donnee* res=new Entier(0);
        Donnee*tmp;
        for(unsigned int i=0; i<x; i++){
            tmp=res;
            res=*tmp+tab[sommet-i];
            delete tmp;
        }
        Donnee * d;
        Entier* taille= new Entier(x);
        try{
            d=*res/taille;
        }catch(exception &e) {
            QMessageBox msgBox;
            msgBox.setText(e.what() );
            msgBox.exec();
        }
        std::cout<<"apres div"<<std::endl;
        empiler(d);
        }
    else
        {
            QMessageBox msgBox;
            msgBox.setText("Il n'y a pas assez d'�l�ments dans la pile !");
            msgBox.exec();
        }
}


void Pile::dup(){
    if (!pileVide())  empiler(tab[sommet]);
}

void Pile::drop(){
    if(!pileVide()) depiler();

}

