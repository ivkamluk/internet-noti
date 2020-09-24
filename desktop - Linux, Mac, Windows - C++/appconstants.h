#ifndef APPCONSTANTS_H
#define APPCONSTANTS_H

#include <QString>
#include <QIcon>
#include <QPixmap>
#include <unordered_map>

//text
extern const char * CONNECTION_ESTABLISHED;
extern const char * CONNECTION_FAILED;
extern const char * ACTION_START;
extern const char * ACTION_STOP;
extern const char * ACTION_ABOUT;
extern const char * ACTION_EXIT;
extern const char * DIALOG_ABOUT_TITLE;
extern const char * DIALOG_ABOUT_DESCRIPTION;
extern const char * ICONS_URL;
extern const char * GITHUB_URL;
extern QString NOTIFICATION_TITLE;

//icons
extern QString ICON_START_ENABLED;
extern QString ICON_START_DISABLED;
extern QString ICON_STOP_ENABLED;
extern QString ICON_STOP_DISABLED;
extern QString ICON_TRAY_CONNECTED;
extern QString ICON_TRAY_DISCONNECTED;
extern QString ICON_NOTIFICATION_CLOSE;

//websites
extern std::unordered_map<unsigned short, std::string> WEBSITES;

#endif // APPCONSTANTS_H
