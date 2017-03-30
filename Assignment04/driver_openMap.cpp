/*************************************************************************
Author : Abhishek
Roll No : B15103
CS202 - ADSA Lab Assignment 04 - Linear Probe driver file
**************************************************************************/

#include <cstdlib>
#include <iostream>
#include "../Assignment03/list.hpp"
#include "dictionary.hpp"
#include "openMap.hpp"
#include <cmath>
#include <limits>
#include <exception>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int no;
    std::cout<<"Enter the size of the dictionary : ";
    std::cin>>no;
    cs202::OpenMap<string,int> A(no);
   	if(A.capacity() != no){
   		cout<<"The size of the table has been changed to "<<A.capacity()<<" for better efficiency"<<endl;
   	}
    string key;
    int value,choice;
    while (1)
    {
        std::cout<<"\n----------------------"<<std::endl;
        std::cout<<"Operations on Hash Table"<<std::endl;
        std::cout<<"\n----------------------"<<std::endl;
        std::cout<<"1.Insert element into the table"<<std::endl;
        std::cout<<"2.Search element from the key"<<std::endl;
        std::cout<<"3.Delete element of a key"<<std::endl;
        std::cout<<"4.Print the table"<<std::endl;
        std::cout<<"5.Current length of the table"<<std::endl;
        std::cout<<"6.Exit"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice)
        {
        	case 1:
            	std::cout<<"Enter element to be inserted: ";
	            std::cin>>value;
    	        std::cout<<"Enter key at which element to be inserted";
                cin>>key;
                try{
                    A.put(key,value);
                }
                catch(int error){
                    cout<<"There is no space for the input! Rehashing.";
                }
            	break;
        	case 2:
            	std::cout<<"Enter key of the element to be searched: ";
		        std::cin>>key;
        	    std::cout<<"Element at key "<<key<<" : ";
            	try{
            		value = A.get(key);
            	}
            	catch(int error){
            		cout<<"There is no element on such key"<<endl;
            	}
            	cout<<value<<endl;
            	break;
		    case 3:
	            std::cout<<"Enter key of the element to be deleted: ";
    	        std::cin>>key;
        	    A.remove(key);
            	break;
        	case 4:
        		A.print();
        		break;
        	case 5:
        		cout<<"The current length of the table : "<<A.size()<<endl;
        		break;
        	case 6:
        		exit(1);
        	default:
           		std::cout<<"\nEnter correct option\n";
       }
    }
	return 0;
}