
#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H

#include <iostream>

template < class T >
class OrderedArray {

    public:

        OrderedArray ( const int size );
        OrderedArray ( const OrderedArray< T > arr, const int size );

        const int getSize () const;
        const int getLength () const;

        T insert ( const T element );
        T insert ( const T element, const int index );

        T mutate ( const T element, const int index );

        void removeAt ( const int index );
        T remove ( const T element, const bool multiple );

        void print ();

        const T indexOf ( const int index ) const;

    private:

        T * array;
        int size;
        int length;
        int lastIndex;

        void _removeOne ( const T element );
        void _removeMultiple ( const T element );

};

template < class T > OrderedArray< T >::OrderedArray ( const int size ) {

    this -> array = new T [ size ];
    this -> size = size;
    this -> lastIndex = 0;
    this -> length = 0;

};

template < class T > OrderedArray< T >::OrderedArray ( const OrderedArray< T > arr, const int size ) {

    const int arr_length = arr.getLength ();

    this -> size = size;
    this -> lastIndex = arr_length - 1;
    this -> length = arr_length;

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

template < class T > void OrderedArray< T >::_removeMultiple ( const T element ) {

    bool shift = false;

    for ( int i = 0; i < this -> length; i++ ) {

        if ( shift ) this -> array [ i - 1 ] = this -> array [ i ];

        if ( this -> array [ i ] == element ) {

            this -> array [ i ] = this -> array [ i + 1 ];

            this -> length --;
            this -> lastIndex --;

            shift = true;

        }

    }

};

template < class T > T OrderedArray< T >::remove ( const T element, const bool multiple ) {

    if ( multiple ) {

        this -> _removeMultiple ( element );

    } else { this -> _removeOne ( element ); }

    return element;

};

template < class T > const int OrderedArray< T >::getSize () const { return this -> size; };

template < class T > const int OrderedArray< T >::getLength () const { return this -> length; };

template < class T > T OrderedArray< T >::insert ( const T element ) {

    if ( this -> lastIndex > this -> size ) throw std::string ( "OrderedArray is full" );

    this -> array [ this -> lastIndex ] = element;

    this -> lastIndex ++;
    this -> length ++;

    return element;

};

template < class T > T OrderedArray< T >::insert ( const T element, const int index ) {

    if ( index > this -> size || this -> lastIndex > this -> size ) throw std::string ( "OrderedArray is full" );

    if ( index > this -> length ) throw std::string ( "OrderedArray cannot be insert further than existing position of array" );

    T nextElement, toMutate;

    for ( int i = 0; i < this -> length; i++ ) {

        if ( i > index ) {

            nextElement = this -> array [ i ];

            this -> array [ i ] = toMutate;

            toMutate = nextElement;

        }

        if ( i == index ) {

            toMutate = this -> array [ i ];
            nextElement = this -> array [ i + 1 ];

            this -> array [ i ] = element;

            this -> lastIndex ++;
            this -> length ++;

        } 

    }

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

#endif