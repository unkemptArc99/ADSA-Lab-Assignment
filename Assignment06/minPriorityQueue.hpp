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
            int left = left_child(pos);
            int right = right_child(pos);
            int smallest;
            
            if(left <= heap_size && heap[left] < heap[pos]){
                smallest = left;
            }
            else{
                smallest = pos;
            }

            if(right <= heap_size && heap[right] < heap[smallest]){
                smallest = right;
            }
            if(smallest != pos){
                heap.swapper(pos,smallest);
                heapify(smallest);
            }
        }

 		// return the parent of an element
 		inline int parent(const size_t& pos){
            return pos/2;
        }

 		// return the left child of an element
 		inline int left_child(const size_t& pos){
            return 2*pos;
        }

 		// return the right child of an element
 		inline int right_child(const size_t& pos){
            return (2*pos + 1);
        }

 	public:
 		// default constructor
 		MinPriorityQueue(){
			 heap(101);
             heap_size = 0;
             heap.push_back(std::numeric_limits<T>::max());
         }

 		// construct a heap from the elements of a LinearList
 		MinPriorityQueue(const LinearList<T>& v){
			heap.resize(v.capacity() + 1);
            heap.push_back(std::numeric_limits<T>::max());
			for(int i = 1; i < v.capacity() + 1; i++){
				heap.push_back(v[i - 1]);
			}
            heap_size = v.size();
		}

 		// insert a value to the heap
 		void insert(const T& a){
			heap_size++;
			heap.insert(a,heap_size);
			heap_decrease_key(heap_size);
        }

 		// get the minimum element from the heap
 		inline T minimum(){
			if(heap_size > 0)
		    	return heap[1];
			else
				throw -1;
		}

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min(){
            if(heap_size > 0){
				T minPriority = heap[1];
				heap.swapper(1,heap_size);
				heap_size--;
				heapify(1);
				return minPriority;
			}
			else{
				throw -1;
			}
        }

 		// return the heap size
 		inline int get_heap_size(){
            return heap_size;
        }

	    // build a heap from elements of a LinearList container 
 		void build_heap(const LinearList<T>& v){
			heap.resize(v.capacity() + 1);
            heap.push_back(std::numeric_limits<T>::max());
			for(int i = 1; i <= v.size(); i++){
				heap.push_back(v[i - 1]);
			}
            heap_size = v.size();
			for(int i = (heap_size/2); i >= 1; i--){
				heapify(i);
			}
        }

 		// check if MinPriorityQueue is empty
 		inline bool empty(){
			 if(heap_size == 0){
				 return true;
			 }
			 else{
				 return false;
			 }
		 }

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos){
			for(int i = pos; i >= 1 && heap[parent(i)] > heap[i]; i = parent(i)){
				heap.swapper(i, parent(i));
			}
		}
 	};
}	
#endif 