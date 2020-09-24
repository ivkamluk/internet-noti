#include "notification.h"
#include "styleqss.h"
#include "appconstants.h"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QSysInfo>
#include <QPixmap>

Notification::Notification(QString connection, QString website,
                           bool connection_status,
                           QWidget *parent) : QDialog(parent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setFixedWidth(260);

    frame_notification = new QFrame(this);
    frame_notification->setObjectName("frameNotification");
    vbox_main = new QVBoxLayout;

    vbox_main->addWidget(frame_notification);

    hbox_name_close = new QHBoxLayout;

    label_name = new QLabel(this);
    label_name->setObjectName("label_name");
    label_name->setText(NOTIFICATION_TITLE);

    label_close = new ExtendedLabel(this);
    label_close->setPixmap(QPixmap(ICON_NOTIFICATION_CLOSE));

    hbox_name_close->addWidget(label_name);
    hbox_name_close->addWidget(label_close);
    hbox_name_close->setAlignment(label_name, Qt::AlignLeft);
    hbox_name_close->setAlignment(label_close, Qt::AlignRight);

    frame_line = new QFrame(this);
    frame_line->setFrameShape(QFrame::HLine);
    frame_line->setObjectName("frame_line");

    label_connection_status = new QLabel(this);

    if (connection_status)
         label_connection_status->setObjectName("label_connection_status_good");
    else
        label_connection_status->setObjectName("label_connection_status_bad");

    label_connection_status->setText(connection);

    label_website = new QLabel(this);
    label_website->setObjectName("label_website");
    label_website->setText(website);

    vbox_main->addLayout(hbox_name_close);
    vbox_main->addWidget(frame_line);
    vbox_main->addWidget(label_connection_status);
    vbox_main->addWidget(label_website);

    vbox_main->setAlignment(label_connection_status, Qt::AlignCenter);
    vbox_main->setAlignment(label_website, Qt::AlignCenter);
    vbox_main->setMargin(5);
    vbox_main->setSpacing(5);

    setLayout(vbox_main);

    timer_close_notification = new QTimer(this);
    timer_close_notification->setInterval(3000); // 3 sec
    timer_close_notification->start();

    determine_screen_place();

    connect(timer_close_notification, SIGNAL(timeout()), this, SLOT(reject()));
    connect(label_close, SIGNAL(clicked()), this, SLOT(reject()));
    setStyleSheet(StyleQSS::loadQSSfromFile
                  (":/qss/QSS/notification.qss"));
}

void Notification::determine_screen_place()
{
    QRect screenpos = QApplication::desktop()->screenGeometry();
    int width = screenpos.width() - 320; // macOS and Linux : top-right
    move(width,0);

    #ifdef Q_OS_WIN
       int height = screenpos.height()-100; // Windows : bottom-right
       int width = screenpos.width() - 320;
       move(width,height);
    #endif
}
