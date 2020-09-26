#ifndef CONNECTIONTYPE_H
#define CONNECTIONTYPE_H

#include <QObject>
#include <QString>

#include "appconstants.h"

class ConnectionType : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionType(QObject *parent = nullptr);
    explicit ConnectionType (InternetStatus connection_status, QObject *parent = nullptr);

    QString connection_title();

  private:
      InternetStatus is_connection_enabled;
};

#endif // CONNECTIONTYPE_H
