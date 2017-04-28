#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {
 public:
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int numVertices, char rep);
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
  int indegree(int i);
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
  int outdegree(int j);
};
#endif /* ifndef DIRECTED_GRAPH */