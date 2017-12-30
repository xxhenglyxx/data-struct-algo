
#include <LinkedList.h>

//////////////////////////////////
/////////// LIST NODE ////////////
//////////////////////////////////

ListNode::~ListNode () {

    // delete this -> prev;
    // delete this -> next;

};

ListNode::ListNode () {

    this -> prev = NULL;
    this -> next = NULL;

};

ListNode::ListNode ( const std::string element, ListNode * prev, ListNode * next ) {

    this -> prev = prev;
    this -> next = next;
    this -> data = element;

};

void ListNode::disposeObject () {

    delete this -> prev;
    delete this -> next;

};

ListNode * ListNode::getNext () {

    return this -> next;

};

ListNode * ListNode::getPrev () {

    return this -> prev;

};

void ListNode::setNext ( ListNode * next ) {

    this -> next = next;

};

void ListNode::setPrev ( ListNode * prev ) {

    this -> prev = prev;

};

std::string ListNode::getData () const {

    return this -> data;

};

//////////////////////////////////
///////// LINKED LIST ////////////
//////////////////////////////////

LinkedList::~LinkedList () {

    if ( this -> size != 0 ) {

        ListNode * head = this -> root;

        while ( head -> getNext () ) {

            ListNode * next = head -> getNext ();

            delete head;

            head = next;

        }
        
    }

    std::cout << "Destructing" << std::endl;

};

LinkedList::LinkedList () {

    this -> root = new ListNode ();

    this -> size = 0;

};

LinkedList::LinkedList ( const std::string element ) {
    
    this -> root = new ListNode ();

    this -> size = 0;

    this -> insert ( element );

};

void LinkedList::insert ( const std::string element, const int index ) {

    if ( this -> size == 0 ) {

        ListNode * new_node = new ListNode ( element );

        this -> root = new_node;

    } else {

        ListNode * node = this -> root;
        unsigned loop_index = 1;

        while ( node -> getNext () && loop_index != index ) {

            node = node -> getNext ();
            ++ loop_index;

        }

        if ( loop_index == index ) {

            ListNode * new_node = new ListNode ( element, node, node -> getNext () );

            node -> getNext () -> setPrev ( new_node );
            node -> setNext ( new_node );

        } else {

            ListNode * new_node = new ListNode ( element, node );

            node -> setNext ( new_node );

        }

    }

    this -> size += 1;

};

int LinkedList::getSize () const {

    return this -> size;

};

std::string LinkedList::getFirst () const {

    if ( this -> size == 0 ) return "None";

    return this -> root -> getData ();

};

std::string LinkedList::getLast () const {

    if ( this -> size == 0 ) return "None";

    ListNode * node = this -> root;

    while ( node -> getNext () ) {

        node = node -> getNext ();

    }

    return node -> getData ();

};

int LinkedList::find ( const std::string element ) const {

    if ( this -> size == 0 ) return -1;

    ListNode * node = this -> root;

    int index = 0;

    while ( node ) {

        if ( node -> getData () == element ) {

            return index;

        }

        node = node -> getNext ();

        ++ index;

    }

    return -1;
 
};

void LinkedList::remove ( const std::string element, const int index ) {

    ListNode * node = this -> root;
    unsigned int loop_index = 0;

    while ( node && loop_index != index ) {

        if ( node -> getData () == element ) break;

        node = node -> getNext ();

        ++ loop_index;

    }

    if ( ( node -> getData () == element && loop_index == index ) || node -> getData () == element ) {

        if ( node -> getPrev () ) {

            node -> getPrev () -> setNext ( node -> getNext () );

        }

        if ( node -> getNext () ) {

            node -> getNext () -> setPrev ( node -> getPrev () );

        }

        delete node;

        this -> size -= 1;

    }

};