#include "reel.h"
#include <sstream>
#include <QMessageBox>

#include "entier.h"
#include "rationnel.h"
#include "complexe.h"

QString Reel::toQString() const
{
    QString res;
    res.setNum(valeur);
    return res;
}

Reel::Reel(Entier* aEntier)
{
    valeur = static_cast<double>(aEntier->getValeur());
}

Reel::Reel(Rationnel* aRationnel)
{
    QMessageBox::information(this, "Conversion", "Perte d'information à la conversion d'un réel vers un rationnel !");
    double num = static_cast<double>(aRationnel->getNum());
    double denum = static_cast<double>(aRationnel->getDenum());
    valeur = num/denum;
}

Reel::Reel(Complexe* aComplexe){}
