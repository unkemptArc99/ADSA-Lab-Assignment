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
            heap_size = 0;
		}

 		// insert a value to the heap
 		void insert(const T& a){
			
        }

 		// get the minimum element from the heap
 		inline T minimum(){
		    int minPriority = std::numeric_limits<T>::max();
			for(int i = 0; i < heap_size; i++){
                if(minPriority > heap[i]){
                    minPriority = heap[i];
                }
			}
            return minPriority;
		}

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min(){
            int minPriority = std::numeric_limits<T>::max();
            int index = 0;
			for(int i = 0; i < heap_size; i++){
                if(minPriority > heap[i]){
                    minPriority = heap[i];
                    index = i;
                }
			}
            heap.erase_pos(index);
            heap.push_back(minPriority);
            heap_size--;
            return minPriority;
        }

 		// return the heap size
 		inline int get_heap_size(){
            return heap_size;
        }

	    // build a heap from elements of a LinearList container 
 		void build_heap(const LinearList<T>& v){
             
         }

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);
 	};
}	
#endif 