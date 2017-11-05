
#include <iostream>

#include "Array/Array.h"

int main ( int argc, char ** argv ) {

    Array < int > arr ( 10 );
    Array < char > arr2 ( 10 );

    arr.insert ( 5 );
    arr.insert ( 0 );
    arr.insert ( -5 );

    arr2.insert ( 'z' );
    arr2.insert ( 'o' );
    arr2.insert ( 'a' );

    arr.insert ( 2, 1 );
    arr2.insert ( 'b', 0 );

    std::cout << "Inserting and show unordered int and char aray" << std::endl;

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting and show unordered int and char array" << std::endl;

    arr.removeAt ( 2 );
    arr2.removeAt ( 3 );

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting an element of unordered int and char array" << std::endl;

    arr.remove ( 5, false );
    arr2.remove ( 'z', false );

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    std::cout << "Deleting concurrent element of unordered int and char array" << std::endl;

    arr.insert ( 2 );
    arr.insert ( 2 );
    arr.insert ( 10 );
    arr.insert ( 6 );
    arr.insert ( 2 );
    arr2.insert ( 'x' );
    arr2.insert ( 'b' );
    arr2.insert ( 'x' );
    arr2.insert ( 'x' );

    arr.print ();
    arr2.print ();

    arr.remove ( 2, true );
    arr2.remove ( 'x', true );

    arr.print ();
    arr2.print ();

    std::cout << '\n';

    arr.insert ( 10 );
    arr.insert ( 2 );
    arr.insert ( 10 );

    arr2.insert ( 'b' );
    arr2.insert ( 'x' );
    arr2.insert ( 'b' );

    arr.print ();
    arr2.print ();

    std::cout << "Get duplicate and non duplicate by input" << std::endl;

    Array< int > duplicate_indexes = arr.getDuplicate ( 10 );
    duplicate_indexes.print ();
    std::cout << arr2.getNonDuplicate ( 'b', 4 ) << std::endl;

    return 0;

}