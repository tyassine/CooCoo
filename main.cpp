#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
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

    return CooCoo.exec();
}
