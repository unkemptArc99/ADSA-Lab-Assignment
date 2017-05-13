/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Adjacency Matrix header file
******************************************************************/
#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include "seqLinearList.hpp"

namespace cs202{
    //Main class for the Adjacency Matrix
    class AdjacencyMatrix : public GraphAdjacencyBase {
    public:
        //main container of the Adjacent Matrix
        LinearList<int> graph;
        int vert;

        //Constructor for the Matrix class
        AdjacencyMatrix(int v) : graph(v*v,0) {vert = v;}

        //destructor for the Matrix class
        ~AdjacencyMatrix() {}

        /*
		* Function: edgeExists
		* Returns true if an edge exists between vertices i and j, false otherwise.
		*/
	    bool edgeExists(int i, int j){
            if(i < vert  && j < vert){
                if(graph.at(i*vert + j) != 0){
                    return true;
                }
                else{
                    return false;
                }
            }
            throw -1;
        }

        /*
		* Function: vertices
		* Returns the number of vertices in the adjacency structure.
		*/
        inline int vertices(){
            return graph.size() / vert;
        }

        /*
		* Function: edges
		* Returns the number of edges in the adjacency structure.
		*/
        int edges(){
            int total = 0;
            //calculating the edges
            for(int i = 0; i < vert; ++i){
                for(int j = 0; j < vert; ++j){
                    if(graph[i*vert + j] != 0)
                        total++;
                }
            }
            return total;
        }

        /*
	    * Function add:
		* Adds an edge between vertices i and j
		*/
        void add(int i, int j, int w){
            if(i < graph.size() && j < graph.size()){
                graph.modify(w,i*vert + j);
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: remove
		* Deleted the edge between vertices i and j
		*/
		void remove(int i, int j){
            if(i < graph.size() && j < graph.size()){
                graph.modify(0,i*vert + j);
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: degree
		* Returns the degree of the vertex i
		*/
		int degree(int i){
            int total = 0;
            if(i < graph.size()){
                for(int j = 0; j < vert; ++j){
                    if(graph[i*vert + j] != 0)
                        total++;
                }
                return total;
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: incomingEdges
		* Returns the number of edges to the the node
		*/
		int incomingEdges(int i){
            if(i < graph.size()){
                int total = 0;
                for(int j = 0; j < vert; ++j){
                    if(j != i){
                        if(graph[j*vert + i] != 0){
                            total++;
                        }
                    }
                }
                return total;
            }
            else{
                throw -1;
            }
        }
    };
}
#endif /* ifndef ADJACENCY_MATRIX */