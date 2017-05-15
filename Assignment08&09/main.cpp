#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "UndirectedGraph.hpp"

using namespace std;

int main() {
    //taking the input of the file name
    cout<<"Enter the name of the file : ";
    string s;
    cin>>s;
    //file pointer to handle the input file
    ifstream in(s);

    //if input file named file doesn't exist report error
    if(!in) {
        cout<<"There is no such file"<<endl;
        return -1;
    }

    //n will store the vertices and m will store the edges
    int n,m;
    in>>n>>m;

    //The main undirected graph for the grid
    cs202::UndirectedGraph A(n,'l');

    //adding the edges
    for(int i = 0; i < m; ++i) {
        int x,y,c;
        in>>x>>y>>c;
        
    }

    return 0;
}