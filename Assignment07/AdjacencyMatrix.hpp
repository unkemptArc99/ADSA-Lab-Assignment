/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Adjacency Matrix header file
******************************************************************/
#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"

namespace cs202{
    //Class for individual vertex node
    class MatrixNode{
    public:
        bool *relation;
    };

    //Main class for the Adjacency Matrix
    class AdjacencyMatrix : public GraphAdjacencyBase {
    public:
        //main container of the Adjacent Matrix
        MatrixNode *graph;
        //Variable to store the total number of nodes
        int totalNodes;

        //Constructor for the Matrix class
        AdjacencyMatrix(int vertices){
            graph = new MatrixNode[vertices];
            totalNodes = vertices;
            for(int i = 0;i < totalNodes; i++){
                graph[i].relation = new bool[totalNodes];
            }
            for(int i = 0; i < totalNodes; ++i){
                for(int j = 0; j < totalNodes; ++j){
                    graph[i].relation[j] = false;
                }
            }
        }

        //destructor for the Matrix class
        ~AdjacencyMatrix(){
            delete graph;
        }
    };
}
#endif /* ifndef ADJACENCY_MATRIX */