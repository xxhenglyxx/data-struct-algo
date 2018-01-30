
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

    return 0;

};