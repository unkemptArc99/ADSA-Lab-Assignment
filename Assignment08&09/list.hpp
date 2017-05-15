/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - List header file
****************************************************************/
/*
 * list.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * 
 */

#ifndef LIST_HPP
#define LIST_HPP 1

#include <cstdlib>
#include <iostream>

namespace cs202
{
    template<class T>
    class node{
        public:
            T node_val;
            node *next;
    };

    template<class T>
    class list{
        public:
            node<T> *head;
        /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */
            list();
        /*
         * Seondary constructor.
         * Creates a new list which is a copy of the provided list.
         */
            list(const list<T>& x);
        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
            ~list();
        /*
         * adds value at the end of the list.
         */
            void append(const T& value);
        /*
         * Returns the length of the list.
         */
            inline int length(){
                node<T> *temp;
                temp = head;
                int i=0;
                while(temp!=NULL){
                    i++;
                    temp = temp->next;
                }
                return i;
            };
        /*
         * Returns a boolean indicating whether the list is empty.
         */
            inline bool empty(){
                if(head==NULL)
                    return true;
                else
                    return false;
            };
        /*
         * Adds a value to the front of the list.
         */
            void cons(const T& value);
        /*
         * Removes the first occurence of the value from list.
         */
            void remove(const T & x);
        /*
         * Appends the given list x at the end of the current list.
         */
            void append(list<T>& x);

            void display();
    };

    template<class T>
    list<T>::list(void){
        head = (node<T> *)NULL;
    }

    template<class T>
    list<T>::list(const list<T>& x){
        head = NULL;
        node<T> *temp = x.head;
        while(temp != NULL){
            append(temp->node_val);
            temp = temp->next;
        }
    }

    template<class T>
    list<T>::~list(void){
        while(head!=NULL){
            node<T> *temp1 = head;
            head = temp1->next;
        }
    }

    template<class T>
    void list<T>::append(const T& value){
        node<T> *temp;
        temp = new node<T>;
        temp->node_val = value;
        temp->next = NULL;
        if(head!=NULL){
            node<T> *temp1;
            temp1 = head;
            while(temp1->next!=NULL){
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
        else
            head = temp;
    }

    template<class T>
    void list<T>::cons(const T& value){
        node<T> *temp;
        temp = new node<T>;
        temp->node_val = value;
        temp->next = head;
        head = temp;
    }

    template<class T>
    void list<T>::remove(const T& x){
        node<T> *temp,*temp1;
        temp = head;
        if(temp!=NULL){
            while(temp!=NULL){
                if(temp->node_val == (T)x){
                    if(temp!=head){
                        temp1 = head;
                        while(temp1->next != temp){
                            temp1 = temp1->next;
                        }
                        temp1->next = temp->next;
                    }
                    else{
                        head = temp->next;
                    }
                    delete temp;
                    break;
                }
                else{
                    temp = temp->next;
                }
            }
            return;
        }
        else
            return;
    }

    template<class T>
    void list<T>::append(list<T>& x){
        node<T> *temp1 = x.head;
        while(temp1 != NULL){
            append(temp1->node_val);
        }
    }

    template<class T>
    void list<T>::display(void){
        node<T> *temp = head;
        while(temp!=NULL){
            std::cout<<temp->node_val<<" ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }
}
#endif