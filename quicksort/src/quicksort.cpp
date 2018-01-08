
#include "quicksort.h"

template < typename T, std::size_t size >
void arrayElementSwap ( T ( &arr ) [ size ], unsign_int index1, const int index2 ) {

    if ( index2 >= 0 ) {

        const T temporary_store = arr [ index1 ];

        arr [ index1 ] = arr [ index2 ];

        arr [ index2 ] = temporary_store;

    }

};

template < typename T, std::size_t size >
void arrayInsertionSort ( T ( &arr ) [ size ] ) {

    unsigned int index = 0, index_behind = 0;

    for ( ; index < size - 1; ++index ) {

        if ( arr [ index ] > arr [ index + 1 ] ) {

            arrayElementSwap ( arr, index, index + 1 );

            index_behind = index;

            while ( index_behind != 0 ) {

                if ( arr [ index_behind ] < arr [ index_behind - 1 ] ) {

                    arrayElementSwap ( arr, index_behind, index_behind - 1 );

                } else {

                    break;

                }

                -- index_behind;

            }

        }

    }

};

template < typename T, std::size_t size >
int medianOfThree ( T ( &arr ) [ size ], unsign_int start, unsign_int end ) {

    const int middle = size / 2;

    if ( arr [ start ] <= arr [ middle ] ) {

        arrayElementSwap ( arr, start, middle );

    } else if ( arr [ end ] <= arr [ middle ] ) {

        arrayElementSwap ( arr, middle, end );

    } else if ( arr [ start ] <= arr [ end ] ) {

        arrayElementSwap ( arr, start, end );

    }

    return middle;

};

template < typename T, std::size_t size >
unsigned int arrayPartition ( T ( &arr ) [ size ], unsign_int start, unsign_int end ) {

    // modify or uncomment below to use first pivot, last pivot or median
    // unsign_int pivot_index = end;
    unsign_int pivot_index = medianOfThree ( arr, start, end );

    const T pivot = arr [ pivot_index ];
    unsigned int loop_index = 0, swap_index = 0;

    for ( ; loop_index <= end - 1; ++ loop_index ) {

        if ( pivot >= arr [ loop_index ] ) {

            arrayElementSwap ( arr, swap_index, loop_index );

            ++ swap_index;

        }

    }

    arrayElementSwap ( arr, swap_index, pivot_index );

    return swap_index;

};

template < typename T, std::size_t size >
void arrayQuickSort ( T ( &arr ) [ size ], unsign_int start, unsign_int end ) {

    if ( end > start && end > 9 ) {

        unsign_int partition_index = arrayPartition ( arr, start, end );

        arrayQuickSort ( arr, start, partition_index == 0 ? 0 : partition_index - 1 );
        arrayQuickSort ( arr, partition_index + 1, end );

    } else {

        arrayInsertionSort ( arr );

    }

};