#ifndef MACNOTIFICATION_H
#define MACNOTIFICATION_H

#include <QString>
#include "appconstants.h"

class MacNotification
{
public:
    MacNotification();
    void postNotification(QString connection_title, QString website);
    ~MacNotification();
};

#endif // MACNOTIFICATION_H
