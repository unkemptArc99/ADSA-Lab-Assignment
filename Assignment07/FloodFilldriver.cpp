/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Flood Fill driver file
******************************************************************/
#include <iostream>
#include <cstdlib>
#include "AbstractGraph.hpp"
#include "UndirectedGraph.hpp"

using namespace std;

int main(){
    system("clear");
    cout<<"WELCOME TO THE FLOOD-FILL SIMULATOR"<<endl;
    cout<<"-----------------------------------"<<endl;

    //Variable to store the representation of the graph
    char rep;
    //Variable to store the size of matrix,source and destination cell
    int n,m,source,dest;
    //List to store the non-visiting cells;
    cs202::LinearList<int> X;

    cout<<endl<<"Enter the value of n (number of columns of matrix OR the maximum X-axis value of the matrix) : ";
    cin>>n;
    cout<<endl<<"Enter the value of m (number of rows of matrix OR the maximum Y-axis value of the matrix) : ";
    cin>>m;
    cout<<endl<<"Enter the representation of the graph : ";
    cin>>rep;

    cs202::UndirectedGraph *A;
    if(rep == 'm'){
        A = new cs202::UndirectedGraph (n*m,'m');
    }
    else{
        A = new cs202::UndirectedGraph (n*m,'l');
    }

    return 0;
}