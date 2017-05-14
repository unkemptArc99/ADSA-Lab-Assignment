#ifndef UFDS_
#define UFDS_ 1

#include "seqLinearList.hpp"

namespace cs202 {

class UFDS {
    // Private attributes and functions for class
    // If you want to add any more variables, please add them
    // and give a valid reason for their use.
    // DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
    // YOU NEED TO USE THEM ALL.

    // node in consideration for union find data structure
    // stores parent and rank for each vertex
    // You may add new members to the node, with explanation as to
    // why the members were necessary.
    class node {
    public:
        int parent;
        int rank;

        node() {}
    };

    LinearList<node> vertex;

public:
    // Create an empty union find data structure with N isolated sets.
    UFDS(const unsigned int& N) : vertex(N) {}

    // Default constructor
    ~UFDS();

    // Make a new set with N vertices with all sets being disjoint
    void make_set (const unsigned int& N) {
        for(int i = 0; i < N; ++i){
            node temp;
            temp.parent = i;
            temp.rank = 0;
            vertex.push_back(temp);
        }
    }

    // Return the representative / parent of set consisting of object x.
    int find_set (const unsigned int& x) {
        if(x != vertex[x].parent){
            vertex[x].parent = find_set(vertex[x].parent);
        }
        return vertex[x].parent;
    }
    
    // Unite sets containing objects x and y.
    void union_set (const unsigned int& x, const unsigned int& y) {
        int root_x = find_set(x);
        int root_y = find_set(y);

        if(vertex[root_x].rank > vertex[root_y].rank){
            vertex[root_y].parent = root_x;
        }
        else{
            vertex[root_x].parent = root_y;
            if(vertex[root_x].rank == vertex[root_y].rank){
                vertex[root_y].rank++;
            }
        }
    }
    
    // Are objects x and y in the same set?
    bool is_same_set (const unsigned int& x, const unsigned int& y) {
        int root_x = find_set(x);
        int root_y = find_set(y);

        if(root_x == root_y){
            return true;
        }
        else{
            return false;
        }
    }

    // Return the number of disjoint sets.
    int num_disjoint_sets(){
        int count = 0;
        for(int i = 0; i < vertex.size(); ++i){
            if(vertex[i].parent == i){
                count++;
            }
        }
        return count;
    }
    

    //Returns the parent of set
    int getParent (int& i){
        return vertex[i].parent;
    }

    // Return the size of the set containing object x.
    int size_set (const unsigned int& x) {}
};    

}

#endif  /* UFDS_ */
