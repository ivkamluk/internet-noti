#ifndef APPCONSTANTS_H
#define APPCONSTANTS_H

#include <QString>
#include <QIcon>
#include <QPixmap>
#include <unordered_map>
#include <QApplication>

//text
extern QString CONNECTION_ESTABLISHED;
extern QString CONNECTION_FAILED;
extern QString INTERNET_STATUS_CONNECTED;
extern QString INTERNET_STATUS_NOT_CONNECTED;
extern QString INTERNET_STATUS_NOT_MONITORED;
extern QString ACTION_STATUS;
extern QString ACTION_START;
extern QString ACTION_STOP;
extern QString ACTION_WORKSPACE;
extern QString ACTION_SETTINGS;
extern QString ACTION_ABOUT;
extern QString ACTION_EXIT;
extern QString DIALOG_ABOUT_TITLE;
extern QString DIALOG_ABOUT_DESCRIPTION;
extern QString ICONS_URL;
extern QString GITHUB_URL;
extern QString NOTIFICATION_TITLE;

//icons
extern QString ICON_START_ENABLED;
extern QString ICON_START_DISABLED;
extern QString ICON_STOP_ENABLED;
extern QString ICON_STOP_DISABLED;
extern QString ICON_TRAY_CONNECTED;
extern QString ICON_TRAY_NOT_CONNECTED;
extern QString ICON_TRAY_NOT_MONITORED;
//extern QString ICON_TRAY_WORKSPACE;
//extern QString ICON_TRAY_SETTINGS;
extern QString ICON_NOTIFICATION_CLOSE;

//websites
extern std::unordered_map<unsigned short, std::string> WEBSITES;

//enums
enum InternetStatus
{
    INTERNET_NOT_MONITORED,   // monitoring disabled for determening connection
    INTERNET_CONNECTED,      // connection established
    INTERNET_NOT_CONNECTED // connection failed
};

#endif // APPCONSTANTS_H
