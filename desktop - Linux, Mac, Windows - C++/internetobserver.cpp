#include "internetobserver.h"

InternetObserver::InternetObserver(QWidget *parent) : QWidget(parent)
{}

QString InternetObserver::determine_internet_status(InternetStatus status)
{

}

void InternetObserver::show_internet_notification(InternetStatus status, QString website)
{
    connectiontype = new ConnectionType(status, this);
    notification = new Notification(connectiontype->connection_title(),
                                    website, status, this);
    notification->show();
}
