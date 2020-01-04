import requests
import time
from notification import show_notification
from ErrorType import ErrorType
from logger import logger

from PyQt5.QtCore import QObject, pyqtSlot

class Internet(QObject):
    def __init__(self):
        QObject.__init__(self)
        self.isInternet_monitor_stopped = None

    # websites request
    websites = {    # replace values with websites of which you would like to send response
         0:  'http://www.kamluk.wd.nubip.edu.ua',
         1:  'http://www.google.com',
         2:  'https://duckduckgo.com/'
    }

    # -----
    logger.debug('Provided URLs to connection >\n %s', websites)
    # -----

    def enable_monitoring(self, isInternet_monitor_stopped):
        self.isInternet_monitor_stopped = isInternet_monitor_stopped

    def get_request_connection_website(self, website_url):
        # if connection was corrupted, than let`s check next website
        try:
            internet_status = requests.get(website_url)
        except Exception as e:
            return False
        # we will return True (200 statusCode) if all is fine
        return True if internet_status else False

    def check_internet_connection(self):
        # before start we need to check if we have internet
        internet_current_status = self.get_request_connection_website(self.websites[0])
        # -----
        logger.warning('Have an Internet connection > %s', internet_current_status)
        # -----
        while not self.isInternet_monitor_stopped:
            for i in range (len(self.websites)):
                while not self.isInternet_monitor_stopped:
                     website_conn_established = self.get_request_connection_website(self.websites[i])

                     if internet_current_status != website_conn_established:
                         internet_current_status = website_conn_established
                         show_notification(ErrorType(website_conn_established).error_title(), self.websites[i])

                     if not website_conn_established:
                         break

                     time.sleep(2)  # Delay 2s to show notification