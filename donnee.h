#ifndef DONNEE_H
#define DONNEE_H

#include <string>

using namespace std;

// ABSTRAITE

class Donnee
{
public:
    Donnee();
    virtual const string afficher() const = 0; // Définit ce qui va être lu par l'utilisateur
};

#endif // DONNEE_H
