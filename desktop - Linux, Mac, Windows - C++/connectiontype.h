#ifndef CONNECTIONTYPE_H
#define CONNECTIONTYPE_H

#include <QObject>
#include <QString>

class ConnectionType : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionType(QObject *parent = nullptr);
    explicit ConnectionType (bool connection_status, QObject *parent = nullptr);

    QString connection_title();

  private:
      bool is_connection_enabled;
};

#endif // CONNECTIONTYPE_H
