
#ifndef SIMPLE_ARRAY_H
#define SIMPLE_ARRAY_H

#include <iostream>
#include <time.h> // for clock
#include <iomanip> // for fixed and set precision

template < class T >
class SimpleArray {

    public:
        SimpleArray ( const int size );
        SimpleArray ( const SimpleArray< T > arr, const int size );

        T insert ( const T element );
        T remove ( const T element );

        const T indexOf ( const int index ) const;
        const void print () const;
        const T next ();

        void sort ();

    private:
        T * array;
        int size, length, lastIndex, nextValue;

        void _insertionSort ();

};

template < class T >
SimpleArray< T >::SimpleArray ( const int size ) {

    this -> array = new T [ size ];
    this -> size = size;
    this -> lastIndex = 0;
    this -> length = 0;
    this -> nextValue = 0;

};

template < class T >
SimpleArray< T >::SimpleArray ( const SimpleArray< T > arr, const int size ) {

    const int arr_length = arr.getLength ();

    this -> size = size;
    this -> lastIndex = arr_length;
    this -> length = arr_length;
    this -> nextValue = 0;

    this -> array = new T [ size ];

    for ( int i = 0; i < arr_length; i++ ) {

        this -> array [ i ] = arr.indexOf ( i );

    }

};

template < class T > T SimpleArray< T >::insert ( const T element ) {

    if ( this -> lastIndex > this -> size ) throw std::string ( "Array is full" );

    this -> array [ this -> lastIndex ] = element;

    this -> lastIndex ++;
    this -> length ++;

    return this -> array [ this -> lastIndex ];

};

template < class T >
T SimpleArray< T >::remove ( const T element ) {

    bool removed = false;

    for ( int i = 0; i < this -> length; i ++ ) {

        if ( removed ) {

            this -> array [ i ] = this -> array [ i + 1 ];

        }

        if ( this -> array [ i ] == element && !removed ) {

            this -> array [ i ] = this -> array[ i + 1 ];

            this -> length --;
            this -> lastIndex --;

            removed = true;

        }

    }

    return this -> array [ lastIndex ];

}

template < class T >
const T SimpleArray< T >::next () {

    const int index = this -> nextValue;

    if ( this -> nextValue < this -> length ) {

        this -> nextValue ++;

    } else if ( this -> nextValue < this -> length ) {

        this -> nextValue = 0;

    }

    return this -> array [ index ];

}

template < class T >
const void SimpleArray< T >::print () const {

    if ( this -> length == 0 ) {

        std::cout << "Array is empty" << std::endl;
        
        return;

    }

    for ( int i = 0; i < this -> length; i++ ) {

        std::cout << this -> array [ i ] << ", ";

    }

    std::cout << '\n';

};

template < class T >
void SimpleArray< T >::sort () {

    this -> _insertionSort ();

};

template < class T >
void SimpleArray< T >::_insertionSort () {

    int index, index_behind, size = this -> length;

    bool swap;

    T temporary_store;

    std::cout << std::setprecision( 5 ) << std::fixed; // taking only 5 precision

    clock_t start = clock ();   // start the clock

    /////////////////////////////////////////////
    ///////////// PSEUDO CODE //////////////////
    ///////////////////////////////////////////
    /*
        for every element in the array
            if current element > next element
                swap
                for every element behind
                    if current swapped element < previous element
                        swap
                    repeat over
                    else break
            repeat over
        repeat for every element ahead
    */

    for ( index = 0; index < size - 1; index ++ ) { // loop over the array

        if ( this -> array [ index ] > this -> array [ index + 1 ] ) { // if current element > next element

            temporary_store = this -> array [ index ]; // store current element temporary

            this -> array [ index ] = this -> array [ index + 1 ]; // mutate next element with current element

            this -> array [ index + 1 ] = temporary_store; // mutate next element with temporary stored element

            index_behind = index; // store current index to check backward

            while ( index_behind != 0 ) { // cannot check the very first element

                if ( this -> array [ index_behind ] < this -> array [ index_behind - 1 ] ) { // same logic above repeated

                    temporary_store = this -> array [ index_behind ];

                    this -> array [ index_behind ] = this -> array [ index_behind - 1 ];

                    this -> array [ index_behind - 1 ] = temporary_store;

                } else { break; }

                index_behind --;

            }

        }

    }

    // take current clock and minus start clock to get execution time
    std::cout << this -> length << " " << ( double ) ( clock () - start ) / CLOCKS_PER_SEC << std::endl;
 
};

#endif