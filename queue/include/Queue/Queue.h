
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template < class T >
class Queue {

    public:

        Queue ( const int size );
        ~Queue ();

        T insert ( const T element );
        bool remove ();

        T peakFront () const;

        int size () const;
        bool isEmpty () const;
        bool isFull () const;

    private:

        T * array;
        int arrLength, arrSize, rearIndex, frontIndex;

};

template < class T >
Queue< T >::Queue ( const int size ) {

    this -> array = new T [ size ];
    this -> arrSize = size;
    this -> arrLength = 0;
    this -> rearIndex = -1;
    this -> frontIndex = -1;

}

template < class T >
Queue< T >::~Queue () {



}

template < class T >
bool Queue< T >::isEmpty () const {

    return this -> arrLength == 0;

}

template < class T >
bool Queue< T >::isFull () const {

    return this -> arrLength == this -> arrSize;

}

template < class T >
T Queue< T >::insert ( const T element ) {

    if ( this -> isFull () ) {

        std::cout << "Queue is full" << std::endl;

        return element;

    }

    if ( this -> isEmpty () ) {

        this -> frontIndex = 0;

    }

    this -> rearIndex = ( this -> rearIndex + 1 ) % this -> arrSize;

    this -> array [ this -> rearIndex ] = element;

    this -> arrLength ++;

    return element;

}

template < class T >
bool Queue< T >::remove () {

    if ( this -> isEmpty () ) {

        std::cout << "Queue is empty" << std::endl;

        return false;

    }
    
    this -> frontIndex = ( this -> frontIndex + 1 ) % this -> arrSize;

    this -> arrLength --;

    return true;

}

template < class T >
T Queue< T >::peakFront () const {

    if ( this -> arrLength == 0 ) throw std::string ( "Queue is empty" );

    return this -> array [ this -> frontIndex ];

}

template < class T >
int Queue< T >::size () const {

    return this -> arrLength;

}

#endif