/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - Stack header file
****************************************************************/
/* 
 * stack.hpp
 * 
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 * 
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <cstdlib>
#include <iostream>
#include "list.hpp"

namespace cs202
{
    template<typename T>
    class stack
    {
      public:
        list<T> st;
        /*
         * Constructs a new stack.
         */
        stack();
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const T& t);
        /*
         * Returns the element at the top of the stack.
         * Also removes the top element from the stack.
         */
        T pop();
        /*
         * Returns the element at the top of the stack.
         * Does not remove the top element.
         */
        T top();
        /*
         * Returns the number of elements currently in the stack.
         */
        inline int size(){
            return st.length();
        };
        /*
         * Returns a boolean indicating whether the stack is empty or not.
         */
        inline bool empty(){
            return st.empty();
        };
        /*
         * Destructor
         * Fress the memory occupied by the stack elements.
         */
        ~stack();
    };

    template<typename T>
    stack<T>::stack(void){
        st.head->next = (node<T> *)NULL;
    }

    template<typename T>
    void stack<T>::push(const T& t){
        st.append(t);
    }

    template<typename T>
    T stack<T>::pop(void){
        node<T> *temp;
        temp = st.head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        T x = temp->node_val;
        free(temp);
        return x;
    }

    template<typename T>
    T stack<T>::top(void){
        node<T> *temp;
        temp = st.head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        T x = temp->node_val;
        return x;
    }

    template<typename T>
    stack<T>::~stack(void){
        ~st();
    }
}

#endif