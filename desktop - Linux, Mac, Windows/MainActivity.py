import threading
import concurrent.futures
import time
from logger import logger
from Internet import Internet
import noti_constants

from PyQt5.QtCore import pyqtSignal
from PyQt5 import QtWidgets
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QSystemTrayIcon, QAction, QWidget, QLabel, QDialog, QVBoxLayout

class MainActivity(QWidget):

    def __init__(self):
        QWidget.__init__(self)
        self.dialog_about = QDialog()
        self.internet = Internet()
        self.internet_monitor_start = pyqtSignal()
        self.internet_monitor_stop = pyqtSignal()
        self.noti_thread = None

    def create_menu(self):
        self.menu = QtWidgets.QMenu()

        self.trayIcon = QSystemTrayIcon()
        self.trayIcon.setIcon(QIcon(noti_constants.ICON_NOTI_TRAY))

        self.noti_action_start = QAction(QIcon(noti_constants.ICON_NOTI_START_ENABLED), "Start", self.menu)
        self.noti_action_stop = QAction(QIcon(noti_constants.ICON_NOTI_STOP_ENABLED), "Stop", self.menu)
        self.noti_action_about = QAction("About", self.menu)
        self.noti_action_exit = QAction("Exit", self.menu)

        self.tray_action_start()  # by default action start will be enabled

        self.noti_action_start.triggered.connect(self.tray_action_start)
        self.noti_action_stop.triggered.connect(self.tray_action_stop)
        self.noti_action_about.triggered.connect(self.tray_action_about)
        self.noti_action_exit.triggered.connect(self.tray_action_exit)

        self.menu.addAction(self.noti_action_start)
        self.menu.addAction(self.noti_action_stop)
        self.menu.addAction(self.noti_action_about)
        self.menu.addAction(self.noti_action_exit)

        self.trayIcon.setContextMenu(self.menu)
        self.trayIcon.show()
        # -----
        logger.debug('Tray menu was created')
        # -----

    def tray_action_start(self):
        self.internet.enable_monitoring(False)
        self.noti_thread = threading.Thread(target = self.internet.check_internet_connection, daemon = True)
        # -----
        logger.debug('New thread was CREATED')
        # -----
        self.noti_thread.start()
        self.noti_action_start.setEnabled(False)
        self.noti_action_stop.setEnabled(True)
        self.noti_action_start.setIcon(QIcon(noti_constants.ICON_NOTI_START_DISABLED))
        self.noti_action_stop.setIcon(QIcon(noti_constants.ICON_NOTI_STOP_ENABLED))
        # -----
        logger.debug('Tray menu > Start was clicked')
        # -----

    def tray_action_stop(self):
        self.internet.enable_monitoring(True)
        threading.Thread.join(self.noti_thread)
        # -----
        logger.debug('Created Thread was STOPPED')
        # -----
        self.noti_action_start.setEnabled(True)
        self.noti_action_stop.setEnabled(False)
        self.noti_action_stop.setIcon(QIcon(noti_constants.ICON_NOTI_STOP_DISABLED))
        self.noti_action_start.setIcon(QIcon(noti_constants.ICON_NOTI_START_ENABLED))
        # -----
        logger.debug('Tray menu > Stop was clicked')
        # -----

    def tray_action_about(self):
        if not self.dialog_about.isVisible():
            self.dialog_about.setWindowTitle("internet-noti: About")
            vbox_about = QVBoxLayout()
            self.dialog_about.setLayout(vbox_about)

            description_text = QLabel()
            description_text.setText("An application that sends to you a notification if internet connection"
                                     " was established or not.")

            icons_url = QLabel()
            icons_url.setText("All icons was used from <a href='https://icons8.ru'>Icons8</a>")
            icons_url.setOpenExternalLinks(True)

            github_account = QLabel()
            github_account.setText("Github: <a href='https://github.com/ivkamluk'>ivkamluk</a>")
            github_account.setOpenExternalLinks(True)

            vbox_about.addWidget(description_text)
            vbox_about.addWidget(icons_url)
            vbox_about.addWidget(github_account)

            self.dialog_about.setFixedSize(600,100) # Max width and height for about content
            # -----
            logger.debug('Tray menu > About was clicked')
            # -----
            self.dialog_about.exec()

    def tray_action_exit(self):
        # -----
        logger.debug('Tray menu > Exit was clicked')
        # -----
        self.tray_action_stop()
        exit()