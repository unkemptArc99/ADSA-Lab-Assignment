/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - List driver file
****************************************************************/

#include <iostream>
#include <cstdlib>
#include "list.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	int ch,pos,num;
	bool flag = true;
	cs202::list<int> A;
	while(flag){
		cout<<"1. Add element at back"<<endl;
		cout<<"2. Remove the first occurence of element"<<endl;
		cout<<"3. Add Element at front"<<endl;
		cout<<"4. Print Linked List"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the number : "<<endl;
				cin>>num;
				A.append(num);
				break;
			case 2:
				if(A.empty()){
					cout<<"Empty List!! Cannot remove anything."<<endl;
				}
				else{
					cout<<"Enter the number : "<<endl;
					cin>>num;
					A.remove(num);
				}
				break;
			case 3:
				cout<<"Enter the number : "<<endl;
				cin>>num;
				A.cons(num);
				break;
			case 4:
				A.display();
				break;
			case 5:
				flag = false;
				break;
			default:
				cout<<"Wrong choice! Try again!"<<endl;
				break;
		}
	}
	return 0;
}