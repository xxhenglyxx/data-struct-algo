
#include <iostream>

#include "OrderedArray/OrderedArray.h"

int main ( int argc, char ** argv ) {

    // !!! ORDERED ARRAY NOT SORTED ARRAY, SO THERE WONT BE METHOD TO SORT THIS
    // BUT THE CLASS HAS METHOD FOR ORDERED OR SORTED ARRAY

    OrderedArray < int > arr ( 10 );
    OrderedArray < char > arr2 ( 10 );

    std::cout << "Inserting and show unordered int and char aray" << std::endl;

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting and show unordered int and char array" << std::endl;

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting an element of unordered int and char array" << std::endl;

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting concurrent element of unordered int and char array" << std::endl;

    arr.print ();
    arr2.print ();

    arr.print ();
    arr2.print ();

    return 0;

}