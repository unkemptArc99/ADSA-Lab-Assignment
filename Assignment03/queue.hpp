/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - Queue header file
****************************************************************/
/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of queues
 * 
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <cstdlib>
#include <iostream>
#include "list.hpp"

namespace cs202
{
  template <class T>
    class queue
    {
      public:
        list<T> qu;
        /*
         * Constructs a new queue.
         */
        queue();
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const T& t);
        /*
         * Returns the element at the front of the queue.
         * Also removes the front element from the queue.
         */
        T pop();
        /*
         * Returns the element at the front of the queue.
         * Does not remove the front element.
         */
        T front();
        /*
         * Returns the number of elements currently in the queue.
         */
        inline int size(){
            return qu.length();
        };
        /*
         * Returns a boolean indicating whether the queue is empty or not.
         */
        inline bool empty(){
            return qu.empty();
        };
        /*
         * Destructor
         * Fress the memory occupied by the queue elements.
         */
        ~queue();
    };

    template<class T>
    queue<T>::queue(void){
        qu.head = (node<T> *)NULL;
    }

    template<class T>
    void queue<T>::push(const T& t){
        qu.append(t);
    }

    template<class T>
    T queue<T>::pop(void){
        T x = (qu.head)->node_val;
        node<T> *temp = qu.head;
        qu.head = (qu.head)->next;
        free(temp);
        return x;
    }

    template<class T>
    T queue<T>::front(void){
        T x = (qu.head)->node_val;
        return x;
    }

    template<class T>
    queue<T>::~queue(void){
        cout<<endl;
    }
}
#endif