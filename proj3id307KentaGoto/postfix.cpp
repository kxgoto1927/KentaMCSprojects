/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 3
 *	\file postfix.cpp
 *	\brief Contains definition for evaluating postfix expressions.
 */
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "stack.h"
#include "postfix.h"

using namespace std;
double Whatisvalue(string operate,double op1, double op2){
	if (operate=="+")
		return op1 + op2;
	else if (operate=="-")
		return op1 - op2;
	else if (operate=="*")
		return op1 * op2;
	else if (operate=="/")
		return op1 / op2;
	else if (operate=="^")
		return pow(op1,op2);
	else if (operate=="%")
		return fmod(op1,op2);
	else 
		return -1;

}

bool IsOperator(string op){
	if (op=="+" || op== "-" || op== "*" || op=="/" || op=="%" || op=="^")
		return true;
	return false;

}
bool CheckIfNum(string D){
	//if (D >= '0' && D <= '9')
		//return true;
	stringstream ttest;
	double numb;
	ttest << D;
	if (ttest >> numb)
		return true;
	return false;

}
double eval_postfix(string postfix){
	Stack<double> Evalp;
	stringstream ss;
	ss << postfix;
	string oneVal;

	while (ss >> oneVal){

		if (oneVal==" ")
			continue;

		else if (IsOperator(oneVal)){

			double one = Evalp.top();
			Evalp.pop();
			double two = Evalp.top();
			Evalp.pop();

			double sol = Whatisvalue(oneVal,two,one);
			Evalp.push(sol);
		}
		else if (CheckIfNum(oneVal)){
			double num = stod(oneVal);
	
			Evalp.push(num);
		}
		
	}
	return Evalp.top();


}