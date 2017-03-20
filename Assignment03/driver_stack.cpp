/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - Stack driver file
****************************************************************/

#include <iostream>
#include <cstdlib>
#include "list.hpp"
#include "stack.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	int ch,pos,num;
	bool flag = true;
	cs202::stack<int> A;
	while(flag){
		cout<<"1. Push an element"<<endl;
		cout<<"2. Pop an element"<<endl;
		cout<<"3. Top Element"<<endl;
		cout<<"4. Size of stack"<<endl;
		cout<<"5. Check if stack is empty"<<endl;
		cout<<"6. Display the stack"<<endl;
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
					cout<<"Empty Stack!! Cannot pop anything."<<endl;
				}
				else{
					cout<<"The popped number is "<<A.pop()<<endl;
				}
				break;
			case 3:
				if(A.empty()){
					cout<<"Empty Stack!! Nothing on top"<<endl;
				}
				else{
					cout<<"The top number is "<<A.top()<<endl;
				}
				break;
			case 4:
				cout<<"The size of the list is : "<<A.size()<<endl;
				break;
			case 5:
				if(A.empty())
					cout<<"Empty"<<endl;
				else
					cout<<"Not empty"<<endl;
				break;
			case 6:
				cout<<"The list is as follows : "<<endl;
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