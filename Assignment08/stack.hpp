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

        void print();
    };

    template<typename T>
    stack<T>::stack(void){
        st.head = (node<T> *)NULL;
    }

    template<typename T>
    void stack<T>::push(const T& t){
        st.cons(t);
    }

    template<typename T>
    T stack<T>::pop(void){
        if(!st.empty()){
            T x = (st.head)->node_val;
            node<T> *temp = st.head;
            st.head = (st.head)->next;
            return x;
        }
    }

    template<typename T>
    T stack<T>::top(void){
        return st.head->node_val;
    }

    template<typename T>
    stack<T>::~stack(void){
        std::cout<<std::endl;
    }

    template<typename T>
    void stack<T>::print(void){
        st.display();
    }
}

#endif