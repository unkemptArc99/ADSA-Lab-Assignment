/****************************************************
Author : Abhishek
Roll No. : B15103
ADSA Assignment06 - Heap Driver File
****************************************************/

#include <cstdlib>
#include <iostream>
#include <limits>
#include <exception>

#include "minPriorityQueue.hpp"

int main(){
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Welcome to the Heap driver file!!"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
    
    MinPriorityQueue<int> heap_structure;
    bool flag = true;

    while(flag){
        std::cout<<"1. Insert in the heap"<<std::endl;
        std::cout<<"2. Get the minimum element"<<std::endl;
        std::cout<<"3. Extract the minimum element"<<std::endl;
        std::cout<<"4. Get the current heap size"<<std::endl;
        std::cout<<"5. Check if the heap is empty or not"<<std::endl;
        std::cout<<"6. Exit"<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        std::cout<<"Enter your choice : ";
        int ch;
        cin>>ch;
        int priority;
        switch(ch){
            case 1:
                std::cout<<"Enter the priority value you want to insert";
                cin>>priority;
                heap_structure.insert(priority);
                std::cout<<"Insertion successfull!"<<std::endl;
                break;
            case 2:
                try{
                    priority = heap_structure.minimum();
                }
                catch(int error){
                    std::cout<<"Heap is currently empty! Nothing to show. Move Forward."<<std::endl;
                    break;
                }
                std::cout<<priority<<" is the minimum priority"<<std::endl;
                break;
            case 3:
                try{
                    priority = heap_structure.extract_min();
                }
                catch(int error){
                    std::cout<<"Heap is currently empty! Nothing to show. Move Forward."<<std::endl;
                    break;
                }
                std::cout<<priority<<" is the minimum priority which has been deleted."<<std::endl;
                break;
            case 4:
                std::cout<<"The current heap size is "<<heap_structure.get_heap_size()<<std::endl;
                break;
            case 5:
                if(heap_structure.empty()){
                    std::cout<<"The heap is EMPTY!!"<<std::endl;
                }
                else{
                    std::cout<<"The heap is NOT EMPTY!!"<<Std::endl;
                }
                break;
            case 6:
                exit(0);
            default:
                std::cout<<"Wrong input!!"<<Std::endl;
        }
        std::cout<<"------------------------------------------------------------"<<std::endl;
    }
    return 0;
}