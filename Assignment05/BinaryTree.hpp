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
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

#include "hash_main.hpp"

namespace cs202{
    std::string convbinary(int n){
        std::string s;
        while(n){
            if(n%2==1)
                s.push_back('1');
            else
                s.push_back('0');
            n = n/2;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    template <typename Key, typename Value>
    class BinaryNode
    {
    public:
        Key key_value;
        Value val_value;
        BinaryNode<Key,Value> * left,* right,* parent;
        unsigned int compressed_key;
        /*Default constructor. Should assign the default value to key and value
        */
        BinaryNode(){
            key_value = std::numeric_limits<Key>::min();
            val_value = std::numeric_limits<Value>::min();
            left = NULL;
            right = NULL;
            parent = NULL;
            compressed_key = cs202_hash::primary_hash_map(key_value);
        }
        /*This contructor should assign the key and val from the passed parameters
        */
        BinaryNode(Key key, Value value){
            key_value = key;
            val_value = value;
            left = NULL;
            right = NULL;
            parent = NULL;
            compressed_key = cs202_hash::primary_hash_map(key_value);
        }
    };

    template<typename Key, typename Value>
    class BinaryTree
    {
        /* You can implement your own helper functions whenever required.
        */
    protected:
        BinaryNode<Key,Value> *root;
        int total_node;
        std::vector<Key> value_of_key;

    public:
        /* Implement get function to retrieve the value corresponding to given key in binary tree.
        */
        virtual Value get(const Key& key){
            std::queue<BinaryNode<Key,Value> *> q;
            q.push(root);
            while(q.size() > 0){
                BinaryNode<Key,Value> *x = q.front();
                q.pop();
                if(x->key_value == key){
                    return x->val_value;
                }
                if(x->left != NULL)
                    q.push(x->left);
                if(x->right != NULL)
                    q.push(x->right);
            }
            throw -1;
        }
        
        void transplant(BinaryNode<Key,Value>* u,BinaryNode<Key,Value>* v){
            if(u->parent == NULL)
                root = v;
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
        virtual void remove(const Key& key){
            std::queue<BinaryNode<Key,Value> *> q;
            q.push(root);
            while(q.size() > 0){
                BinaryNode<Key,Value> *x = q.front();
                q.pop();
                if(x->key_value == key){
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
                    total_node--;
                }
                if(x->left != NULL)
                    q.push(x->left);
                if(x->right != NULL)
                    q.push(x->right);
            }
        }

        /* Implement has function which will return true if the given key is present in binary tree 
        * otherwise return false.  
        */
        virtual bool has(const Key& key){
            typename std::vector<Key>::iterator it;
            it = find(value_of_key.begin(), value_of_key.end(),key);
            if(it != value_of_key.end()){
                return true;
            }
            return false;
        }

        /* Implement put function such that newly inserted node keep the tree balanced. 
        */ 
        virtual void put(const Key& key, const Value& value){
            BinaryNode<Key,Value> *z = new BinaryNode<Key,Value>(key,value);
            total_node++;
            if(root == NULL){
                root = z;
            }
            else{
                BinaryNode<Key,Value> *y = root;
                std::string ye = convbinary(total_node);
                int len = ye.length();
                for (int i = 1; i < len - 1 ; i++)
                {
                    if(ye[i]=='1'){
                        y = y->right;
                    }
                    else{
                        y = y->left;
                    }
                }
                if(ye[len - 1] == '0')
                    y->left = z;
                else
                    y->right = z;
                z->parent = y;
            }
            value_of_key.push_back(key);
        }

        /*
        *This method print all the key value pairs of the binary tree, as
        *observed in an in order traversal.
        */
        virtual void print_in_order(){
            std::cout<<"Key_value\tValue\tCompressed_Key"<<std::endl;
            inorder(root);
        }

        virtual void inorder(BinaryNode<Key,Value>* node){
            if(node != NULL){
                inorder(node->left);
                std::cout<<node->key_value<<"\t"<<node->val_value<<"\t"<<node->compressed_key<<std::endl;
                inorder(node->right);
            }
        }

        /*
        *This method print all the key value pairs of the binary tree, as
        *observed in an pre order traversal.
        */
        virtual void print_pre_order(){
            std::cout<<"Key_value\tValue\tCompressed_Key"<<std::endl;
            preorder(root);
        }

        virtual void preorder(BinaryNode<Key,Value>* node){
            if(node != NULL){
                std::cout<<node->key_value<<"\t"<<node->val_value<<"\t"<<node->compressed_key<<std::endl;
                preorder(node->left);
                preorder(node->right);
            }
        }

        /*
        *This method print all the key value pairs of the binary tree, as
        *observed in a post order traversal.
        */
        virtual void print_post_order(){
            std::cout<<"Key_value\tValue\tCompressed_Key"<<std::endl;
            postorder(root);
        }

        virtual void postorder(BinaryNode<Key,Value>* node){
            if(node != NULL){
                postorder(node->left);
                postorder(node->right);
                std::cout<<node->key_value<<"\t"<<node->val_value<<"\t"<<node->compressed_key<<std::endl;
            }
        }

        /*
        *This method returns the minimum element in the binary tree.
        */
        virtual Key minimum(){
            std::vector<Key> v = value_of_key;
            sort(v.begin(), v.end());
            return v[0];
        }

        /*
        * This method returns the maximum element in the binary tree.
        */
        virtual Key maximum(){
            std::vector<Key> v = value_of_key;
            sort(v.begin(), v.end());
            return v[v.size() - 1];
        }

        /*
        *This method returns the successor, i.e, the next larget element in the
        *binary tree, after Key.
        */
        virtual Key successor(const Key& key){
            typename std::vector<Key>::iterator it;
            it = find(value_of_key.begin(), value_of_key.end(),key);
            int dis = std::distance(value_of_key.begin(),it);
            if(dis == value_of_key.size() - 1){
                throw -2;
            }
            else if(dis == value_of_key.size()){
                throw -1;
            }
            else
                return value_of_key[dis + 1];
        }

        /*
        * This method returns the predessor, ie, the next smallest element in the
        * binary tree, after Key.
        */
        virtual Key predecessor(const Key& key){
            typename std::vector<Key>::iterator it;
            it = find(value_of_key.begin(), value_of_key.end(),key);
            int dis = std::distance(value_of_key.begin(),it);
            if(dis == 0){
                throw -2;
            }
            else if(dis == value_of_key.size()){
                throw -1;
            }
            else
                return value_of_key[dis - 1];
        }
        BinaryTree(){
            root = NULL;
            total_node = 0;
        }
    };
}
#endif /* ifndef BINARYTREE_HPP */