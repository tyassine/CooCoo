#ifndef MEMENTO_H
#define MEMENTO_H


/*!
* \file memento.h
* \author Letellier/Yassine
*/

/*! \class gardien
* \brief Classe representant un gardien
*/

/* Normalement, dans le design pattern memento, il y a 3 classes:
  créateur (ici, la Pile), Memento (une capsule qui conserve un état du créateur),
  gardien (qui contient un historique des états et communique avec le Memento)
  Ca respecte mieux l'encapsulation

  Mais pour simplifier, on ne fera pas de classe Memento, juste une classe Gardien.
  Le gardien sera appelé depuis la pile pour sauvegarder et restaurer les contextes.
*/

/*
  Donc quand l'utilisateur cliquera sur "undo", par exemple, la calculatrice (mainwindow.cpp)
  fera un truc du genre :
  Pile* newInstancePile = instancePile->gard->undo();
  delete instancePile;
  instancePile = newInstancePile;

 Bref : il faut supprimer l'ancienne instance de Pile (tout l'objet, pas seulement son tableau!)
 et installer la nouvelle dans l'attribut de notre mainwindow
*/

/*
  Mais faut vraiment revoir l'enchainement des undo/redo là, c'est la galère!
*/


#include <QVector>
#include "donnee.h"

class Pile;

class Gardien
{
    // QVector de pointeurs vers des Pile
    // Chaque pointeur correspond à un état sauvegardé
    // Au début je voulais faire un QStack. Ca marche très bien pour undo,
    // Mais ça devient très peu commode pour le redo!
    QVector<Pile*> tabPile;
    int current;

    // Idée : se servir des attributs de cet objet pour rendre possible ou non l'undo/redo
    // j'entends par là griser leurs boutons dans l'interface s'il est impossible de les faire


public:
    // On est obligés d'allouer dès le départ de la mémoire, si l'on veut utiliser, par exemple, tabPile[i]
    Gardien() : tabPile(QVector<Pile*>(200)), current(-1) {}
    ~Gardien();
    void addMemento(Pile* aPile);
    Pile* undo();
    Pile* redo();
    //virtual void execute();

};



#endif // MEMENTO_H
