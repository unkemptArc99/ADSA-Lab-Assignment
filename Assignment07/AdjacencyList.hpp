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
            
        }

        /*
		* Function: vertices
		* Returns the number of vertices in the adjacency structure.
		*/
        inline int vertices(){
            return totalNodes;
        }

        /*
		* Function: edges
		* Returns the number of edges in the adjacency structure.
		*/
        inline int edges(){
            return totalEdges;
        }


    };
}
#endif /* ifndef ADJACENCY_LIST */