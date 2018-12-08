=============
Eskapade-ROOT
=============

* Version: 0.9.0
* Released: Dec 2018

Eskapade is a light-weight, python-based data analysis framework, meant for modularizing all sorts of data analysis problems
into reusable analysis components. For documentation on Eskapade, please go to this `link <http://eskapade.readthedocs.io>`_.

Eskapade-ROOT is the ROOT-based extension of Eskapade.
For documentation on Eskapade-ROOT, please go `here <http://eskapade-root.readthedocs.io>`_.


Release notes
=============

Version 0.9
-----------

Eskapade-ROOT v0.9 (December 2018) contains several small updates compared with v0.8:

* All code has been updated to Eskapade v0.9, where the core functionality has been split off into the Eskapade-Core package. As such the code is backwards-incompatible with v0.8.
* The link RoofitPercentileBinning has an option for a default number of bins.
* Several minor updates to the UncorrelationHypothesisTester link, in particular the options to store the correlation and significance matrices.

See `release notes <http://eskapade-root.readthedocs.io/en/latest/releasenotes.html>`_ for previous versions of Eskapade-ROOT.


Installation
============

requirements
------------

Eskapade-ROOT requires ``Python 3.5+``, ``Eskapade v0.8+``, ``root_numpy 4.7.1`` and ``ROOT v6.10+``.
These are pre-installed in the Eskapade `docker <http://eskapade.readthedocs.io/en/latest/installation.html#eskapade-with-docker>`_.


pypi
----

To install the package from pypi, do:

.. code-block:: bash

  $ pip install Eskapade-ROOT

github
------

Alternatively, you can check out the repository from github and install it yourself:

.. code-block:: bash

  $ git clone https://github.com/KaveIO/Eskapade-ROOT.git eskapade-root

To (re)install the python code from your local directory, type from the top directory:

.. code-block:: bash

  $ pip install -e eskapade-root

To (re)compile the cxx library, execute the following commands from the top directory:

.. code-block:: bash

  $ cd cxx
  $ cmake esroofit
  $ cmake --build . -- -j1
  $ cd ../
  $ pip install -e .

python
------

After installation, you can now do in Python:

.. code-block:: python

  import esroofit

To load the Eskapade ROOT library in python, do:

.. code-block:: python

  from esroofit import roofit_utils
  roofit_utils.load_libesroofit()

**Congratulations, you are now ready to use Eskapade-ROOT!**


Quick run
=========

To see the available Eskapade example, do:

.. code-block:: bash

  $ export TUTDIR=`pip show Eskapade-ROOT | grep Location | awk '{ print $2"/esroofit/tutorials" }'`
  $ ls -l $TUTDIR/

E.g. you can now run:

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk401_roothist_fill_plot_convert.py


For all available examples, please see the `tutorials <http://eskapade-root.readthedocs.io/en/latest/tutorials.html>`_.


Contact and support
===================

Contact us at: kave [at] kpmg [dot] com

Please note that the KPMG Eskapade group provides support only on a best-effort basis.
