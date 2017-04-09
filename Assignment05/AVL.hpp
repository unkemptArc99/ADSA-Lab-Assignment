/******************************************************************************
Author : Abhishek
Roll No. : B15103
CS202 - ADSA - Assignment05 - AVL Tree header file
******************************************************************************/

#ifndef AVL_HPP
#define AVL_HPP 1

#include <cstdlib>
#include <iostream>
#include <limits>

#include "BSTree.hpp"
#include "BinaryTree.hpp"

namespace cs202{

    template <typename Key, typename Value>
    class AVLNode : public BinaryNode<Key,Value>{
    public:
        int AVLheight;
        int AVL_BF;

        /*Default constructor. Should assign the default value to key and value
        */
        AVLNode();
        /*This contructor should assign the key and val from the passed parameters
        */
        AVLNode(Key key, Value value);
    };

    template <typename Key, typename Value>
    class AVL : public BSTree<Key, Value> {
    /*
    * Inherit as much functionality as possible from the BSTree class.
    * Then provide custom AVL Tree functionality on top of that.
    * The AVL Tree should make use of as many BST functions as possible.
    * Override only those methods which are extremely necessary.
    */
    /*
    * Apart from that, your code should have the following four functions:
    * getBalance(node) -> To get the balance at any given node;
    * doBalance(node) -> To fix the balance at the given node;
    * rightRotate(node) -> Perform a right rotation about the given node.
    * leftRotate(node) -> Perform a left rotation about the given node.
    *
    * The signature of these functions are not provided in order to provide you
    * some flexibility in how you implement the internals of your AVL Tree. But
    * make sure these functions are there.
    */
    };
}

#endif /* ifndef AVL_HPP */