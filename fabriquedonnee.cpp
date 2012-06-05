#include "fabriquedonnee.h"

Donnee* FabriqueDonnee::creerDonnee(const QString& typeDonnee, const QString& valeur)
{
    if (typeDonnee == "Entier")
        return new Entier(valeur);
    if (typeDonnee == "Reel")
        return new Reel(valeur);
    if (typeDonnee == "Rationnel")
        return new Entier(valeur);
    if (typeDonnee == "Complexe")
        return new Entier(valeur);

    // Glisser exception si le type ne correspond à rien
}
