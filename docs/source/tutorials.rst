=========
Tutorials
=========

This section contains materials on how to use Eskapade-ROOT.
All command examples can be run from any directory with write access.
For more in depth explanations on the functionality of the code-base,
try the `API docs <code.html>`_.



All ROOT Examples in Eskapade
------------------------------

All Eskapade-ROOT example macros can be found in the tutorials directory.
For ease of use, let's make a shortcut to the directory containing the tutorials:

.. code-block:: bash

  $ export TUTDIR=`pip show Eskapade-ROOT | grep Location | awk '{ print $2"/esroofit/tutorials" }'`
  $ ls -l $TUTDIR/

The numbering of the example macros follows the package structure:

* ``esk400+``: macros for processing ROOT datasets and performing analysis with ROOT.

These macros are briefly described below.
You are encouraged to run all examples to see what they can do for you!


Example esk401: root histogram fill, plot, and convert
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro illustrates how to 1) fill 1-3 dimensional root histograms from a
pandas dataframe. In turn, these histogram are: 2) plotted,
3) converted to a roofit histogram (roodatahist), and 4) converted to a
roofit dataset (roodataset).

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk401_roothist_fill_plot_convert.py


Example esk402: roodatahist filling from a pandas dataframe
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro illustrates how to fill a N-dimensional roodatahist from a
pandas dataframe. (A roodatahist can be filled iteratively, while looping
over multiple pandas dataframes.) The roodatahist can be used to create
a roofit histogram-pdf (roohistpdf).

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk402_roodatahist_fill.py


Example esk403: roodataset conversion into dataframe and back
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro illustrates how to convert a pandas dataframe to a roofit dataset
(= roodataset), do something to it with roofit, and then convert the roodataset
back again to a pandas dataframe.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk403_roodataset_convert.py


Example esk404: workspace to create a pdf, simulate, fit, and plot
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macro illustrates how do basic statistical data analysis with roofit,
by making use of the rooworkspace functionality.

The example shows how to define a pdf, simulate data, fit this data,
and then plot the fit result.

The generated data is converted to a dataframe and the contents is plotted
with a default plotter link.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk404_workspace_createpdf_simulate_fit_plot.py


Example esk405: simulation based on binned data
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Imagine the situation where you wish to simulate an existing dataset, where
you want the simulated dataset to have the same features and characteristics
as the input dataset, including all known correlations between observables,
possibly non-linear.
The input data can have both categorical and continuous (float) observables.

This macro shows how this simulation can be done with roofit, by building a
(potentially large) n-dimensional roofit histogram of all requested
input observables with the RooDataHistFiller link.

Be careful not to blow up the total number of bins, which grows exponentially
with the number of input observables. We can control this by setting the number of
bins per continuous observable, or by setting the maximum total number of bins
allowed in the histogram, which scales down the number of allowed bins in each
continuous observable. Realize that, the more bins one has, the more input data
is needed to will all bins with decent statistics.

This macro has two settings, controlled with settings['high_num_dims'].
When false, the roodatahist contains 3 observables, of which two continous and
1 categorical. When true, the roodatahist is 6 dimensional, with 4 continous
observables and 2 categorical ones. The latter example is slower, but works fine!

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk405_simulation_based_on_binned_data.py


Example esk406: simulation based on unbinned data
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Imagine the situation where you wish to simulate an existing dataset consisting
of continuous (float) observables only, where you want the simulated dataset
to have the same features and characteristics as the input dataset, including
the all correlations between observables.

This macro shows how this simulation can be done with roofit, by building a
smooth pdf of the input dataset with kernel estimatation techniques, the so-called
KEYS pdf, which describes the input observables and their correlations.
The technique works very well to describe 1 and 2 dimensional distributions,
but is very cpu intensive and becomes ever more slow for higher number of dimensions.

This macro has two settings, controlled with settings['high_num_dims'].
When false, the keys pdf contains 2 continuous observables. When true,
the keys pdf 3 dimensional.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk406_simulation_based_on_unbinned_data.py


Example esk407: classification unbiased fit estimate
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro illustrates how to get an unbiased estimate of the number of
high risk clients, by doing a template fit to data.

Assume a classifier has been trained and optimized to separate high-risk from
low risk clients. But the high- to low-risk ratio in data is very low and unknown,
so the false-positive rate is non-negligible.

We can use templates of the score of the ML classifier of the high- and low-risk
testing samples to (at least) get an unbiased estimate of the total number of
high-risk clients. This is done by fitting the (unbiased) testing templates
to the score distribution in the actual dataset. The shapes differentiate
the number of high- and low-risk clients.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk407_classification_unbiased_fit_estimate.py


Example esk408: classification error propagation after fit
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro continues on the idea in esk407_classification_unbiased_fit_estimate.
It illustrates how to assign statistically motivated probabilities to
high risk clients, by doing a template fit to data, and - based on this -
calculating the probability and uncertainty on this for each client.

Assume a classifier has been trained and optimized to separate high-risk from
low risk clients. But the high- to low-risk ratio in data is very low and unknown,
so the false-positive rate is non-negligible.

We can use templates of the score of the ML classifier of the high- and low-risk
testing samples to (at least) score the probability that someone is a high risk
client, in light of the fact that most clients with a high classifier score will
in fact be false-positive low risk clients.

In addition to the probability, the algorithm assigns as statistical uncertainty
to each probability.
The total sum of these probabilities equals the number of estimated high-risk
clients, as also obtained in example esk407.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk408_classification_error_propagation_after_fit.py


Example esk409: unredeemed vouchers
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro is an example of an application of the truncated
exponential PDF that is provided by Eskapade.  The redeem of
gift vouchers by customers of a store is modelled.

Vouchers are given out to customers of the store and can be
exchanged for goods sold in the store.  All vouchers represent
the same amount of money and can only be used once.  They are
given to customers in batches at different dates.

Not all released vouchers are actually spent.  To estimate how
many currently released vouchers will be spent, the voucher age
at which the redeem takes place is modelled by a
double-exponential decay model.  The exponential PDF is
truncated at the voucher age, beyond which there can have been
no redeems yet. Once the parameters of the model have been fit
to (generated) redeem-event data, the total number of redeems at
infinite voucher ages is estimated by scaling to the surface of
an untruncated PDF with identical parameter values.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk409_unredeemed_vouchers.py


Example esk410: testing correlations between categories
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This macro illustrates how to find correlations between categorical
observables.

Based on the hypothesis of no correlation expected frequencies of observations *
are calculated. The measured frequencies are compared to expected frequencies. *
From these the (significance of the) p-value of the hypothesis that the
observables in the input dataset are not correlated is determined. The
normalized residuals (pull values) for each bin in the dataset are also
calculated. A detailed description of the method can be found in ABCDutils.h.
A description of the method to calculate the expected frequencies can be found *
in RooABCDHistPDF.cxx.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk410_testing_correlations_between_categories.py


Example esk411: weibull predictive maintenance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Macro illustrates how to fit several Weibull distributions to a falling
time difference distribution, indicating times between maintenance. The
Weibull probability distribution is provided by Eskapade.

.. code-block:: bash

  $ eskapade_run $TUTDIR/esk411_weibull_predictive_maintenance.py



.. include:: tutorial_roofit.rst
