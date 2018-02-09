
#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

enum GraphType { DIGRAPH, UNDIGRAPH };

template < typename T, std::size_t V, GraphType G  >
class Graph {

    struct Edge {

        std::string start_vertex, end_vertex;
        std::size_t weight;

    };

    struct Vertex {

        T data;

    };

    const std::size_t size = V;
    const GraphType type = G;

    Edge Edges [ G == GraphType::DIGRAPH ? V - 1 : V * ( V - 1 ) / 2 ];
    Vertex Vertices [ V ];

    public:

        Graph ();

};

template < typename T, std::size_t V, GraphType G >
Graph< T, V, G >::Graph () {

    std::memset (

        ( & this -> Edges ) [ G == GraphType::DIGRAPH ? V - 1 : V * ( V - 1 ) / 2 ],
        0,
        sizeof ( & this -> Edges ) * ( G == GraphType::DIGRAPH ? V - 1 : V * ( V - 1 ) / 2 )

    );
    std::memset ( ( & this -> Vertices ) [ V ], 0, sizeof ( & this -> Vertices ) [ V ] );

};

#endif