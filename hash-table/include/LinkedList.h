
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class ListNode {

    private:

        ListNode * prev;
        ListNode * next;
        std::string data;

    public:

        ListNode ();
        ListNode ( const std::string element, ListNode * prev = NULL, ListNode * next = NULL );
        ~ListNode ();

        ListNode * getNext ();
        ListNode * getPrev ();
        std::string getData () const;

        void disposeObject ();
        void setNext ( ListNode * next );
        void setPrev ( ListNode * prev );

};

class LinkedList {

    private:

        ListNode * root;
        int size;

    public:

        LinkedList ( const LinkedList * list );
        LinkedList ( const std::string element );
        LinkedList ();
        ~LinkedList ();

        void insert ( const std::string element, const int index = -1 );
        void remove ( const std::string element, const int index = -1 );
        void removeAt ( const unsigned int index );

        int find ( const std::string element ) const;
        int getSize () const;
        std::string getLast () const;
        std::string getFirst () const;

};

#endif