/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - Queue driver file
****************************************************************/

#include <iostream>
#include <cstdlib>
#include "list.hpp"
#include "queue.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	int ch,pos,num;
	bool flag = true;
	cs202::queue<int> A;
	while(flag){
		cout<<"1. Enqueue an element"<<endl;
		cout<<"2. Dequeue an element"<<endl;
		cout<<"3. Front Element"<<endl;
		cout<<"4. Size of queue"<<endl;
		cout<<"5. Check if queue is empty"<<endl;
		cout<<"6. Display the queue"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the number : "<<endl;
				cin>>num;
				A.push(num);
				break;
			case 2:
				if(A.empty()){
					cout<<"Empty Queue!! Cannot pop anything."<<endl;
				}
				else{
					cout<<"The dequeued number is "<<A.pop()<<endl;
				}
				break;
			case 3:
				if(A.empty()){
					cout<<"Empty Queue!! Nothing on top"<<endl;
				}
				else{
					cout<<"The front number is "<<A.front()<<endl;
				}
				break;
			case 4:
				cout<<"The size of the queue is : "<<A.size()<<endl;
				break;
			case 5:
				if(A.empty())
					cout<<"Empty"<<endl;
				else
					cout<<"Not empty"<<endl;
				break;
			case 6:
				cout<<"The queue is as follows : "<<endl;
				A.print();
				break;
			case 7:
				flag = false;
				break;
			default:
				cout<<"Wrong choice! Try again!"<<endl;
				break;
		}
	}
	return 0;
}