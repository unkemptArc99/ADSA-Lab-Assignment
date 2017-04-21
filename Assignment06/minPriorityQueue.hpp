/****************************************************
Author : Abhishek
Roll No. : B15103
ADSA Assignment06 - Minimum Priority Queue Header File
****************************************************/

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include <cstdlib>
#include <iostream>
#include <limits>
#include <exception>

#include "seqLinearList.hpp"

 namespace cs202{
 	
 	template<typename T>
 	class MinPriorityQueue{
 		// Private attributes and functions for class
 		// If you need any more functions / attributes
 		// define them yourself along with proper reasoning
 		// why they were introduced.
 		// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
 		// YOU NEED TO USE THEM ALL.


 		// Primary container used in MinPriorityQueue
    private:
 		LinearList<T> heap;
 		int heap_size;

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos){

         }

 		// return the parent of an element
 		inline int parent(const size_t& pos);

 		// return the left child of an element
 		inline int left_child(const size_t& pos);

 		// return the right child of an element
 		inline int right_child(const size_t& pos);

 	public:
 		// default constructor
 		MinPriorityQueue(){
			 heap(100);
             heap_size = 0;
         }

 		// construct a heap from the elements of a LinearList
 		MinPriorityQueue(const LinearList<T>& v){
			heap.resize(v.capacity());
			for(int i = 0; i < capacity_; i++){
				heap.push_back(v[i]);
			}
		}

 		// insert a value to the heap
 		void insert(const T& a){
			heap.push_back(a);
        }

 		// get the minimum element from the heap
 		inline T minimum(){
			 int min = std::numeric_limits<T>::max();
			 for(int i = 0; i < heap.capacity(); i++){
				 
			 }
		 }

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min();

 		// return the heap size
 		inline int heap_size();

	// build a heap from elements of a LinearList container 
 		void build_heap(const LinearList<T>& v);

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);
 	};
 	
#endif 