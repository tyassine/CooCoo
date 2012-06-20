#include "logsystem.h"

LogMessage::LogMessage(const std::string& str,unsigned int d){
    this->log = QString(str.c_str());
    this->imp = d;
}

void LogSystem::imprim(const LogMessage& mes){

    std::cerr<<mes.getLog().toStdString()<<endl;

    QFile file("LogFichier");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
         return;

    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << mes.getLog().toStdString().c_str() << endl;
}
