
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

typedef const unsigned int unsign_int;

template < typename T, std::size_t size >
extern void arrayElementSwap ( T ( &arr ) [ size ], unsign_int index1, const int index2 );

template < typename T, std::size_t size >
extern void arrayInsertionSort ( T ( &arr ) [ size ] );

template < typename T, std::size_t size >
extern void arrayQuickSort (

    T ( &arr ) [ size ],
    unsign_int start,
    unsign_int end
    
);

template < typename T, std::size_t size >
extern unsigned int arrayPartition (

    T ( &arr ) [ size ],
    unsign_int start,
    unsign_int end
    
);

template < typename T, std::size_t size >
extern int medianOfThree ( T ( &arr ) [ size ], unsign_int start, unsign_int end );

#include "../src/quicksort.cpp"

#endif