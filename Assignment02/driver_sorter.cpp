// Driver Program for testing `sorting` class
// Author: Abhishek
// Roll Number: B15103
#include <iostream>
#include <fstream>
#include "seqLinearList.hpp"
#include "sorting.hpp"
#include "timer.hpp"
using namespace std;
// Please read the guidelines carefully before writing any piece of code

int main(int argc, char const *argv[])
{
	cs202::Sort<int> sort;
	bool stop=false;
	timer T;
	double tim;
	while(!stop){
		std::cout<<"1. Ascending"<<std::endl;
		std::cout<<"2. Descending"<<std::endl;
		std::cout<<"3. Random"<<std::endl;
		std::cout<<"4. Exit"<<std::endl;
		int ch;
		std::cout<<"Enter your choice : ";
		std::cin>>ch;
		std::ifstream file1;
		std::fstream file2;
		int num,pos,n,ch1;
		cs202::LinearList<int> A;
		switch(ch){
			case 1:
				std::cout<<"1. 100 input"<<std::endl;
				std::cout<<"2. 500 input"<<std::endl;
				std::cout<<"3. 1000 input"<<std::endl;
				std::cout<<"4. 5000 input"<<std::endl;
				std::cout<<"5. 10000 input"<<std::endl;
				std::cout<<"6. 50000 input"<<std::endl;
				std::cout<<"7. 100000 input"<<std::endl;
				std::cout<<"8. 500000 input"<<std::endl;
				std::cout<<"9. 1000000 input"<<std::endl;
				std::cout<<"10. 5000000 input"<<std::endl;
				std::cout<<"Enter your choice : ";
				std::cin>>ch1;
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
						std::cout<<"Wrong Choice!"<<std::endl;
				}
				file1>>n;
				cout<<n<<endl;
				A.resize(n);
				cout<<A.size()<<" "<<A.capacity()<<endl;
				for(int i=0;i<n;++i){
					file1>>num;
					A.push_back(num);
				}
				std::cout<<"1. Insertion Sort"<<std::endl;
				std::cout<<"2. Bubble Sort"<<std::endl;
				std::cout<<"3. Rank Sort"<<std::endl;
				std::cout<<"4. Selection Sort"<<std::endl;
				std::cout<<"5. Merge Sort"<<std::endl;
				std::cout<<"6. Quick Sort"<<std::endl;
				std::cout<<"Enter your choice : ";
				std::cin>>ch1;
				switch(ch1){
					case 1:
						T.start();
						sort.insertionSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_ins_asc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 2:
						T.start();
						sort.bubbleSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_bub_asc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 3:
						T.start();
						sort.rankSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_rank_asc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 4:
						T.start();
						sort.selectionSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_sel_asc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 5:
						T.start();
						sort.mergeSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_mer_asc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 6:
						T.start();
						sort.quickSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_qui_asc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					default:
						std::cout<<"Wrong choice";
				}
				break;
			case 2:
				std::cout<<"1. 100 input"<<std::endl;
				std::cout<<"2. 500 input"<<std::endl;
				std::cout<<"3. 1000 input"<<std::endl;
				std::cout<<"4. 5000 input"<<std::endl;
				std::cout<<"5. 10000 input"<<std::endl;
				std::cout<<"6. 50000 input"<<std::endl;
				std::cout<<"7. 100000 input"<<std::endl;
				std::cout<<"8. 500000 input"<<std::endl;
				std::cout<<"9. 1000000 input"<<std::endl;
				std::cout<<"10. 5000000 input"<<std::endl;
				std::cout<<"Enter your choice : ";
				std::cin>>ch1;
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
						std::cout<<"Wrong Choice!"<<std::endl;
				}
				file1>>n;
				A.resize(n);
				for(int i=0;i<n;++i){
					file1>>num;
					A.push_back(num);
				}
				std::cout<<"1. Insertion Sort"<<std::endl;
				std::cout<<"2. Bubble Sort"<<std::endl;
				std::cout<<"3. Rank Sort"<<std::endl;
				std::cout<<"4. Selection Sort"<<std::endl;
				std::cout<<"5. Merge Sort"<<std::endl;
				std::cout<<"6. Quick Sort"<<std::endl;
				std::cout<<"Enter your choice : ";
				std::cin>>ch1;
				switch(ch1){
					case 1:
						T.start();
						sort.insertionSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_ins_desc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 2:
						T.start();
						sort.bubbleSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_bub_desc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 3:
						T.start();
						sort.rankSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_rank_desc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 4:
						T.start();
						sort.selectionSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_sel_desc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 5:
						T.start();
						sort.mergeSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_mer_desc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 6:
						T.start();
						sort.quickSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_qui_desc.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					default:
						std::cout<<"Wrong choice";
				}
				break;
			case 3:
				std::cout<<"1. 100 input"<<std::endl;
				std::cout<<"2. 500 input"<<std::endl;
				std::cout<<"3. 1000 input"<<std::endl;
				std::cout<<"4. 5000 input"<<std::endl;
				std::cout<<"5. 10000 input"<<std::endl;
				std::cout<<"6. 50000 input"<<std::endl;
				std::cout<<"7. 100000 input"<<std::endl;
				std::cout<<"8. 500000 input"<<std::endl;
				std::cout<<"9. 1000000 input"<<std::endl;
				std::cout<<"10. 5000000 input"<<std::endl;
				std::cout<<"Enter your choice : ";
				std::cin>>ch1;
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
						std::cout<<"Wrong Choice!"<<std::endl;
				}
				file1>>n;
				A.resize(n);
				for(int i=0;i<n;++i){
					file1>>num;
					A.push_back(num);
				}
				std::cout<<"1. Insertion Sort"<<std::endl;
				std::cout<<"2. Bubble Sort"<<std::endl;
				std::cout<<"3. Rank Sort"<<std::endl;
				std::cout<<"4. Selection Sort"<<std::endl;
				std::cout<<"5. Merge Sort"<<std::endl;
				std::cout<<"6. Quick Sort"<<std::endl;
				std::cout<<"Enter your choice : ";
				std::cin>>ch1;
				switch(ch1){
					case 1:
						T.start();
						sort.insertionSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_ins_rand.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 2:
						T.start();
						sort.bubbleSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_bub_rand.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 3:
						T.start();
						sort.rankSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_rank_rand.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 4:
						T.start();
						sort.selectionSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_sel_rand.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 5:
						T.start();
						sort.mergeSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_mer_rand.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					case 6:
						T.start();
						sort.quickSort(A,0,n-1);
						T.stop();
						tim=T.last_timing();
						file2.open("output_qui_rand.txt",std::fstream::app);
						file2<<n<<" "<<tim<<std::endl;
						std::cout<<tim<<" s"<<std::endl;
						break;
					default:
						std::cout<<"Wrong choice";
				}
				break;
			case 4:
				std::cout<<"---------------------------"<<std::endl;
				std::cout<<"Exiting the program"<<std::endl;
				stop=true;
				std::cout<<"---------------------------"<<std::endl;
				break;
			default:
				std::cout<<"Wrong choice!"<<std::endl;
				break;
		}
	}
	return 0;
}