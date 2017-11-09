
#include <iostream> // for input output
#include <stdlib.h> // for rand
#include <time.h>

#include <SimpleArray/SimpleArray.h>

//////////////////////////////////////////////////////////////////////////
////////////////////// DEFINE NUMBER OF TEST CASES ///////////////////////
/////////////////////////////////////////////////////////////////////////

#define TEST_CASE_NUMBER 300

////////////////////////////////////////////////////////////////////////
//////////////////// ELEMENT INCREMENT EACH TEST //////////////////////
///////////////////////////////////////////////////////////////////////

#define ELEMENT_INCREASE 100

//////////////////////////////////////////////////////////////////////

int main ( int argc, char * argv [] ) {

    int run = 1, index = 0, negate, arr_size;

    while ( run < TEST_CASE_NUMBER ) {

        arr_size = run * ELEMENT_INCREASE;

        SimpleArray < int > arr ( arr_size );

        srand ( time ( 0 ) );

        for ( index = 0; index < arr_size; index ++ ) {

            negate = rand () % 2 == 0 ? -1 : 1;  // randomly negate number

            arr.insert ( ( rand() % ( index + 2 ) ) * negate * 2 ); // range mod 100 to get range from 0 to 1

        }

        arr.sort ();

        arr.print ();

        run ++;

    }

    return 0;

};