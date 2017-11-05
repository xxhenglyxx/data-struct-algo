
#include <iostream>

#include "OrderedArray/OrderedArray.h"

int main ( int argc, char ** argv ) {

    //!!! ORDERED ARRAY NOT SORTED ARRAY, SO THERE WONT BE METHOD TO SORT THIS
    //BUT THE CLASS HAS METHOD FOR ORDERED OR SORTED ARRAY

    OrderedArray < int > arr ( 10 );
    OrderedArray < char > arr2 ( 10 );

    arr.insert ( 1 );
    arr.insert ( 2 );
    arr.insert ( 3 );

    arr2.insert ( 'a' );
    arr2.insert ( 'b' );
    arr2.insert ( 'c' );

    std::cout << "Inserting and show ordered int and char aray" << std::endl;

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting and show ordered int and char array" << std::endl;

    arr.remove ( 1 );
    arr2.remove ( 'c' );

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Searching" << std::endl;

    std::cout << arr.search ( 2 ) << std::endl;
    std::cout << arr2.search ( 'x' ) << std::endl;

    std::cout << "\nTesting string type of array" << std::endl;

    OrderedArray < std::string > stringArray ( 10 );

    stringArray.insert ( "Hello" );
    stringArray.insert ( "man" );
    stringArray.insert ( "xmanlolxx" );

    stringArray.print ();

    return 0;

}