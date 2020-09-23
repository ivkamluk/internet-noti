#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QDialog>
#include <QFrame>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QString>
#include <string>

#include "extendedlabel.h"

class Notification : public QDialog
{
    Q_OBJECT
public:
    explicit Notification(QString connection, QString website,
                          bool connection_status,
                          QWidget *parent = nullptr);

    void determine_screen_place();

private:
    QFrame *frame_notification, *frame_line;
    QVBoxLayout *vbox_main;
    QTimer *timer_close_notification;
    ExtendedLabel *label_close;
    QLabel *label_connection_status, *label_website,
    *label_name;
    QHBoxLayout *hbox_name_close;
};

#endif // NOTIFICATION_H
