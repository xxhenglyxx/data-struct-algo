
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <string>

template < class T >
class Heap {

    private:

        Heap< T > leftHeap;
        Heap< T > rightHeap;
        Heap< T > parent;
        T element;
    
    public:

        Heap ();
        Heap ( const T element );

        void setLeftHeap ( const Heap< T > heap );
        void setRightHeap ( const Heap< T > heap );
        void setElement ( const T element );

        T getElement ();

};

template < class T >
Heap< T >::Heap () {

    this -> element = this -> parent = NULL;

}

template < class T >
Heap< T >::Heap ( const T element ) {

    this -> element = element;
    this -> parent = NULL;

};

template < class T >
void Heap< T >::setLeftHeap ( const Heap< T > heap ) {

    this -> leftHeap = heap;

}

template < class T >
void Heap< T >::setRightHeap ( const Heap< T > heap ) {

    this -> rightHeap = heap;

}

template < class T >
T Heap< T >::getElement () {

    return this -> element;

}

template < class T >
class PriorityQueue {

    private:

        T * array;
        // priority 0 = ascending, 1 = descending
        int priority, rear, front, length, size;

    public:

        PriorityQueue ( const int size, const int priority = 0 );
        ~PriorityQueue ();

        bool isFull () const;
        bool isEmpty () const;
        int getSize () const;
        int getLength () const;
        T peekFront () const;

        T insert ( const T element );
        T remove ();

};

template < class T >
PriorityQueue< T >::PriorityQueue ( const int size, const int priority ) {

    this -> array = new T [ size ];
    this -> size = size;
    this -> rear = this -> front = -1;
    this -> length = 0;
    this -> priority = priority;

}

template < class T >
PriorityQueue< T >::~PriorityQueue () {}

template < class T >
bool PriorityQueue< T >::isFull () const {
    
    return this -> length == this -> size;

}

template < class T >
bool PriorityQueue< T >::isEmpty () const {
    
    return this -> length == 0;

}

template < class T >
int PriorityQueue< T >::getSize () const {
    
    return this -> size;

}

template < class T >
int PriorityQueue< T >::getLength () const {
    
    return this -> length;

}

template < class T >
T PriorityQueue< T >::peekFront () const {

    if ( this -> length != 0 ) {

        return this -> array [ this -> front ];

    } else {

        throw std::string ( "No element" );

    }

}

template < class T >
T PriorityQueue< T >::insert ( const T element ) {

    if ( this -> isFull () ) {

        throw std::string ( "Queue is full" );

    }

    if ( this -> isEmpty () ) {

        this -> front = 0; 

    }

    this -> rear = ( this -> rear + 1 ) % this -> size;

    this -> array [ rear ] = element;

    this -> length ++;

    return element;

}

template < class T >
T PriorityQueue< T >::remove () {

    T temp = this -> array [ this -> front ];

    if ( this -> length == 1 ) {

        this -> front = this -> rear = -1;

    }

    if ( this -> length == 0 ) {

        throw std::string ( "Queue is empty" );

    }

    if ( this -> length > 1 ) {

        this -> front = ( this -> front + 1 ) % this -> size;

    }

    return temp;

}

#endif