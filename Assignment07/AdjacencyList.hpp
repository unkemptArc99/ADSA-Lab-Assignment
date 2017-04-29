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
#include "seqLinearList.hpp"

namespace cs202{
    //Main class for Adjacency List
    class AdjacencyList : public GraphAdjacencyBase {
    public:
        //Main container for the List
        LinearList<list<int> > graph;

        //Constructor for Adjacency List class
        AdjacencyList(int v) : graph(v, list<int>()) {}

        //Destructor for the List class   
        ~AdjacencyList(){}

        /*
		* Function: edgeExists
		* Returns true if an edge exists between vertices i and j, false otherwise.
		*/
	    bool edgeExits(int i, int j){
            if(i < graph.capacity() && j < graph.capacity()){
                //creating temporary variables for traversal of list
                list<int> x = graph[i];
                node<int> *temp = x.head;
                while(temp != NULL){
                    if(temp->node_val == j){
                        return true;
                    }
                    temp = temp->next;
                }
                return false;
            }
            throw -1;
        }

        /*
		* Function: vertices
		* Returns the number of vertices in the adjacency structure.
		*/
        inline int vertices(){
            return graph.size();
        }

        /*
		* Function: edges
		* Returns the number of edges in the adjacency structure.
		*/
        int edges(){
            int total = 0;
            for(int i = 0; i < graph.size(); ++i){
                total += graph[i].length();
            }
            return total;
        }


    };
}
#endif /* ifndef ADJACENCY_LIST */