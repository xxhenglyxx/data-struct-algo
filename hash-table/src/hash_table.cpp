
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
    void HashEntry< K, T >::setKey ( const K key ) {

        this -> key = key;

    };

    template < typename K, typename T >
    void HashEntry< K, T >::setValue ( const T value ) {

        this -> value = value;

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

    // method not generic yet
    template < typename K, typename T >
    int HashTable< K, T >::elementToASCII ( const K key ) const {

        int value = 0;

        if ( std::is_arithmetic < K >::value ) {

            // just placeholder
            value = 5;

        } else {

            // for std::string

            for ( char character : key ) {

                value += int ( character );

            }

        }

        return value;

    };
    
    template < typename K, typename T >
    int HashTable< K, T >::hashFunction ( const K key ) const {

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

        return this -> array [ hash_key ].getValue ();

    };

    template < typename K, typename T >
    int HashTable< K, T >::getLength () const {

        return this -> length;

    };

    template < typename K, typename T >
    int HashTable< K, T >::getSize () const {

        return this -> size;

    };

    template < typename K, typename T >
    void HashTable< K, T >::insert ( const K key, const T value ) {

        if ( this -> size == this -> length ) {

            std::cout << "Hash Table is Full" << std::endl;

            return;

        }

        int index = this -> hashFunction ( key );
        // const HashTable < K, T > ( & hash ) = this -> array;

        if ( this -> isExist ( key ) ) {

            // linear probing
            while ( !this -> array [ index ].isRemoved () ) {

                ++ index;

            }

        }

        this -> array [ index ] = HashEntry < K, T > ( key, value );

        ++ this -> length;

    };

    template < typename K, typename T >
    void HashTable< K, T >::removeByKey ( const K key ) {

        -- this -> length;

    };

    template < typename K, typename T >
    void HashTable< K, T >::removeByElement ( const T element ) {

        -- this -> length;

    };

};