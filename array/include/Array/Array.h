
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template < class T >
class Array {

    public:

        Array ( const int size );
        Array ( const Array< T > arr, const int size );

        const int getSize () const;
        const int getLength () const;

        T insert ( const T element );
        T insert ( const T element, const int index );

        T mutate ( const T element, const int index );

        void removeAt ( const int index );
        T remove ( const T element, const bool multiple );

        const void print () const;

        const T indexOf ( const int index ) const;
        const Array< int > getDuplicate ( const T element ) const;
        const int getNonDuplicate ( const T element, const int occur_at ) const;

    private:

        T * array;
        int size;
        int length;
        int lastIndex;

        void _removeOne ( const T element );
        void _removeMultiple ( const T element );

};

template < class T > Array< T >::Array ( const int size ) {

    this -> array = new T [ size ];
    this -> size = size;
    this -> lastIndex = 0;
    this -> length = 0;

};

template < class T > Array< T >::Array ( const Array< T > arr, const int size ) {

    const int arr_length = arr.getLength ();

    this -> size = size;
    this -> lastIndex = arr_length;
    this -> length = arr_length;

    this -> array = new T [ size ];

    for ( int i = 0; i < arr_length; i++ ) {

        this -> array [ i ] = arr.indexOf ( i );

    }

};

template < class T > void Array< T >::removeAt ( const int index ) {

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

template < class T > void Array< T >::_removeOne ( const T element ) {

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

template < class T > void Array< T >::_removeMultiple ( const T element ) {

    for ( int i = 0; i < this -> length; i++ ) {

        this -> _removeOne ( element );

    }

};

template < class T > T Array< T >::remove ( const T element, const bool multiple ) {

    if ( multiple ) {

        this -> _removeMultiple ( element );

    } else { this -> _removeOne ( element ); }

    return element;

};

template < class T > const int Array< T >::getSize () const { return this -> size; };

template < class T > const int Array< T >::getLength () const { return this -> length; };

template < class T > T Array< T >::insert ( const T element ) {

    if ( this -> lastIndex > this -> size ) throw std::string ( "Array is full" );

    this -> array [ this -> lastIndex ] = element;

    this -> lastIndex ++;
    this -> length ++;

    return element;

};

template < class T > T Array< T >::insert ( const T element, const int index ) {

    if ( index > this -> size || this -> lastIndex > this -> size ) throw std::string ( "Array is full" );

    if ( index > this -> length ) throw std::string ( "Array cannot be insert further than existing position of array" );

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

template < class T > const void Array< T >::print () const {

    if ( this -> length == 0 ) {

        std::cout << "Array is empty" << std::endl;
        
        return;

    }

    for ( int i = 0; i < this -> length; i++ ) {

        std::cout << this -> array [ i ] << ", ";

    }

    std::cout << '\n';

};

template < class T > const T Array< T >::indexOf ( const int index ) const {

    if ( index > this -> length ) {

        std::cout << "Index out of range" << std::endl;

        return 0;

    }
    
    return this -> array [ index ];

};

template < class T > const Array< int > Array< T >::getDuplicate ( const T element ) const {

    const int length = this -> length;

    Array< int > element_indexes ( length );

    for ( int i = 0; i < length; i ++ ) {

        if ( this -> array [ i ] == element ) {

            element_indexes.insert ( i );

        }

    }

    return element_indexes;

};

template < class T > const int Array< T >::getNonDuplicate ( const T element, const int occur_at ) const {

    int occur = 1;

    for ( int i = 0; i < length; i ++ ) {

        if ( this -> array [ i ] == element && occur == occur_at ) {

            return i;

        } else if ( this -> array [ i ] == element && occur != occur_at ) {

            occur ++;

        }

    }

    return -1;

};

#endif