#ifndef INTERNETOBSERVER_H
#define INTERNETOBSERVER_H

#include <QWidget>

#include "connectiontype.h"
#include "notification.h"
#include "appconstants.h"

class InternetObserver : public QWidget
{
    Q_OBJECT
public:
    explicit InternetObserver(QWidget *parent = nullptr);

public slots:
    QString determine_internet_status(InternetStatus status);
    void show_internet_notification(InternetStatus status, QString website);

private:
        ConnectionType *connectiontype;
        Notification *notification;
};

#endif // INTERNETOBSERVER_H
