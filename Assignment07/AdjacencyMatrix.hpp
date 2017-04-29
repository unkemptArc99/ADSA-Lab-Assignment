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
        LinearList<LinearList<bool> > graph;

        //Constructor for the Matrix class
        AdjacencyMatrix(int v) : graph(v,LinearList<bool> (v,false)) {}

        //destructor for the Matrix class
        ~AdjacencyMatrix() {}

        /*
		* Function: edgeExists
		* Returns true if an edge exists between vertices i and j, false otherwise.
		*/
	    bool edgeExists(int i, int j){
            if(i < graph.size()  && j < graph.size()){
                if(graph[i][j]){
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
            return graph.size();
        }

        /*
		* Function: edges
		* Returns the number of edges in the adjacency structure.
		*/
        int edges(){
            int total = 0;
            //calculating the edges
            for(int i = 0; i < graph.size(); ++i){
                for(int j = 0; j < graph[i].size(); ++j){
                    if(graph[i][j])
                        total++;
                }
            }
            return total;
        }

        /*
	    * Function add:
		* Adds an edge between vertices i and j
		*/
        void add(int i, int j){
            if(i < graph.size() && j < graph.size()){
                graph[i].modify(true,j);
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
                graph[i].modify(false,j);
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
                for(int j = 0; j < graph[i].size(); ++j){
                    if(graph[i][j])
                        total++;
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