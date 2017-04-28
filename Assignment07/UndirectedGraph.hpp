#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
#include "AbstractGraph.hpp"

namespace cs202{
    class UndirectedGraph : AbstractGraph {
    public:
        /*
        * Constructor: UndirectedGraph
        *
        * Parameters: mode
        * Used to decide which representation to use
        * 'm' for AdjacencyMatrix
        * 'l' for AdjacencyList
        */
        UndirectedGraph(int vertices, char mode);
        /*
        * Returns the degree of the vertex.
        */
        int degree(int i);
    };
}
#endif /* ifndef UNDIRECTED_GRAPH */