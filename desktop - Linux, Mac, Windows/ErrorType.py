from logger import logger

class ErrorType:

    def __init__(self, statusConnection):
        self.statusConnection = statusConnection

    def error_title(self):
        if self.statusConnection:
            # -----
            logger.debug(' Connection  was established')
            # -----
            return "Connection established to "
        else:
            # -----
            logger.debug(' Connection  was failed')
            # -----
            return "Connection failed with "





