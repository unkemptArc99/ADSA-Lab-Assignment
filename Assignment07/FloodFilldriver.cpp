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

void printer(char matrix[],int x,int y){
    int counter = 0;
    for(int i = 0; i < y; ++i){
        for(int j = 0; j < x; ++j){
            cout<<matrix[counter]<<" "<<endl;
            counter++;
        }
        cout<<endl;
    }
}

int main(){
    system("clear");
    cout<<"WELCOME TO THE FLOOD-FILL SIMULATOR"<<endl;
    cout<<"-----------------------------------"<<endl;

    //Variable to store the representation of the graph
    char rep;
    //Variable to store the size of matrix,source and destination cell
    int n,m,source,dest;

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

    //making a standard matrix with many cases
    for(int i = 0; i < n*m; ++i){
        if(i == 0){
            A->add(i, i + 1);
            A->add(i, i + n);
            A->add(i, i + n + 1);
        }
        else if(i == n - 1){
            A->add(i, i - 1);
            A->add(i, i + n);
            A->add(i, i + n - 1);
        }
        else if(i == n * (m - 1)){
            A->add(i, i + 1);
            A->add(i, i - n);
            A->add(i, i - n + 1);
        }
        else if(i == n * m - 1){
            A->add(i, i - 1);
            A->add(i, i - n);
            A->add(i, i - n - 1);
        }
        else if(i % n == 0){
            A->add(i, i + 1);
            A->add(i, i + n);
            A->add(i, i - n);
            A->add(i, i + n + 1);
            A->add(i, i - n + 1);
        }
        else if(i % n == n - 1){
            A->add(i, i - 1);
            A->add(i, i + n);
            A->add(i, i - n);
            A->add(i, i + n - 1);
            A->add(i, i - n - 1); 
        }
        else if(i / n == 0){
            A->add(i, i + 1);
            A->add(i, i - 1);
            A->add(i, i + n);
            A->add(i, i + n + 1);
            A->add(i, i + n - 1);
        }
        else if(i / n == m - 1){
            A->add(i, i + 1);
            A->add(i, i - 1);
            A->add(i, i - n);
            A->add(i, i - n + 1);
            A->add(i, i - n - 1);
        }
        else{
            //lateral
            A->add(i, i + 1);
            A->add(i, i - 1);
            A->add(i, i + n);
            A->add(i, i - n);
            //diagonalsadd
            A->add(i, i + n + 1);
            A->add(i, i + n - 1);
            A->add(i, i - n + 1);
            A->add(i, i - n - 1);
        }
    }

    //enquiring for source and destination node
    int x,y;
    cout<<endl<<"Enter the source node's coordinate (x y) : ";
    cin>>x>>y;
    source = x*n + y;
    cout<<endl<<"Enter the destination node's coordinate (x y) : ";
    cin>>x>>y;
    dest = x*n + y;

    //initial matrix initialisation
    char matrix[n*m];
    for(int i = 0; i < n*m; ++i){
        if(i == source){
            matrix[i] = 'S';
        }
        else if(i == dest){
            matrix[i] = 'D';
        }
        else{
            matrix[i] = 'U';
        }
    }

    //taking the blocked cells
    cout<<endl<<"Enter the number of blocked cells : ";
    int num;
    cin>>num;
    cout<<endl;
    for(int i = 0; i < num; ++i){
        int x,y;
        cout<<endl<<"Point "<<i + 1<<endl;
        cout<<"Enter x-coordinate (0-based) : ";
        cin>>x;
        cout<<"Enter y-coordinate (0-based) : ";
        cin>>y;
        int cell = x*n + y;
        int temp = i;
        i = cell;
        if(i == 0){
            A->remove(i, i + 1);
            A->remove(i, i + n);
            A->remove(i, i + n + 1);
        }
        else if(i == n - 1){
            A->remove(i, i - 1);
            A->remove(i, i + n);
            A->remove(i, i + n - 1);
        }
        else if(i == n * (m - 1)){
            A->remove(i, i + 1);
            A->remove(i, i - n);
            A->remove(i, i - n + 1);
        }
        else if(i == n * m - 1){
            A->remove(i, i - 1);
            A->remove(i, i - n);
            A->remove(i, i - n - 1);
        }
        else if(i % n == 0){
            A->remove(i, i + 1);
            A->remove(i, i + n);
            A->remove(i, i - n);
            A->remove(i, i + n + 1);
            A->remove(i, i - n + 1);
        }
        else if(i % n == n - 1){
            A->remove(i, i - 1);
            A->remove(i, i + n);
            A->remove(i, i - n);
            A->remove(i, i + n - 1);
            A->remove(i, i - n - 1); 
        }
        else if(i / n == 0){
            A->remove(i, i + 1);
            A->remove(i, i - 1);
            A->remove(i, i + n);
            A->remove(i, i + n + 1);
            A->remove(i, i + n - 1);
        }
        else if(i / n == m - 1){
            A->remove(i, i + 1);
            A->remove(i, i - 1);
            A->remove(i, i - n);
            A->remove(i, i - n + 1);
            A->remove(i, i - n - 1);
        }
        else{
            //lateral
            A->remove(i, i + 1);
            A->remove(i, i - 1);
            A->remove(i, i + n);
            A->remove(i, i - n);
            //diagonals
            A->remove(i, i + n + 1);
            A->remove(i, i + n - 1);
            A->remove(i, i - n + 1);
            A->remove(i, i - n - 1);
        }
        matrix[i] = 'B';
        i = temp;
    }
    
    printer(matrix,n,m);
    return 0;
}