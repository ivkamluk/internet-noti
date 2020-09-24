#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QAction>
#include <QDesktopWidget>
#include <QApplication>
#include <thread>

#include "internet.h"
#include "internetobserver.h"

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void create_menu();

    ~MainWindow();

public slots:
    //tray functions
    void tray_action_start();
    void tray_action_stop();
    void tray_action_about();
    void tray_action_exit();
   // void tray_status_changed();

private:
    QDialog *dialog_about;
    Internet *internet;
    QVBoxLayout *vbox_about;
    QLabel *dialog_about_description, *icons_url, *github_url;
    QMenu *menu;
    QSystemTrayIcon *tray_icon;
    QAction *noti_action_start, *noti_action_stop, *noti_action_about,
    *noti_action_exit;
    std::thread noti_thread;
    InternetObserver *internet_observer;
};
#endif // MAINWINDOW_H
