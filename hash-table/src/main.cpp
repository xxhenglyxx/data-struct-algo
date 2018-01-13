
#include "hash_table.h"

#define MAX_SIZE 200

int main ( int args_len, char ** args_context ) {

    NonStd::HashTable < std::string, double > * myHash = new NonStd::HashTable < std::string, double > ( MAX_SIZE );

    // delete myHash;

    return 0;

};