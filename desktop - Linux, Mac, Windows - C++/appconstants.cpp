#include "appconstants.h"

//text
 QString CONNECTION_ESTABLISHED = "Connection established to";
 QString CONNECTION_FAILED = "Connection failed to";
 QString INTERNET_STATUS_CONNECTED = "Connected";
 QString INTERNET_STATUS_NOT_CONNECTED = "Not Connected";
 QString INTERNET_STATUS_NOT_MONITORED = "Not Monitored";
 QString ACTION_STATUS = "Status: ";
 QString ACTION_START = "Start";
 QString ACTION_STOP = "Stop";
 QString ACTION_WORKSPACE = "Workspace";
 QString ACTION_SETTINGS = "Settings";
 QString ACTION_ABOUT = "About";
 QString ACTION_EXIT = "Exit";
 QString DIALOG_ABOUT_TITLE = "internet-noti: About";
 QString DIALOG_ABOUT_DESCRIPTION = "An application that sends to you a "
                                        "notification if internet connection"
                                        " was established or not.";
 QString ICONS_URL = "Icons was used from <a href='https://icons8.ru'>Icons8</a> "
                         "and <a href='https://www.flaticon.com/authors/vectors-market'>Flaticon</a>";
 QString GITHUB_URL = "Github: <a href='https://github.com/ivkamluk'>ivkamluk</a>";
 QString NOTIFICATION_TITLE = "internet-noti";
 QString APPLICATION_NAME = "internet-noti";

//icons
 QString ICON_START_ENABLED = ":/images/icons/noti_start_enabled.png";
 QString ICON_START_DISABLED = ":/images/icons/noti_start_disabled.png";
 QString ICON_STOP_ENABLED = ":/images/icons/noti_stop_enabled.png";
 QString ICON_STOP_DISABLED = ":/images/icons/noti_stop_disabled.png";
 QString ICON_TRAY_CONNECTED = ":/images/icons/noti_tray_connected.svg";
 QString ICON_TRAY_NOT_CONNECTED = ":/images/icons/noti_tray_not_connected.svg";
 QString ICON_TRAY_NOT_MONITORED = ":/images/icons/noti_tray_not_monitored.svg";
// QString ICON_TRAY_WORKSPACE = "";
// QString ICON_TRAY_SETTINGS = "";
 QString ICON_NOTIFICATION_CLOSE = ":/images/icons/noti_notification_close.png";

//websites
 std::unordered_map<unsigned short, std::string> WEBSITES
{
    { 0, "www.bing.com"},
    { 1, "www.google.com"},
    { 2, "www.duckduckgo.com"}
};
