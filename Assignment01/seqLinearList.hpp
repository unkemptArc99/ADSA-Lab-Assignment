/*********************************************************
Name : Abhishek
Roll No : B15103
CS 202 Lab Assignment 01 - Linear List header file
Date : 18/02/2017
*********************************************************/
#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		LinearList();
		LinearList(const int& MaxListSize);
		~LinearList();
		Item& operator[](const int& i); //return i'th element of list
		bool isEmpty();
		int  length();
		int  maxSize();
		Item  returnListElement(const int k);
		bool find(const int k, Item& x);
		int  search(Item& x);
		void  deleteElement(const int  k, Item& x);
		void  insert(const int  k, Item& x);
};

template<class Item>
LinearList<Item>::LinearList(void){
	cout<<"The list is being created"<<endl;
}

template<class Item>
LinearList<Item>::LinearList(const int& MaxListSize){
	MaxSize=MaxListSize;
	len=0;
	element=(Item *)malloc(MaxListSize*sizeof(Item));
	for(int i=0;i<MaxSize;++i)
		element[i]=NULL;
	cout<<"The list is being created"<<endl;
	cout<<"The maximum size of the list is "<<MaxSize<<endl;
}

template<class Item>
Item& LinearList<Item>::operator[](const int& i){
	return element[i-1];
}

template<class Item>
Item LinearList<Item>::returnListElement(const int k){
	return element[k-1];
}

template<class Item>
bool LinearList<Item>::isEmpty(void){
	if(len==0)
		return true;
	else
		return false;
}

template<class Item>
int LinearList<Item>::length(void){
	return len;
}

template<class Item>
int LinearList<Item>::maxSize(void){
	return MaxSize;
}

template<class Item>
bool LinearList<Item>::find(const int k, Item& x){
	if(len<k)
		return false;
	else{
		x=element[k-1];
		return true;
	}
}

template<class Item>
int LinearList<Item>::search(Item& x){
	for(int i=0;i<len;++i){
		if(element[i]==x)
			return i+1;
	}
	return 0;
}

template<class Item>
void LinearList<Item>::deleteElement(const int k, Item& x){
	if(len<k)
		cout<<"The position doesn't exist"<<endl;
	else{
		x=element[k-1];
		for(int i=k-1;i<len;++i){
			element[i]=element[i+1];
		}
		len--;
		cout<<"Delete successful!"<<endl;
	}
}

template<class Item>
void LinearList<Item>::insert(const int k,Item& x){
	if(len==MaxSize)
		cout<<"There is no space for extra input"<<endl;
	else{
		len++;
		for(int i=len-1;i>k;i--){
			element[i]=element[i-1];
		}
		element[k]=x;
		cout<<"Insert successful"<<endl;
	}
}
#endif
