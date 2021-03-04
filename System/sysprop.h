#ifndef SYSPROP_H
#define SYSPROP_H

#include <QString>
#include <QSettings>
#include <QDebug>

class SysProp
{
public:
    static SysProp * instance();
    static void makeInstance();
    static void deleteInstance();

    QSettings *customProp();

    //new QSettings("conf/custom.ini",QSettings::IniFormat)


private:
    SysProp();
    QString filePath="conf/custom.ini";
    static SysProp * instance_;
    QSettings *CustomProp;
};

#endif // SYSPROP_H
