// Driver Program for testing `sorting` class
// Author: Abhishek
// Roll Number: B15103
#include <iostream>
#include "seqLinearList.hpp"
#include "sorting.hpp"
#include "timer.hpp"

// Please read the guidelines carefully before writing any piece of code
int main(int argc, char const *argv[])
{
	Sort<int> sort;
	bool stop=false;
	while(!stop){
		cout<<"1. Ascending"<<endl;
		cout<<"2. Descending"<<endl;
		cout<<"3. Random"<<endl;
		cout<<"4. Exit"<<endl;
		int ch;
		cout<<"Enter your choice : ";
		cin>>ch;
		ifstream file1;
		
		int num,pos,n;
		switch(ch){
			case 1:
				cout<<"1. 100 input"<<endl;
				cout<<"2. 500 input"<<endl;
				cout<<"3. 1000 input"<<endl;
				cout<<"4. 5000 input"<<endl;
				cout<<"5. 10000 input"<<endl;
				cout<<"6. 50000 input"<<endl;
				cout<<"7. 100000 input"<<endl;
				cout<<"8. 500000 input"<<endl;
				cout<<"9. 1000000 input"<<endl;
				cout<<"10. 5000000 input"<<endl;
				cout<<"Enter your choice : ";
				cin<<ch1;
				switch(ch1){
					case 1:
						file1.open("input/asc_100.in");
						break;
					case 2:
						file1.open("input/asc_500.in");
						break;
					case 3:
						file1.open("input/asc_1000.in");
						break;
					case 4:
						file1.open("input/asc_5000.in");
						break;
					case 5:
						file1.open("input/asc_10000.in");
						break;
					case 6:
						file1.open("input/asc_50000.in");
						break;
					case 7:
						file1.open("input/asc_100000.in");
						break;
					case 8:
						file1.open("input/asc_500000.in");
						break;
					case 9:
						file1.open("input/asc_1000000.in");
						break;
					case 10:
						file1.open("input/asc_5000000.in");
						break;
					default:
						cout<<"Wrong Choice!"<<endl;
				}
				file1>>n;
				LinearList<int> A1(n);
				for(int i=0;i<n;++i){
					file1>>num;
					A1.push_back(num);
				}
				cout<<"1. Insertion Sort"<<endl;
				cout<<"2. Bubble Sort"<<endl;
				cout<<"3. Rank Sort"<<endl;
				cout<<"4. Selection Sort"<<endl;
				cout<<"5. Merge Sort"<<endl;
				cout<<"6. Quick Sort"<<endl;
				cout<<"Enter your choice : ";
				cin>>ch1;
				switch(ch1){
					case 1:
						sort.insertionSort(A1,0,n-1);
						break;
					case 2:
						sort.bubbleSort(A1,0,n-1);
						break;
					case 3:
						sort.rankSort(A1,0,n-1);
						break;
					case 4:
						sort.selectionSort(A1,0,n-1);
						break;
					case 5:
						sort.mergeSort(A1,0,n-1);
						break;
					case 6:
						sort.quickSort(A1,0,n-1);
						break;
					default:
						cout<<"Wrong choice";
				}
				break;
			case 2:
				cout<<"1. 100 input"<<endl;
				cout<<"2. 500 input"<<endl;
				cout<<"3. 1000 input"<<endl;
				cout<<"4. 5000 input"<<endl;
				cout<<"5. 10000 input"<<endl;
				cout<<"6. 50000 input"<<endl;
				cout<<"7. 100000 input"<<endl;
				cout<<"8. 500000 input"<<endl;
				cout<<"9. 1000000 input"<<endl;
				cout<<"10. 5000000 input"<<endl;
				cout<<"Enter your choice : ";
				cin<<ch1;
				switch(ch1){
					case 1:
						file1.open("input/desc_100.in");
						break;
					case 2:
						file1.open("input/desc_500.in");
						break;
					case 3:
						file1.open("input/desc_1000.in");
						break;
					case 4:
						file1.open("input/desc_5000.in");
						break;
					case 5:
						file1.open("input/desc_10000.in");
						break;
					case 6:
						file1.open("input/desc_50000.in");
						break;
					case 7:
						file1.open("input/desc_100000.in");
						break;
					case 8:
						file1.open("input/desc_500000.in");
						break;
					case 9:
						file1.open("input/desc_1000000.in");
						break;
					case 10:
						file1.open("input/desc_5000000.in");
						break;
					default:
						cout<<"Wrong Choice!"<<endl;
				}
				file1>>n;
				LinearList<int> A2(n);
				for(int i=0;i<n;++i){
					file1>>num;
					A2.push_back(num);
				}
				cout<<"1. Insertion Sort"<<endl;
				cout<<"2. Bubble Sort"<<endl;
				cout<<"3. Rank Sort"<<endl;
				cout<<"4. Selection Sort"<<endl;
				cout<<"5. Merge Sort"<<endl;
				cout<<"6. Quick Sort"<<endl;
				cout<<"Enter your choice : ";
				cin>>ch1;
				switch(ch1){
					case 1:
						sort.insertionSort(A1,0,n-1);
						break;
					case 2:
						sort.bubbleSort(A1,0,n-1);
						break;
					case 3:
						sort.rankSort(A1,0,n-1);
						break;
					case 4:
						sort.selectionSort(A1,0,n-1);
						break;
					case 5:
						sort.mergeSort(A1,0,n-1);
						break;
					case 6:
						sort.quickSort(A1,0,n-1);
						break;
					default:
						cout<<"Wrong choice";
				}
				break;
			case 3:
				cout<<"1. 100 input"<<endl;
				cout<<"2. 500 input"<<endl;
				cout<<"3. 1000 input"<<endl;
				cout<<"4. 5000 input"<<endl;
				cout<<"5. 10000 input"<<endl;
				cout<<"6. 50000 input"<<endl;
				cout<<"7. 100000 input"<<endl;
				cout<<"8. 500000 input"<<endl;
				cout<<"9. 1000000 input"<<endl;
				cout<<"10. 5000000 input"<<endl;
				cout<<"Enter your choice : ";
				cin<<ch1;
				switch(ch1){
					case 1:
						file1.open("input/rand_100.in");
						break;
					case 2:
						file1.open("input/rand_500.in");
						break;
					case 3:
						file1.open("input/rand_1000.in");
						break;
					case 4:
						file1.open("input/rand_5000.in");
						break;
					case 5:
						file1.open("input/rand_10000.in");
						break;
					case 6:
						file1.open("input/rand_50000.in");
						break;
					case 7:
						file1.open("input/rand_100000.in");
						break;
					case 8:
						file1.open("input/rand_500000.in");
						break;
					case 9:
						file1.open("input/rand_1000000.in");
						break;
					case 10:
						file1.open("input/rand_5000000.in");
						break;
					default:
						cout<<"Wrong Choice!"<<endl;
				}
				file1>>n;
				LinearList<int> A3(n);
				for(int i=0;i<n;++i){
					file1>>num;
					A1.push_back(num);
				}
				cout<<"1. Insertion Sort"<<endl;
				cout<<"2. Bubble Sort"<<endl;
				cout<<"3. Rank Sort"<<endl;
				cout<<"4. Selection Sort"<<endl;
				cout<<"5. Merge Sort"<<endl;
				cout<<"6. Quick Sort"<<endl;
				cout<<"Enter your choice : ";
				cin>>ch1;
				switch(ch1){
					case 1:
						sort.insertionSort(A1,0,n-1);
						break;
					case 2:
						sort.bubbleSort(A1,0,n-1);
						break;
					case 3:
						sort.rankSort(A1,0,n-1);
						break;
					case 4:
						sort.selectionSort(A1,0,n-1);
						break;
					case 5:
						sort.mergeSort(A1,0,n-1);
						break;
					case 6:
						sort.quickSort(A1,0,n-1);
						break;
					default:
						cout<<"Wrong choice";
				}
				break;
			case 4:
				cout<<"---------------------------"<<endl;
				cout<<"Exiting the program"<<endl;
				stop=true;
				cout<<"---------------------------"<<endl;
				break;
			default:
				cout<<"Wrong choice!"<<endl;
				break;
		}
	}
	return 0;
}