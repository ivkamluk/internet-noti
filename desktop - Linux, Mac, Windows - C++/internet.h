#ifndef INTERNET_H
#define INTERNET_H

#include <QWidget>
#include <unordered_map>
#include <string>

#include "appconstants.h"

class Internet : public QWidget
{
    Q_OBJECT
public:
    explicit Internet(QWidget *parent = nullptr);

    void disable_monitoring(bool stop_monitoring);
    InternetStatus get_by_socket_connection_website(std::string website_url);
    void check_internet_connection();
    InternetStatus get_internet_connection_at_launch(std::string website_url);

signals:
    void internet_status_at_launch (InternetStatus status);
    void internet_status_changed(InternetStatus status, QString website);
    void internet_stopped_monitored(InternetStatus status);

private:
    bool isInternet_monitor_stopped;
};

#endif // INTERNET_H
