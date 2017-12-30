
#include <iostream>
#include <list>
#include <stack>
#include <queue>

int main () {

    std::list < std::string > str_list = { "mam", "lam", "sam" };

    str_list.push_front ( "front" );
    str_list.push_back ( "back" );

    str_list.remove ( "lam" );

    std::stack < int > int_stack;

    int_stack.push ( 5 );
    int_stack.push ( 10 );

    int_stack.pop ();

    std::queue < std::list < int > > int_queue;

    int_queue.push ( std::list < int > { 5, 6, 7, 8 } );
    int_queue.push ( std::list < int > { 7, 8, 9, 10 } );

};