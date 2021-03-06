/*********************************************************
Name : Abhishek
Roll No : B15103
CS 202 Lab Assignment 01 - Main file
Date : 18/02/2017
*********************************************************/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "seqLinearList.hpp"
#include "sorting.hpp"
#include "timer.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the Maximum Size of the list you want to create : ";
	cin>>n;
	timer T;
	LinearList<int> A(n);
	bool stop=false;
	while(!stop){
		cout<<"1. Enter a number in the list"<<endl;
		cout<<"2. Delete a number in the list"<<endl;
		cout<<"3. Get the current length of the list"<<endl;
		cout<<"4. Get the max length of the list"<<endl;
		cout<<"5. Check if the list is empty or not"<<endl;
		cout<<"6. Get a specific positioned number from the list"<<endl;
		cout<<"7. Find a number on the specific position"<<endl;
		cout<<"8. Search for a number"<<endl;
		cout<<"9. Insertion Sort"<<endl;
		cout<<"10. Bubble Sort"<<endl;
		cout<<"11. Rank Sort"<<endl;
		cout<<"12. Selection Sort"<<endl;
		cout<<"13. Exit"<<endl;
		cout<<"14. Display the list"<<endl;
		int ch;
		cout<<"Enter your choice : ";
		cin>>ch;
		Sort<int> sorter;
		int num,pos;
		switch(ch){
			case 1:
				cout<<"Enter the number to be entered : ";
				cin>>num;
				cout<<"Enter the position after which the number is to be inserted : ";
				cin>>pos;
				cout<<"---------------------------"<<endl;
				A.insert(pos,num);
				cout<<"---------------------------"<<endl;
				break;
			case 2:
				cout<<"Enter the position on which the number is to be deleted : ";
				cin>>pos;
				A.deleteElement(pos,num);
				cout<<"---------------------------"<<endl;
				cout<<"The deleted number is "<<num<<endl;
				cout<<"---------------------------"<<endl;
				break;
			case 3:
				cout<<"---------------------------"<<endl;
				cout<<"The current length of the list is "<<A.length()<<endl;
				cout<<"---------------------------"<<endl;
				break;
			case 4:
				cout<<"---------------------------"<<endl;
				cout<<"The maximum length of the list is "<<A.maxSize()<<endl;
				cout<<"---------------------------"<<endl;
				break;
			case 5:
				if(A.isEmpty()){
					cout<<"---------------------------"<<endl;
					cout<<"The list is empty"<<endl;
					cout<<"---------------------------"<<endl;
				}
				else{
					cout<<"---------------------------"<<endl;
					cout<<"The list is not empty"<<endl;
					cout<<"---------------------------"<<endl;
				}
				break;
			case 6:
				cout<<"Enter the position number : ";
				cin>>pos;
				if(pos>A.length()){
					cout<<"---------------------------"<<endl;
					cout<<"Element not accessible"<<endl;
					cout<<"---------------------------"<<endl;
				}
				else{
					cout<<"---------------------------"<<endl;
					cout<<A.returnListElement(pos)<<endl;
					cout<<"---------------------------"<<endl;
				}
				break;
			case 7:
				cout<<"Enter the position number : "<<endl;
				cin>>pos;
				if(A.find(pos,num)){
					cout<<"---------------------------"<<endl;
					cout<<"The number is "<<num<<endl;
					cout<<"---------------------------"<<endl;
				}
				else{
					cout<<"---------------------------"<<endl;
					cout<<"There is no number on this position"<<endl;
					cout<<"---------------------------"<<endl;
				}
				break;
			case 8:
				cout<<"Enter the number : ";
				cin>>num;
				pos=A.search(num);
				if(pos==0){
					cout<<"---------------------------"<<endl;
					cout<<"There is no such number in the list"<<endl;
					cout<<"---------------------------"<<endl;
				}
				else{
					cout<<"---------------------------"<<endl;
					cout<<"The position number is "<<pos<<endl;
					cout<<"---------------------------"<<endl;
				}
				break;
			case 9:
				cout<<"Enter the starting position : ";
				cin>>num;
				cout<<"enter the ending position : ";
				cin>>pos;
				cout<<"---------------------------"<<endl;
				T.start();
				sorter.insertionSort(A,num-1,pos-1);
				T.stop();
				T.print();
				cout<<"---------------------------"<<endl;
				break;
			case 10:
				cout<<"Enter the starting position : ";
				cin>>num;
				cout<<"enter the ending position : ";
				cin>>pos;
				cout<<"---------------------------"<<endl;
				T.start();
				sorter.bubbleSort(A,num-1,pos-1);
				T.stop();
				T.print();
				cout<<"---------------------------"<<endl;
				break;
			case 11:
				cout<<"Enter the starting position : ";
				cin>>num;
				cout<<"enter the ending position : ";
				cin>>pos;
				cout<<"---------------------------"<<endl;
				T.start();
				sorter.rankSort(A,num-1,pos-1);
				T.stop();
				T.print();
				cout<<"---------------------------"<<endl;
				break;
			case 12:
				cout<<"Enter the starting position : ";
				cin>>num;
				cout<<"---------------------------"<<endl;
				cout<<"enter the ending position : ";
				cin>>pos;
				cout<<"---------------------------"<<endl;
				T.start();
				sorter.selectionSort(A,num-1,pos-1);
				T.stop();
				T.print();
				cout<<"---------------------------"<<endl;
				break;
			case 13:
				cout<<"---------------------------"<<endl;
				cout<<"Exiting the program"<<endl;
				stop=true;
				cout<<"---------------------------"<<endl;
				break;
			case 14:
				cout<<"---------------------------"<<endl;
				for(int i=0;i<A.length();++i)
					cout<<A[i]<<" ";
				cout<<endl;
				cout<<"---------------------------"<<endl;
				break;
			default:
				cout<<"---------------------------"<<endl;
				cout<<"Wrong choice! Please enter again"<<endl;
				cout<<"---------------------------"<<endl;
				break;
		}
	}
	return 0;
}