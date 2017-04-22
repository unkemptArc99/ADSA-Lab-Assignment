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

namespace cs202{
    class ProcessDescription{
    public:
        int PriorityValue;
        int ProcessID;
        unsigned int delay;
        unsigned int processTime;

        bool operator < (class ProcessDescription& x){
            if(PriorityValue < x.PriorityValue){
                return true;
            }
            else{
                return false;                
                }
        }

        bool operator > (class ProcessDescription& x){
            if(PriorityValue > x.PriorityValue){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator == (class ProcessDescription& x){
            if(PriorityValue == x.PriorityValue){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator != (class ProcessDescription& x){
            if(PriorityValue != x.PriorityValue){
                return false;
            }
            else{
                return false;
            }
        }

        void operator = (class ProcessDescription& x){
            PriorityValue = x.PriorityValue;
            ProcessID = x.ProcessID;
            delay = x.delay;
            processTime = x.processTime;
        }
    }
}

int main(){

    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"Welcome to the Interrupt Simulation Program!!"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl<<std::endl;

    int n;
    std::cout<<"Enter the number of processes : ";
    std::cin>>n;
    cs202::ProcessDescription P[n];

    for(int i = 0; i < n; ++i){
        unsigned int d;
        std::cout<<i+1<<" Process"<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cout<<"Enter the Process ID : ";
        std::cin>>P[i].ProcessID;
        std::cout<<"Enter the priority value of the process : ";
        std::cin>>P[i].PriorityValue;
        std::cout<<"Enter the process time of the process : ";
        std::cin>>P[i].processTime;
        std::cout<<"Enter the delay time of the process : ";
        std::cin>>d;
        P[i].delay = P[i-1].delay + d;
    }

    cs202::MinPriorityQueue<cs202::ProcessDescription> A;
    unsigned int counter = 0;
    int processIteration = 0;
    int doneProcess = 0;

    while(doneProcess < n){
        A.insert(P[doneProcess]);
        cs202::ProcessDescription N;

    }
    return 0;
}