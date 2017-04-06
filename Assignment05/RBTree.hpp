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

	template <class Key, class Value>
	class RBTree : public BSTree<Key, Value> {
	/* Inherit as many functions as possible from BSTree.
 	* Only override those which absolutely need it.
 	* Also make sure that all inherited functions work correctly in the context of a red black tree.
 	* node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 	* Use a typedef to refer to a pointer to your node via node_ptr
 	*/

	public:
	 	/* Function insertRBFixup
	 	*
	 	* Used for:
	 	* Used after an insertion in the rb tree.
	 	* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 	*/
		void insertRBFixup(node_ptr root);

		/* Function deleteRBFixup
	 	* Used for:
	 	* Used after a deletion in the rb tree.
	 	* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 	*/
		void deleteRBFixup(node_ptr root);
		/* Function : blackHeight
	 	* 
	 	* Returns:
	 	* the black height of the red black tree which begins at node_ptr root
	 	*/
		int blackHeight(node_ptr root);	
		/*
	 	* Apart from these functions, also provide functions for rotations in the tree.
	 	* The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 	*/
	};
}
#endif /* ifndef RBTree_HPP_ */	