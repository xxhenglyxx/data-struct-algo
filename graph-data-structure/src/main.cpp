
#include "graph.h"

int main ( int args_len, char ** args_context ) {

    Graph < std::string, 10, GraphType::DIGRAPH > graph;

    graph.addVertex ( "Jenny" );
    graph.addVertex ( "Lucifer" );
    graph.addEdge ( "Lucy", "Jenny" );
    graph.addEdge ( "Jenny", "Lucifer" );
    graph.addEdge ( "Lucifer", "Jenny" );

    log ( graph.findVertex ( "Jenny" ) );
    log ( graph.findVertex ( "Lucifer" ) );

    return 0;

};