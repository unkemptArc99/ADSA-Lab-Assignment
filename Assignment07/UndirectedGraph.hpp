/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Undirected Graph header file
******************************************************************/
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
#include "queue.hpp"
#include "stack.hpp"

namespace cs202{
    class UndirectedGraph : public AbstractGraph {
    public:
        //main container for the graph
        GraphAdjacencyBase *main_graph;
        char representation;

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
                representation = mode;
            }
            else if(mode == 'l'){
                AdjacencyList *c2 = new AdjacencyList(vertices);
                main_graph = c2;
                representation = mode;
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
        void dfs(void (*work)(int&)) {
            //Initially marking all vertex as not visited
            LinearList<int> colorOfNodes(main_graph->vertices(),0);         //0 FOR white, 1 for black
            //Initially marking predecessor's null
            LinearList<int> predecessor(main_graph->vertices(),-1);

            //main stack for dfs
            stack<int> main_stack;

            //pushing the source node
            main_stack.push(0);

            while(!main_stack.empty()){
                //popping the topmost vertex and working on it
                int u = main_stack.top();
                main_stack.pop();

                //There might be already visited nodes in the stack
                if(colorOfNodes.at(u) == 0){
                    colorOfNodes.modify(1,u);
                    work(u);
                }

                //putting the node's adjacent nodes in the stack
                for(int i = 0; i < main_graph->vertices(); ++i){
                    if(main_graph->edgeExists(u,i) && main_graph->edgeExists(i,u)){
                        if(colorOfNodes.at(i) == 0){
                            predecessor.modify(u,i);
                            main_stack.push(i);
                        }
                    }
                }
            }
        }

        /*
        * Funtion flood_fill_path:
        * Determines the flood fill path
        */
        void flood_fill_path(int source,int n,bool (*work)(int&)) {
            //Initially marking all vertex as not visited
            LinearList<int> colorOfNodes(main_graph->vertices(),0);         //0 FOR white, 1 for black
            //Initially marking predecessor's null
            LinearList<int> predecessor(main_graph->vertices(),-1);

            //main stack for dfs
            stack<int> main_stack;

            //pushing the source node
            main_stack.push(source);

            while(!main_stack.empty()){
                //popping the topmost vertex and working on it
                int u = main_stack.top();
                main_stack.pop();

                bool temporary;
                //There might be already visited nodes in the stack
                if(colorOfNodes.at(u) == 0){
                    colorOfNodes.modify(1,u);
                    temporary = work(u);
                }

                if(temporary){
                    //putting the node's adjacent nodes in the stack
                    for(int i = 0; i < main_graph->vertices(); ++i){
                        if(main_graph->edgeExists(u,i) && main_graph->edgeExists(i,u)){
                            if(colorOfNodes.at(i) == 0){
                                predecessor.modify(u,i);
                                main_stack.push(i);
                            }
                        }
                    }
                }
                else{
                    std::cout<<"The path is ";
                    while(u != source){
                        std::cout<<"("<<u%n<<","<<u/n<<")<-";
                        u = predecessor.at(u);
                    }
                    std::cout<<"("<<source%n<<","<<source/n<<")";
                    return;
                }
            }
        }

        /*
        * Function bfs:
        * Does a breadth first traversal of the entire graph.
        * Runs the given function work, with the value of each vertex.
        */
        void bfs(void (*work)(int&)) {
            //Initially marking all nodes unvisited
            LinearList<int> colorOfNodes(main_graph->vertices(),0);         //0 FOR white, 1 for gray, 2 for black
            //Initially marking the predecessors as null
            LinearList<int> predecessor(main_graph->vertices(),-1);
            //Initially marking the distance as infinity
            LinearList<int> distance(main_graph->vertices(),std::numeric_limits<int>::max());

            //changing source parameters
            colorOfNodes.modify(1,0);
            distance.modify(0,0);

            //main queue for bfs
            queue<int> main_queue;

            //pushing source node in the queue
            main_queue.push(0);

            while(!main_queue.empty()){
                int u = main_queue.pop();
                //marking the popped node as visited
                colorOfNodes.modify(2,u);
                work(u);

                //putting all the adjacent nodes in the queue
                for(int i = 0; i < main_graph->vertices(); ++i){
                    if(main_graph->edgeExists(u,i) && main_graph->edgeExists(i,u)){
                        if(colorOfNodes.at(i) == 0){
                            colorOfNodes.modify(1,i);
                            distance.modify(distance[u] + 1,i);
                            predecessor.modify(u,i);
                            main_queue.push(i);
                        }
                    }
                }
            }
        }
    };
}
#endif /* ifndef UNDIRECTED_GRAPH */