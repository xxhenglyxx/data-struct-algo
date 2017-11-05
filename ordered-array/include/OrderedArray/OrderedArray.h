
#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H

#include <iostream>
#include <type_traits>

template < class T >
class OrderedArray {

    public:

        OrderedArray ( const int size );
        OrderedArray ( const OrderedArray< T > arr, const int size );

        const int getSize () const;
        const int getLength () const;

        T insert ( const T element );

        T mutate ( const T element, const int index );

        void removeAt ( const int index );
        T remove ( const T element );

        const int search ( const T element ) const;
        
        void print ();

        const T indexOf ( const int index ) const;

        const T next () const;

    private:

        T * array;
        int size;
        int length;
        int lastIndex;
        int nextValue;

        void _removeOne ( const T element );

        const int _search ( const T element, const int fisrt, const int last ) const;

};

template < class T > OrderedArray< T >::OrderedArray ( const int size ) {

    this -> array = new T [ size ];

    this -> size = size;
    this -> lastIndex = -1;
    this -> length = 0;
    this -> nextValue = 0;

};

template < class T > OrderedArray< T >::OrderedArray ( const OrderedArray< T > arr, const int size ) {

    const int arr_length = arr.getLength ();

    this -> size = size;
    this -> lastIndex = arr_length - 1;
    this -> length = arr_length;
    this -> nextValue = 0;
 
    this -> array = new T [ size ];

    for ( int i = 0; i < arr_length; i++ ) {

        this -> array [ i ] = arr.indexOf ( i );

    }

};

template < class T > void OrderedArray< T >::removeAt ( const int index ) {

    if ( index > this -> length ) throw std::string ( "Index out of bounds" );

    this -> length --;
    this -> lastIndex --;

    for ( int i = 0; i < this -> length; i ++ ) {

        if ( i == index ) {

            this -> array [ i ] = this -> array [ i + 1 ];

        }

        if ( i > index ) {

            this -> array [ i ] = this -> array [ i + 1 ];

        }

    }

};

template < class T > void OrderedArray< T >::_removeOne ( const T element ) {

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

};

template < class T > T OrderedArray< T >::remove ( const T element ) {

    this -> _removeOne ( element );

    return element;

};

template < class T > const int OrderedArray< T >::getSize () const { return this -> size; };

template < class T > const int OrderedArray< T >::getLength () const { return this -> length; };

template < class T > T OrderedArray< T >::insert ( const T element ) {

    int searched_index = -1;

    if ( this -> lastIndex > this -> size ) throw std::string ( "OrderedArray is full" );

    if ( this -> lastIndex != -1 ) searched_index = this -> search ( element );

    if ( searched_index != -1 ) throw std::string ( "Ordered Array is a set which cannot have duplicate value" );

    if ( this -> lastIndex != -1 && this -> array [ this -> lastIndex ] > element ) {

        std::cout << "in hererer";

        throw std::string ( "Next element cannot be smaller than previous element" );

    }

    this -> lastIndex ++;
    this -> length ++;

    this -> array [ this -> lastIndex ] = element;

    return element;

};

template < class T > void OrderedArray< T >::print () {

    if ( this -> length == 0 ) {

        std::cout << "OrderedArray is empty" << std::endl;
        
        return;

    }

    for ( int i = 0; i < this -> length; i++ ) {

        std::cout << this -> array [ i ] << ", ";

    }

    std::cout << '\n';

};

template < class T >const T OrderedArray< T >::indexOf ( const int index ) const {

    if ( index > this -> length ) {

        std::cout << "Index out of range" << std::endl;

        return 0;

    }
    
    return this -> array [ index ];

};

template < class T > const T OrderedArray< T >::next () const {

    const T element = this -> array [ this -> nextValue ];

    if ( this -> nextValue < this -> length ) {

        this -> nextValue ++;

    } else if ( this -> nextValue > this -> length ) {

        this -> nextValue = 0;

    }

    return element;

};

template < class T > const int OrderedArray< T >::search ( const T element ) const {

    return this -> _search ( element, 0, this -> length - 1 );

};

template < class T > const int OrderedArray< T >::_search ( const T element, const int first, const int last ) const {

    if ( first > last ) return -1;

    const int mid = ( first + last ) / 2;

    if ( this -> array [ mid ] == element ) return mid;

    if ( this -> array [ mid ] > element ) {

        return this -> _search ( element, first, mid - 1 );

    } else {

        return this -> _search ( element, mid + 1, last );

    }
    
};
#endif