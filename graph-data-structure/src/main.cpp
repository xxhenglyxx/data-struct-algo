
#include "graph-adj-matrix.h"

int main ( int args_len, char ** args_context ) {

    std::ios::sync_with_stdio ( false );

    Graph < std::string, 10, GraphType::DIGRAPH > graph;

    graph.addEdge ( "Lucy", "Jenny" );
    graph.addEdge ( "Jenny", "Lucifer" );
    graph.addEdge ( "LoL", "Jenny" );
    graph.addEdge ( "Dean", "LoL" );
    graph.addEdge ( "Femem", "LoL" );

    log ( graph.findVertex ( "Jenny" ) );
    log ( graph.findVertex ( "Lucifer" ) );
    log ( graph.findVertex ( "Sam" ) );

    graph.depthFirstSearch ();

    return 0;

};