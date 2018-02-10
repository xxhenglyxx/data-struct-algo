
#include "graph-adj-matrix.h"

int main ( int args_len, char ** args_context ) {

    std::ios::sync_with_stdio ( false );

    Graph < std::string, 10, GraphType::DIGRAPH > graph;

    graph.addEdge ( "Lucy", "Jenny" );
    graph.addEdge ( "Jenny", "Lucifer" );
    graph.addEdge ( "Lucifer", "Jenny" );

    log ( graph.findVertex ( "Jenny" ) );
    log ( graph.findVertex ( "Lucifer" ) );

    graph.depthFirstSearch ();

    return 0;

};