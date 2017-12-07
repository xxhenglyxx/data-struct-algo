
#include <iostream>

#include <PriorityQueue/PriorityQueue.h>

int main ( int args_len, char * args_context [] ) {

    PriorityQueue < std::string > priorityQueue ( 10 );

    std::cout << priorityQueue.isFull () << std::endl;

    std::cout << priorityQueue.isEmpty () << std::endl;

    std::cout << priorityQueue.getSize () << std::endl;

    std::cout << priorityQueue.getLength () << std::endl;

    priorityQueue.insert ( "mame" );
    priorityQueue.insert ( "gen" );
    priorityQueue.insert ( "lame" );

    std::cout << priorityQueue.peekFront () << std::endl;

    return 0;

}