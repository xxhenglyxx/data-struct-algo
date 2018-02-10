
#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

template < typename T >
void log ( const T text ) {

    std::cout << text << std::endl;

};

template < typename T, typename ... TArgs >
void log ( const char * text, const T value, const TArgs ... args ) {

    while ( * text ) {

        if ( * text == '%' ) {

            std::cout << value;

            log ( ++ text, args ... );

            return;

        }

        std::cout << * text;

        ++ text;

    }

};

enum GraphType { DIGRAPH, UNDIGRAPH };

template < typename T, int V, GraphType G  >
class Graph {

    struct Edge {

        T * start_vertex, * end_vertex;
        int weight;

    };

    struct Vertex {

        T data;

    };

    const int size = V;
    const GraphType type = G;

    int vertices_last_index, edges_last_index;

    Edge Edges [ G == GraphType::UNDIGRAPH ? V - 1 : V * ( V - 1 ) / 2 ];
    Vertex Vertices [ V ];

    public:

        Graph ();

        void addVertex ( const T vertex );
        void removeVertex ( const T vertex );
        int findVertex ( const T vertex ) const;

        void addEdge ( const T vertex1, const T vertex2 );
        void removeEdge ( const T vertex1, const T vertex2 );

};

template < typename T, int V, GraphType G >
Graph< T, V, G >::Graph () : vertices_last_index ( 0 ), edges_last_index ( 0 ) {
};

template < typename T, int V, GraphType G >
void Graph< T, V, G >::addVertex ( const T vertex ) {

    if ( this -> vertices_last_index == this -> size ) {

        log ( "Error: Vertex Array is Fulled" );
        return;

    }

    if ( this -> vertices_last_index != 0 ) {

        ++ this -> vertices_last_index;

    }

    this -> Vertices [ this -> vertices_last_index ].data = vertex;

};

template < typename T, int V, GraphType G >
int Graph< T, V, G >::findVertex ( const T vertex ) const {

    int index = this -> vertices_last_index;

    for ( ; index > 0; -- index ) {

        if ( this -> Vertices [ index ] == vertex ) {

            return index;

        }

    }

    return index;

};

template < typename T, int V, GraphType G >
void Graph< T, V, G >::addEdge ( const T vertex1, const T vertex2 ) {

    const int v1 = this -> findVertex ( vertex1 );
    const int v2 = this -> findVertex ( vertex2 );

    if ( !v1 || !v2 ) {

        log ( "Either one or both vertices not exist" );

        return;

    }

    if ( this -> edges_last_index != 0 ) {

        ++ this -> edges_last_index;

    }

    this -> Edges [ this -> edges_last_index ] -> start_vertex = & this -> Vertices [ v1 ];
    this -> Edges [ this -> edges_last_index ] -> end_vertex = & this -> Vertices [ v2 ];

};

#endif