
#include <iostream>

#include <Queue/Queue.h>

int main ( int args_len, char ** args_context ) {

    Queue < int > queue ( 3 );

    queue.insert ( 2 );
    queue.insert ( 3 );
    queue.insert ( 4 );
    queue.insert ( 5 );

    std::cout << queue.peakFront () << std::endl;

    queue.remove ();
    queue.remove ();

    std::cout << queue.peakFront () << std::endl;

    queue.remove ();

    queue.insert ( 6 );
    queue.insert ( 7 );
    queue.insert ( 8 );
    
    std::cout << queue.peakFront () << std::endl;

    queue.insert ( 9 );

    return 0;

};