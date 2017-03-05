// Driver Program for testing `seqLinearList` class
// Author: Abhishek
// Roll Number: B15103
#include <iostream>
#include "seqLinearList.hpp"

// Please read the guidelines carefully before writing any piece of code
int main(int argc, char const *argv[])
{
	int MaxSize;
	cout<<"Enter the max amount of size : ";
	cin>>MaxSize;
	LinearList<int> A(MaxSize);
	bool stop=false;
	while(!stop){
		cout<<"1. Insert a number at the back of the list"<<endl;
		cout<<"2. Insert a number at a specific position in the list"<<endl;
		cout<<"3. Delete all occurences of a number in the list"<<endl;
		cout<<"4. Delete a specific positioned number in the list"<<endl;
		cout<<"5. Get the current length of the list"<<endl;
		cout<<"6. Get the max length of the list"<<endl;
		cout<<"7. Check if the list is empty or not"<<endl;
		cout<<"8. Get a specific positioned number from the list"<<endl;
		cout<<"9. Find a number on the specific position"<<endl;
		cout<<"10. Display the list"<<endl;
		cout<<"11. Exit"<<endl;
		int ch;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter your number : ";
				cin>>num;
				A.push_back(num);
				break;
			case 2:
				cout<<"Enter your number : ";
				cin>>num;
				cout<<"Enter the position : ";
				cin>>pos;
				A.insert(num,pos);
				break;
			case 3:
				cout<<"Enter the number : ";
				cin>>num;
				A.erase(num);
				break;
			case 4:
				cout<<"Enter the position : ";
				cin>>pos;
				A.erase_pos(pos);
				break;
			case 5:
				cout<<A.size()<<endl;
				break;
			case 6:
				cout<<A.capacity()<<endl;
				break;
			case 7:
				if(A.empty())
					cout<<"Empty list"<<endl;
				else
					cout<<"List is not empty"<<endl;
				break;
			case 8:
				cout<<"Enter the position"<<endl;
				cin>>pos;
				if(pos>=A.size())
					cout<<"Wrong input!"<<endl;
				else
					cout<<A[pos]<<endl;
				break;
			case 9:
				cout<<"Enter the number";
				cin>>num;
				int q=A.find(num);
				if(q!=A.size())
					cout<<"The number is at "<<q<<endl;
				else
					cout<<"The number is not in the list"<<endl;
				break;
			case 10:
				for(int i=0;i<A.size();++i){
					cout<<A[i]<<" ";
				}
				cout<<endl;
				break;
			case 11:
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