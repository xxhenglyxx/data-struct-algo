
#include <iostream>

#include "Stack/Stack.h"

int main ( int argc, char ** argv ) {

    Stack < std::string > stack ( 10 );

    stack.push ( "Happy lol" );
    stack.push ( "i know right ?" );
    stack.push ( "asdlkfjlkasdjfkl" );

    std::cout << stack.peek () << std::endl;

    std::cout << stack.size () << std::endl;

    return 0;

}