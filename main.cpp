#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication CooCoo(argc, argv);
    MainWindow fenetre;
    fenetre.show();
    
    return CooCoo.exec();
}