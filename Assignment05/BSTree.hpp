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
#include <queue>

#include "BinaryTree.hpp"

using namespace cs202;

namespace cs202{
    template <typename Key, typename Value>
    class BSTree : public BinaryTree<Key, Value> {
        /* Inherit as many functions as possible from BinaryTree.
        * Only override those where you can decrease the time complexity and where you absolutely need to do it.
        * Also make sure that all inherited functions work correctly in the context of a binary search tree.
        */
    public:
        /*
        * This method returns the current height of the binary search tree.
        */
        virtual int getHeight(){
            if(BinaryTree<Key,Value>::root == NULL){
                return -1;
            }
            std::queue<BinaryNode<Key,Value> *> q;
            q.push(BinaryTree<Key,Value>::root);
            int height = -1;

            while(1){
                int nC = q.size();
                if(nC == 0)
                    return height;

                height++;

                while(nC > 0){
                    BinaryNode<Key,Value> *ptr = q.front();
                    q.pop();
                    if(ptr->left != NULL){
                        q.push(ptr->left);
                    }
                    if(ptr->right != NULL){
                        q.push(ptr->right);
                    }
                    nC--;
                }
            }
        };
        /*
        * This method returns the total number of elements in the binary search tree.
        */
        virtual int size(){
            if(BinaryTree<Key,Value>::root == NULL){
                return 0;
            }
            std::queue<BinaryNode<Key,Value> *> q1,q2;
            q1.push(BinaryTree<Key,Value>::root);
            while(q1.size > 0){
                BinaryNode<Key,Value> *x = q1.front();
                q1.pop();
                if(x->left != NULL){
                    q1.push(x->left);
                }
                if(x->right != NULL){
                    q1.push(x->right);
                }
                q2.push(x);
            }
            return q2.size();
        }
        /*
        * This method prints the key value pairs of the binary search tree, sorted by
        * their keys.
        */
        virtual void print(){
            BinaryTree<Key,Value>::print_in_order();
        };

        /* Implement put function such that newly inserted node keep the tree balanced. 
        */
        void put(const Key& key, const Value& value){
            BinaryNode<Key,Value> *y = NULL;
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x != NULL){
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
            if(y == NULL){
                BinaryTree<Key,Value>::root = z;
            }
            else if(key < y->key){
                y->left = z;
            }
            else{
                y->right = z;
            }
        }

        /* Implement has function which will return true if the given key is present in binary tree 
        * otherwise return false.  
        */
        bool has(const Key& key){
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
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
        }

        /* Implement get function to retrieve the value corresponding to given key in binary tree.
        */
        Value get(const Key& key){
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x != NULL){
                if(key == x->key){
                    return x->value;
                }
                else if(key < x->key){
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
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x->left != NULL){
                x = x->left;
            }
            return x->key_value;
        }

        /*
        * This method returns the maximum element in the binary tree.
        */
        Key maximum(void){
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x->right != NULL){
                x = x->right;
            }
            return x->key_value;
        }

        virtual void transplant(BinaryNode<Key,Value>* u,BinaryNode<Key,Value>* v){
            if(u->parent == NULL)
                BinaryTree<Key,Value>::root = v;
            else if(u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            if(v != NULL){
                v->parent = u->parent;
            }
        }

        /* Implement remove function that can delete a node in binary tree with given key. 
        */
        void remove(const Key& key){
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x != NULL){
                if(key == x->key){
                    BinaryNode<Key,Value> *y;
                    if(x->left == NULL){                                        //having no child or only left child
                        transplant(x,x->right);
                    }
                    else if(x->right == NULL){                                  //having only right child
                        transplant(x,x->left);
                    }
                    else{                                                       //having both children
                        BinaryNode<Key,Value> *z = x->right;
                        while(z->left != NULL){                                 //seeking out the successor of x
                            z = z->left;
                        }
                        y = z;              
                        if(y->parent != x){                                     //stabilising at the previous y node and
                            transplant(y,y->right);                             //taking care of its right child
                            y->right = x->right;
                            y->right->parent = y;
                        }
                        transplant(x,y);                                        //swapping x and its successor
                        y->left = x->left;
                        y->left->parent = y;
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
        }

        /*
        *This method returns the successor, i.e, the next larget element in the
        *binary tree, after Key.
        */
        Key successor(const Key& key){
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x != NULL){
                if(key == x->key){
                    if(x->right != NULL){
                        x = x->right;
                        while(x->left != NULL){
                            x = x->left;
                        }
                        return x->key_value;
                    }
                    BinaryNode<Key,Value> *y = x->parent;
                    while(y != NULL && x == y->right){
                        x = y;
                        y = y->parent;
                    }
                    return y->key_value;
                }
                else if(key < x->key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            throw -1;
        }

        /*
        * This method returns the predessor, ie, the next smallest element in the
        * binary tree, after Key.
        */
        Key predecessor(const Key& key){
            BinaryNode<Key,Value> *x = BinaryTree<Key,Value>::root;
            while(x != NULL){
                if(key == x->key){
                    if(x->left != NULL){
                        x = x->left;
                        while(x->right != NULL){
                            x = x->right;
                        }
                        return x->key_value;
                    }
                    BinaryNode<Key,Value> *y = x->parent;
                    while(y != NULL && x == y->left){
                        x = y;
                        y = y->parent;
                    }
                    return y->key_value;
                }
                else if(key < x->key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
        }
    };
}

#endif /* ifndef BSTREE_HPP */