/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 1
 *	\file infix.cpp
 *	\brief Header file for infix.cpp.  Functions declarations to convert expressions to postfix.
 */
#include <iostream>
#include <string>
#ifndef INFIX_H
#define INFIX_H

using namespace std;
bool isOperator(string D);
bool isOperand(string D);
int IsRightAssociative(string op);
int GetOperatorWeight(string op);
int HasHigherPrecedence(string op1, string op2);
string infix2postfix(string infix);


#endif