#include "appconstants.h"

 const char * CONNECTION_ESTABLISHED = "Connection established to";
 const char * CONNECTION_FAILED = "Connection failed to";
 const char * ACTION_START = "Start";
 const char * ACTION_STOP = "Stop";
 const char * ACTION_ABOUT = "About";
 const char * ACTION_EXIT = "Exit";
 const char * DIALOG_ABOUT_TITLE = "internet-noti: About";
 const char * DIALOG_ABOUT_DESCRIPTION = "An application that sends to you a "
                                        "notification if internet connection"
                                        " was established or not.";
 const char * ICONS_URL = "Icons was used from <a href='https://icons8.ru'>Icons8</a> "
                         "and <a href='https://www.flaticon.com/authors/vectors-market'>Flaticon</a>";
 const char * GITHUB_URL = "Github: <a href='https://github.com/ivkamluk'>ivkamluk</a>";
 QString NOTIFICATION_TITLE = "internet-noti";

//icons
 QString ICON_START_ENABLED = ":/images/icons/noti_start_enabled.png";
 QString ICON_START_DISABLED = ":/images/icons/noti_start_disabled.png";
 QString ICON_STOP_ENABLED = ":/images/icons/noti_stop_enabled.png";
 QString ICON_STOP_DISABLED = ":/images/icons/noti_stop_disabled.png";
 QString ICON_TRAY_CONNECTED = ":/images/icons/noti_tray_connected.svg";
 QString ICON_TRAY_DISCONNECTED = ":/images/icons/noti_tray_disconnected.svg";
 QString ICON_NOTIFICATION_CLOSE = ":/images/icons/noti_notification_close.png";

//websites
 std::unordered_map<unsigned short, std::string> WEBSITES
{
    { 0, "www.bing.com"},
    { 1, "www.google.com"},
    { 2, "www.duckduckgo.com"}
};
