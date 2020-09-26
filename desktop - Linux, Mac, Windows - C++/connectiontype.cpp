#include "connectiontype.h"

#include <QDebug>

ConnectionType::ConnectionType(QObject *parent) : QObject(parent)
{}

ConnectionType::ConnectionType(InternetStatus connection_status, QObject *parent)
    : QObject(parent)
{
   is_connection_enabled = connection_status;
}

QString ConnectionType::connection_title()
{
   if (is_connection_enabled == INTERNET_CONNECTED)
       return QObject::tr(qPrintable(CONNECTION_ESTABLISHED));
   else
       return QObject::tr(qPrintable(CONNECTION_FAILED));
//    return is_connection_enabled ?
//                QObject::tr(qPrintable(CONNECTION_ESTABLISHED)) : QObject::tr(qPrintable(CONNECTION_FAILED));
}
