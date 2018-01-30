
#include "binary_tree.h"

namespace NonStd {

    template < typename T >
    TreeNode< T >::TreeNode ( TreeNode < T > * parent, TreeNode < T > * left, TreeNode < T > * right ) :
    parent ( parent ), left ( left ), right ( right ) {
    };

    template < typename T >
    TreeNode< T >::TreeNode ( const T element ) : data ( element ), parent ( nullptr ), left ( nullptr ), right ( nullptr ) {
    };

    template < typename T >
    void TreeNode< T >::setData ( const T element ) {

        this -> data = element;

    };

    template < typename T >
    T * TreeNode< T >::getData () {

        return & this -> data;

    };

    template < typename T >
    TreeNode< T >::~TreeNode () {

        delete this -> left;
        delete this -> right;
        delete this -> parent;

    };

    template < typename T >
    void TreeNode< T >::disposeObject () {

        delete this;

    };

    template < typename T >
    TreeNode < T > * TreeNode< T >::getLeftChild () {

        return this -> left;

    };

    template < typename T >
    TreeNode < T > * TreeNode< T >::getRightChild () {

        return this -> right;

    };

    template < typename T >
    TreeNode < T > * TreeNode< T >::getParent () {

        return this -> parent;

    };

    template < typename T >
    void TreeNode< T >::setLeftChild ( TreeNode < T > * node ) {

        this -> left = node;

    };

    template < typename T >
    void TreeNode< T >::setRightChild ( TreeNode < T > * node ) {

        this -> right = node;

    };

    template < typename T >
    void TreeNode< T >::setParent ( TreeNode < T > * node ) {

        this -> parent = node;

    };

    template < typename T >
    BinaryTree< T >::BinaryTree ( const T element ) : root ( new TreeNode < T > ( element ) ), size ( 1 ) {
    };

    template < typename T >
    BinaryTree< T >::BinaryTree () : root ( nullptr ), size ( 0 ) {
    };

    template < typename T >
    BinaryTree< T >::~BinaryTree () {

        delete this -> root;

    };

    template < typename T >
    std::size_t BinaryTree< T >::getSize () const {

        return this -> size;

    };

    template < typename T >
    void BinaryTree< T >::insert ( const T element ) {

        if ( !this -> root ) {

            this -> root = new TreeNode < T > ( element );

        } else {

            TreeNode < T > * tree = this -> root;
            TreeNode < T > * parent;
            bool insert_right = true;
            T * data = nullptr;

            while ( tree ) {

                parent = tree;
                data = tree -> getData ();

                if ( data ) {

                    if ( *data < element ) {

                        tree = tree -> getRightChild ();
                        insert_right = true;

                    } else if ( *data >= element ) {

                        tree = tree -> getLeftChild ();
                        insert_right = false;

                    }

                }

            }

            tree = new TreeNode < T > ( element );
            insert_right ? parent -> setRightChild ( tree ) : parent -> setLeftChild ( tree );

        }

        ++ this -> size;

    };

    template < typename T >
    void BinaryTree< T >::remove ( const T element ) {

        -- this -> size;

    };

    template < typename T >
    bool BinaryTree< T >::find ( const T element ) const {

        TreeNode < T > * tree = this -> root;
        T * data = nullptr;

        while ( tree ) {

            data = tree -> getData ();

            if ( *data == element ) {

                return true;

            } else if ( *data >= element ) {

                tree = tree -> getLeftChild ();

            } else if ( *data < element ) {

                tree = tree -> getRightChild ();

            }

        }

        return false;

    };

};