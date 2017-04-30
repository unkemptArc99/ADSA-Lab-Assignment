#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
/*
* A class to represent a directed graph.
*/

namespace cs202{
    class DirectedGraph : AbstractGraph {
    public:
        GraphAdjacencyBase *main_graph;
        /*
        * Constructor: DirectedGraph
        *
        * Parameters: mode
        * Used to decide which representation to use
        * 'm' for AdjacencyMatrix
        * 'l' for AdjacencyList
        */
        DirectedGraph(int numVertices, char rep){
            if(rep == 'm'){
                AdjacencyMatrix *c1 = new AdjacencyMatrix(numVertices);
                main_graph = c1;
            }
            else if(rep == 'l'){
                AdjacencyList *c2 = new AdjacencyList(numVertices);
                main_graph = c2;
            }
            else{
                throw -1;
            }
        }
        /*
        * Function: Destructor
        * Class Destructor
        */
        ~DirectedGraph() {}

        /*
        * Function: indegree
        * Returns the indegree of a vertex
        */
        int indegree(int i){
            return main_graph->incomingEdges(i);
        }

        /*
        * Function: outdegree
        * Returns the outdegree of a vertex.
        */
        int outdegree(int j){
            return main_graph->degree(j);
        }

        /*
        * Function: edgeExists
        * Returns true if an edge exists between vertices i and j, false otherwise.
        */
        bool edgeExits(int i, int j) {}

        /*  
        * Function: edges
        * Returns the number of edges in the adjacency structure.
        */
        virtual void edges() = 0;

        /*
        * Function: vertices
        * Returns the number of vertices in the adjacency structure.
        */
        virtual void vertices() = 0;

        /*
        * Function add:
        * Adds an edge between vertices i and j
        */
        virtual void add(int i, int j) = 0;

        /*
        * Function: remove
        * Deleted the edge between vertices i and j
        */
        virtual void remove(int i, int j) = 0;

        /*
        * Function dfs:
        * Does a depth first traversal of the entire graph.
        * Runs the given function work, with the value of each vertex.
        */
        virtual void dfs(void (*work)(int&)) = 0;

        /*
        * Function bfs:
        * Does a breadth first traversal of the entire graph.
        * Runs the given function work, with the value of each vertex.
        */
        virtual void bfs(void (*work)(int&)) = 0;
    };
}
#endif /* ifndef DIRECTED_GRAPH */