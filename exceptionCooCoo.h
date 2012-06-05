#ifndef EXCEPTIONCOOCOO_H
#define EXCEPTIONCOOCOO_H

#include <QString>
#include <iostream>

class ExceptionCooCoo
{
    QString infos;

public:
    ExceptionCooCoo(QString s="") : infos(s){}
    void GetInfos() const {std::cout<<infos.toStdString()<<std::endl;}

};

#endif // EXCEPTIONCOOCOO_H
