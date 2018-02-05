
#include <iostream>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

namespace NonStd {

    template < typename T >
    class TreeNode {

        private:

            TreeNode < T > * left, * right, * parent;
            T data;

            void disposeObject ();

        public:

            TreeNode ( const T element );
            TreeNode ( TreeNode < T > * parent = nullptr, TreeNode < T > * left = nullptr, TreeNode < T > * right = nullptr );
            virtual ~TreeNode ();

            TreeNode < T > * getLeftChild ();
            TreeNode < T > * getRightChild ();
            TreeNode < T > * getParent ();
            T * getData ();

            void setLeftChild ( TreeNode < T > * node );
            void setRightChild ( TreeNode < T > * node );
            void setParent ( TreeNode < T > * node );
            void setData ( T element );

    };

    template < typename T >
    class BinaryTree {

        private:

            TreeNode < T > * root;
            std::size_t size;

            void deepTransversal ( TreeNode < T > & node );

        public:

            BinaryTree ( const T element );
            BinaryTree ();
            virtual ~BinaryTree ();

            void insert ( const T element );
            void remove ( const T element );

            bool find ( const T element ) const;
            std::size_t getSize () const;

    };

};

#include "../src/binary_tree.cpp"

#endif