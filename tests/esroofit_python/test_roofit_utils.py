import sys

import unittest
import unittest.mock as mock

import ROOT

from esroofit import resources
from esroofit.roofit_utils import load_libesroofit


class LoadLibesroofitTest(unittest.TestCase):
    """Tests for loading Eskapade RooFit library"""

    @mock.patch('ROOT.gSystem.GetLibraries')
    @mock.patch('ROOT.gSystem.Load')
    @mock.patch('esroofit.roofit_utils.CUSTOM_ROOFIT_OBJECTS')
    def test_load_libesroofit(self, mock_objects, mock_load, mock_get_libraries):
        """Test loading Eskapade RooFit library"""

        # set custom object attributes
        ROOT.MyCustomClass = mock.Mock(name='MyCustomClass')
        ROOT.MyCustomNamespace = mock.Mock(name='MyCustomNamespace')

        # the Eskapade RooFit library name
        esroofit_lib_base = 'libesroofit'
        if sys.platform == 'darwin':
            esroofit_lib_ext = '.dylib'
        else:
            esroofit_lib_ext = '.so'
        esroofit_lib_name = esroofit_lib_base + esroofit_lib_ext

        # test normal build/load
        mock_objects.__iter__ = lambda s: iter(('MyCustomClass', ('MyCustomNamespace', 'MyCustomFunction')))
        mock_load.return_value = 0
        mock_get_libraries.return_value = 'lib/libmylib.so'
        load_libesroofit()
        mock_load.assert_called_once_with(resources.lib(esroofit_lib_name))
        mock_load.reset_mock()

        # test with loaded library
        mock_get_libraries.return_value = 'lib/libmylib.so lib/{}'.format(esroofit_lib_name)
        load_libesroofit()
        mock_load.assert_not_called()
        mock_get_libraries.return_value = 'lib/libmylib.so'
        mock_load.reset_mock()

        # test failed load
        mock_load.return_value = -1
        with self.assertRaises(RuntimeError):
            load_libesroofit()
        mock_load.return_value = 0
        mock_load.reset_mock()

        # test missing custom class
        mock_objects.__iter__ = lambda s: iter(('NoSuchClass',))
        with self.assertRaises(RuntimeError):
            load_libesroofit()

        # delete custom class attribute
        del ROOT.MyCustomClass
