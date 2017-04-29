/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Adjacency List header file
******************************************************************/
#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include <exception>

#include "GraphAdjacencyBase.hpp"
#include "list.hpp"

namespace cs202{
    //Class for individual vertex node.
    class ListNode{
    public:
        list<int> connections;
        ListNode(){};
    };

    //Main class for Adjacency List
    class AdjacencyList : public GraphAdjacencyBase {
    public:
        //Main container for the List
        ListNode *graph;
        //Variable to store the total number of nodes
        int totalNodes;

        //Constructor for Adjacency List class
        AdjacencyList(int vertices){
            //creating space for the vertices
            graph = new ListNode[vertices];
            totalNodes = vertices;
        }

        //Destructor for the List class   
        ~AdjacencyList(){
            delete graph;
        }

        /*
		* Function: edgeExists
		* Returns true if an edge exists between vertices i and j, false otherwise.
		*/
	    bool edgeExits(int i, int j){
            //temp pointer for traversal of list
            node<int> *temp;
            if(i < totalNodes && j < totalNodes){
                temp = graph[i].connections.head;
                while(temp != NULL){
                    //searching for j
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
            //throwing exceptions if the nodes are out of range
            throw -1;
            return false;
        }
    };
}
#endif /* ifndef ADJACENCY_LIST */