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

signals:
    void internet_status_changed(bool status, QString website);

private:
    bool isInternet_monitor_stopped;
    std::unordered_map<unsigned short, std::string> websites;
};

#endif // INTERNET_H
