/******************************************************************************
Author : Abhishek
Roll No. : B15103
CS202 - ADSA - Assignment05 - Binary Tree header file
******************************************************************************/

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1

#include <cstdlib>
#include <iostream>
#include <limits>

namespace cs202{
    template <typename Key, typename Value>
    class BinaryNode
    {
    public:
        Key key_value;
        Value val_value;
        BinaryNode<Key,Value> * left,* right,* parent;
        /*Default constructor. Should assign the default value to key and value
        */
        BinaryNode();
        /*This contructor should assign the key and val from the passed parameters
        */
        BinaryNode(Key key, Value value);
    };

    template<typename Key, typename Value>
    class BinaryTree
    {
        /* You can implement your own helper functions whenever required.
        */
    protected:
        BinaryNode<Key,Value> *root;

    public:
        /* Implement get function to retrieve the value corresponding to given key in binary tree.
        */
        virtual Value get(const Key& key);
        /* Implement remove function that can delete a node in binary tree with given key. 
        */
        virtual void remove(const Key& key) ;
        /* Implement has function which will return true if the given key is present in binary tree 
        * otherwise return false.  
        */
        virtual bool has(const Key& key) ;  
        /* Implement put function such that newly inserted node keep the tree balanced. 
        */ 
        virtual void put(const Key& key, const Value& value) ;
        /*
        *This method print all the key value pairs of the binary tree, as
        *observed in an in order traversal.
        */
        virtual void print_in_order();
        /*
        *This method print all the key value pairs of the binary tree, as
        *observed in an pre order traversal.
        */
        virtual void print_pre_order();
        /*
        *This method print all the key value pairs of the binary tree, as
        *observed in a post order traversal.
        */
        virtual void print_post_order();
        /*
        *This method returns the minimum element in the binary tree.
        */
        virtual Key minimum();
        /*
        * This method returns the maximum element in the binary tree.
        */
        virtual Key maximum();
        /*
        *This method returns the successor, i.e, the next larget element in the
        *binary tree, after Key.
        */
        virtual Key successor(const Key& key);
        /*
        * This method returns the predessor, ie, the next smallest element in the
        * binary tree, after Key.
        */
        virtual Key predecessor(const Key& key);
    };
}
#endif /* ifndef BINARYTREE_HPP */