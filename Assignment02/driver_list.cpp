// Driver Program for testing `seqLinearList` class
// Author: Abhishek
// Roll Number: B15103
#include <iostream>
#include "seqLinearList.hpp"
using namespace std;
// Please read the guidelines carefully before writing any piece of code

int main(int argc, char const *argv[])
{
	int MaxSize;
	std::cout<<"Enter the max amount of size : ";
	std::cin>>MaxSize;
	cs202::LinearList<int> A(MaxSize);
	bool stop=false;
	while(!stop){
		std::cout<<"1. Insert a number at the back of the list"<<std::endl;
		std::cout<<"2. Insert a number at a specific position in the list"<<std::endl;
		std::cout<<"3. Delete all occurences of a number in the list"<<std::endl;
		std::cout<<"4. Delete a specific positioned number in the list"<<std::endl;
		std::cout<<"5. Get the current length of the list"<<std::endl;
		std::cout<<"6. Get the max length of the list"<<std::endl;
		std::cout<<"7. Check if the list is empty or not"<<std::endl;
		std::cout<<"8. Get a specific positioned number from the list"<<std::endl;
		std::cout<<"9. Find a number on the specific position"<<std::endl;
		std::cout<<"10. Display the list"<<std::endl;
		std::cout<<"11. Exit"<<std::endl;
		int ch;
		std::cout<<"Enter your choice : ";
		std::cin>>ch;
		int num,pos,q;
		switch(ch){
			case 1:
				std::cout<<"Enter your number : ";
				std::cin>>num;
				A.push_back(num);
				break;
			case 2:
				std::cout<<"Enter your number : ";
				std::cin>>num;
				std::cout<<"Enter the position : ";
				std::cin>>pos;
				A.insert(num,pos);
				break;
			case 3:
				std::cout<<"Enter the number : ";
				std::cin>>num;
				A.erase(num);
				break;
			case 4:
				std::cout<<"Enter the position : ";
				std::cin>>pos;
				A.erase_pos(pos);
				break;
			case 5:
				std::cout<<A.size()<<std::endl;
				break;
			case 6:
				std::cout<<A.capacity()<<std::endl;
				break;
			case 7:
				if(A.empty())
					std::cout<<"Empty list"<<std::endl;
				else
					std::cout<<"List is not empty"<<std::endl;
				break;
			case 8:
				std::cout<<"Enter the position"<<std::endl;
				std::cin>>pos;
				if(pos>=A.size())
					std::cout<<"Wrong input!"<<std::endl;
				else
					std::cout<<A[pos]<<std::endl;
				break;
			case 9:
				std::cout<<"Enter the number";
				std::cin>>num;
				q=A.find(num);
				if(q!=A.size())
					std::cout<<"The number is at "<<q<<std::endl;
				else
					std::cout<<"The number is not in the list"<<std::endl;
				break;
			case 10:
				for(int i=0;i<A.size();++i){
					std::cout<<A[i]<<" ";
				}
				std::cout<<std::endl;
				break;
			case 11:
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