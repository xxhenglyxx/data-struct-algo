
#include "binary_tree.h"

template < typename T >
void log ( const T text ) {

    std::cout << text << std::endl;

};

int main ( int args_len, char ** args_context ) {

    NonStd::BinaryTree < int > tree = NonStd::BinaryTree < int > ();

    tree.insert ( 55 );
    tree.insert ( -2 );
    tree.insert ( 2 );
    tree.insert ( -1 );
    tree.insert ( 3 );

    log ( tree.find ( 55 ) );
    log ( tree.find ( -2 ) );
    log ( tree.find ( 2 ) );
    log ( tree.find ( -1 ) );
    log ( tree.find ( 3 ) );
    log ( tree.find ( 99 ) );

    return 0;

};