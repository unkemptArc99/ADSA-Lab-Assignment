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

char *matrix;
//Variable to store the size of matrix,source and destination cell
int n,m,source,dest;

bool worker(int& i){
    if(i == dest){
        return false;
    }
    else{
        if(i != source){
            return true;
        }
        return false;
    }
}

void printer(int x,int y){
    cout<<endl;
    int counter = 0;
    cout<<"  ";
    for(int i = 0; i < x; ++i){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 0; i < y; ++i){
        cout<<i<<" ";
        for(int j = 0; j < x; ++j){
            
            cout<<matrix[counter]<<" ";
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
    matrix = new char[n*m];
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
    
    printer(n,m);

    return 0;
}