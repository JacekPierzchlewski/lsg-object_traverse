/*
 *   object_traverse.cpp
 *
 *   This code measures time in which C++ changes a class variable in
 *   every object in a set of objects.
 *
 *   `Cosniwa` software is used to measure the time.
 *
 *   Read more on www.speedupcode.com
 *
 */
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <cosniwa.h>


// Simple class definition
class SC
{
    public:
        SC(int);
        int val;
};

// Simple class constructor
SC::SC(int val_)
{
    val = val_;
}

void generate_objects(SC** list, int iN)
{
/*
 * 'generate_objects':
 *
 * Generate the requested number of objects and store pointers to the objects
 * in a table.
 *
 * Parameters:
 *
 *     list:  [SC**]  Pointer to a table with place for pointers to
 *                    generated objects.
 *
 *     iN:    [int]   The number of objects to be generated.
 */

    // Generate the required number of objects
    for(int i=0; i<iN; i++)
    {
        list[i] = new SC(i);
    }
}

void traverse_objects(SC** list, int iN)
{
/*
 * 'traverse_objects':
 *
 * Traverse through all the objects amd increase the variable `val` in every
 * object.
 *
 * Parameters:
 *
 *     list:  [SC**]  Pointer to a table with pointers to objects.
 *
 *     iN:    [int]   The  number of objects in the table.
 */

    // Loop over all the objects
    for(int i=0; i<iN; i++)
    {
        list[i]->val++;
    }
}

void delete_objects(SC** list, int iN)
{
/*
 * 'delete_objects':
 *
 * Delete all the `SC` objects used in the example.
 *
 * Parameters:
 *
 *     list:  [SC**]  Pointer to a table with pointers to objects.
 *
 *     iN:    [int]   The  number of objects in the table.
 */

    // Loop over all the objects
    for(int i=0; i<iN; i++)
    {
        delete list[i];
    }
}


void time_objects(int iN, Cosniwa* csw)
{
/*
 *
 * Function generates the requested number of objects and measures time of
 * changing a variable in all the objects.
 *
 * Parameters:
 *
 *      iN:  [integer number]  The number of objects which will be generated
 *                             and traversed.
 *
 *      csw: [Cosniwa*]       Pointer to Cosniwa object.
 *
 */

    // Register traverse through objects in Cosniwa
    std::ostringstream ostrReg;
    ostrReg << std::setw(10) << iN <<  " objects";
    std::string strReg = ostrReg.str();
    unsigned int iRegoTr = csw->reg_code(strReg);

    // Generate the required number of objects
    SC* list[iN];  // List with objects
    generate_objects(list,iN);

    // Traverse through all the objects
    csw->call_start(iRegoTr);
    traverse_objects(list, iN);
    csw->call_stop(iRegoTr);

    // Delete the objects
    delete_objects(list, iN);
}


int main()
{
    // List with the number of objects to be traversed in every test
    // (must end with zero)
    int isN[] =
        {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 0};

    // Create Cosniwa object
    Cosniwa csw = Cosniwa();

    // Loop over all the tests
    int inxTest = 0;
    while(isN[inxTest] > 0)
    {
        time_objects(isN[inxTest], &csw);
        inxTest++;
    }

    /// Print the results
    csw.resultc();

    return 0;
}
