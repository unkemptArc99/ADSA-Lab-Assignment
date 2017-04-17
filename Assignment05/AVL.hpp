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
        Key key_value;
        Value val_value;
        AVLNode *left,*right,*parent;
        unsigned int compressed_key;
        int AVLheight;
        int AVL_BF;

        /*Default constructor. Should assign the default value to key and value
        */
        AVLNode(){
            key_value = std::numeric_limits<Key>::min();
            val_value = std::numeric_limits<Value>::min();
            left = NULL;
            right = NULL;
            parent = NULL;
            compressed_key = cs202_hash::primary_hash_map(key_value);
            AVLheight = 0;
            AVL_BF = 0;
        };
        /*This contructor should assign the key and val from the passed parameters
        */
        AVLNode(Key key, Value value){
            key_value = key;
            val_value = value;
            left = NULL;
            right = NULL;
            parent = NULL;
            compressed_key = cs202_hash::primary_hash_map(key_value);
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
    public:
        /* Implement put function such that newly inserted node keep the tree balanced. 
        */
        void put(const Key& key, const Value& value){
            AVLNode<Key,Value> *y = NULL;
            AVLNode<Key,Value> *x = root;
            while(x != NULL){
                y = x;
                if(key < x->key_value){
                    x = x->left;   
                }
                else{
                    x = x->right;
                }
            }
            AVLNode<Key,Value> *z = new AVLNode<Key,Value>(key,value);
            z->parent = y;
            z->left = NULL;
            z->right = NULL;
            if(y == NULL){
                root = z;
            }
            else if(key < y->key_value){
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
        void computeBF(AVLNode<Key, Value> *z){
            while(z->parent != NULL){
                if(z->left == NULL && z->right == NULL){
                    z->AVLheight = 0;
                    z->AVL_BF = 0;
                }
                else{
                    if(z->left == NULL){
                        z->AVLheight = z->right->AVLheight + 1;
                        z->AVL_BF = (-1) - z->right->AVLheight;
                    }
                    else if(z->right == NULL){
                        z->AVLheight = z->left->AVLheight + 1;
                        z->AVL_BF = z->left->AVLheight + 1;
                    }
                    else{
                        z->AVLheight = z->left->AVLheight,z->right->AVLheight + 1;
                        z->AVL_BF = z->left->AVLheight - z->right->AVLheight;
                    }
                }
                z = z->parent;
            }
        }
        
        /* Function : insertBalance
        Balances the tree after insertion of new node;
        */
        void insertBalance(AVLNode<Key,Value> *z){
           bool flag = false;
           //Balancing the node
           computeBF(z);
           //Balancing the node ends
           while(!flag && z != NULL){
                //Checking if there is an imbalance in the Balance factor
                //case 1
                if(z->AVL_BF == 2 && z->left->AVL_BF == 1){
                    rightRotation(z);
                    flag = true;
                }
                //case 2
                else if(z->AVL_BF == -2 && z->right->AVL_BF == -1){
                    leftRotation(z);
                    flag = true;
                }
                //case 3
                else if(z->AVL_BF == 2 && z->left->AVL_BF == -1){
                    leftRotation(z->left);
                    rightRotation(z);
                    flag = true;
                }
                //case 4
                else if(z->AVL_BF == -2 && z->right->AVL_BF == 1){
                    rightRotation(z->right);
                    leftRotation(z);
                    flag = true;
                }
                z = z->parent;
            }
        }
         /* Function leftRotation
        *
        * Used for: left rotation around a node
        */
		void leftRotation(AVLNode<Key,Value>* node){
        	AVLNode<Key,Value> *y = node->right;
        	AVLNode<Key,Value> *x = node;
            y->parent = x->parent;
        	x->right = y->left;
        	if(y->left != NULL){
        		y->left->parent = x;
        	}
        	if(x->parent == NULL){
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
            computeBF(y);
        }

        /* Function rightRotation
        *
        * Used for: right rotation around a node
        */
		void rightRotation(AVLNode<Key,Value>* node){
        	AVLNode<Key,Value> *y = node->left;
        	AVLNode<Key,Value> *x = node;
        	x->left = y->right;
        	if(y->right != NULL){
        		y->right->parent = x;
        	}
        	y->parent = x->parent;
        	if(x->parent == NULL){
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
            computeBF(y);
        }

        void transplant(AVLNode<Key,Value>* u,AVLNode<Key,Value>* v){
            if(u->parent == NULL)
                root = v;
            else if(u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            if(v != NULL){
                v->parent = u->parent;
            }
            if(v != NULL)
                computeBF(v);
        }

        /* Implement remove function that can delete a node in binary tree with given key. 
        */
        void remove(const Key& key){
            AVLNode<Key,Value> *x = root;
            unsigned int key1 = cs202_hash::primary_hash_map(key);
            bool flag = true;
            while(x != NULL && flag){
                if(key1 == x->compressed_key){
                    AVLNode<Key,Value> *y;
                    AVLNode<Key, Value> *p;
                    if(x->left == NULL){                                        //having no child or only left child
                        p = x->parent;
                        transplant(x,x->right);
                        insertBalance(p);
                    }
                    else if(x->right == NULL){                                  //having only right child
                        p = x->parent;
                        transplant(x,x->left);
                        insertBalance(p);
                    }
                    else{                                                       //having both children
                        AVLNode<Key,Value> *z = x->right;
                        while(z->left != NULL){                                 //seeking out the successor of x
                            z = z->left;
                        }
                        y = z;              
                        if(y->parent != x){                                     //stabilising at the previous y node and
                            transplant(y,y->right);                             //taking care of its right child
                            y->right = x->right;
                            y->right->parent = y;
                        }
                        p = y->parent;
                        transplant(x,y);                                        //swapping x and its successor
                        y->left = x->left;
                        y->left->parent = y;
                        insertBalance(p);
                    }
                    delete(x);
                    flag = false;
                }
                else if(key1 < x->compressed_key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            if(x == NULL){
                throw -1;
            }
        }

        /* Implement has function which will return true if the given key is present in binary tree 
        * otherwise return false.  
        */
        bool has(const Key& key){
            AVLNode<Key,Value> *x = root;
            unsigned int key1 = cs202_hash::primary_hash_map(key);
            while(x != NULL){
                if(key1 == x->compressed_key){
                    return true;
                }
                else if(key1 < x->compressed_key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            return false;
        }

        /* Implement get function to retrieve the value corresponding to given key in binary tree.
        */
        Value get(const Key& key){
            AVLNode<Key,Value> *x = root;
            unsigned int key1 = cs202_hash::primary_hash_map(key);
            while(x != NULL){
                if(key1 == x->compressed_key){
                    return x->val_value;
                }
                else if(key1 < x->compressed_key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            throw -1;
        }

        /*
        *This method returns the minimum element in the binary tree.
        */
        Key minimum(void){
            AVLNode<Key,Value> *x = root;
            while(x->left != NULL){
                x = x->left;
            }
            return x->key_value;
        }

        /*
        * This method returns the maximum element in the binary tree.
        */
        Key maximum(void){
            AVLNode<Key,Value> *x = root;
            while(x->right != NULL){
                x = x->right;
            }
            return x->key_value;
        }

        /*
        *This method returns the successor, i.e, the next larget element in the
        *binary tree, after Key.
        */
        Key successor(const Key& key){
            AVLNode<Key,Value> *x = root;
            unsigned int key1 = cs202_hash::primary_hash_map(key);
            while(x != NULL){
                if(key1 == x->compressed_key){
                    if(x->right != NULL){
                        x = x->right;
                        while(x->left != NULL){
                            x = x->left;
                        }
                        return x->key_value;
                    }
                    AVLNode<Key,Value> *y = x->parent;
                    while(y != NULL && x == y->right){
                        x = y;
                        y = y->parent;
                    }
                    if(y == NULL){
                        throw -2;
                    }
                    return y->key_value;
                }
                else if(key1 < x->compressed_key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            if(x == NULL){
                throw -1;
            }
        }

        /*
        * This method returns the predessor, ie, the next smallest element in the
        * binary tree, after Key.
        */
        Key predecessor(const Key& key){
            AVLNode<Key,Value> *x = root;
            unsigned int key1 = cs202_hash::primary_hash_map(key);
            while(x != NULL){
                if(key1 == x->compressed_key){
                    if(x->left != NULL){
                        x = x->left;
                        while(x->right != NULL){
                            x = x->right;
                        }
                        return x->key_value;
                    }
                    AVLNode<Key,Value> *y = x->parent;
                    while(y != NULL && x == y->left){
                        x = y;
                        y = y->parent;
                    }
                    if(y == NULL){
                        throw -2;
                    }
                    return y->key_value;
                }
                else if(key1 < x->compressed_key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            if(x == NULL){
                throw -1;
            }
        }
    };
}

#endif /* ifndef AVL_HPP */