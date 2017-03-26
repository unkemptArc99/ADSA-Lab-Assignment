/*************************************************************
Name : Abhishek
Roll No : B15103
CS202 - ADSA Assignment 04 - Main LRU Solver file
*************************************************************/

#include <cstdlib>
#include <iostream>
#include <exception>
#include "openMap.hpp"

using namespace std;

int hash_function(int n,int size){
	return n%size;
}

int maxkey(int *array, int size){
	int max = 0;
	for(int i = 0; i < size; ++i){
		if(array[max] < array[i]){
			max = i;
		}
	}	
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	cout<<"Enter the size of each memory block : ";
	cin>>k;
	cout<<"Enter the number of memory blocks in the main memory : ";
	cin>>m;
	cout<<"Enter the number of memory blocks in the cache memory : ";
	cin>>n;
	cs202::OpenMap<int,int> A(n);
	cout<<"The size of the cache memory is resized to "<<A.capacity()<<" for more efficiency"<<endl;
	int counter[A.capacity()];
	for (int i = 0; i < A.capacity(); ++i)
	{
		counter[i] = 0;
	}
	int numofOp;
	cout<<"Enter the number of operations you want to do : ";
	cin>>numofOp;
	for (int i = 0; i < numofOp; ++i)
	{
		cout<<"Enter the location you want to read : ";
		int address;
		cin>>address;
		try{
			A.put(hash_function(address%k,A.capacity()),address%k);
		}
		catch(int n){
			if(n==-2){
				int mk = maxkey(counter,A.capacity());
				int memblock = A[mk];
				A.remove(mk);
				A.put(hash_function(address%k,A.capacity()),address%k);
			}
		}
		int key = A.search(hash_function(address%k,A.capacity()),address%k);
		counter[key] = 0;
		for (int i = 0; i < A.capacity(); ++i)
		{
			if(i!=key)
				counter[key]++;
		}
	}
	A.print();
	return 0;
}