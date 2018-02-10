
#include <iostream>
#include <list>
#include <queue>

// should use static polyporphism to handle representations of Graph for both performance and reusability

#ifndef GRAPH_ADJ_LIST_H
#define GRAPH_ADJ_LIST_H

template < typename T, int V >
class Graph {

    struct Vertex {

        T data;
        bool is_removed;

        Vertex () : is_removed ( true ) {};

    };

    Vertex Vertices [ V ] = {};
    std::list < T > Edges [ V ] = {};

    const int size = V;
    std::size_t vertices_length;
    std::size_t edges_length;
    int vertices_last_index, edges_last_index;

    public:

        Graph ();

        void addVertex ( const T vertex );
        void addEdge ( const T vertex1, const T vertex2 );

        int findVertex ( const T vertex ) const;
        T getVertex ( const std::size_t index ) const;

        void deepFirstSearch () const;
        void breathFirstSearch () const;

};

template < typename T, int V >
Graph< T, V >::Graph () : vertices_length ( 0 ), edges_length ( 0 ), vertices_last_index ( 0 ), edges_last_index ( 0 ) {

};

template < typename T, int V >
int Graph< T, V >::findVertex ( const T vertex ) const {

    int index = this -> vertices_last_index;

    for ( ; index >= 0; -- index ) {

        if ( this -> Vertices [ index ].data == vertex && !this -> Vertices [ index ].is_removed ) {

            return index;

        }

    }

    return -1;

};

template < typename T, int V >
void Graph< T, V >::addVertex ( const T vertex ) {

    if ( this -> vertices_last_index == this -> size ) {

        std::cout << "Error: Vertex Array is Fulled" << std::endl;
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

template < typename T, int V >
void Graph< T, V >::addEdge ( const T vertex1, const T vertex2 ) {

    int v1 = this -> findVertex ( vertex1 );
    int v2 = this -> findVertex ( vertex2 );

    if ( v1 < 0 ) {

        if ( this -> vertices_last_index == this -> size - 1 ) {

            std::cout << "Error: Vertex Array is Fulled" << std::endl;
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

        this -> Edges [ v1 ].push_back ( v2 );

        ++ this -> edges_length;

        return;

    }

    if ( this -> Edges [ v1 ].empty () ) {

        ++ this -> edges_last_index;

    }

    ++ this -> edges_length;

    this -> Edges [ v1 ].push_back ( v2 );

};

template < typename T, int V >
void Graph< T, V >::breathFirstSearch () const {

    std::queue < int > visited;
    int index = 0;
    const int & s = this -> vertices_length;
    std::size_t visited_length = 0;

    if ( !this -> vertices_length || !this -> edges_length ) {

        std::cout << "Cannot depth search on empty storage" << std::endl;
        return;

    }

    while ( visited_length != s ) {

        if ( visited.empty () ) {

            visited.push ( index );

            std::cout << this -> Vertices [ index ].data << std::endl;

            index = this -> Edges [ index ].front ();

            ++ visited_length;

        } else {

            if ( this -> Edges [ index ].front () == visited.back () ) {

                visited.pop ();

                index = this -> Edges [ index ].back ();

            } else {

                visited.push ( index );

                std::cout << this -> Vertices [ index ].data << std::endl;

                index = this -> Edges [ index ].front ();

                ++ visited_length;

            }

        }

    }

};

#endif