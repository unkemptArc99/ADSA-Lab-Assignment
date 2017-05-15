#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "UndirectedGraph.hpp"

using namespace std;

//n will store the vertices and m will store the edges
int n,m;

cs202::LinearList<int> sou(1000);
cs202::LinearList<int> des(1000);

void storing(int& a,int& b) {
    sou.push_back(a);
    des.push_back(b);
}

//handles the questions
void answering(ifstream &in) {
    int q;
    in >> q;

    for(int i = 0; i < q; ++i) {
        int x,y;
        in >> x >> y;
        bool flag = false;
        for (int j = 0; j < sou.size() && !flag; ++j) {
            if(x == sou.at(j) && y == des.at(j)) { 
                flag = true;
            }
            else if(y == sou.at(j) && x == des.at(j)) {
                flag = true;
            }
        }
        if(flag) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}

int main() {
    //taking the input of the file name
    cout<<"Enter the name of the file : ";
    string s;
    cin>>s;
    //file pointer to handle the input file
    ifstream in(s.c_str());

    //if input file named file doesn't exist report error
    if(!in) {
        cout<<"There is no such file"<<endl;
        return -1;
    }

    in>>n>>m;

    //The main undirected graph for the grid
    cs202::UndirectedGraph A(n,'l');

    //adding the edges
    for(int i = 0; i < m; ++i) {
        int x,y,c;
        in>>x>>y>>c;
        A.add(x,y,c);
    }

    A.prim(storing);

    answering(in);
    return 0;
}