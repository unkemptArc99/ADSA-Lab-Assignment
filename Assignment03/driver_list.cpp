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
	cout<<"Enter the number L"<<endl;
	cout<<"A"<<endl;
	cs202::list<int> main_list;
	cout<<"A"<<endl;
	main_list.append(1);
	cout<<"A"<<endl;
	main_list.cons(0);
	cout<<"A"<<endl;
	main_list.append(2);
	cout<<"A"<<endl;
	cout<<main_list.length()<<endl;
	return 0;
}