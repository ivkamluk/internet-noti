#include "connectiontype.h"
#include "appconstants.h"

#include <QDebug>

ConnectionType::ConnectionType(QObject *parent) : QObject(parent)
{}

ConnectionType::ConnectionType(bool connection_status, QObject *parent)
    : QObject(parent)
{
   is_connection_enabled = connection_status;
}

QString ConnectionType::connection_title()
{
    return is_connection_enabled ?
                tr(CONNECTION_ESTABLISHED) : tr(CONNECTION_FAILED);
}
