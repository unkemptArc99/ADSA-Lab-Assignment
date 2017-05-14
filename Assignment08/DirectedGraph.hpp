/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Directed Graph header file
******************************************************************/
#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "sorting.hpp"
#include "UFDS.hpp"
/*
* A class to represent a directed graph.
*/

namespace cs202{
    class nodes {
    public:
        int source;
        int dest;
        int weight;

        nodes() {}

        bool operator == (nodes temp) {
            if(temp.weight == weight) { 
                return true;
            }
            else {
                return false;
            }
        }

        bool operator < (nodes temp) {
            if(temp.weight < weight) {
                return true;
            }
            else {
                return false;
            }
        }

        bool operator > (nodes temp) {
            if(temp.weight > weight) {
                return true;
            }
            else {
                return false;
            }
        }

        bool operator <= (nodes temp) {
            if(temp.weight <= weight) {
                return true;
            }
            else {
                return false;
            }
        }

        bool operator >= (nodes temp) {
            if(temp.weight >= weight) {
                return true;
            }
            else {
                return false;
            }
        }

        void operator = (nodes& temp) {
            weight = temp.weight;
            dest = temp.dest;
            source = temp.source;
        }

        void operator = (nodes temp) {
            weight = temp.weight;
            dest = temp.dest;
            source = temp.source;
        }
    };

    class DirectedGraph : public AbstractGraph {
    public:
        //main container for the graph
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
        bool edgeExists(int i, int j) {
            return main_graph->edgeExists(i,j);
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
        void add(int i, int j, int w){
            main_graph->add(i,j,w);
        }

        /*
        * Function: remove
        * Deleted the edge between vertices i and j
        */
        void remove(int i, int j){
            main_graph->remove(i,j);
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
                    if(main_graph->edgeExists(u,i)){
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
                        if(main_graph->edgeExists(u,i)){
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
                    if(main_graph->edgeExists(u,i)){
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

        /*
        * Function kruskal:
        * Gives a minimum spanning tree using the Kruskal algorithm
        */
        void kruskal(void (*work)(int&, int&)) {
            int vert = main_graph->vertices();
            bool check[vert][vert];

            LinearList<nodes> edges_list (vert*vert);
            
            for(int i = 0; i < vert; ++i){
                for(int j = 0; j < vert; ++j){
                    check[i][j] = false;
                }
            }

            for(int i = 0; i < vert; ++i){
                for(int j = 0; j < vert; ++j){
                    if(!check[i][j]){
                        nodes temp;
                        if(main_graph->edgeExists(i,j)) {
                            temp.source = i;
                            temp.dest = j;
                            temp.weight = main_graph->getWeight(i,j);
                            edges_list.push_back(temp);
                            check[i][j] = true;
                            check[j][i] = true;
                        }
                    }
                }
            }

            Sort<nodes> sort;
            sort.mergeSort(edges_list,0,vert - 1);

            UFDS sets(vert);
            sets.make_set(vert);
            LinearList<int> MSTsource (edges_list.size());
            LinearList<int> MSTdest (edges_list.size());

            for(int i = 0; i < edges_list.size(); ++i) {
                nodes temp;
                temp = edges_list.at(i);
                if(sets.find_set(temp.source) != sets.find_set(temp.dest)) {
                    MSTsource.push_back(temp.source);
                    MSTdest.push_back(temp.dest);
                    sets.union_set(temp.source,temp.dest);
                }
            }

            for(int i = 0; i < MSTsource.size(); ++i) {
                work(MSTsource[i],MSTdest[i]);
            }
        }
    };
}
#endif /* ifndef DIRECTED_GRAPH */