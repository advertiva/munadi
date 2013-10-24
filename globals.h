#ifndef GLOBALS_H
#define GLOBALS_H

#include "libitl/prayer.h"
#include <QtCore>

struct City
{
    QString name;
    int calcMethod;
    Location location;
    Method method;
    Prayer ptList[6];
};

#define APP_VERSION "1.0.0"

#endif //GLOBALS_H
