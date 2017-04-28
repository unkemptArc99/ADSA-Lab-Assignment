#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"

namespace cs202{
    template<class T>
    class MatrixNode{
    public:
        T value;
        bool *relation;
    };

    template<class T>
    class AdjacencyMatrix : public GraphAdjacencyBase {
    public:
        MatrixNode<T> *graph;
        AdjacencyMatrix(int vertices){
            graph = new MatrixNode<T>[vertices];
            for(int i = 0;i < vertices; i++){
                graph[i] = new bool[vertices];
            }
            for(int i = 0; i < vertices; ++i){
                graph[i]->value = std::numeric_limits<T>::min();
                for(int j = 0; j < vertices; ++j){
                    graph[i]->relation[j] = false;
                }
            }
        }
        ~AdjacencyMatrix(){
            delete graph;
        }
    };
}
#endif /* ifndef ADJACENCY_MATRIX */