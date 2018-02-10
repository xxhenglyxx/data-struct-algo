
#include "graph.h"

int main ( int args_len, char ** args_context ) {

    Graph < std::string, 10, GraphType::DIGRAPH > graph;

    graph.addVertex ( 5 );
    graph.addVertex ( 10 );

    return 0;

};