#ifndef INTERNETOBSERVER_H
#define INTERNETOBSERVER_H

#include <QWidget>
#include <string>

#include "connectiontype.h"
#include "notification.h"

class InternetObserver : public QWidget
{
    Q_OBJECT
public:
    explicit InternetObserver(QWidget *parent = nullptr);

public slots:
    void show_internet_notification(bool status, QString website);

private:
        ConnectionType *connectiontype;
        Notification *notification;
};

#endif // INTERNETOBSERVER_H
