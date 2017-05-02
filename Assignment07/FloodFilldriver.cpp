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
            //diagonals
            A->add(i, i + n + 1);
            A->add(i, i + n - 1);
            A->add(i, i - n + 1);
            A->add(i, i - n - 1);
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
        i = temp;
    }

    return 0;
}