/******************************************************************************
Author : Abhishek
Roll No. : B15103
CS202 - ADSA - Assignment05 - Binary Search Tree header file
******************************************************************************/

#ifndef BSTREE_HPP
#define BSTREE_HPP 1

#include <cstdlib>
#include <iostream>
#include <limits>
#include <exception>

#include "BinaryTree.hpp"

namespace cs202{
    template <Key, Value>
    class BSTree : public BinaryTree<Key, Value> {
        /* Inherit as many functions as possible from BinaryTree.
        * Only override those where you can decrease the time complexity and where you absolutely need to do it.
        * Also make sure that all inherited functions work correctly in the context of a binary search tree.
        */
    public:
        /*
        * This method returns the current height of the binary search tree.
        */
        virtual int getHeight();
        /*
        * This method returns the total number of elements in the binary search tree.
        */
        virtual int size();
        /*
        * This method prints the key value pairs of the binary search tree, sorted by
        * their keys.
        */
        virtual void print();

        /* Implement put function such that newly inserted node keep the tree balanced. 
        */
        void put(const Key& key, const Value& value){
            BinaryNode<Key,Value> *y = NULL;
            BinaryNode<Key,Value> *x = root;
            while(x != NULL){
                y = x;
                if(key < x->key_value){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            BinaryNode<Key,Value> *z = new BinaryNode<Key,Value>;
            z->key_value = key;
            z->val_value = value;
            z->parent = y;
            if(y == NULL){
                root = z;
            }
            else if(key < y->key){
                y->left = z;
            }
            else{
                y->right = z;
            }
        };

        /* Implement has function which will return true if the given key is present in binary tree 
        * otherwise return false.  
        */
        bool has(const Key& key){
            BinaryNode<Key,Value> *x = root;
            while(x != NULL){
                if(key == x->key){
                    return true;
                }
                else if(key < x->key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            return false;
        };

        /* Implement get function to retrieve the value corresponding to given key in binary tree.
        */
        Value get(const Key& key){
            BinaryNode<Key,Value> *x = root;
            while(x != NULL){
                if(key == x->key){
                    return value;
                }
                else if(key < x->key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            throw -1;
        };

        /*
        *This method returns the minimum element in the binary tree.
        */
        Key minimum(){
            BinaryNode<Key,Value> *x = root;
            while(x->left != NULL){
                x = x->left;
            }
            return x->key_value;
        };

        /*
        * This method returns the maximum element in the binary tree.
        */
        Key maximum(){
            BinaryNode<Key,Value> *x = root;
            while(x->right != NULL){
                x = x->right;
            }
            return x->key_value;
        };

        /* Implement remove function that can delete a node in binary tree with given key. 
        */
        void remove(const Key& key){
            BinaryNode<Key,Value> *x = root;
            while(x != NULL){
                if(key == x->key){
                    if(x->left == NULL && x->right == NULL){
                        delete x;
                    }
                    else if(x->right == NULL){
                        BinaryNode<Key,Value> *y = x->parent;
                        if(y->left == x){
                            y->left == x->left;
                        }
                        else{
                            y->right == x->left;
                        }
                        (x->left)->parent = y;
                        delete x; 
                    }
                    else if(x->left == NULL){
                        BinaryNode<Key,Value> *y = x->parent;
                        if(y->left == x){
                            y->left == x->right;
                        }
                        else{
                            y->right == x->right;
                        }
                        (x->right)->parent = y;
                        delete x; 
                    }
                    else{
                        BinaryNode<Key,Value> *y = x->parent;
                        BinaryNode<Key,Value> *z = x->left;
                        while(z->left != NULL){
                            z = z->left;
                        }
                        if(y->left == x){
                            y->left == z;
                        }
                        else{
                            y->right == z;
                        }
                        z->parent = y;
                        z->left = x->left;
                        z->right = x->right;
                        delete x;
                    }
                }
                else if(key < x->key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            throw -1;
        };
    };
}

#endif /* ifndef BSTREE_HPP */