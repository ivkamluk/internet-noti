# import notify2
import noti_constants
from logger import logger

import pync
import os
import platform

def show_notification(website_status, website_url):

    # if platform.system() == 'Linux':
    #     notify2.init("internet-noti")
    #     noti = notify2.Notification("internet-noti ",
    #                                 website_status + website_url,
    #                                 noti_constants.ICON_NOTI_TRAY
    #                                )
    #     noti.show()
    # elif
    if platform.system() == 'Darwin': # MacOS
        pync.notify(title='internet-noti ', message=website_url,
                    subtitle=website_status, remove ='ALL')

    # -----
    logger.debug('Notification displayed for system > %s', platform.system())
    # -----