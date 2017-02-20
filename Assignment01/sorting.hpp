/*********************************************************
Name : Abhishek
Roll No : B15103
CS 202 Lab Assignment 01 - Sorting header file
Date : 18/02/2017
*********************************************************/
#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"
using namespace std;

template<class Item>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<Item>& A, int low, int high);
		void bubbleSort(LinearList<Item>& A, int low, int high);
	 	void rankSort(LinearList<Item>& A, int low, int high);
        void selectionSort(LinearList<Item>& A, int low, int high);

//		void mergeSort(LinearList<Item>& A, int low, int high);
//            	void quickSort(LinearList<Item>& A, ifnt low, int high);
};

template<class Item>
void Sort<Item>::insertionSort(LinearList<Item>& A, int low, int high){
	if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
		cout<<"You have given wrong parameters"<<endl;
	else{
		for(int i=low+1;i<=high;++i){
			int j=i;
			while(j>0 && A[j-1]>A[j]){
				int temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
			}
		}
	}
	cout<<"The list has been sorted according to the parameters given."<<endl;
	cout<<"The list in the given parameters is : ";
	for(int i=low;i<=high;++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

template<class Item>
void Sort<Item>::bubbleSort(LinearList<Item>& A, int low, int high){
	if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
		cout<<"You have given wrong parameters"<<endl;
	else{
		int n=high-low+1;
		bool swapped=true;
		while(swapped!=false){
			swapped=false;
			for(int i=low+1;i<=high;++i){
				if(A[i-1]>A[i]){
					int temp=A[i];
					A[i]=A[i-1];
					A[i-1]=temp;
					swapped=true;
				}
			}
		}
	}
	cout<<"The list has been sorted according to the parameters given."<<endl;
	cout<<"The list in the given parameters is : ";
	for(int i=low;i<=high;++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

template<class Item>
void Sort<Item>::rankSort(LinearList<Item>& A, int low, int high){
	if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
		cout<<"You have given wrong parameters"<<endl;
	else{
		int n=high-low+1;
		int rank[n];
		for(int i=0;i<n;++i)
			rank[i]=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<i;++j){
				if(A[j+low]>A[i+low])
					rank[j]++;
				else
					rank[i]++;
			}
		}
		int b[n];
		for(int i=0;i<n;++i)
			b[rank[i]]=A[i+low];
		for(int i=0;i<n;++i)
			A[i+low]=b[i];
	}
	cout<<"The list has been sorted according to the parameters given."<<endl;
	cout<<"The list in the given parameters is : ";
	for(int i=low;i<=high;++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

template<class Item>
void Sort<Item>::selectionSort(LinearList<Item>& A,int low,int high){
	if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
		cout<<"You have given wrong parameters"<<endl;
	else{
		int n=high-low+1;
		for(int j=low;j<n-1+low;++j){
			int iMin=j;
			for(int i=j+1;i<n+low;++i){
				if(A[i]<A[iMin])
					iMin=i;
			}
			if(iMin!=j){
				int temp=A[j];
				A[j]=A[iMin];
				A[iMin]=temp;
			}
		}
	}
	cout<<"The list has been sorted according to the parameters given."<<endl;
	cout<<"The list in the given parameters is : ";
	for(int i=low;i<=high;++i)
		cout<<A[i]<<" ";
	cout<<endl;
}
#endif
