
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
        const T next () const;

        void sort ();

    private:
        T * array;
        int size, length, lastIndex, nextValue;

        void _bubbleSort ();

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
const T SimpleArray< T >::next () const {

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

    this -> _bubbleSort ();

};

template < class T >
void SimpleArray< T >::_bubbleSort () {

    int index, check_index, size = this -> length;

    bool swap;

    T temporary_store;

    std::cout << std::setprecision( 5 ) << std::fixed; // taking only 5 precision

    clock_t start = clock ();   // start the clock

    for ( index = 0; index < size - 1; index ++ ) {

        swap = false;

        for ( check_index = 0; check_index < size - index - 1; check_index ++ ) {

            if ( this -> array [ check_index ] > this -> array [ check_index + 1 ] ) {

                temporary_store = this -> array [ check_index ];

                this -> array [ check_index ] = this -> array [ check_index + 1 ];

                this -> array [ check_index + 1 ] = temporary_store;

                swap = true;

            }

        }

        if ( !swap ) break;

    }

    // take current clock and minus start clock to get execution time
    std::cout << this -> length << " " << ( double ) ( clock () - start ) / CLOCKS_PER_SEC << std::endl;
 
};

#endif