
#include <iostream>
#include <stack>

#ifndef GRAPH_ADJ_MATRIX_H
#define GRAPH_ADJ_MATRIX_H

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

        int start_vertex, end_vertex;
        int weight;
        bool is_removed;

        Edge () : weight ( 0 ), is_removed ( true ) {};

    };

    // should have use hash table to improve performance for vertices
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
        T getVertex ( const std::size_t index ) const;

        void addEdge ( const T vertex1, const T vertex2 );
        void removeEdge ( const T vertex1, const T vertex2 );

        void depthFirstSearch () const;
        void breathFirstSearch () const;

};

template < typename T, int V, GraphType G >
Graph< T, V, G >::Graph () : vertices_last_index ( 0 ), edges_last_index ( 0 ), vertices_length ( 0 ) {
};

template < typename T, int V, GraphType G >
void Graph< T, V, G >::depthFirstSearch () const {

    std::stack < int > visited;
    int index = 0;
    std::size_t visited_length = 0;
    const Edge ( & edges ) [ G == GraphType::UNDIGRAPH ? V - 1 : V * ( V - 1 ) / 2 ] = this -> Edges;
    const Vertex ( & vertices ) [ V ] = this -> Vertices;

    while ( visited_length != this -> size ) {

        if ( visited.size () ) {

            if ( visited.top () == edges [ index ].start_vertex ) {
                
                visited.pop ();

                index = edges [ visited.top () ].end_vertex;

            } else {

                visited.push ( edges [ index ].start_vertex );

                log ( vertices [ index ].data );

                index = edges [ index ].start_vertex;
                ++ visited_length;

            }

        } else {

            visited.push ( edges [ index ].start_vertex );

            log ( vertices [ index ].data );

            index = edges [ index ].start_vertex;
            ++ visited_length;

        }

    }

};

template < typename T, int V, GraphType G >
void Graph< T, V, G >::breathFirstSearch () const {



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

    int v1 = this -> findVertex ( vertex1 );
    int v2 = this -> findVertex ( vertex2 );

    if ( v1 < 0 ) {

        if ( this -> vertices_last_index == this -> size - 1 ) {

            log ( "Error: Vertex Array is Fulled" );
            return;

        }

        this -> addVertex ( vertex1 );

    }

    if ( v2 < 0 ) {

        this -> addVertex ( vertex2 );

    }

    v1 = this -> findVertex ( vertex1 );
    v2 = this -> findVertex ( vertex2 );

    if ( this -> edges_length == 0 ) {

        this -> Edges [ this -> edges_last_index ].start_vertex = v1;
        this -> Edges [ this -> edges_last_index ].end_vertex = v2;
        this -> Edges [ this -> edges_last_index ].is_removed = false;

        ++ this -> edges_length;

        return;

    }

    ++ this -> edges_last_index;
    ++ this -> edges_length;

    this -> Edges [ this -> edges_last_index ].start_vertex = v1;
    this -> Edges [ this -> edges_last_index ].end_vertex = v2;
    this -> Edges [ this -> edges_last_index ].is_removed = false;

};

#endif