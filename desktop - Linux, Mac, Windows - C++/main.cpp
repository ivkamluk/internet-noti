#include <QApplication>
#include <QIcon>
#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    qDebug() << "internet-noti application started";
    MainWindow w;
    w.create_menu();
    return a.exec();
}
