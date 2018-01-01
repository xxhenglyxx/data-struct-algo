
#include <iostream>

unsigned int factorial ( const unsigned int number );

template < typename T, std::size_t size >
int binarySearch (

    const T ( &arr ) [ size ],
    const int element,
    const unsigned int low,
    const unsigned int high

);

template < typename T, std::size_t size >
void ___arrayMerge (

    T ( &arr ) [ size ],
    const unsigned int low,
    const unsigned int middle,
    const unsigned int high

);

template < typename T, std::size_t size >
void mergeSort (

    T ( &arr )[ size ],
    const unsigned int low,
    const unsigned int high

);

int main ( int args_len, char ** args_context ) {

    std::cout << factorial ( 6 ) << std::endl;

    int int_arr [ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::string str_arr [ 5 ] = { "XYZ", "ABC", "X", "XYZQES", "LO" };

    std::cout << binarySearch ( int_arr, 10, 0, 9 ) << std::endl;

    mergeSort ( str_arr, 0, 4 );

    unsigned int index = 0;

    for ( ; index < 5; ++ index ) {

        std::cout << str_arr [ index ] << std::endl;

    }
    
    return 0;

};

unsigned int factorial ( const unsigned int number ) {

    return number == 0 || number == 1 ? 1 : ( number * factorial ( number - 1 ) );

};

template < typename T, std::size_t size >
int binarySearch (

    const T ( &arr ) [ size ],
    const int element,
    const unsigned int low,
    const unsigned int high

) {

    if ( high >= low ) {

        const unsigned middle = low + ( high - low ) / 2;

        if ( arr [ middle ] == element ) return middle;

        return
            arr [ middle ] > element ?
                binarySearch ( arr, element, low, middle - 1 )
                :
                binarySearch ( arr, element, middle + 1, high );

    }

    return -1;

};

template < typename T, std::size_t size >
void ___arrayMerge (

    T ( &arr ) [ size ],
    const unsigned int low,
    const unsigned int middle,
    const unsigned int high

) {

    unsigned int index1 = 0, index2 = 0, right_arr_size = high - middle, loop_index = 0;

    T * temp_left_arr = new T [ middle ], * temp_right_arr = new T [ right_arr_size ];

    while ( loop_index <= high ) {

        loop_index < middle ?
            temp_left_arr [ loop_index ] = arr [ loop_index ] : temp_right_arr [ loop_index ] = arr [ loop_index ];

        ++ loop_index;
 
    }

    loop_index = 0;

    while ( index1 < middle && index2 < right_arr_size ) {

        temp_left_arr [ index1 ] <= temp_right_arr [ index2 ] ?
            ( arr [ loop_index ] = temp_left_arr [ index1 ], ++ index1 )
            :
            ( arr [ loop_index ] = temp_right_arr [ index2 ], ++ index2 );

        ++ loop_index;

    }

    while ( index1 < middle ) {

        arr [ loop_index ] = temp_left_arr [ index1 ];
        ++ index1;
        ++ loop_index;

    }

    while ( index2 < right_arr_size ) {

        arr [ loop_index ] = temp_right_arr [ index2 ];
        ++ index2;
        ++ loop_index;

    }

    delete [] temp_left_arr;
    delete [] temp_right_arr;

};

template < typename T, std::size_t size >
void mergeSort (

    T ( &arr ) [ size ],
    const unsigned int low,
    const unsigned int high

) {

    if ( high > low ) {

        const unsigned int middle = low + ( high - low ) / 2;

        mergeSort ( arr, low, middle );
        mergeSort ( arr, middle + 1, high );
        ___arrayMerge ( arr, low, middle, high );

    }

};