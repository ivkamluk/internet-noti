#ifndef INTERNETOBSERVER_H
#define INTERNETOBSERVER_H

#include <QWidget>

#include "connectiontype.h"
#include "notification.h"
#include "appconstants.h"
#include "macnotification.h"

class InternetObserver : public QWidget
{
    Q_OBJECT
public:
    explicit InternetObserver(QWidget *parent = nullptr);

public slots:
    void show_internet_notification(InternetStatus status, QString website);

private:
        ConnectionType *connectiontype;
//        Notification *notification;
        MacNotification *macnotification;
};

#endif // INTERNETOBSERVER_H
