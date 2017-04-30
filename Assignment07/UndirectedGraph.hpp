#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"

namespace cs202{
    class UndirectedGraph : AbstractGraph {
    public:
        //main container for the graph
        GraphAdjacencyBase *main_graph;

        /*
        * Constructor: UndirectedGraph
        *
        * Parameters: mode
        * Used to decide which representation to use
        * 'm' for AdjacencyMatrix
        * 'l' for AdjacencyList
        */
        UndirectedGraph(int vertices, char mode){
            if(mode == 'm'){
                AdjacencyMatrix *c1 = new AdjacencyMatrix(vertices);
                main_graph = c1;
            }
            else if(mode == 'l'){
                AdjacencyList *c2 = new AdjacencyList(vertices);
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
        ~UndirectedGraph() {}

        /*
        * Returns the degree of the vertex.
        */
        int degree(int i){
            return main_graph->degree(i);
        }

        /*
        * Function: edgeExists
        * Returns true if an edge exists between vertices i and j, false otherwise.
        */
        bool edgeExists(int i, int j) {
            bool r1 = main_graph->edgeExists(i,j);
            bool r2 = main_graph->edgeExists(j,i);
            if(r1 && r2){
                return true;
            }
            else{
                return false;
            }
        }

        /*  
        * Function: edges
        * Returns the number of edges in the adjacency structure.
        */
        int edges(){
            return main_graph->edges();
        }

        /*
        * Function: vertices
        * Returns the number of vertices in the adjacency structure.
        */
        int vertices(){
            return main_graph->vertices();
        }

        /*
        * Function add:
        * Adds an edge between vertices i and j
        */
        void add(int i, int j){
            main_graph->add(i,j);
            main_graph->add(j,i);
        }

        /*
        * Function: remove
        * Deleted the edge between vertices i and j
        */
        void remove(int i, int j){
            main_graph->remove(i,j);
            main_graph->remove(j,i);
        }

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
#endif /* ifndef UNDIRECTED_GRAPH */