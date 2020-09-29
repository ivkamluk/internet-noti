#include "macnotification.h"
#include "appconstants.h"

#include <Foundation/Foundation.h>

MacNotification::MacNotification()
{}

void MacNotification::postNotification(QString connection_title, QString website)
{
    NSUserNotification* notification = [[NSUserNotification alloc] init];
    notification.title = APPLICATION_NAME.toNSString();
    QString subtitle = connection_title + " " + website;
    notification.subtitle = subtitle.toNSString();
    //notification.informativeText = website.toNSString();
    notification.soundName = NSUserNotificationDefaultSoundName;   //Will play a default sound
    [[NSUserNotificationCenter defaultUserNotificationCenter] deliverNotification: notification];
    [notification autorelease];
}

MacNotification::~MacNotification()
{}
