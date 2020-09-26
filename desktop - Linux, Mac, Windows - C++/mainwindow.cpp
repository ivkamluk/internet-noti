#include "mainwindow.h"

#include <QDialog>
#include <QApplication>
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    dialog_about = new QDialog(this);
    internet = new Internet(this);
    internet_observer = new InternetObserver(this);
    menu = new QMenu(this);
    noti_thread = std::thread();
}

void MainWindow::create_menu()
{
    tray_icon = new QSystemTrayIcon(this);
    noti_action_status = new QAction("", this);
    noti_action_status->setDisabled(true);
    noti_action_start = new QAction(QIcon(ICON_START_ENABLED),
                                    QObject::tr(qPrintable(ACTION_START)), this);
    noti_action_stop = new QAction(QIcon(ICON_STOP_ENABLED),
                                    QObject::tr(qPrintable(ACTION_STOP)), this);
    noti_action_workspace = new QAction(QObject::tr(qPrintable(ACTION_WORKSPACE)), this);
    noti_action_settings = new QAction(QObject::tr(qPrintable(ACTION_SETTINGS)), this);
    noti_action_about = new QAction(QObject::tr(qPrintable(ACTION_ABOUT)), this);
    noti_action_exit = new QAction(QObject::tr(qPrintable(ACTION_EXIT)), this);

    tray_action_start(); // by default action start will be enabled

    connect(noti_action_start, SIGNAL(triggered()), this, SLOT(tray_action_start()));
    connect(noti_action_stop, SIGNAL(triggered()), this, SLOT(tray_action_stop()));
    connect(noti_action_workspace, SIGNAL(triggered()), this, SLOT(tray_action_workspace()));
    connect(noti_action_settings, SIGNAL(triggered()), this, SLOT(tray_action_settings()));
    connect(noti_action_about, SIGNAL(triggered()), this, SLOT(tray_action_about()));
    connect(noti_action_exit, SIGNAL(triggered()), this, SLOT(tray_action_exit()));

    menu->addAction(noti_action_status);
    menu->addAction(noti_action_start);
    menu->addAction(noti_action_stop);
    menu->addSeparator();
    menu->addAction(noti_action_workspace);
    menu->addAction(noti_action_settings);
    menu->addAction(noti_action_about);
    menu->addSeparator();
    menu->addAction(noti_action_exit);

    tray_icon->setContextMenu(menu);
    tray_icon->show();
}

void MainWindow::tray_action_start()
{
    internet->disable_monitoring(false);
    noti_thread = std::thread(&Internet::check_internet_connection, internet);
    connect (internet, &Internet::internet_status_at_launch,
                this, &MainWindow::tray_status_changed);
    connect(internet, &Internet::internet_status_changed,
                internet_observer, &InternetObserver::show_internet_notification);
    connect(internet, &Internet::internet_status_changed,
                this, &MainWindow::tray_status_changed);
    connect (internet, &Internet::internet_stopped_monitored,
                this, &MainWindow::tray_status_changed);

    qDebug() <<"Thread created";

    noti_action_start->setDisabled(true);
    noti_action_stop->setEnabled(true);
    noti_action_start->setIcon(QIcon(ICON_START_DISABLED));
    noti_action_stop->setIcon(QIcon(ICON_STOP_ENABLED));
}

void MainWindow::tray_action_stop()
{
    internet->disable_monitoring(true);
    if (noti_thread.joinable())
    {
        noti_thread.join();
        qDebug() <<"Thread stopped";
    }

    noti_action_start->setEnabled(true);
    noti_action_stop->setDisabled(true);
    noti_action_start->setIcon(QIcon(ICON_START_ENABLED));
    noti_action_stop->setIcon(QIcon(ICON_STOP_DISABLED));
}

void MainWindow::tray_action_workspace()
{
    // code will be added soon
}

void MainWindow::tray_action_settings()
{
    // code will be added soon
}

void MainWindow::tray_action_about()
{
    if (!dialog_about->isVisible())
    {
        const QRect screen = QApplication::desktop()->screenGeometry();
        this->move(screen.center() - this->rect().center());

        dialog_about->setWindowTitle(QObject::tr(qPrintable(DIALOG_ABOUT_TITLE)));
        vbox_about = new QVBoxLayout(this);
        dialog_about->setLayout(vbox_about);

        dialog_about_description = new QLabel(this);
        dialog_about_description->setText(QObject::tr(qPrintable(DIALOG_ABOUT_DESCRIPTION)));

        icons_url = new QLabel(this);
        icons_url->setText(QObject::tr(qPrintable(ICONS_URL)));
        icons_url->setOpenExternalLinks(true);

        github_url = new QLabel(this);
        github_url->setText(QObject::tr(qPrintable(GITHUB_URL)));
        github_url->setOpenExternalLinks(true);

        vbox_about->addWidget(dialog_about_description);
        vbox_about->addWidget(icons_url);
        vbox_about->addWidget(github_url);

        dialog_about->setFixedSize(600,100);
        dialog_about->exec();
    }
}

void MainWindow::tray_action_exit()
{
   QApplication::quit();
}

void MainWindow::tray_status_changed(InternetStatus status)
{
    switch(status)
    {
        case INTERNET_NOT_MONITORED:
            noti_action_status->setText(QObject::tr(qPrintable(ACTION_STATUS)) +
                                        QObject::tr(qPrintable(INTERNET_STATUS_NOT_MONITORED)));
            QApplication::setWindowIcon(QIcon(ICON_TRAY_NOT_MONITORED));
            tray_icon->setIcon(QIcon(ICON_TRAY_NOT_MONITORED));
            break;
        case INTERNET_CONNECTED:
            noti_action_status->setText(QObject::tr(qPrintable(ACTION_STATUS)) +
                                        QObject::tr(qPrintable(INTERNET_STATUS_CONNECTED)));
            QApplication::setWindowIcon(QIcon(ICON_TRAY_CONNECTED));
            tray_icon->setIcon(QIcon(ICON_TRAY_CONNECTED));
            break;
        case INTERNET_NOT_CONNECTED:
            noti_action_status->setText(QObject::tr(qPrintable(ACTION_STATUS)) +
                                        QObject::tr(qPrintable(INTERNET_STATUS_NOT_CONNECTED)));
            QApplication::setWindowIcon(QIcon(ICON_TRAY_NOT_CONNECTED));
            tray_icon->setIcon(QIcon(ICON_TRAY_NOT_CONNECTED));
            break;
    }
}

MainWindow::~MainWindow()
{
    // stop all threads if app was closed with force
    tray_action_stop();
}

