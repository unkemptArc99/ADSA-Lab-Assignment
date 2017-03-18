/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - Main question file
****************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "list.hpp"
#include "stack.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"Enter your input string : ";
	string a;
	cin>>a;
	vector<int> s;
	for (int i = 0; i < a.length(); ++i)
	{
		
	}
	reverse(s.begin(),s.end());
	cs202::stack<int> sta;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] >= 48 && s[i] <= 57){
			sta.push(s[i]-48);
		}
		else{
			int x1,x2;
			x1 = sta.pop();
			x2 = sta.pop();
			if(s[i]=='+'){
				sta.push(x1+x2);
			}
			else if(s[i]=='-'){
				sta.push(x1-x2);
			}
			else if(s[i]=='*'){
				sta.push(x1*x2);
			}
			else if(s[i]=='/'){
				sta.push(x1/x2);
			}
		}
	}
	int x = sta.pop();
	cout<<x<<endl;
	return 0;
}