import logging
import noti_constants

logging.basicConfig(filename=noti_constants.LOGGER_PATH_TO_FILE,
                    filemode='w',
                    format='%(asctime)s - %(process)d - %(filename)s - %(levelname)s - '
                           '%(funcName)s - %(lineno)d - %(message)s',
                    level=logging.DEBUG)
logger = logging.getLogger('noti')