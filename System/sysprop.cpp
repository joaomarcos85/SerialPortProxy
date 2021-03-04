#include "System/sysprop.h"
#include <QDebug>

SysProp *SysProp::instance_ = 0;

void SysProp::makeInstance(){
    instance_ = new SysProp;
}

void SysProp::deleteInstance(){
    delete instance_;
}

SysProp * SysProp::instance()
{
    if(!instance_){
        makeInstance();
    }

    return instance_;
}

SysProp::SysProp()
{
    this->CustomProp = new QSettings(filePath,QSettings::IniFormat);
}

QSettings *SysProp::customProp()
{
    return this->CustomProp;
}

