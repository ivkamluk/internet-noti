import sys # using for arguments to QApplication
from MainActivity import MainActivity
from PyQt5.QtWidgets import QApplication
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import QSize
from logger import logger
import noti_constants

if __name__ == '__main__':
    # -----
    logger.debug('Internet-noti application started')
    # -----
    app = QApplication(sys.argv)
    app_icon = QIcon()
    app_icon.addFile(noti_constants.ICON_NOTI, QSize(24,24))
    noti_app = MainActivity()
    noti_app.create_menu()

    app.setWindowIcon(app_icon)
    app.setQuitOnLastWindowClosed(False)
    sys.exit(app.exec())