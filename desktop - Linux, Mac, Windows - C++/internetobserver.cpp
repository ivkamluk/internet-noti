#include "internetobserver.h"

InternetObserver::InternetObserver(QWidget *parent) : QWidget(parent)
{}

void InternetObserver::show_internet_notification(bool status, QString website)
{
    connectiontype = new ConnectionType(status, this);
    notification = new Notification(connectiontype->connection_title(),
                                    website, status, this);
    notification->show();
}
