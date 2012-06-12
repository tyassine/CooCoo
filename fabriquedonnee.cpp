#include "fabriquedonnee.h"


double FabriqueDonnee::int2double(int x)
{
    //dynamic_cast
}

Donnee* FabriqueDonnee::creerDonnee(QString s)
{
        if(Donnee::isComplexe(s))
        {
            return new Complexe(s);
        }
        if(Donnee::isEntier(s))
            return new Entier(s);

        if(Donnee::isReel(s))
            return new Reel(s);

        if(Donnee::isRationnel(s))
        {
            try
        {
            type* res= new Rationnel(s);
            return res;
        }catch (std::exception &e) {
            QMessageBox msgBox;
             msgBox.setText(e.what());
             msgBox.exec();
        }
        }
        if(Donnee::isExpression(s))
            return new ConstanteExp(s);
        else
        {
            return NULL;
        }
}
