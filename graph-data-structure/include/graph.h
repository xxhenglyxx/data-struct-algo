
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
        bool is_removed;

        Edge () : start_vertex ( nullptr ), end_vertex ( nullptr ), weight ( 0 ), is_removed ( true ) {};

    };

    struct Vertex {

        T data;
        bool is_removed;

        Vertex () : is_removed ( true ) {};

    };

    const int size = V;
    std::size_t vertices_length;
    std::size_t edges_length;
    const GraphType type = G;

    int vertices_last_index, edges_last_index;

    Edge Edges [ G == GraphType::UNDIGRAPH ? V - 1 : V * ( V - 1 ) / 2 ] = {};
    Vertex Vertices [ V ] = {};

    public:

        Graph ();

        void addVertex ( const T vertex );
        void removeVertex ( const T vertex );
        int findVertex ( const T vertex ) const;

        void addEdge ( const T vertex1, const T vertex2 );
        void removeEdge ( const T vertex1, const T vertex2 );

};

template < typename T, int V, GraphType G >
Graph< T, V, G >::Graph () : vertices_last_index ( 0 ), edges_last_index ( 0 ), vertices_length ( 0 ) {
};

template < typename T, int V, GraphType G >
void Graph< T, V, G >::addVertex ( const T vertex ) {

    if ( this -> vertices_last_index == this -> size ) {

        log ( "Error: Vertex Array is Fulled" );
        return;

    }

    if ( this -> vertices_length == 0 ) {

        this -> Vertices [ this -> vertices_last_index ].data = vertex;
        this -> Vertices [ this -> vertices_last_index ].is_removed = false;

        ++ this -> vertices_length;

        return;

    }

    ++ this -> vertices_last_index;
    ++ this -> vertices_length;

    this -> Vertices [ this -> vertices_last_index ].data = vertex;
    this -> Vertices [ this -> vertices_last_index ].is_removed = false;

};

template < typename T, int V, GraphType G >
int Graph< T, V, G >::findVertex ( const T vertex ) const {

    int index = this -> vertices_last_index;

    for ( ; index >= 0; -- index ) {

        if ( this -> Vertices [ index ].data == vertex && !this -> Vertices [ index ].is_removed ) {

            return index;

        }

    }

    return -1;

};

template < typename T, int V, GraphType G >
void Graph< T, V, G >::addEdge ( const T vertex1, const T vertex2 ) {

    const int v1 = this -> findVertex ( vertex1 );
    const int v2 = this -> findVertex ( vertex2 );

    if ( v1 == -1 || v2 == -1 ) {

        log ( "Either one or both vertices not exist" );

        return;

    }

    if ( this -> edges_length == 0 ) {

        this -> Edges [ this -> edges_last_index ].start_vertex = & this -> Vertices [ v1 ].data;
        this -> Edges [ this -> edges_last_index ].end_vertex = & this -> Vertices [ v2 ].data;
        this -> Edges [ this -> edges_last_index ].is_removed = false;

        ++ this -> edges_length;

        return;

    }

    ++ this -> edges_last_index;
    ++ this -> edges_length;

    this -> Edges [ this -> edges_last_index ].start_vertex = & this -> Vertices [ v1 ].data;
    this -> Edges [ this -> edges_last_index ].end_vertex = & this -> Vertices [ v2 ].data;
    this -> Edges [ this -> edges_last_index ].is_removed = false;

};

#endif