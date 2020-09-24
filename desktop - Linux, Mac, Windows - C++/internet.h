#ifndef INTERNET_H
#define INTERNET_H

#include <QWidget>
#include <unordered_map>
#include <string>

class Internet : public QWidget
{
    Q_OBJECT
public:
    explicit Internet(QWidget *parent = nullptr);

    void disable_monitoring(bool stop_monitoring);
    bool get_by_socket_connection_website(std::string website_url);
    void check_internet_connection();
    bool get_internet_connection_at_launch(std::string website_url);

signals:
    void internet_status_at_launch (bool status);
    void internet_status_changed(bool status, QString website);

private:
    bool isInternet_monitor_stopped;
};

#endif // INTERNET_H
