#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icons/noti_tray.png"));
    a.setQuitOnLastWindowClosed(false);
    qDebug() << "internet-noti application started";
    MainWindow w;
    w.create_menu();
    return a.exec();
}
