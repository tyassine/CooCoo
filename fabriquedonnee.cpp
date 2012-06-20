#include "fabriquedonnee.h"
#include <QStringList>
#include <QMessageBox>
#include <typeinfo>

// Initialisation du membre statique du singleton
FabriqueDonnee* FabriqueDonnee::instance = 0;

FabriqueDonnee* FabriqueDonnee::getInstance()
{
    if (!instance) instance = new FabriqueDonnee;
    return instance;
}

void FabriqueDonnee::libereInstance()
{
    if (instance) delete instance;
}

Donnee* FabriqueDonnee::creerDonnee(const QString& terme)
{

    if(Donnee::isComplexe(terme))
    {
        QStringList nombres = terme.split("$");
        // Static cast car on est SUR que l'on n'obtiendra jamais une ConstanteExp, et donc que le résultat sera toujours de type Constante!
        Constante* pRe = static_cast<Constante*>(creerDonnee(nombres[0]));
        Constante* pIm = static_cast<Constante*>(creerDonnee(nombres[1]));
        return new Complexe(pRe, pIm);
    }

    if(Donnee::isEntier(terme))
        return new Entier(terme);

    if(Donnee::isReel(terme))
        return new Reel(terme);

    if(Donnee::isRationnel(terme))
    {
        try{
            return new Rationnel(terme);
        }
        catch (ExceptionCooCoo &e) {
             QMessageBox msgBox;
             msgBox.setText(e.GetInfos());
             msgBox.exec();
        }
        return NULL;
    }


    if(Donnee::isComplexe(terme))
    {
        return new Complexe(terme);
    }

    if(Donnee::isExpression(terme))
        return new ConstanteExp(terme);
    else
        return NULL;
}



Donnee* FabriqueDonnee::creerDonnee(const Donnee* donneeDepart, int typeSouhaite, int complexe)
{
    if (typeid(*donneeDepart)==typeid(Entier))
        return creerDonneeStatic(static_cast<const Entier*>(donneeDepart), typeSouhaite, complexe);
    if (typeid(*donneeDepart)==typeid(Reel))
        return creerDonneeStatic(static_cast<const Reel*>(donneeDepart), typeSouhaite, complexe);
    if (typeid(*donneeDepart)==typeid(Rationnel))
        return creerDonneeStatic(static_cast<const Rationnel*>(donneeDepart), typeSouhaite, complexe);
    if (typeid(*donneeDepart)==typeid(Complexe))
        return creerDonneeStatic(static_cast<const Complexe*>(donneeDepart), typeSouhaite, complexe);

}


