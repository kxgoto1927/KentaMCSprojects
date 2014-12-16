/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 1
 *	\file postfix.h
 *	\brief Header file for evaluating postfix expressons.
 */
#include <iostream>
#include <string>
#ifndef POSTFIX_H
#define POSTFIX_H
using namespace std;

double Whatisvalue(char operate,int op1, int op2);
bool IsOperator(string op);
bool CheckIfNum(string D);
double eval_postfix(string postfix);


#endif