#include "rationnel.h"
#include <sstream>

#include "entier.h"
#include "reel.h"

QString Rationnel::toQString() const
{
    QString resNum, resDenom, res;
    resNum.setNum(num);
    resDenom.setNum(denom);
    res = resNum + "/" + resDenom;
    return res;
}

Rationnel::Rationnel(const Entier* aEntier)
{
    num = aEntier->getValeur();
    denom = 1;
}

Rationnel::Rationnel(const Reel* aReel)
{
   /*
     Ca a l'air d'être un algo compliqué... ce qui semble logique,
     http://stackoverflow.com/questions/95727/how-to-convert-floats-to-human-readable-fractions
   */

    // En attendant :
    num = 999;
    denom = 999;
}

