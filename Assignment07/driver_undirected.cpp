/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Undirected Graph driver file
******************************************************************/
#include <cstdlib>
#include <iostream>
#include <exception>

#include "UndirectedGraph.hpp"

using namespace std;

void printTheNode(int& x){
    cout<<x<<" ";
}

int main()
{
    int v;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    char rep;
    cout<<"Enter your mode of representation : ";
    bool flag = true;
    while(flag){
        cin>>rep;
        if(rep == 'm' || rep == 'M' || rep == 'l' || rep == 'L'){
            flag = false;
        }
        else{
            cout<<"Wrong"<<endl;
        }
    }
    cs202::UndirectedGraph *A;
    if(rep == 'm' || rep == 'M'){
        A = new cs202::UndirectedGraph(v,'m');
    }
    else{
        A = new cs202::UndirectedGraph(v,'l');
    }

    while(1)
    {
        int ch;
        cout<<"1. Insert"<<endl;
        cout<<"2. Remove"<<endl;
        cout<<"3. Check edge"<<endl;
        cout<<"4. vertices"<<endl;
        cout<<"5. edges"<<endl;
        cout<<"6. degree"<<endl;
        cout<<"7. exit"<<endl;
        cout<<"8. dfs"<<endl;
        cout<<"9. bfs"<<endl;
        cout<<endl;
        cout<<"Enter : ";
        cin>>ch;
        int i,j;
        bool result;
        switch(ch){
            case 1:
                cout<<"Enter you i and j : ";
                cin>>i>>j;
                try{
                    A->add(i,j);
                }
                catch(int error){
                    cout<<"Error"<<endl;
                }
                break;
            case 2:
                cout<<"Enter you i and j : ";
                cin>>i>>j;
                try{
                    A->remove(i,j);
                }
                catch(int error){
                    cout<<"Error"<<endl;
                }
                break;
            case 3:
                cout<<"Enter you i and j : ";
                cin>>i>>j;
                try{
                    result = A->edgeExists(i,j);
                }
                catch(int error){
                    cout<<"Error"<<endl;
                    break;
                }
                if(result){
                    cout<<"Y"<<endl;
                }
                else{
                    cout<<"N"<<endl;
                }
                break;
            case 4:
                cout<<"The number of vertices are : "<<A->vertices()<<endl;
                break;
            case 5:
                cout<<"The number of edges are : "<<A->edges()<<endl;
                break;
            case 6:
                cout<<"Enter the node"<<endl;
                cin>>i;
                try{
                    j = A->degree(i);
                }
                catch(int error){
                    cout<<"Error"<<endl;
                    break;
                }
                cout<<"The degree is "<<j<<endl;
                break;
            case 7:
                exit(0);
            case 8:
                A->dfs(printTheNode);
                break;
            case 9:
                A->bfs(printTheNode);
                break;
            default:
                cout<<"Wrong input"<<endl;
        }
    }
    return 0;
}