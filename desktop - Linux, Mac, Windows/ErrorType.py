class ErrorType:

    def __init__(self, statusConnection):
        self.statusConnection = statusConnection

    def error_title(self):
        if self.statusConnection:
            return "Connection established to "
        else:
            return "Connection failed with "





