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
        AVLNode(){
            BinaryNode<Key,Value>::key_value = std::numeric_limits<Key>::min();
            BinaryNode<Key,Value>::val_value = std::numeric_limits<Value>::min();
            BinaryNode<Key,Value>::left = NULL;
            BinaryNode<Key,Value>::right = NULL;
            BinaryNode<Key,Value>::parent = NULL;
            AVLheight = 0;
            AVL_BF = 0;
        };
        /*This contructor should assign the key and val from the passed parameters
        */
        AVLNode(Key key, Value value){
            BinaryNode<Key,Value>::key_value = key;
            BinaryNode<Key,Value>::val_value = value;
            BinaryNode<Key,Value>::left = NULL;
            BinaryNode<Key,Value>::right = NULL;
            BinaryNode<Key,Value>::parent = NULL;
            AVLheight = 0;
            AVL_BF = 0;
        };
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
    protected:
        AVLNode<Key,Value> *root;
        AVLNode<Key,Value> *nil;
    public:
        /* Implement put function such that newly inserted node keep the tree balanced. 
        */
        void put(const Key& key, const Value& value){
            BinaryNode<Key,Value> *y = nil;
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x != nil){
                x->
                y = x;
                if(key < x->key_value){
                    x = x->left;   
                }
                else{
                    x = x->right;
                }
            }
            BinaryNode<Key,Value> *z = new BinaryNode<Key,Value>(key,value);
            z->parent = y;
            z->left = nil;
            z->right = nil;
            if(y == NULL){
                BinaryTree<Key,Value>::root = z;
            }
            else if(key < y->key){
                y->left = z;
            }
            else{
                y->right = z;
            }
            insertBalance(z);
        }

        /* Function : computeBF
        * computes the Balance Factor at the specified node
        */
        void computeBF(BinaryNode<Key, Value> *z){
            if(z->left == nil && z->right == nil){
                z->AVLheight = 0;
                z->AVL_BF = 0;
            }
            else{
                if(z->left == nil){
                    z->AVLheight = z->right->AVLheight + 1;
                    z->AVL_BF = (-1) - z->right->AVLheight;
                }
                else if(z->right == nil){
                    z->AVLheight = z->left->AVLheight + 1;
                    z->AVL_BF = z->left->AVLheight + 1;
                }
                else{
                    z->AVLheight = max(z->left->AVLheight,z->right->AVLheight) + 1;
                    z->AVL_BF = z->left->AVLheight - z->right->AVLheight;
                }
            }
        }
        
        /* Function : insertBalance
        Balances the tree after insertion of new node;
        */
        void insertBalance(BinaryNode<Key,Value> *z){
            //Balancing the node
            computeBF(z);
            //Balancing the node ends
            //Checking if there is an imbalance in the Balance factor
            //case 1
            if(z->AVL_BF == 2 && z->left->AVL_BF == 1){
                rightRotation(z);
            }
            //case 2
            else if(z->AVL_BF == -2 && z->right->AVL_BF == -1){
                leftRotation(z);
            }
            //case 3
            else if(z->AVL_BF == 2 && z->left->AVL_BF == -1){
                leftRotation(z->left);
                rightRotation(z);
            }
            //case 4
            else if(z->AVL_BF == -2 && z->right->AVL_BF == 1){
                rightRotation(z->right);
                leftRotation(z);
            }
        }

         /* Function leftRotation
        *
        * Used for: left rotation around a node
        */
		void leftRotation(BinaryNode<Key,Value>* node){
        	BinaryNode<Key,Value> *y = node->right;
        	BinaryNode<Key,Value> *x = node;
            y->parent = x->parent;
        	x->right = y->left;
        	if(y->left != nil){
        		y->left->parent = x;
        	}
        	if(x->parent == nil){
        		root = y;
        	}
        	else if(x == x->parent->left){
        		x->parent->left = y;
        	}
        	else{
        		x->parent->right = y;
        	}
        	y->left = x;
        	x->parent = y;
            computeBF(x);
            computeBF(y);
            computeBF(y->parent);
        }

        /* Function rightRotation
        *
        * Used for: right rotation around a node
        */
		void rightRotation(BinaryNode<Key,Value>* node){
        	BinaryNode<Key,Value> *y = node->left;
        	BinaryNode<Key,Value> *x = node;
        	x->left = y->right;
        	if(y->right != nil){
        		y->right->parent = x;
        	}
        	y->parent = x->parent;
        	if(x->parent == nil){
        		root = y;
        	}
        	else if(x == x->parent->right){
        		x->parent->right = y;
        	}
        	else{
        		x->parent->left = y;
        	}
        	y->right = x;
        	x->parent = y;
            computeBF(x);
            computeBF(y);
            computeBF(y->parent);
        }
    };
}

#endif /* ifndef AVL_HPP */