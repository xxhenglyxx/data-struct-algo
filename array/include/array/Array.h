
#ifndef ARRAY_H
#define ARRAY_H

template < class T >

class Array {

    public:
        Array ( const int size );
        T insert ( const T element );
        T remove ( const T element );
        T insertAt ( const T element, const int index );
        T removeAt ( const T element, const int index );
    
    private:
        T array;

};

#endif