/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Adjacency List header file
******************************************************************/
#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include "list.hpp"

namespace cs202{
    //Class for individual vertex node.
    template<class T>
    class ListNode{
    public:
        T value;
        list<T> connections;
    };

    //Main class for Adjacency List
    template<typename T>
    class AdjacencyList : public GraphAdjacencyBase {
    public:
        //Main container for the List
        ListNode<T> *graph;
        //Variable to store the total number of nodes
        int totalNodes;

        //Constructor for Adjacency List class
        AdjacencyList(int vertices){
            //creating space for the vertices
            graph = new ListNode<T>[vertices];
            totalNodes = vertices;
            //initialising the vertices
            for(int i = 0; i < totalNodes; ++i){
                graph[i]->value = std::numeric_limits<T>::min();               
            }
        }

        //Destructor for the List class   
        ~AdjacencyList(){
            delete graph;
        }

        /*
		* Function: edgeExists
		* Returns true if an edge exists between vertices i and j, false otherwise.
		*/
	    bool edgeExits(T i, T j){
            //temp pointer for traversal of list
            node<T> *temp;
            int p;
            for(p = 0; p < totalNodes; ++p){
                if(graph[p]->value == i){
                    temp = graph[p]->connections->head;
                    while(temp != NULL){
                        if(temp->node_val == j){
                            return true;
                        }
                        else{
                            temp = temp->next;
                        }
                    }
                    if(temp == NULL){
                        return false;
                    }
                }
            }
            if(p == totalNodes){
                throw -1;
            }
        }
    };
}
#endif /* ifndef ADJACENCY_LIST */