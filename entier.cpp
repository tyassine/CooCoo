#include "entier.h"
#include <sstream>

const string Entier::afficher() const
{
    ostringstream oss;
    oss << valeur;
    return oss.str();
}
