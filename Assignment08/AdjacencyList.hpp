/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Adjacency List header file
******************************************************************/
#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include <exception>

#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include "seqLinearList.hpp"

namespace cs202{
    //Main class for Adjacency List
    class AdjacencyList : public GraphAdjacencyBase {
    public:
        class graph_node {
            public:
                int dest;
                int weight;

                graph_node() {}

                bool operator == (int j) {
                    if(dest == j){
                        return true;
                    }
                    else{
                        return false;
                    }
                }

                void operator = (graph_node& temp) {
                    dest = temp.dest;
                    weight = temp.weight;                    
                }
        };

        //Main container for the List
        LinearList<list<graph_node> > graph;

        //Constructor for Adjacency List class
        AdjacencyList(int v) : graph(v, list<graph_node>()) {}

        //Destructor for the List class   
        ~AdjacencyList() {}

        /*
		* Function: edgeExists
		* Returns true if an edge exists between vertices i and j, false otherwise.
		*/
	    virtual bool edgeExists(int i, int j){
            if(i < graph.size() && j < graph.size()){
                //creating temporary variables for traversal of list
                list<graph_node> x = graph[i];
                node<graph_node> *temp = x.head;
                while(temp != NULL){
                    if(temp->node_val == j){
                        return true;
                    }
                    temp = temp->next;
                }
                return false;
            }
            throw -1;
        }

        /*
		* Function: vertices
		* Returns the number of vertices in the adjacency structure.
		*/
        virtual inline int vertices(){
            return graph.size();
        }

        /*
		* Function: edges
		* Returns the number of edges in the adjacency structure.
		*/
        virtual int edges(){
            int total = 0;
            //calculating the edges
            for(int i = 0; i < graph.size(); ++i){
                total += graph[i].length();
            }
            return total;
        }

        /*
	    * Function add:
		* Adds an edge between vertices i and j
		*/
        virtual void add(int i, int j, int w){
            if(i < graph.size() && j < graph.size()){
                graph_node temp;
                temp.dest = j;
                temp.weight = w;
                graph[i].append(temp);
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: remove
		* Deleted the edge between vertices i and j
		*/
		virtual void remove(int i, int j){
            if(i < graph.size() && j < graph.size()){
                graph_node temp;
                temp.dest = j;
                graph[i].remove(temp);
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: degree
		* Returns the degree of the vertex i
		*/
		virtual int degree(int i){
            if(i < graph.size()){
                return graph[i].length();
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: incomingEdges
		* Returns the number of edges to the the node
		*/
		virtual int incomingEdges(int i){
            if(i < graph.size()){
                int total = 0;
                for(int j = 0; j < graph.size(); ++j){
                    if(j != i){
                        node<graph_node> *temp = graph[i].head;
                        while(temp != NULL){
                            if(temp->node_val == i){
                                total++;
                            }
                            temp = temp->next;
                        }
                    }
                }
                return total;
            }
            else{
                throw -1;
            }
        }

        /*
		* Function: getWeight
		* Returns the weight of edge
		*/
		virtual int getWeight(int i,int j){
            if(i < graph.size() && j < graph.size()){
                //creating temporary variables for traversal of list
                list<graph_node> x = graph[i];
                node<graph_node> *temp = x.head;
                while(temp != NULL){
                    if(temp->node_val == j){
                        return temp->node_val.weight;
                    }
                    temp = temp->next;
                }
                return 0;
            }
            throw -1;
        }
    };
}
#endif /* ifndef ADJACENCY_LIST */