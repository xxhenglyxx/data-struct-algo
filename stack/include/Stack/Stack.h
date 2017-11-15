
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <type_traits>

template < class T >
class Stack {

    public:

        Stack ( const int size );
        ~Stack ();

        T push ( const T element );
        T pop ();

        T peek () const;
        bool isFull () const;
        bool isEmpty () const;
        
    private:

        T * array;
        int arrSize, arrLength, lastIndex;
        bool full, empty;

        void DisposeObject ();

};

template < class T >
Stack< T >::Stack ( const int size ) {

    this -> array = new T [ size ];
    this -> arrSize = size;
    this -> full = false;
    this -> empty = true;
    this -> lastIndex = -1;
    this -> arrLength = 0;

};

template < class T >
Stack< T >::~Stack () {

    std::cout << "Deconstructing" << std::endl;

}

template < class T >
void Stack< T >::DisposeObject () {

    std::cout << "Disposing object" << std::endl;

    delete this;

};

template < class T >
T Stack< T >::push ( const T element ) {

    if ( this -> full ) throw std::string ( "Stack is full" );

    if ( this -> empty ) this -> empty = false;

    this -> lastIndex ++;
    this -> arrLength ++;
    this -> array [ lastIndex ] = element;

    if ( this -> arrLength >= this -> arrSize ) this -> full = true;

    return element;

};

template < class T >
T Stack< T >::pop (){

    if ( this -> empty ) throw std::string ( "Stack is empty" );

    const T element = this -> array [ this -> lastIndex ];

    if ( this -> full ) this -> full = false;

    this -> arrLength --;
    this -> lastIndex --;

    if ( this -> arrLength == 0 ) this -> empty = true;

    return element;

};

template < class T >
T Stack< T >::peek () const {

    return this -> array [ lastIndex ];

};

template < class T >
bool Stack< T >::isEmpty () const {

    return this -> empty;

}

template < class T >
bool Stack< T >::isFull () const {

    return this -> full;

}

#endif