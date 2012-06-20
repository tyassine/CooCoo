#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "mainwindow.h"
#include "logsystem.h"

int main(int argc, char *argv[])
{
    QFile file("LogFichier");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.close();

    LogSystem::imprim(LogMessage("Demarrage de l'application", 1));

    QApplication CooCoo(argc, argv);

    // Traduction des QMessageBox en français
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    CooCoo.installTranslator(&translator);
    // Fin de trad

    MainWindow fenetre;
    fenetre.InitParam();
    fenetre.show();
    fenetre.refresh();


    LogSystem::imprim(LogMessage("Fermeture de l'application", 1));
    CooCoo.exec();

    return 0;
}
