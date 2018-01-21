
#include <iostream>
#include <type_traits>

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

namespace NonStd {

    template < typename K, typename T >
    class HashEntry {

        private:

            K key;
            T value;
            bool removed;

        public:

            HashEntry ( const K key, const T value );
            HashEntry ();
            // ~HashEntry ();

            void setValue ( const T value );
            void setKey ( const K key );
            void setRemoved ( const bool state );

            T getValue () const;
            K getKey () const;
            bool isRemoved () const;

    };

    template < typename K, typename T >
    class HashTable {

        private:

            HashEntry < K, T > * array;
            int size, length;

            int hashFunction ( const K key ) const;
            int elementToASCII ( const K key ) const;

            void quadraticHash ( int & start_index );
            void hashFunction2 ( int & start_index );

        public:

            HashTable ( const HashTable < K, T > & hashTable, const int size );
            HashTable ( const int size );

            ~HashTable ();

            // void operator = ( const HashTable < K, T > & hashTable );

            int getLength () const;
            int getSize () const;
            T getElement ( const K key, const int occurence = 1 ) const;
            int getKey ( const T element ) const;
            bool isExist ( const K key ) const;

            void insert ( const K key, const T element );
            // void removeByElement ( const T element );
            void removeByKey ( const K key, const int occurence = 1 );

    };

};

#include "../src/hash_table.cpp"

#endif