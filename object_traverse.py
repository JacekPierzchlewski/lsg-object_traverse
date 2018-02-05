"""
    object_traverse.py

    This script measures time in which Python3 changes a class variable in
    every object in a set of objects. Objects are stored in a list.

    `Cosniwa` software is used to measure the time.

    Read more on www.speedupcode.com

"""

try:
    import cCosniwa as csw
except ImportError:
    print("\nERROR: cCosniwa was not found! \n")


class SC():
    """
    `SC` - Simple Class definition.

    This is a definition of a class with one class variable `val`.
    """
    def __init__(self, val_):
        self.val = val_


def main():

    # List with the number of objects to be traversed in every test
    lN = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000]

    # Loop over all the tests
    for iN in lN:
        time_objects(iN)

    # Print the results
    csw.resultc()


def time_objects(iN):
    """
    time_objects:

    Function generates the requested number of objects and measures time of
    changing a class variable in all the objects.

    Parameters:

          iN:  [integer number]  The number of objects which will be generated
                                 and traversed.
    """

    # Register traverse through objects
    iRegoTr = csw.reg_code(' %d objects' % iN)

    # Generate the required number of objects
    lObj = generate_objects(iN)

    # Traverse through all the objects
    csw.call_start(iRegoTr)
    traverse_objects(lObj, iN)
    csw.call_stop(iRegoTr)


def generate_objects(iN):
    """
    time_objects:

    Generate the requested number of objects and store them in a list.

    Parameters:

        iN:  [integer number]   Size of the list with objects

    Return:

        lObj:  [list]      List with the generated objects
    """

    # Start a list with objects
    lObj = [];

    # Create all the objects
    for i in range(iN):
        lObj.append(SC(i))

    return lObj;

def traverse_objects(lObj, iN):
    """
    'traverse_objects':

    Function traverse through all the objects in list `lObj` and increases
    class variable `val` of every object.

    Parameters:

     lObj:  [list]             List with all the objects to traverse
     iN:    [integer number]   Size of the list with objects
    """

    # Loop over all the objects
    for i in range(iN):
        lObj[i].val = lObj[i].val + 1;


if __name__ == "__main__":
    main()
