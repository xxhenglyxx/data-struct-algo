
#include <iostream>

#include "ArrayFunc/ArrayFunc.h"

int main ( int argc, char ** argv ) {

    int uo_int_array[ 18 ] = { 10, 7, 1, 3, 2, 9, 5, 8, 6 };

    char uo_char_array[ 18 ] = "adios";

    std::cout << "Inserting and show unordered int and char aray" << std::endl;

    arrayInsert ( uo_int_array, -3 );
    arrayInsert ( uo_int_array, 11 );

    arrayInsert ( uo_char_array, 's' );
    arrayInsert ( uo_char_array, 'e' );

    showArray ( uo_int_array );
    showArray ( uo_char_array );

    std::cout << '\n';

    std::cout << "Deleting and show unordered int and char array" << std::endl;

    deleteArrayElement ( uo_int_array, 5 );
    deleteArrayElement ( uo_char_array, 'i' );

    showArray ( uo_int_array );
    showArray ( uo_char_array );

    std::cout << '\n';

    return 0;

}