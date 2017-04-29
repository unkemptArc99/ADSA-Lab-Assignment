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
    template<class T>
    class MatrixNode{
    public:
        T value;
        bool *relation;
    };

    //Main class for the Adjacency Matrix
    template<class T>
    class AdjacencyMatrix : public GraphAdjacencyBase {
    public:
        //main container of the Adjacent Matrix
        MatrixNode<T> *graph;
        //Variable to store the total number of nodes
        int totalNodes;

        //Constructor for the Matrix class
        AdjacencyMatrix(int vertices){
            graph = new MatrixNode<T>[vertices];
            totalNodes = vertices;
            for(int i = 0;i < totalNodes; i++){
                graph[i] = new bool[totalNodes];
            }
            for(int i = 0; i < totalNodes; ++i){
                graph[i]->value = std::numeric_limits<T>::min();
                for(int j = 0; j < totalNodes; ++j){
                    graph[i]->relation[j] = false;
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