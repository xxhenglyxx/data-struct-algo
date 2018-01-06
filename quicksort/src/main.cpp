
#include "quicksort.h"

int main ( int args_len, char ** args_context ) {

    int int_arr [ 5 ] = { 50, 30, 20, 10, 0 };

    std::string str_arr [ 5 ] = { "XZ", "ABC", "GHI", "LDF", "XY" };

    arrayQuickSort ( int_arr, 0, 5 );
    arrayQuickSort ( str_arr, 0, 5 );
    
    for ( int x : int_arr ) {

        std::cout << x << std::endl;

    }

    for ( std::string x : str_arr ) {

        std::cout << x << std::endl;

    }

    return 0;

};