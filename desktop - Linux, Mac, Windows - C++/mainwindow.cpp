#include "mainwindow.h"

#include <QDialog>
#include <QCoreApplication>
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    dialog_about = new QDialog(this);
    internet = new Internet(this);
    intrn_observer = new InternetObserver(this);
    menu = new QMenu(this);
    noti_thread = std::thread();
}

void MainWindow::create_menu()
{
    tray_icon = new QSystemTrayIcon(this);
    tray_icon->setIcon(QIcon(":/images/icons/noti_tray.png"));

    noti_action_start = new QAction(QIcon(":/images/icons/noti_start_enabled.png"),
                                    "Start", this);
    noti_action_stop = new QAction(QIcon(":/images/icons/noti_stop_enabled.png"),
                                    "Stop", this);
    noti_action_about = new QAction("About", this);
    noti_action_exit = new QAction("Exit", this);

    tray_action_start(); // by default action start will be enabled

    connect(noti_action_start, SIGNAL(triggered()), this, SLOT(tray_action_start()));
    connect(noti_action_stop, SIGNAL(triggered()), this, SLOT(tray_action_stop()));
    connect(noti_action_about, SIGNAL(triggered()), this, SLOT(tray_action_about()));
    connect(noti_action_exit, SIGNAL(triggered()), this, SLOT(tray_action_exit()));

    menu->addAction(noti_action_start);
    menu->addAction(noti_action_stop);
    menu->addAction(noti_action_about);
    menu->addAction(noti_action_exit);

    tray_icon->setContextMenu(menu);
    tray_icon->show();
}

void MainWindow::tray_action_start()
{
    internet->disable_monitoring(false);
    noti_thread = std::thread(&Internet::check_internet_connection, internet);
    connect(internet, &Internet::internet_status_changed,
                     intrn_observer, &InternetObserver::show_internet_notification);
    qDebug() <<"Thread created";

    noti_action_start->setEnabled(false);
    noti_action_stop->setEnabled(true);
    noti_action_start->setIcon(QIcon(":/images/icons/noti_start_disabled.png"));
    noti_action_stop->setIcon(QIcon(":/images/icons/noti_stop_enabled.png"));
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
    noti_action_stop->setEnabled(false);
    noti_action_start->setIcon(QIcon(":/images/icons/noti_start_enabled.png"));
    noti_action_stop->setIcon(QIcon(":/images/icons/noti_stop_disabled.png"));
}

void MainWindow::tray_action_about()
{
    if (!dialog_about->isVisible())
    {
        const QRect screen = QApplication::desktop()->screenGeometry();
        this->move(screen.center() - this->rect().center());

        dialog_about->setWindowTitle(tr("internet-noti: About"));
        vbox_about = new QVBoxLayout(this);
        dialog_about->setLayout(vbox_about);

        description_text = new QLabel(this);
        description_text->setText(tr("An application that sends to you a "
                                  "notification if internet connection"
                                  " was established or not."));

        icons_url = new QLabel(this);
        icons_url->setText(tr("All icons was used from <a href='https://icons8.ru'>Icons8</a>"));
        icons_url->setOpenExternalLinks(true);

        github_account = new QLabel(this);
        github_account->setText(tr("Github: <a href='https://github.com/ivkamluk'>ivkamluk</a>"));
        github_account->setOpenExternalLinks(true);

        vbox_about->addWidget(description_text);
        vbox_about->addWidget(icons_url);
        vbox_about->addWidget(github_account);

        dialog_about->setFixedSize(600,100);
        dialog_about->exec();
    }
}

void MainWindow::tray_action_exit()
{
   QApplication::quit();
}

MainWindow::~MainWindow()
{
    // stop all threds if app was closed with force
    tray_action_stop();
}

