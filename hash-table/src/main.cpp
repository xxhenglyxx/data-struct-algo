
#include "hash_table.h"

#define MAX_SIZE 200
#define BREAKLINE std::cout << "----------------------\n"

int main ( int args_len, char ** args_context ) {

    NonStd::HashTable < std::string, double > * myHash = new NonStd::HashTable < std::string, double > ( MAX_SIZE );

    myHash -> insert ( "Lisa", 50.55 );
    myHash -> insert ( "Baby", 11.32 );
    myHash -> insert ( "Lancelot", 2.3 );
    myHash -> insert ( "Lisa", 23.32 );
    myHash -> insert ( "Baby", 42.42 );
    myHash -> insert ( "Lisa", 77.12 );
    myHash -> insert ( "Baby", 123.123 );

    std::cout << "Lisa Existence: " << myHash -> isExist ( "Lisa" ) << std::endl;
    std::cout << "Baby Existence: " << myHash -> isExist ( "Baby" ) << std::endl;
    std::cout << "lancelot Existence: " << myHash -> isExist ( "lancelot" ) << std::endl;
    std::cout << "Lisa - Collision Test - Existence: " << myHash -> isExist ( "Lisa" ) << std::endl;
    std::cout << "Lisa - Double Collision Test - Existence: " << myHash -> isExist ( "Lisa" ) << std::endl;
    std::cout << "Baby - Collision Test - Existence: " << myHash -> isExist ( "Baby" ) << std::endl;
    std::cout << "Baby - Double Collision Test - Existence: " << myHash -> isExist ( "Baby" ) << std::endl;

    BREAKLINE;
    
    std::cout << "Lisa Value: " << myHash -> getElement ( "Lisa" ) << std::endl;
    std::cout << "Baby Value: " << myHash -> getElement ( "Baby" ) << std::endl;
    std::cout << "Lancelot Value: " << myHash -> getElement ( "Lancelot" ) << std::endl;
    std::cout << "Lisa - Collision Value: " << myHash -> getElement ( "Lisa", 2 ) << std::endl;
    std::cout << "Lisa - Double Collision Value: " << myHash -> getElement ( "Lisa", 3 ) << std::endl;
    std::cout << "Baby - Collision Value: " << myHash -> getElement ( "Baby", 2 ) << std::endl;
    std::cout << "Baby - Double Collision Value: " << myHash -> getElement ( "Baby", 3 ) << std::endl;

    BREAKLINE;

    std::cout << "HashTable / HashMap Length: " << myHash -> getLength () << " NOTE: It is Lancelot, not lancelot => not existence" << std::endl;

    BREAKLINE;

    delete myHash;

    return 0;

};