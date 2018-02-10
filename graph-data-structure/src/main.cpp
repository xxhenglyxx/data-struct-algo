
// #include "graph-adj-matrix.h"

// void graphAsAdjMatrix () {

//     Graph < std::string, 10, GraphType::DIGRAPH > matrixGraph;

//     matrixGraph.addEdge ( "Lucy", "Jenny" );
//     matrixGraph.addEdge ( "Jenny", "Lucifer" );
//     matrixGraph.addEdge ( "LoL", "Jenny" );
//     matrixGraph.addEdge ( "Dean", "LoL" );
//     matrixGraph.addEdge ( "Femem", "LoL" );

//     log ( matrixGraph.findVertex ( "Jenny" ) );
//     log ( matrixGraph.findVertex ( "Lucifer" ) );
//     log ( matrixGraph.findVertex ( "Sam" ) );

//     matrixGraph.depthFirstSearch ();

// };

#include "graph-adj-list.h"

int main ( int args_len, char ** args_context ) {

    std::ios::sync_with_stdio ( false );

    Graph < int, 10 > listGraph;

    listGraph.addEdge ( 1, 2 );
    listGraph.addEdge ( 2, 3 );
    listGraph.addEdge ( 1, 5 );
    listGraph.addEdge ( 5, 6 );
    listGraph.addEdge ( 3, 5 );

    listGraph.breathFirstSearch ();

    return 0;

};