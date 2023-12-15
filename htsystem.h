#ifndef HTSYSTEM_H
#define HTSYSTEM_H

#include "htSystem_global.h"
class HTSYSTEM_EXPORT htSystem
{
public:
    htSystem();
    int memTKB(); //Return total memory in KB
    double memTMB(); //Return total memory in MB
    double memTGB(); //Return total memory in GB
    int memFKB(); //Return Free memory in KB
    double memFMB(); //Return Free memory in MB
    double memFGB(); //Return Free memory in GB
    int memUKB(); //Return Used memory in KB
    double memUMB(); //Return Used memory in MB
    double memUGB(); //Return Used memory in GB
    void upTime(int*,int*,int*,int*); //Return system uptime
    string hostPull();
    string osPull();
    string kernPull();
    double cpuUse();
};

#endif // HTSYSTEM_H
