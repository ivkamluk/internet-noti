#include "internet.h"
#include "appconstants.h"

#include <QThread>
#include <QTcpSocket>
#include <QDebug>


Internet::Internet(QWidget *parent) : QWidget(parent)
{
    isInternet_monitor_stopped = false;
}

void Internet::disable_monitoring(bool stop_monitoring)
{
    this->isInternet_monitor_stopped = stop_monitoring;
}

bool Internet::get_by_socket_connection_website(std::string website_url)
{
      qDebug() <<"Inside socket function";
      QTcpSocket *socket = new QTcpSocket;
      socket->connectToHost(QString(website_url.c_str()), 80);
      if (socket->waitForConnected(3000))
      {
        socket->close();
        return true;
      }
     delete socket;
     return false;
}

void Internet::check_internet_connection()
{
   // before start we need to check if we have internet
   bool internet_current_status = get_internet_connection_at_launch(WEBSITES[0]);

    while (!isInternet_monitor_stopped)
    {
        for (unsigned short i=0; i<WEBSITES.size(); i++)
        {
            while(!isInternet_monitor_stopped)
            {
                bool website_conn_established = get_by_socket_connection_website(WEBSITES[i]);

                if (internet_current_status != website_conn_established)
                {
                    internet_current_status = website_conn_established;
                    emit internet_status_changed(internet_current_status,
                                                 QString::fromUtf8((WEBSITES[i].c_str())));
                }

                if (!website_conn_established)
                    break;

               QThread::sleep(3); // Delay 3s to show notification
            }
        }
    }
}

bool Internet::get_internet_connection_at_launch(std::string website_url)
{
     bool internet_status = get_by_socket_connection_website(website_url);
     emit internet_status_at_launch(internet_status);
     qDebug() << "At launch have an Internet connection " << internet_status;
     return internet_status;
}



