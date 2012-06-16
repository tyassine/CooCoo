#include "rationnel.h"
#include <sstream>

#include "entier.h"
#include "reel.h"

QString Rationnel::toQString() const
{
    QString resNum, resDenum, res;
    resNum.setNum(num);
    resDenum.setNum(denum);
    res = resNum + "/" + resDenum;
    return res;
}

Rationnel::Rationnel(const Entier* aEntier)
{
    num = aEntier->getValeur();
    denum = 1;
}

Rationnel::Rationnel(const Reel* aReel)
{
   /*
     Ca a l'air d'être un algo compliqué... ce qui semble logique,
     http://stackoverflow.com/questions/95727/how-to-convert-floats-to-human-readable-fractions
   */

    // En attendant :
    num = 999;
    denum = 999;
}

