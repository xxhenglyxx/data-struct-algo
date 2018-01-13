
#include "hash_table.h"

#define MAX_SIZE 200
#define BREAKLINE std::cout << "----------------------\n"

int main ( int args_len, char ** args_context ) {

    NonStd::HashTable < std::string, double > * myHash = new NonStd::HashTable < std::string, double > ( MAX_SIZE );

    myHash -> insert ( "Lisa", 50.55 );
    myHash -> insert ( "Baby", 11.32 );
    myHash -> insert ( "Lancelot", 2.3 );
    // myHash -> insert ( "Lisa", 23.32 );

    std::cout << "Lisa Existence: " << myHash -> isExist ( "Lisa" ) << std::endl;
    std::cout << "Baby Existence: " << myHash -> isExist ( "Baby" ) << std::endl;
    std::cout << "lancelot Existence: " << myHash -> isExist ( "lancelot" ) << std::endl;

    BREAKLINE;
    
    std::cout << "Lisa Value: " << myHash -> getElement ( "Lisa" ) << std::endl;
    std::cout << "Baby Value: " << myHash -> getElement ( "Baby" ) << std::endl;
    std::cout << "Lancelot Value: " << myHash -> getElement ( "Lancelot" ) << std::endl;

    BREAKLINE;

    std::cout << "HashTable / HashMap Length: " << myHash -> getLength () << " NOTE: It is Lancelot, not lancelot => not existence" << std::endl;

    BREAKLINE;

    delete myHash;

    return 0;

};