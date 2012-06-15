#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

class Entier;
class Reel;
class Rationnel;

class Convertisseur
{
public:
    static Entier* toEntier(const Reel* aReel);
    static Entier* toEntier(const Rationnel* aRationnel);
    static Reel* toReel(const Entier* aEntier);
    static Reel* toReel(const Rationnel* aRationnel);
    static Rationnel* toRationnel(const Entier* aEntier);
    static Rationnel* toRationnel(const Reel* aReel);
};

#endif // CONVERTISSEUR_H
