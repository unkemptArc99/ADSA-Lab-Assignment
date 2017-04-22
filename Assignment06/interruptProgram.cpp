/****************************************************
Author : Abhishek
Roll No. : B15103
ADSA Assignment06 - Heap Driver File
****************************************************/

#include <cstdlib>
#include <iostream>
#include <limits>
#include <exception>
#include <vector>

#define NUL (0)

#include "minPriorityQueue.hpp"

namespace cs202{
    class ProcessDescription{
    public:
        int PriorityValue;
        int ProcessID;
        unsigned int delay;
        unsigned int processTime;
        int slno;

        bool operator < (class ProcessDescription x){
            if(this->PriorityValue < x.PriorityValue){
                return true;
            }
            else{
                return false;                
                }
        }

        bool operator > (class ProcessDescription x){
            if(this->PriorityValue > x.PriorityValue){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator == (class ProcessDescription x){
            if(this->PriorityValue == x.PriorityValue){
                return true;
            }
            else{
                return false;
            }
        }

        bool operator != (class ProcessDescription x){
            if(this->PriorityValue != x.PriorityValue){
                return false;
            }
            else{
                return false;
            }
        }

        void operator = (class ProcessDescription x){
            this->PriorityValue = x.PriorityValue;
            this->ProcessID = x.ProcessID;
            this->delay = x.delay;
            this->processTime = x.processTime;
            this->slno = x.slno;
        }
    };
}

int main(){

    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"Welcome to the Interrupt Simulation Program!!"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl<<std::endl;

    int n;
    std::cout<<"Enter the number of processes : ";
    std::cin>>n;
    std::vector<cs202::ProcessDescription> P;

    for(int i = 0; i < n; ++i){
        unsigned int d;
        cs202::ProcessDescription N;
        std::cout<<i+1<<" Process"<<std::endl;
        std::cout<<"----------"<<std::endl;
        std::cout<<"Enter the Process ID : ";
        std::cin>>N.ProcessID;
        std::cout<<"Enter the priority value of the process : ";
        std::cin>>N.PriorityValue;
        std::cout<<"Enter the process time of the process : ";
        std::cin>>N.processTime;
        std::cout<<"Enter the delay time of the process : ";
        std::cin>>d;
        if(i != 0){
            N.delay = P[i-1].delay + d;            
        }
        N.slno = i;
        P.push_back(N);
    }

    cs202::MinPriorityQueue<cs202::ProcessDescription> A;
    unsigned int counter = 0;                           //time counter
    int processIteration = 0;                           //the current slno of the process that is to be inserted
    int insertedProcess = 0;                            //number of process inserted in the heap
    int doneProcess = 0;                                //number of process completed
    int cpuPriority = 10;                               //default CPU priority

    while(doneProcess < n){
        if(insertedProcess < n){
            if(counter == P[processIteration].delay){
                A.insert(P[processIteration]);
                processIteration++;
                insertedProcess++;
                std::cout<<"Process "<<P[processIteration - 1].ProcessID<<" has been added at "<<counter<<" ms!"<<std::endl;
            }
        }

        counter++;
        
        if(!A.empty()){
            cs202::ProcessDescription N = A.minimum();

            if(P[N.slno].processTime == 0){
                N = A.extract_min();
                doneProcess++;
                std::cout<<"Process "<<N.ProcessID<<" has ended at "<<counter<<" ms!!!!!!"<<std::endl;
            }
            else{
                P[N.slno].processTime--;
                std::cout<<"Process "<<N.ProcessID<<" is being worked upon at "<<counter<<" ms!!"<<std::endl;
            }

            if(!A.empty()){
                if(cpuPriority > N.PriorityValue){
                    cpuPriority = N.PriorityValue;
                }
            }
            else{
                cpuPriority = 10;
            }
        }

        std::cout<<std::endl;
    }

    std::cout<<"Computer interrupt handling stopped at "<<counter<<" ms."<<std::endl;
    return 0;
}