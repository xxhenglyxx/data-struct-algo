
#ifndef ARRAYFUNC_H
#define ARRAYFUNC_H

template < typename T >
int arrayElementCount ( const T *arr ) {

    int count = 0;

    while ( *arr ) {

        count++;
        arr++;

    }

    return count;

}

template < typename T, typename T2 >
bool arrayInsert ( T *arr, const T2 element ) {

    if ( !element ) return false;

    int
        index = 0,
        elem_count = arrayElementCount ( arr );

    T * nextElem = arr;
    T * cloned_arr = arr;
    nextElem++;

    while ( *arr ) {

        if ( !*nextElem ) {

            arr++;
            *arr = element;

            return true;

        }

        nextElem++;
        arr++;

    }

    delete nextElem;
    delete cloned_arr;

    std::cout << "Array is full" << std::endl;

    return false;

}

template < typename T, typename T2, typename T3 >
bool arrayInsertAt ( T *arr, const T2 element, const T3 index ) {

    if ( !element ) return false;

    if ( !index ) return arrayInsert ( arr, element );

    int i = 0;
    T * copy_arr = arr;
    copy_arr ++;

    while ( *arr ) {

        if ( i == index ) {

            

        }

    }

}

template < typename T >
void showArray ( const T *arr ) {

    if ( !*arr ) std::cout << "Empty Array";

    while ( *arr ) {

        std::cout << *arr << ", ";

        arr++;

    }

    std::cout << '\n';

}

template < typename T, typename T2 >
bool deleteArrayElement ( T *arr, const T2 element ) {

    if ( !element ) return false;

    T * copy_arr = arr;
    bool copy = false;

    copy_arr ++;

    while ( *arr ) {

        if ( *arr == element && !copy ) {

            *arr = *copy_arr;
            copy = true;

        } else if ( copy ) {

            *arr = *copy_arr;

        }

        copy_arr++;
        arr++;

    }

    if ( copy ) return true;

    std::cout << "Element not found in the array" << std::endl;

    return false;

}

template < typename T, typename T2 >
T resizeArray ( const T *arr, const T2 size ) {

    T resized_arr = new T [ size * 2 ];

}

#endif