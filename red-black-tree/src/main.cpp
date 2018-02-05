
#include <iostream>
#include "red_black_tree.h"

void log ( const char * text );

template < typename T, typename ... TArgs >
void log ( const char * format, T to_concat, TArgs ... args );

int main ( int args_len, char ** args_context ) {

    std::ios::sync_with_stdio( false );

    NonStd::RedBlackTree < int > tree ( 1 );

    tree.add ( 2 );
    tree.add ( 3 );
    tree.add ( 5 );

    std::cout << std::boolalpha;

    std::cout << tree.find ( 3 );

    return 0;

};

void log ( const char * text ) {

    std::cout << text;

};

template < typename T, typename ... TArgs >
void log ( const char * format, T to_concat, TArgs ... args ) {

    while ( * format ) {

        if ( * format == '%' ) {

            std::cout << to_concat;
            log ( ++ format, args ... );
            return;

        }

        std::cout << * format;

        ++ format;

    }

};