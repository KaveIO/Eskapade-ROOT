Eskapade-ROOT: the ROOT extension of Eskapade
=============================================

For documentation on the ROOT extension of Eskapade, see:
http://eskapade.readthedocs.io/en/latest/

And check out the RooFit section of the Tutorials.

Installation
------------

To install the package from pypi, do:

% pip install Eskapade-ROOT

This package requires ROOT to install, clearly.

Alternatively, you can check out the repository from github and install it yourself:

% git clone 

To (re)install the python code from your local directory, type from the top directory:

% pip install -e .

You can now do in Python:

% import esroofit

To recompile the cxx library, execute the following commands from the top directory:

% cd cxx
% cmake esroofit
% cmake --build . -- -j1
% cd ../
% pip install -e .

Python
------

After installation, you can now do in Python:

% import esroofit

To load the Eskapade ROOT library in python, do:

% from esroofit import roofit_utils
% roofit_utils.load_libesroofit()

