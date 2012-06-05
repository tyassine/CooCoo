#include "rationnel.h"
#include <sstream>

const string Rationnel::afficher() const
{
    ostringstream oss;
    oss << ent1.afficher() << "/" << ent2.afficher();
    return oss.str();
}
