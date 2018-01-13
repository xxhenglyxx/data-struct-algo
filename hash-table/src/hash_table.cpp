
#include "hash_table.h"

namespace NonStd {

    template < typename K, typename T >
    HashEntry< K, T >::HashEntry ( const K key, const T value )
    : key ( key ), value ( value ), removed ( false ) {};

    template < typename K, typename T >
    HashEntry< K, T >::HashEntry () : removed ( false ) {};

    template < typename K, typename T >
    T HashEntry< K, T >::getValue () const {

        return this -> value;

    };

    template < typename K, typename T >
    K HashEntry< K, T >::getKey () const {

        return this -> key;

    };

    template < typename K, typename T >
    bool HashEntry< K, T >::isRemoved () const {

        return this -> removed;

    };

    template < typename K, typename T >
    void HashEntry< K, T >::setRemoved ( const bool state ) {

        this -> removed = state;

    };

    template < typename K, typename T >
    HashTable< K, T >::HashTable ( const int size ) : size ( size ), length ( 0 ) {

        this -> array = new HashEntry < K, T > [ size ] ();

    };

    template < typename K, typename T >
    HashTable< K, T >::HashTable ( const HashTable < K, T > & hashTable, const int size )
    : size ( size ), array ( new HashEntry < K, T > [ size ] ) {

        unsigned int index = 0;

        for ( ; index < hashTable -> getSize (); ++ index ) {

            this -> array [ index ] = hashTable -> setKey ( index );
            this -> array [ index ] = hashTable -> setValue ( index );

        }

    };

    template < typename K, typename T >
    HashTable< K, T >::~HashTable () {

        std::cout << "HashTable Destructing" << std::endl;

        delete [] this -> array;

    };

    template < typename K, typename T >
    int HashTable< K, T >::elementToASCII ( const K key ) {

        int value = 0;

        if ( std::is_same< K, std::string >::value ) {

            for ( char character : key ) {

                value += int ( character );

            }

        } else {

            value = key;

        }

        return value;

    };
    
    template < typename K, typename T >
    int HashTable< K, T >::hashFunction ( const K key ) {

        return this -> elementToASCII ( key ) % this -> size;

    };

    template < typename K, typename T >
    bool HashTable< K, T >::isExist ( const K key ) const {

        int hash_key = this -> hashFunction ( key );

        return this -> array [ hash_key ].getKey () == key && !this -> array [ hash_key ].isRemoved ();

    };

    template < typename K, typename T >
    T HashTable< K, T >::getElement ( const K key ) const {

        int hash_key = this -> hashFunction ( key );

        return this -> array [ hash_key ].value;

    };

    template < typename K, typename T >
    void HashTable< K, T >::insert ( const K key, const T value ) {

        if ( this -> size == this -> length ) {

            std::cout << "Hash Table is Full" << std::endl;

            return;

        }

        int index = this -> hashFunction ( key );
        const HashTable < K, T > ( & hash ) = this -> array;

        while ( this -> isExist ( key ) && hash [ index ] && hash [ index ].removed ) {

            ++ index;

        }

        hash [ index ].setKey ( key );
        hash [ index ].setValue ( value );
        hash [ index ].setRemoved ( false );

        ++ this -> length;

    };

    template < typename K, typename T >
    void HashTable< K, T >::removeByKey ( const K key ) {

    };

    template < typename K, typename T >
    void HashTable< K, T >::removeByElement ( const T element ) {

    };

};