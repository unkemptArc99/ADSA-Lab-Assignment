/******************************************************************************
Author : Abhishek
Roll No. : B15103
CS202 - ADSA - Assignment05 - Red-Black Tree header file
******************************************************************************/

#ifndef RBTree_HPP_
#define RBTree_HPP_ 1

#include <cstdlib>
#include <iostream>
#include <limits>

#include "BSTree.hpp"
#include "BinaryTree.hpp"

namespace cs202{
	/* The color enumeration.
 	* Please use this and not integers or characters to store the color of the node
 	* in your red black tree.
 	* Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 	*/
	enum Color { RED, BLACK };

	template<typename Key, typename Value>
	class RBTNode : public BinaryNode<Key,Value> {
	public:
		Color nodeColor;
		/*Default constructor. Should assign the default value to key and value
        */
        RBTNode(){
        	BinaryNode<Key,Value>::key_value = std::numeric_limits<Key>::min();
        	BinaryNode<Key,Value>::val_value = std::numeric_limits<Value>::min();
        	nodeColor = RED;
        	BinaryNode<Key,Value>::left = NULL;
        	BinaryNode<Key,Value>::right = NULL;
        	BinaryNode<Key,Value>::parent = NULL;
        };
        /*This contructor should assign the key and val from the passed parameters
        */
        RBTNode(Key key, Value value){
        	BinaryNode<Key,Value>::key_value = key;
        	BinaryNode<Key,Value>::val_value = value;
        	nodeColor = RED;
        	BinaryNode<Key,Value>::left = NULL;
        	BinaryNode<Key,Value>::right = NULL;
        	BinaryNode<Key,Value>::parent = NULL;		
        };
	};

	template <typename Key, typename Value>
	class RBTree : public BSTree<Key, Value> {
	protected:
		RBTNode<Key,Value> *root;
		RBTNode<Key,Value> *nil;
	/* Inherit as many functions as possible from BSTree.
 	* Only override those which absolutely need it.
 	* Also make sure that all inherited functions work correctly in the context of a red black tree.
 	* node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 	* Use a typedef to refer to a pointer to your node via node_ptr
 	*/

	public:
		/* Implement put function such that newly inserted node keep the tree balanced. 
        */
        void put(const Key& key, const Value& value){
        	BinaryNode<Key,Value> *z = new BinaryNode<Key,Value>(key,value);
        	BinaryNode<Key,Value> *y = nil;
        	BinaryNode<Key,Value> *x = root;
        	while(x != nil){
        		y = x;
        		if(z->key_value < x->key_value){
        			x = x->left;
        		}
        		else{
        			x = x->right;
        		}
        	}
        	z->parent = y;
        	if(y == nil){
        		root = z;
        	}
        	else if(z->key_value < y->key_value){
        		y->left = z;
        	}
        	else{
        		y->right = z;
        	}
        	z->left = nil;
        	z->right = nil;
        	z->color = RED;
        	insertRBFixup(z);
        }

        /* Function leftRotation
        *
        * Used for: left rotation around a node
        */
		void leftRotation(BinaryNode<Key,Value>* node){
        	BinaryNode<Key,Value> *y = node->right;
        	BinaryNode<Key,Value> *x = node;
        	x->right = y->left;
        	if(y->left != nil){
        		y->left->parent = x;
        	}
        	y->parent = x->parent;
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
        }
	 	/* Function insertRBFixup
	 	*
	 	* Used for:
	 	* Used after an insertion in the rb tree.
	 	* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 	*/
		void insertRBFixup(RBTNode<Key,Value>* node){
			BinaryNode<Key,Value> *z = node;
			while(z->parent->color == RED){
				if(z->parent == z->parent->parent->left){								
					BinaryNode<Key,Value> y = z->parent->parent->right;					//case 1
					if(y->color == RED){												//case 1
						z->parent->color = BLACK;										//case 1
						y->color = BLACK;												//case 1
						z->parent->parent->color = RED;									//case 1
						z = z->parent->parent;											//case 1
					}																	//case 1
					else{
						if(z == z->parent->right){										//case 2
							z = z->parent;												//case 2
							leftRotation(z);											//case 2
						}
						z->parent->color = BLACK;										//case 3
						z->parent->parent->color = RED;									//case 3
						rightRotation(z->parent->parent);								//case 3
					}
				}																		
				else{																	
					BinaryNode<Key,Value> y = z->parent->parent->left;					//case 4
					if(y->color == RED){												//case 4
						z->parent->color = BLACK;										//case 4
						y->color = BLACK;												//case 4
						z->parent->parent->color = RED;									//case 4
						z = z->parent->parent;											//case 4
					}																	//case 4
					else{
						if(z == z->parent->left){										//case 5
							z = z->parent;												//case 5
							rightRotation(z);											//case 5
						}
						z->parent->color = BLACK;										//case 6
						z->parent->parent->color = RED;									//case 6
						leftRotation(z->parent->parent);								//case 6
					}
				}
			}
			root->color = BLACK;
		}

		void transplant(BinaryNode<Key,Value>* u,BinaryNode<Key,Value>* v){
            if(u->parent == nil)
                BinaryTree<Key,Value>::root = v;
            else if(u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }

        /* Implement remove function that can delete a node in binary tree with given key. 
        */
        void remove(const Key& key){
            BinaryNode<Key,Value> *z = BinaryTree<Key,Value>::root;
            while(z != nil){
                if(key == z->key){
                    BinaryNode<Key,Value> *y = z;
                    BinaryNode<Key,Value> *x;
                    Color y_original = y->color;
                    if(z->left == nil){	                                        //having no child or only left child
                    	x = z->right;
                        transplant(z,z->right);
                    }
                    else if(z->right == NULL){                                  //having only right child
                    	x = z->left;
                        transplant(z,z->left);
                    }
                    else{                                                       //having both children
                        BinaryNode<Key,Value> *w = z->right;
                        while(w->left != NULL){                                 //seeking out the successor of x
                            w = w->left;
                        }
                        y = w;
                        y_original = y->color;
                        x = y->right;              
                        if(y->parent == z){                                     //stabilising at the previous y node and
                            x->parent = y;
                        }
                        else{
                        	transplant(y,y->right);
                        	y->right = z->right;
                        	y->right->parent = y;
                        }
                        transplant(z,y);
                        y->left = z->left;
                        y->left->parent = y;
                        y->color = z->color;
                    }
                    if(y_original == BLACK){
                    	deleteRBFixup(x);
                    }
                }
                else if(key < z->key){
                    z = z->left;
                }
                else{
                    z = z->right;
                }
            }
            throw -1;
        }

		/* Function deleteRBFixup
	 	* Used for:
	 	* Used after a deletion in the rb tree.
	 	* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 	*/
		void deleteRBFixup(RBTNode<Key,Value>* x){
			BinaryNode<Key,Value> *w;
			while(x != root && x->color == BLACK){
				if(x == x->parent->left){
					w = x->parent->right;
					if(w->color == RED){
						w->color = BLACK;													//case 1
						x->parent->color = RED;												//case 1
						leftRotation(x->parent);											//case 1
						w = x->parent->right;												//case 1
					}
					if((w->left->color == BLACK || w->left == nil) && (w->right->color == BLACK || w->right == nil)){
						w->color = RED;														//case 3
						x = x->parent;														//case 3
					}
					else{
						if(w->left->color == BLACK || w->left ==nil){
							if(w->left != nil)												//case 5
								w->left->color = BLACK;										//case 5
							w->color = RED;													//case 5
							rightRotation(w);												//case 5
							w = x->parent->right;											//case 5
						}
						w->color = x->parent->color;										//case 6
						x->parent->color = BLACK;											//case 6
						if(w->right != nil){												//case 6
							w->right->color = BLACK;										//case 6
						}																	//case 6
						leftRotation(x->parent);											//case 6
						x = root;
					}
				}
				else{
					w = x->parent->left;
					if(w->color == RED){
						w->color = BLACK;													//case 2
						x->parent->color = RED;												//case 2
						rightRotation(x->parent);											//case 2
						w = x->parent->left;												//case 2
					}
					if((w->right->color == BLACK || w->right == nil) && (w->left->color == BLACK || w->left == nil)){
						w->color = RED;														//case 4
						x = x->parent;														//case 4
					}
					else{
						if(w->right->color == BLACK || w->right ==nil){
							if(w->right != nil)												//case 7
								w->right->color = BLACK;									//case 7
							w->color = RED;													//case 7
							leftRotation(w);												//case 7
							w = x->parent->left;											//case 7
						}
						w->color = x->parent->color;										//case 8
						x->parent->color = BLACK;											//case 8
						if(w->left != nil){													//case 8
							w->left->color = BLACK;											//case 8
						}																	//case 8
						rightRotation(x->parent);											//case 8
						x = root;
					}
				}
			}
		}
		/* Function : blackHeight
	 	* 
	 	* Returns:
	 	* the black height of the red black tree which begins at node_ptr root
	 	*/
		int blackHeight(RBTNode<Key,Value>* r){
			int result = 0;
			while(r != nil){
				if(r->color == BLACK){
					result++;
				}
				r = r->left;
			}
			return result;
		}	
		/*
	 	* Apart from these functions, also provide functions for rotations in the tree.
	 	* The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 	*/
	};
}
#endif /* ifndef RBTree_HPP_ */	