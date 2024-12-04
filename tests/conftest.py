import pytest

from ragger.conftest import configuration
from utils import LedgerUtils


###########################
### CONFIGURATION START ###
###########################

# You can configure optional parameters by overriding the value of ragger.configuration.OPTIONAL_CONFIGURATION
# Please refer to ragger/conftest/configuration.py for their descriptions and accepted values

configuration.OPTIONAL.MAIN_APP_DIR = "tests/.test_dependencies/"
configuration.OPTIONAL.SIDELOADED_APPS_DIR = "tests/.test_dependencies/"

configuration.OPTIONAL.BACKEND_SCOPE = "class"


#########################
### CONFIGURATION END ###
#########################

# Pull all features from the base ragger conftest using the overridden configuration
pytest_plugins = ("ragger.conftest.base_conftest",)


@pytest.fixture
def ledger_utils(backend, navigator, firmware, test_name):
    return LedgerUtils(backend, navigator, firmware, test_name)
