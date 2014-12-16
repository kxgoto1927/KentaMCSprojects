/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 3
 *	\file infix.cpp
 *	\brief Contains function definitions for infix to postfix funciton.
 */
#include <iostream>
#include <string>
#include <sstream>
#include "infix.h"
#include "stack.h"
using namespace std;

int GetOperatorWeight(string op){
	int weight = -1;
	if (op=="+" || op=="-"){
		weight = 1;
	}
	else if (op=="*" || op=="/" || op=="%"){
		weight = 2;
	}
	else if (op=="^"){
		weight = 3;	
	}
	
	return weight;
}
int IsRightAssociative(string op){
	if (op=="^")
		return true;
	return false;
}
bool isOperator(string D){
	if (D =="+" || D =="-" || D =="*" || D =="^" || D =="%" || D =="/"){
		return true;
	}
	else
		return false;
}
bool isOperand(string D){
	//if (D >= '0' && D<= '9')
	//	return true;
	//else
	//	return false;
	stringstream ttest;
	double numb;
	ttest << D;
	if (ttest >> numb)
		return true;
	return false;
}

int HasHigherPrecedence(string op1, string op2){
	int op1weight = GetOperatorWeight(op1);
	int op2weight = GetOperatorWeight(op2);

	if (op1weight == op2weight){
		if (IsRightAssociative(op1))
			return false;
		else
			return true;

	}
	return op1weight > op2weight;
}

string infix2postfix(string infix){
	Stack<string> PostStack;
	stringstream valPost;
	valPost << infix;
	string solution = "";
	string val;
	//for (int i = 0; i< infix.length(); i++){
	while (valPost >> val){
		if (val==" ")
			continue;
		else if (isOperator(val)){
			while(!PostStack.isEmpty() && PostStack.top() != "(" && HasHigherPrecedence(PostStack.top(), val)){
				solution = solution + " " +PostStack.top();
				PostStack.pop();
			}
			PostStack.push(val);
		}
		else if(isOperand(val)){
			solution = solution + " " + val;
		}
		else if(val=="("){
			PostStack.push(val);
		}
		else if(val== ")"){
			while(!PostStack.isEmpty() && PostStack.top()!= "("){
				solution = solution + " " + PostStack.top();
				PostStack.pop();
			}
			PostStack.pop();
		}
	}
	while (!PostStack.isEmpty()){
		solution = solution + " " + PostStack.top();
		PostStack.pop();
	}
	return solution;


}