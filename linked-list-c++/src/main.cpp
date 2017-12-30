
#include <LinkedList.h>

int main ( int args_len, char ** args_context ) {

    {

        LinkedList list ( "Hello" );
        list.insert ( "Random" );
        list.insert ( "Test" );
        list.insert ( "XXX", 2 );

        std::cout << list.getFirst () << std::endl;
        std::cout << list.getLast () << std::endl;
        std::cout << list.find( "Test" ) << std::endl;

        list.remove ( "Random" );

        std::cout << list.find( "Test" ) << std::endl;
        std::cout << list.find( "Random" ) << std::endl;

    }

    return 0;

};