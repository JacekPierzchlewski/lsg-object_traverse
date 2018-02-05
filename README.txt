
OBJECT_TRAVERSE:   Tests of time needed to change a single value in
                   a set of objects.
                   Tests are run for a variaty of languages.


PREREQUISITIES:

    'CoSniWa' must be installed in the system.
    'CoSniWa' is an multi language tool for timing code.

    CoSniWa can be downloaded from:

        https://github.com/JacekPierzchlewski/cosniwa
        read more on: www.speedupcode.com


(c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
    license: BSD-2-Clause.


===============================================================================
I. LIST OF CONTENTS:

    1. object_traverse.cpp  :  Test for C++

    2. object_traverse.m    :  Test for Octave

    3  object_traverse.py   :  Test for Python 3


===============================================================================
II. PREREQUISITIES:

    'CoSniWa' must be installed in the system.
    CoSniWa is an multi language tool for timing code.

    CoSniWa can be downloaded from:

        https://github.com/JacekPierzchlewski/cosniwa


===============================================================================
III. SUPPORTED PLATFORMS:

    1. Linux

    2. Mac OS X


===============================================================================
IV. RUN:

    1. C++:
        a. compile:
            $ make cpp

        b. run the tests:
            $ ./object_traverse


    2. Octave:
        a. run the tests:
            $ octave object_traverse.m


    3. Python 3:
        a. run the tests:
            $ python3 object_traverse.py
