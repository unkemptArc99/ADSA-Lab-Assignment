/*************************************************************
Name : Abhishek
Roll No : B15103
CS202 - ADSA Assignment 04 - Main LRU Solver file
*************************************************************/

#include <cstdlib>
#include <iostream>
#include <exception>
#include <limits>
#include "openMap.hpp"

using namespace std;

int maxkey(int *array, int size){
	int max = 0;
	for(int i = 0; i < size; ++i){
		if(array[max] < array[i]){
			max = i;
		}
	}	
}

/*int search(int *array, int block, int size){
	for (int i = 0; i < size; ++i)
	{
		if(array[i] == block)
			return i;
	}
	return -1;
}*/

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
	int counter[m];
	for (int i = 0; i < m; ++i)
	{
		counter[i] = std::numeric_limits<int>::min();
	}
	int numofOp;
	cout<<"Enter the number of operations you want to do : ";
	cin>>numofOp;
	for (int i = 0; i < numofOp; ++i)
	{
		cout<<"Enter the location you want to read : ";
		int address;
		cin>>address;
		int memblock = address/k;
		try{
			A.put(memblock,address);
		}
		catch(int error){
			int max_key = maxkey(counter,m);
			A.remove(max_key);
			counter[max_key] = std::numeric_limits<int>::min();
			A.put(memblock,address);
		}
		counter[memblock] = 0;
		for (int i = 0; i < m; ++i)
		{
			if(i != memblock){
				if(counter[memblock] != std::numeric_limits<int>::min()){
					counter[i]++;
				}
			}
		}
		A.print();
		cout<<"Counter list : "<<endl;
		cout<<"Memblock \t Counter"<<endl;
		for (int i = 0; i < m; ++i)
		{
			if(counter[i] != std::numeric_limits<int>::min()){
				cout<<i<<"\t"<<counter[i]<<endl;
			}
		}
	}
	return 0;
}