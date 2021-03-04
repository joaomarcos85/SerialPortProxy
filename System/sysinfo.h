#ifndef SYSINFO_H
#define SYSINFO_H
#include <QString>

class SysInfo
{

public:
    static QString sys_version(){
        return "1.0.0";
    }

    static QString sys_name(){
        return "Serial Port Proxy";
    }
};

#endif // SYSINFO_H
