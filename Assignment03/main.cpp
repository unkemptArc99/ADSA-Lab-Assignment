/****************************************************************
Name : Abhishek
Roll No : B15103
CS202 - DSA - Assignment03 - Main question file - Question 1 - Post fix
****************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "list.hpp"
#include "stack.hpp"

using namespace std;

int evaluator(string a);							//Main postfix evaluation function
int performOp(char operand, int op1, int op2);		//Performing operations on op1 and op2 using the operand
bool isOp(char c);									//To verify if c is operand or not
bool isNum(char c);									//To verify if c is numeric digit or not

int main(int argc, char const *argv[])
{
	cout<<"Enter your input string : ";
	string a;
	getline(cin,a);
	int result = evaluator(a);
	cout<<"Output = "<<result<<endl;
	return 0;
}

int evaluator(string a){
	cs202::stack<int> s;
	for (int i = a.length()-1; i >= 0; i--)
	{
		if(a[i]==' ' || a[i]=='(' || a[i]==')')
			continue;
		else if(isOp(a[i])){
			if(!s.empty()){
				int op1 = s.pop();
				int op2 = s.pop();
				int result = performOp(a[i],op1,op2);
				s.push(result);
			}
		}
		else if(isNum(a[i])){
			int op = 0;
			int key = i;
			while(i>=0 && isNum(a[i])){
				op += (a[i]-'0')*((int)pow(10,key-i));
				i--;
			}
			i++;
			s.push(op);
		}
	}
	return s.top();
}

int performOp(char operand, int op1, int op2){
	if(operand == '+')
		return op1+op2;
	else if(operand == '-')
		return op1-op2;
	else if(operand == '*')
		return op1*op2;
	else if(operand == '/')
		return op1/op2;
	else
		cout<<"ERROR!!"<<endl;
	return -1;
}

bool isOp(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

bool isNum(char c){
	if(c >= '0' && c <= '9')
		return true;
	else
		return false;
}