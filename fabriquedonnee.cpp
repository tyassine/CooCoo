#include "fabriquedonnee.h"
#include <QStringList>


Donnee* FabriqueDonnee::creerDonnee(const QString& terme)
{
    /*
    if(Donnee::isComplexe(terme))
        return new Complexe(terme);
    */

    if(Donnee::isEntier(terme))
        return new Entier(terme);

    if(Donnee::isReel(terme))
        return new Reel(terme);

    if(Donnee::isRationnel(terme))
    {
        QStringList nombres = terme.split("/");
        return new Rationnel(nombres[0], nombres[1]);
    }

    if(Donnee::isExpression(terme))
        return new ConstanteExp(terme);
    else
        return NULL;
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
