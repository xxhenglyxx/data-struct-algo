
#include "red_black_tree.h"

namespace NonStd {

    template < typename T >
    RedBlackTree< T >::RedBlackTree ( const T & data ) : root ( std::make_unique < TreeNode > ( data ) ), length ( 1 ) {

        this -> root -> changeColor ();

    };

    template < typename T >
    int RedBlackTree< T >::validateBlackHeight ( TreeNode * node ) {

        if ( !node ) return 0;

        int valid_left = validateBlackHeight ( node -> left.get () );
        int valid_right = validateBlackHeight ( node -> right.get () );

        return valid_left != valid_right ? -1 : node -> is_red ? valid_left : 1 + valid_right;

    };

    template < typename T >
    bool RedBlackTree< T >::validateParentChild ( TreeNode * node ) {

        if ( !node ) return true;

        bool left_red = validateParentChild ( node -> left.get () );
        bool right_red = validateParentChild ( node -> right.get () );

        return left_red == right_red && left_red != node -> is_red ? node -> is_red : left_red;

    };

    template < typename T >
    void RedBlackTree< T >::validateTree () {

        std::cout << std::boolalpha;

        TreeNode * temp = this -> root.get ();

        // validate from property 4 to 1

        // validate property 4: path from node to leaf contain same number of black nodes ( root node does not count )
        bool is_valid = this -> validateBlackHeight ( temp ) <= 0 ? false : true;

        std::cout << "Black Height Valid: " << is_valid << std::endl;

        // validate property 3: external node must be black
        // validate property 2: if parent node is red, both child must be black
        is_valid = this -> validateParentChild ( temp );

        std::cout << "Parent Child Valid: " << is_valid << std::endl;

        // validate property 1: root always red
        // if ( this -> root -> is_red ) {

        //     this -> root -> changeColor ();

        // }

    };

    template < typename T >
    bool RedBlackTree< T >::search ( const T & data, const uniqueTN & node ) {

        if ( !node ) return false;

        return
            node -> data == data ?
                true
                :
                node -> data < data ? this -> search ( data, node -> right ) : this -> search ( data, node -> left );

    };

    template < typename T >
    bool RedBlackTree< T >::find ( const T & data ) {

        return this -> search ( data, this -> root );

    };

    template < typename T >
    void RedBlackTree< T >::rightRotate ( TreeNode * node ) {

        if ( !node -> parent -> parent ) {

            uniqueTN rightNode = std::make_unique < TreeNode > ( node -> parent -> data );
            rightNode -> right = std::move ( node -> parent -> right );
            rightNode -> left = std::move ( node -> right );

            node -> parent -> parent = node;
            node -> parent -> changeColor ();
            this -> root = std::move ( node -> parent -> left );

            this -> root -> right = std::move ( rightNode );

            this -> root -> parent = nullptr;


        } else {

            node -> parent -> parent = node;
            node -> parent -> changeColor ();
            node -> parent -> left = std::move ( node -> right );

        }

        // node -> parent -> left = std::move ( node -> right );
        node -> changeColor ();

    };

    template < typename T >
    void RedBlackTree< T >::leftRotate ( TreeNode * node ) {

        if ( !node -> parent -> parent ) {

            uniqueTN leftNode = std::make_unique < TreeNode > ( node -> parent -> data );
            leftNode -> left = std::move ( node -> parent -> left );
            leftNode -> right = std::move ( node -> left );

            node -> parent -> parent = node;
            node -> parent -> changeColor ();
            this -> root = std::move ( node -> parent -> right );

            this -> root -> left = std::move ( leftNode );

            this -> root -> parent = nullptr;

        } else {

            node -> parent -> parent = node;
            node -> parent -> changeColor ();
            node -> parent -> right = std::move ( node -> left );

        }

        node -> changeColor ();

    };

    template < typename T >
    void RedBlackTree< T >::validateTree ( TreeNode * node, const bool is_left ) {

        if ( is_left ) {

            if ( node -> is_red && node -> left -> is_red ) {

                this -> rightRotate ( node );

            } else if ( node -> is_red && node -> right -> is_red ) {

                this -> leftRotate ( node -> right.get () );
                this -> rightRotate ( node -> parent );

            }

        } else {

            if ( node -> is_red && node -> right -> is_red ) {

                this -> leftRotate ( node );

            } else if ( node -> is_red && node -> left -> is_red ) {

                this -> rightRotate ( node -> left.get () );
                this -> leftRotate ( node -> parent );

            }

        }

    };

    template < typename T >
    bool RedBlackTree< T >::add ( const T & data ) {

        if ( ! this -> root ) {

            this -> root = std::make_unique < TreeNode > ( data );
            this -> root -> changeColor ();

            ++ this -> length;

            return true;

        } else {

            TreeNode * temp = this -> root.get ();
            TreeNode * prev = this -> root.get ();

            while ( temp ) {

                prev = temp;

                temp -> data < data ? temp = temp -> right.get () : temp = temp -> left.get ();

            }

            std::unique_ptr < TreeNode > node = std::make_unique < TreeNode > ( data );

            if ( prev -> data < data ) {

                prev -> right = std::move ( node );
                prev -> right -> parent = prev;

                this -> validateTree ( prev, false );

            } else {

                prev -> left = std::move ( node );
                prev -> left -> parent = prev;

                this -> validateTree ( prev, true );

            }

            ++ this -> length;

            return true;

        }

        return false;

    };

};