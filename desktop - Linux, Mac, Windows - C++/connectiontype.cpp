#include "connectiontype.h"
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
    if (is_connection_enabled)
        return tr("Connection established to");
    else
        return tr("Connection failed to");
}
