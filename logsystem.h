#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QString>
#include <sstream>

class LogMessage
{
    QString log;
    unsigned int imp;

public:
    LogMessage(const std::string&,unsigned int);
    QString getLog()const{

        std::stringstream str;
        str<<"("<<imp<<")";
        return QString(str.str().c_str()+log);

        }
};

class LogSystem
{
public:
    static void imprim(const LogMessage &);
};

#endif // LOGSYSTEM_H
