#include "reel.h"
#include <sstream>

const string Reel::afficher() const
{
    ostringstream oss;
    oss << valeur;
    return oss.str();
}
